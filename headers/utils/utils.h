#pragma once

#include <vector>
#include <string>
#include <random>


std::mt19937 generator();

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator &g)
{
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

int getArgMax(std::vector<double> inputVector);

[[maybe_unused]] void printMatrixContent(std::vector<std::vector<std::string>> inputMatrix);

[[maybe_unused]] void printMatrixSize(int input);

[[maybe_unused]] void printValue(int value);


template<typename T>
void print(T input)
{
    std::cout << input << std::endl;
}
