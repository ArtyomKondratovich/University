//#include <iostream>
//#include <random>
//#include <chrono>
//#include <iomanip>
//#include <cmath>
//
//template<typename T>
//T realRand()            /* generate float/double value in range [-1000, 1000] */
//{
//    static std::random_device rd;
//    static std::mt19937 gen(rd());
//    static std::uniform_real_distribution<T> dis(-1000, 1000);
//    return dis(gen);
//}
//
//int intRand()               /* generate n value in range [1500, 2000]*/
//{
//    static std::random_device rd;  // Will be used to obtain a seed for the random number engine
//    static std::mt19937 gen(rd());
//    static std::uniform_int_distribution<int> dis(1500, 2000);
//    return dis(gen);
//}
//
//template<typename T>
//std::vector<std::vector<T>> generateMatrixA(int n)
//{
//    std::vector<std::vector<T>> a(n,std::vector<T>(n));
//    for (size_t i = 0; i < n; i++)
//    {
//        for (size_t j = 0; j < n; j++) 
//        {
//            a[i][j] = realRand<T>();
//        }
//    }
//
//    return a;
//}
//
//std::vector<int> generateAccurateSolution(int n, int m)
//{
//    std::vector<int> out(n);
//    out[0] = m;
//    for (size_t i = 1; i < n; i++)
//    {
//        out[i] = out[i - 1] + 1;
//    }
// 
//    return out;
//}
//
//template<typename T>
//std::vector<T> generateVectorB(const std::vector<std::vector<T>>& a, const std::vector<int>& x)
//{
//    std::vector<T> b(x.size());
//
//    for (size_t i = 0; i < x.size(); i++)
//    {
//        T sum = 0;
//        for (size_t j = 0; j < x.size(); j++)
//        {
//            sum += a[i][j] * static_cast<T>(x[j]);
//        }
//
//        b[i] = sum;
//    }
//
//    return b;
//}
//
//template<typename T>
//std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
//{
//    for (int i = 0; i < 5; i++)
//    {
//        os << " " << v[i];
//    }
//    os << "\n";
//    return os;
//}
//
//template<typename T>
//std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& v)
//{
//    for (auto line : v)
//    {
//        os << line;
//    }
//
//    return os;
//}
//
//template<typename T>
//std::vector<T> backwardStroke(const std::vector<std::vector<T>>& A, const std::vector<T>& b)
//{
//    auto n = static_cast<int>(b.size());
//    std::vector<T> solution(n);
//    solution[n - 1] = b[n - 1] / A[n - 1][n - 1];
//
//    for (int i = n - 2; i >= 0; i--)
//    {
//        T sum = 0;
//        for (size_t j = i + 1; j < n; j++)
//        {
//            sum += A[i][j] * solution[j];
//        }
//        solution[i] = (b[i] - sum) / A[i][i];
//    }
//
//    return solution;
//}
//
//template<typename T>
//std::vector<T> GaussianMethodWithoutElement(const std::vector<std::vector<T>>& matrix, const std::vector<T>& vector)
//{
//    std::vector<std::vector<T>> A = matrix;
//    std::vector<T> b = vector;
//
//    //forward
//    for (size_t i = 0; i < b.size() - 1; i++)
//    {
//        for (size_t j = i + 1; j < b.size(); j++)
//        {
//            T c = A[j][i] / A[i][i];
//            A[j][i] = 0;
//            b[j] -= b[i] * c;
//
//            for (size_t k = i + 1; k < b.size(); k++)
//            {
//                A[j][k] -= A[i][k] * c;
//            }
//        }
//    }
//
//    return backwardStroke(A,b);
//
//}
//
//template<typename T>
//void swapLines(std::vector<std::vector<T>>& A, std::vector<T>& b, size_t i, size_t j)
//{
//    std::swap(b[i], b[j]);
//    std::swap(A[i], A[j]);
//
//}
//
//template<typename T>
//size_t findMax(const std::vector<std::vector<T>>& A, size_t l, size_t r)
//{
//    T max = 0;
//    size_t line = l;
//    for (size_t i = l; i < A.size(); i++)
//    {
//        if (std::abs(A[i][r]) > max)
//        {
//            max = std::abs(A[i][r]);
//            line = i;
//        }
//    }
//
//    return line;
//}
//
//template<typename T>
//std::vector<T> GaussianMethodWithElement(const std::vector<std::vector<T>>& matrix, const std::vector<T>& vector)
//{
//    std::vector<std::vector<T>> A = matrix;
//    std::vector<T> b = vector;
//
//    //forward with swap
//    for (size_t i = 0; i < b.size() - 1; i++)
//    {
//        size_t max = findMax(A, i, i);
//        if (max != i)
//            swapLines(A, b, i, max);
//
//        for (size_t j = i + 1; j < b.size(); j++)
//        {
//            T c = A[j][i] / A[i][i];
//            A[j][i] = 0;
//            b[j] -= b[i] * c;
//
//            for (size_t k = i + 1; k < b.size(); k++)
//            {
//                A[j][k] -= A[i][k] * c;
//            }
//        }
//    }
//
//    return backwardStroke(A, b);
//}
//
//template<typename T>
//T normOfTheResidualVector(const std::vector<std::vector<T>>& A, const std::vector<T>& x1, const std::vector<T>& b)
//{   
//    T max = 0;
//    for (size_t i = 0; i < b.size(); i++)
//    {
//        T sum = 0;
//        for (size_t j = 0; j < b.size(); j++) 
//        {
//            sum += A[i][j] * x1[j];
//        }
//
//        max = std::max(std::abs(b[i] - sum), max);
//    }
//    return max;
//}
//
//template<typename T>
//T relativeError(std::vector<int> x, std::vector<T> x1)
//{
//    T normNumerator = 0;
//    int normDenominator = x.size() + 3;
//    for (size_t i = 0; i < x.size(); i++)
//    {
//        normNumerator = std::max(normNumerator, std::abs(static_cast<T>(x[i]) - x1[i]));
//    }
//
//    return normNumerator / static_cast<T>(normDenominator);
//}
//
//template<typename T>
//void printReport(std::chrono::steady_clock::time_point t3, std::chrono::steady_clock::time_point t4,const std::vector<T>& x1,const std::vector<int>& x, const std::vector<T>& b, const std::vector<std::vector<T>>& A)
//{
//    std::cout << std::setprecision(typeid(T) == typeid(float) ? 8 : 15);
//    std::cout << "1) Accurate solution x = " << x;
//    std::cout << "2) Approximate solution x* = " << x1;
//    std::cout << "3) Norm of residual vector = " << normOfTheResidualVector<T>(A, x1, b) << std::endl;
//    std::cout << "4) Relative error = " << relativeError<T>(x, x1) << std::endl;
//    std::cout << "5) Time forward and backward travel times of the Gaussian method = " << std::chrono::duration<double>(t4 - t3).count() << std::endl << std::endl;
//}
//
//template<typename T>
//void solve()
//{
//    //.................generating data for task.....................
//    auto t1 = std::chrono::steady_clock::now();
//    int n = intRand();
//    std::cout << "Generated n = " << n << std::endl;
//    auto x = generateAccurateSolution(n, 4);    //generate accurate solution x
//    auto A = generateMatrixA<T>(n);     // generate matrix A
//    auto b = generateVectorB<T>(A, x); // generate vector b
//    auto t2 = std::chrono::steady_clock::now();
//    std::cout << "Time to generate data = " << std::chrono::duration<double>(t2 - t1).count() << std::endl << std::endl;
//    //--------------------------------------------------------------
//
//    //Gaussian method without selecting element
//    auto t3 = std::chrono::steady_clock::now();
//    auto x1 = GaussianMethodWithoutElement<T>(A, b);
//    auto t4 = std::chrono::steady_clock::now();
//    printReport<T>(t3, t4, x1, x, b, A);
//    
//    //Gaussian method with selecting element
//    t3 = std::chrono::steady_clock::now();
//    x1 = GaussianMethodWithElement(A, b);
//    t4 = std::chrono::steady_clock::now();
//    printReport<T>(t3, t4, x1, x, b, A);
//}
//
//int main()
//{
//    std::cout << "______________________________________________Gaussian method with float_______________________________________________" << std::endl;
//    solve<float>();
//    std::cout << "______________________________________________Gaussian method with double______________________________________________" << std::endl;
//    solve<double>();
//}