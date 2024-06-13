#pragma
#include <vector>
#include <iostream>
#include <iomanip>

std::vector<std::vector<double>> operator* (const std::vector<std::vector<double>>&, const std::vector<std::vector<double>>&);

std::vector<double> operator* (const std::vector<std::vector<double>>&, const std::vector<double>&);

std::ostream& operator << (std::ostream&, const std::vector<std::vector<double>>&);

double MaxNorm(const std::vector<double>&);

double Sign(double);

std::vector<double> operator/ (const std::vector<double>&, double);

std::vector<double> operator* (const std::vector<double>&, double);

std::vector<double> operator- (const std::vector<double>&, const std::vector<double>&);

double operator* (const std::vector<double>&, const std::vector<double>&);

size_t IndexOfMax(const std::vector<double>&);