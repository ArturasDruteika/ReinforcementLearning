#include <iostream>
#include <string>
#include "../headers/frozen_lake/environment.h"


void printMatrixContent(std::vector<std::vector<std::string>> inputMatrix)
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


int main()
{
    FrozenLake frozenLake;

    printMatrixContent(frozenLake.env);

    return 0;
}
