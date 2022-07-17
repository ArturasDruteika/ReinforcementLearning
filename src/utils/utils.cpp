#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <iterator>

#include "../../headers/utils/utils.h"


std::mt19937 generator()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return gen;
}


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


int getArgMax(std::vector<double> inputVector)
{
    return (int) std::distance(inputVector.begin(), std::max_element(inputVector.begin(), inputVector.end()));
}


[[maybe_unused]] void printMatrixContent(std::vector<std::vector<std::string>> inputMatrix)
{
    for (int i = 0; i < inputMatrix.size(); i++)
    {
        for (int j = 0; j < inputMatrix[0].size(); j++)
        {
            std::cout << inputMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}


[[maybe_unused]] void printMatrixSize(int input)
{
    std::cout << input << std::endl;
}

[[maybe_unused]] void printValue(int value)
{
    std::cout << value << std::endl;
}