#include "Operators.h"

double operator* (const std::vector<double>& a, const std::vector<double>& b)
{
    double sum = 0.;

    for (size_t i = 0; i < a.size(); i++)
    {
        sum += a[i] * b[i];
    }

    return sum;
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

std::vector<double> operator+ (const std::vector<double>& a, const std::vector<double>& b)
{
    std::vector<double> result(a.size());

    for (size_t i = 0; i < a.size(); i++)
    {
        result[i] = a[i] + b[i];
    }

    return result;
}


std::vector<double> operator* (const std::vector<std::vector<double>>& m, const std::vector<double>& v)
{
    std::vector<double> result(m.size());

    for (int i = 0; i < m.size(); i++)
    {
        double sum = 0.;

        for (int j = 0; j < m.size(); j++)
        {
            sum += m[i][j] * v[j];
        }

        result[i] = sum;
    }

    return result;
}

std::vector<double> operator* (double scalar, const std::vector<double>& v)
{
    std::vector<double> result(v.size());

    for (size_t i = 0; i < v.size(); i++)
    {
        result[i] = scalar * v[i];
    }

    return result;
}

std::ostream& operator << (std::ostream& out, const std::vector<std::vector<double>>& arg)
{
    out << std::endl;

    for (auto const& line : arg)
    {
        for (auto const& item : line)
        {
            out << item << " ";
        }

        out << std::endl;
    }

    return out;
}

std::ostream& operator << (std::ostream& out, const std::vector<double>& v)
{
    out << std::setprecision(14);

    for (size_t i = 0; i < 5; i++)
    {
        out << v[i] << " ";
    }

    out << std::endl;

    return out;
} 

std::vector<double> operator/ (const std::vector<double>& a, const std::vector<double>& b)
{
    std::vector<double> result(a.size());

    for (size_t i = 0; i < a.size(); i++)
    {
        result[i] = a[i] / b[i];
    }

    return result;
}
