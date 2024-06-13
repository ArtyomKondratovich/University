#pragma once
#include <vector>
#include <iostream>
#include <iomanip>

double operator* (const std::vector<double>&, const std::vector<double>&);

std::vector<double> operator+ (const std::vector<double>&, const std::vector<double>&);

std::vector<double> operator- (const std::vector<double>&, const std::vector<double>&);

std::vector<double> operator* (const std::vector<std::vector<double>>&, const std::vector<double>&);

std::vector<double> operator* (double, const std::vector<double>&);

std::ostream& operator << (std::ostream&, const std::vector<std::vector<double>>&);

std::ostream& operator << (std::ostream&, const std::vector<double>&);