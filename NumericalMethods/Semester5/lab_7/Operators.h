#pragma once
#include <vector>
#include <iostream>
#include <iomanip>

std::vector<std::vector<float>> operator* (const std::vector<std::vector<float>>&, const std::vector<std::vector<float>>&);

std::ostream& operator << (std::ostream&, const std::vector<std::vector<float>>&);