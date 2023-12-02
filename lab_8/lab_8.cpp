#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include "Operators.h"

const int k = 4;
const int iterations = 50;

double realRand()            /* generate float/double value in range [-1000, 0] */
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<double> dis(-1000, 0);
    return dis(gen);
}

int intRand()               /* generate n value in range [1500, 2000] */
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(1500, 2000);
    return dis(gen);
}

std::vector<std::vector<double>> GenerateMatrixA(int n)
{
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            matrix[i][j] = realRand();
            matrix[j][i] = matrix[i][j];
        }
    }

    matrix[0][0] = std::pow(10, 2 - k);

    for (int i = 1; i < n; ++i) {
        matrix[0][0] += -matrix[0][i];
    }


    for (int i = 1; i < n; ++i) {
        matrix[i][i] = -matrix[i][0];
        for (int j = 0; j < n; ++j) {
            if (i != j)
                matrix[i][i] += -matrix[i][j];
        }
    }

    return matrix;
}

void PrintReport(const std::vector<std::vector<double>>& a,const std::vector<double>& u,double lamdba, double time)
{
    std::cout << "Lambda = " << lamdba << std::endl;

    std::cout << "|A * u - lambda * u| = " << MaxNorm(a * u - u * lamdba) << std::endl;

    std::cout << "Time = " << time << "s" << std::endl;
}

void SolveFirstSituation(const std::vector<std::vector<double>>& a)
{
    std::vector<double> y(a.size());

    y[1] = 1;

    std::vector<double> u = y;

    double lambda = 0;

    auto t1 = std::chrono::steady_clock::now();

    for (auto i = 0; i < iterations ; i++)
    {
        auto v = a * u;

        auto index = IndexOfMax(v);

        lambda = v[index] * Sign(u[index]);

        u = v / MaxNorm(v);

        y = v;
    }

    auto t2 = std::chrono::steady_clock::now();

    PrintReport(a, u,lambda, std::chrono::duration<double>(t2 - t1).count());
}

void SolveSecondSituation(const std::vector<std::vector<double>>& a)
{
    std::vector<double> y(a.size());

    y[1] = 1;

    std::vector<double> u = y;

    double lambda = 0;

    auto t1 = std::chrono::steady_clock::now();

    for (auto i = 0; i < iterations; i++)
    {
        auto v = a * u;

        lambda = (v * u) / (u * u);

        u = v / MaxNorm(v);
    }

    auto t2 = std::chrono::steady_clock::now();

    PrintReport(a, u, lambda, std::chrono::duration<double>(t2 - t1).count());
}

int main()
{
    auto n = intRand();
    auto a = GenerateMatrixA(n);
    SolveFirstSituation(a);
    SolveSecondSituation(a);
}