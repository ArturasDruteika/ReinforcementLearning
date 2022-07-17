#pragma once

#include <vector>
#include <string>
#include <random>


std::mt19937 generator();

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator &g);

template<typename Iter>
Iter select_randomly(Iter start, Iter end);

int getArgMax(std::vector<double> inputVector);

[[maybe_unused]] void printMatrixContent(std::vector<std::vector<std::string>> inputMatrix);

[[maybe_unused]] void printMatrixSize(int input);

[[maybe_unused]] void printValue(int value);
