#include <iostream>
#include <random>
#include <vector>
#include <map>
#include "Operators.h"
#include <string>

const int n = 4;
const float epsilon = (float)std::pow(10, -8);


float GetRandomFromRange(int a, int b)
{
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_real_distribution<float> distribution(a, b);
    return distribution(generator);
}

std::vector<std::vector<float>> GenerateE()
{
    std::vector<std::vector<float>> e(n, std::vector<float>(n));

    for (size_t i = 0; i < n ;i++)
    {
        e[i][i] = 1;
    }

    return e;
}

std::vector<std::vector<float>> GenerateA()
{
    std::vector<std::vector<float>> matrix(n, std::vector<float>(n));

    for(auto& line : matrix)
    {
        for (auto& element : line)
        {
            element = GetRandomFromRange(-50, 50);
        }
    }

    return matrix;
}

std::vector<std::vector<float>> MatrixM(const std::vector<std::vector<float>>& a, float leading, int i)
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

std::vector<std::vector<float>> InverseMatrixM(const std::vector<std::vector<float>>& a, int i)
{
    auto e = GenerateE();

    for (int j = 0; j < n; j++)
    {
        e[i - 1][j] = a[i][j];
    }

    return e;
}

float Trace(const std::vector<std::vector<float>>& matrix)
{
    float trace = 0;

    for (size_t i = 0; i < n; i++)
    {
        trace += matrix[i][i];
    }

    return trace;
}

bool DanilevskiMethod(std::vector<std::vector<float>> a, std::map<std::string, std::vector<std::vector<float>>>& matrices, std::vector<std::vector<float>>& frobenius)
{
    for (int i = n - 1; i >= 1; i--)
    {
        if (std::fabs(a[i][i - 1]) < epsilon)
        {
            return false;
        }

        //std::cout << std::endl << a[i][i - 1] << " " << i << std::endl;
        auto m = MatrixM(a, a[i][i - 1], i);
        //std::cout << "M" << std::endl << m;
        matrices.insert({ "M" + std::to_string(i), m});
        auto m1 = InverseMatrixM(a, i);
        //std::cout << "M^-1" << std::endl << m1;
        a = m1 * a * m;
    }

    frobenius = a;

    return true;
}

float CheckResult(float sourceTrace, float resultTrace)
{
    return std::fabs(sourceTrace - resultTrace);
}

void Printreport(const std::vector<std::vector<float>>& frobenius, const std::map<std::string, std::vector<std::vector<float>>>& matrices, const float& sourceTrace)
{
    std::cout << "Frobenius" << std::endl;
    std::cout << frobenius;

    for (auto const& m : matrices)
    {
        std::cout << m.first << std::endl;
        std::cout << m.second;
    }

    std::cout << "p1 = " << frobenius[0][0] << std::endl;
    std::cout << "|sourceTrace - p1| = " << CheckResult(sourceTrace, frobenius[0][0]);
}

void Solve()
{
    std::vector<std::vector<float>> frobenius(n, std::vector<float>(n));
    std::map<std::string, std::vector<std::vector<float>>> matrices;

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
}


int main()
{
    Solve();
}