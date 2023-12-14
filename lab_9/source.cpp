#include "Operations.h"
#include <string>
#include <random>


const int n = 4;
const float epsilon = (float)std::pow(10, -8);

static float GetRandomFromRange(float a, float b)
{
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_real_distribution<float> distribution(a, b);
    return distribution(generator);
}

static  std::vector<std::vector<float>> GenerateA()
{
    std::vector<std::vector<float>> matrix(n, std::vector<float>(n));

    for (auto& line : matrix)
    {
        for (auto& element : line)
        {
            element = GetRandomFromRange(-50, 50);
        }
    }

    return matrix;
}

static float Trace(const std::vector<std::vector<float>>& matrix)
{
    float trace = 0;

    for (size_t i = 0; i < n; i++)
    {
        trace += matrix[i][i];
    }

    return trace;
}


static std::vector<std::vector<float>> GenerateE()
{
    std::vector<std::vector<float>> e(n, std::vector<float>(n));

    for (size_t i = 0; i < n; i++)
    {
        e[i][i] = 1;
    }

    return e;
}

static std::vector<std::vector<float>> InverseMatrixM(const std::vector<std::vector<float>>& a, int i)
{
    auto e = GenerateE();

    for (int j = 0; j < n; j++)
    {
        e[i - 1][j] = a[i][j];
    }

    return e;
}


static std::vector<std::vector<float>> MatrixM(const std::vector<std::vector<float>>& a, float leading, int i)
{
    auto e = GenerateE();

    for (int j = 0; j < n; j++)
    {
        if (j != i - 1)
        {
            e[i - 1][j] = -(a[i][j] / leading);
        }
        else
        {
            e[i - 1][j] = 1 / leading;
        }
    }

    return e;
}

static float CheckResult(float sourceTrace, float resultTrace)
{
    return std::fabs(sourceTrace - resultTrace);
}

static void Printreport(const std::vector<std::vector<float>>& frobenius, const std::vector<std::pair<std::string, std::vector<std::vector<float>>>>& matrices, const float& sourceTrace)
{
    std::cout << "Frobenius" << std::endl;
    std::cout << frobenius;

    for (auto const& m : matrices)
    {
        std::cout << m.first << std::endl;
        std::cout << m.second;
    }

    std::cout << "p1 = " << frobenius[0][0] << std::endl;
    std::cout << "|sourceTrace - p1| = " << CheckResult(sourceTrace, frobenius[0][0]) << std::endl;
}

static bool DanilevskiMethod(std::vector<std::vector<float>> a, std::vector<std::pair<std::string, std::vector<std::vector<float>>>>& matrices, std::vector<std::vector<float>>& frobenius)
{
    for (int i = n - 1; i >= 1; i--)
    {
        if (std::fabs(a[i][i - 1]) < epsilon)
        {
            return false;
        }

        auto m = MatrixM(a, a[i][i - 1], i);
        matrices.emplace_back("M" + std::to_string(i), m);
        auto m1 = InverseMatrixM(a, i);
        a = m1 * a * m;
    }

    frobenius = a;

    return true;
}

static std::vector<std::vector<float>> Solve()
{
    std::vector<std::vector<float>> frobenius(n, std::vector<float>(n));
    std::vector<std::pair<std::string, std::vector<std::vector<float>>>> matrices;

    while (true)
    {
        auto a = GenerateA();

        std::cout << "Start" << std::endl;
        std::cout << "Source matrix A" << std::endl;
        std::cout << a;

        auto trace = Trace(a);
        if (DanilevskiMethod(a, matrices, frobenius))
        {
            Printreport(frobenius, matrices, trace);
            break;
        }

        std::cout << "Exception! One of the leading elements less than 10^-8" << std::endl;

        if (!matrices.empty())
        {
            matrices.clear();
        }
    }

    return frobenius;
}

static std::vector<float> GetPlambda(const std::vector<std::vector<float>>& frobenius)
{
    std::vector<float> p_lambda(n + 1);
    p_lambda[n] = 1.f;

    for (int i = n - 1; i >= 0; i--)
    {
        p_lambda[i] = -frobenius[0][n - 1 - i];
    }

    return p_lambda;
}

static std::vector<float> TakeDerivative(const std::vector<float>& polinom)
{
    int k = polinom.size() - 1;

    if (k <= 0)
    {
        return std::vector<float>(0);
    }

    std::vector<float> derivative(k);

    for (int i = derivative.size() - 1; i >= 0; i--)
    {
        derivative[i] = (i + 1) * polinom[k--];
    }

    return derivative;
}

static std::vector<double> solveCubicEquation(double p1, double p2, double p3) {
    std::vector<double> solutions;

    // Calculate discriminant
    double Q = (3 * p2 - std::pow(p1, 2)) / 9;
    double R = (9 * p1 * p2 - 27 * p3 - 2 * std::pow(p1, 3)) / 54;
    double discriminant = std::pow(Q, 3) + std::pow(R, 2);

    // Check discriminant for real solutions
    if (discriminant > 0) {
        double S = std::cbrt(R + std::sqrt(discriminant));
        double T = std::cbrt(R - std::sqrt(discriminant));

        // Calculate solutions
        double x1 = S + T - p1 / 3;
        solutions.push_back(x1);
    }
    else if (discriminant == 0) {
        double K = R >= 0 ? -std::cbrt(R) : std::cbrt(-R);
        double x1 = 2 * K - p1 / 3;
        double x2 = -K - p1 / 3;
        solutions.push_back(x1);
        solutions.push_back(x2);
    }

    return solutions;
}

int main()
{
    auto frobenius = Solve();

    
}