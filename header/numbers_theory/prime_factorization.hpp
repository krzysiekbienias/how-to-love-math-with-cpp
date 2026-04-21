#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "types.hpp"

std::vector<i64> primeFactors(i64 n);
std::unordered_map<i64,int> countPrimeFactors(const std::vector<i64>& factors);