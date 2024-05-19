#include <iostream>
#include <chrono>
#include <iomanip>
#include <random>
#include <cmath>

const int N = 6;
const int M = 4;
const int K = 4;

std::ostream& operator <<(std::ostream& output, const float* vector)
{
    for (size_t i = 0; i < 5; i++)
    {
        output << vector[i] << " ";
    }
    output << "\n";

    return output;
}

float* GetVectorA()
{
    auto a = new float[N + 1];

    for (size_t i = 1; i < N + 1; i++)
        a[i] = -K;

    return a;
}

float* GetVectorB()
{
    auto b = new float[N + 1];

    for (int i = 0; i < N; i++)
    {
        b[i] = float(M - 1 + i);
    }

    return b;
}

float* GetVectorC()
{
    auto c = new float[N + 1];

    c[0] = M;

    for (int i = 1; i < N + 1; i++)
    {
        c[i] = float(M + K + i - 1);
    }

    return c;
}

float* GetVectorY()
{
    auto y = new float[N + 1];
    y[0] = 1;

    for (size_t i = 1; i < N + 1; i++)
    {
        y[i] = y[i - 1] + 1;
    }

    return y;
}

float* GetVectorF(const float* a, const float* b, const float* c, const float* y)
{
    auto f = new float[N + 1];

    f[0] = c[0] * y[0] + b[0] * y[1];

    for (size_t i = 1; i < N; i++)
    {
        f[i] = a[i] * y[i - 1] + c[i] * y[i] + b[i] * y[i + 1];
    }

    f[N] = a[N] * y[N - 1] + c[N] * y[N];

    return f;
}

float* GetVectorAlpha(const float* a, const float* b, const float* c, const float* f)
{
    auto alpha = new float[N + 1];

    alpha[1] =  - b[0] / c[0];

    for (size_t i = 1; i <= N - 1; i++)
    {
        alpha[i + 1] = (-b[i]) / (c[i] + a[i] * alpha[i]);
    }

    return alpha;
}

float* GetVectorBeta(const float* a, const float* c, const float* f, const float* alpha)
{
    auto beta = new float[N + 1];

    beta[0] = f[0] / c[0];

    for (size_t i = 1; i < N; i++)
    {
        /*std::cout << "(" << f[i] << " - " << "( " << a[i] << " * " << beta[i - 1] << "))";
        std::cout << " / (" << c[i] << " + " << a[i] << " * " << alpha[i] << ")" << std::endl;*/
        beta[i] = (f[i] - a[i] * beta[i - 1]) / (c[i] + a[i] * alpha[i]);
    }

    beta[N] = (f[N] - a[N] * beta[N - 1]) / (c[N] + a[N] * alpha[N]);

    return beta;
}

float* GetVectorY1(const float* alpha, const float* beta)
{
    auto y1 = new float[N + 1];

    y1[N] = beta[N];

    for (int i = N - 1; i >= 0; i--)
    {
        y1[i] = alpha[i + 1] * y1[i + 1] + beta[i];
    }

    return y1;
}

float GetRelativeError(const float* y, const float* y1)
{
    float normNumerator = 0.f;
    float normDenominator = 0.f;

    for (size_t i = 0; i < N + 1; i++)
    {
        normDenominator = std::max(normDenominator, std::fabsf(y[i]));
    }

    for (size_t i = 0; i < N + 1; i++)
    {
        normNumerator = std::max(normNumerator, std::fabsf(y[i] - y1[i]));
    }

    return (normNumerator / normDenominator);
}

void solution()
{
    auto a = GetVectorA();
    auto b = GetVectorB();
    auto c = GetVectorC();
    auto y = GetVectorY();
    auto f = GetVectorF(a, b, c, y);

    auto t3 = std::chrono::steady_clock::now();
    auto alpha = GetVectorAlpha(a, b, c, f);
    auto beta = GetVectorBeta(a, c, f, alpha);
    auto y1 = GetVectorY1(alpha, beta);
    auto t4 = std::chrono::steady_clock::now();

    std::cout << "1) Accurate solution  y = " << y;
    std::cout << "2) Approximate solution y* = " << y1;
    std::cout << "3) Relative error = " << GetRelativeError(y, y1) << std::endl;
    std::cout << "4) Time = " << std::chrono::duration<double>(t4 - t3).count() << "s " << std::endl;

}

int main()
{
    solution();
}