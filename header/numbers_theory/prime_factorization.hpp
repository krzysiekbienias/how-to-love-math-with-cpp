#pragma once

#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> primeFactors(int n);
std::unordered_map<int,int> countPrimeFactors(const std::vector<int>& factors);