#include "Operators.h"

std::vector<std::vector<double>> operator* (const std::vector<std::vector<double>>& a, const std::vector<std::vector<double>>& b)
{
    std::vector<std::vector<double>> result(a.size(), std::vector<double>(a.size()));

    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a.size(); j++) {
            for (size_t k = 0; k < a.size(); k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

std::vector<double> operator* (const std::vector<std::vector<double>>& m, const std::vector<double>& v)
{
    std::vector<double> result(v.size());

    for (auto i = 0; i < m.size(); i++)
    {
        auto sum = 0.;

        for (auto j = 0; j < m[i].size(); j++)
        {
            sum += m[i][j] * v[j];
        }

        result[i] = sum;
    }

    return result;
}

std::ostream& operator << (std::ostream& stream, const std::vector<std::vector<double>>& matrix)
{

    stream << std::fixed << std::setprecision(8);

    for (auto const& line : matrix) {
        for (auto const& element : line) {
            stream << std::setw(14) << element << " ";
        }
        stream << std::endl;
    }

    return stream;
}

double MaxNorm(const std::vector<double>& v)
{
    auto max = 0.;

    for (auto x : v)
        max = std::max(max, std::fabs(x));

    return max;
}

double Sign(double n)
{
    return n >= 0. ? 1. : -1.;
}

std::vector<double> operator/ (const std::vector<double>& v, double s)
{
    if (s == 0)
    {
        throw "Division by zero";
    }

    std::vector<double> result(v.size());

    for (size_t i = 0; i < v.size(); i++)
    {
        result[i] = v[i] / s;
    }

    return result;
}

std::vector<double> operator* (const std::vector<double>& v, double s)
{
    std::vector<double> result(v.size());

    for (size_t i = 0; i < v.size(); i++)
    {
        result[i] = v[i] * s;
    }

    return result;
}

std::vector<double> operator- (const std::vector<double>& a, const std::vector<double>& b)
{
    std::vector<double> result(a.size());

    for (size_t i = 0; i < a.size(); i++)
    {
        result[i] = a[i] - b[i];
    }

    return result;
}

double operator* (const std::vector<double>& a, const std::vector<double>& b)
{
    auto result = 0.;

    for (size_t i = 0; i < a.size(); i++)
    {
        result += a[i] * b[i];
    }

    return result;
}

size_t IndexOfMax(const std::vector<double>& v)
{
    auto max = 0.;
    auto index = 0;

    for (auto i = 0; i < v.size(); i++)
    {
        if (max < std::fabs(v[i]))
        {
            max = std::fabs(v[i]);
            index = i;
        }
    }

    return index;
}