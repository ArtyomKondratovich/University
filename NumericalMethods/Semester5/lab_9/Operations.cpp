#include "Operations.h"

std::vector<std::vector<float>> operator* (const std::vector<std::vector<float>>& a,
    const std::vector<std::vector<float>>& b)
{
    std::vector<std::vector<float>> result(a.size(), std::vector<float>(a.size()));

    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a.size(); j++) {
            for (size_t k = 0; k < a.size(); k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

std::ostream& operator << (std::ostream& stream, const std::vector<std::vector<float>>& matrix)
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

std::ostream& operator << (std::ostream& stream, const std::vector<float>& vector)
{

    for (auto const& element : vector) {
        stream << element << " ";
    }

    return stream;
}

int sgn(double value)
{
    return value < 0. ? -1 : 1;
}