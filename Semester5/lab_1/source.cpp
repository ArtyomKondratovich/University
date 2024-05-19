#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <cmath>

template<typename T>
T realRand()            /* generate float/double value in range [-1000, 1000] */
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<T> dis(-1000, 1000);
    return dis(gen);
}

int intRand()               /* generate n value in range [1500, 2000]*/
{
    static std::random_device rd;  // Will be used to obtain a seed for the random number engine
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(1500, 2000);
    return dis(gen);
}

template<typename T>
class GaussianMethod
{
public:
    GaussianMethod() = default;
    
    void printMatrix(T** m, int n) const
    {
        std::cout << std::endl;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                std::cout << m[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    
    T** generateMatrixA(int n)
    {
        auto a = new T * [n];
        for (size_t i = 0; i < n; i++)
        {
            a[i] = new T[n];
            for (size_t j = 0; j < n; j++)
            {
                a[i][j] = realRand<T>();
            }
        }

        return a;
    }

    std::vector<int> generateAccurateSolution(int n, int m) const
    {
        std::vector<int> out(n);
        out[0] = m;
        for (size_t i = 1; i < n; i++)
        {
            out[i] = out[i - 1] + 1;
        }

        return out;
    }
    
    T* generateVectorB(T** a, std::vector<int>& x)
    {
        auto b = new T[x.size()];

        for (size_t i = 0; i < x.size(); i++)
        {
            T sum = 0;
            for (size_t j = 0; j < x.size(); j++)
            {
                sum += a[i][j] * static_cast<T>(x[j]);
            }

            b[i] = sum;
        }

        return b;
    }
    
    T* backwardStroke(T** A, T* b, int n)
    {
        auto solution = new T[n];
        solution[n - 1] = b[n - 1] / A[n - 1][n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            T sum = 0;
            for (size_t j = i + 1; j < n; j++)
            {
                sum += A[i][j] * solution[j];
            }
            solution[i] = (b[i] - sum) / A[i][i];
        }

        return solution;
    }

    T* GaussianMethodWithoutElement(T** A, T* b, int n)
    {
        //forward
        for (size_t i = 0; i < n - 1; i++)
        {
            for (size_t j = i + 1; j < n; j++)
            {
                T c = A[j][i] / A[i][i];
                A[j][i] = 0;
                b[j] -= b[i] * c;

                for (size_t k = i + 1; k < n; k++)
                {
                    A[j][k] -= A[i][k] * c;
                }
            }
        }

        return backwardStroke(A, b, n);

    }
    
    size_t findMax(T** A, size_t l, size_t r, int n) const
    {
        T max = 0;
        size_t line = l;
        for (size_t i = l; i < n; i++)
        {
            if (std::abs(A[i][r]) > max)
            {
                max = std::abs(A[i][r]);
                line = i;
            }
        }

        return line;
    }

    T* GaussianMethodWithElement(T** A, T* b, int n)
    {

        //forward with swap
        for (size_t i = 0; i < n - 1; i++)
        {
            size_t max = findMax(A, i, i, n);
            if (max != i)
            {
                std::swap(b[i], b[max]);
                std::swap(A[i], A[max]);
            }

            for (size_t j = i + 1; j < n; j++)
            {
                T c = A[j][i] / A[i][i];
                A[j][i] = 0;
                b[j] -= b[i] * c;

                for (size_t k = i + 1; k < n; k++)
                {
                    A[j][k] -= A[i][k] * c;
                }
            }
        }

        return backwardStroke(A, b, n);
    }

    T normOfTheResidualVector(T** A, T* x1, T* b, int n)
    {
        T max = 0;
        for (size_t i = 0; i < n; i++)
        {
            T sum = 0;
            for (size_t j = 0; j < n; j++)
            {
                sum += A[i][j] * x1[j];
            }

            max = std::max(std::abs(b[i] - sum), max);
        }
        return max;
    }

    T relativeError(std::vector<int> x, T* x1)
    {
        T normNumerator = 0;
        int normDenominator = x.size() + 3;
        for (size_t i = 0; i < x.size(); i++)
        {
            normNumerator = std::max(normNumerator, std::abs(static_cast<T>(x[i]) - x1[i]));
        }

        return normNumerator / static_cast<T>(normDenominator);
    }

    void printReport(std::chrono::steady_clock::time_point t3, std::chrono::steady_clock::time_point t4, T* x1, std::vector<int>& x, T* b, T** A, int n)
    {
        std::cout << std::setprecision(typeid(T) == typeid(float) ? 8 : 15);
        std::cout << "1) Accurate solution x = ";
        for (size_t i = 0; i < 5; i++)
            std::cout << x[i] << " ";
        std::cout << "\n2) Approximate solution x* = ";
        for (size_t i = 0; i < 5; i++)
            std::cout << x1[i] << " ";
        std::cout << "\n3) Norm of residual vector = " << normOfTheResidualVector(A, x1, b, n) << std::endl;
        std::cout << "4) Relative error = " << relativeError(x, x1) << std::endl;
        std::cout << "5) Time forward and backward travel times of the Gaussian method = " << std::chrono::duration<double>(t4 - t3).count() << std::endl << std::endl;
    }

    T** makeCopyMatrix(T** A, int n)
    {
        auto m = new T * [n];
        for (size_t i = 0; i < n; i++)
        {
            m[i] = new T[n];
            for (size_t j = 0; j < n; j++)
            {
                m[i][j] = A[i][j];
            }
        }

        return m;
    }

    T* makeCopyVector(T* b, int n)
    {
        auto m = new T[n];
        for (size_t i = 0; i < n; i++)
        {
            m[i] = b[i];
        }

        return m;
    }

    void solve()
    {
        //.................generating data for task.....................
        auto t1 = std::chrono::steady_clock::now();
        int n = 1500;
        std::cout << "Generated n = " << n << std::endl;
        auto x = generateAccurateSolution(n, 4);    //generate accurate solution x
        auto A = generateMatrixA(n);     // generate matrix A
        auto b = generateVectorB(A, x); // generate vector b
        auto t2 = std::chrono::steady_clock::now();
        std::cout << "Time to generate data = " << std::chrono::duration<double>(t2 - t1).count() << std::endl << std::endl;
        //--------------------------------------------------------------

        //Gaussian method without selecting element
        auto copy1_A = makeCopyMatrix(A, n);
        auto copy1_b = makeCopyVector(b, n);
        auto t3 = std::chrono::steady_clock::now();
        auto x1 = GaussianMethodWithoutElement(A, b, n);
        auto t4 = std::chrono::steady_clock::now();
        std::cout << "[Gaussian method without selecting element]" << std::endl;
        printReport(t3, t4, x1, x, copy1_b, copy1_A, n);

        //Gaussian method with selecting element
        auto copy2_A = makeCopyMatrix(copy1_A, n);
        auto copy2_b = makeCopyVector(copy1_b, n);
        t3 = std::chrono::steady_clock::now();
        x1 = GaussianMethodWithElement(copy1_A, copy1_b, n);
        t4 = std::chrono::steady_clock::now();
        std::cout << "[Gaussian method with selecting element]" << std::endl;
        printReport(t3, t4, x1, x, copy2_b, copy2_A, n);
    }

};

int main()
{
    auto solutionF = GaussianMethod<float>();
    auto solutionD = GaussianMethod<double>();
    std::cout << "______________________________________________Gaussian method with float_______________________________________________" << std::endl;
    solutionF.solve();
    std::cout << "______________________________________________Gaussian method with double______________________________________________" << std::endl;
    solutionD.solve();
}