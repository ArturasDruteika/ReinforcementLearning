#include <iostream>
#include <vector>
#include <string>

#include "../../headers/frozen_lake/environment.h"


FrozenLake::FrozenLake()
{
    observationSpace = 4;
    actionSpace = 4;
    isSlippery = false;
    transitionProbability = 33.3333;
    positionOnGrid = 0;

    env = {{"s", "f", "f", "f"},
           {"f", "h", "f", "h"},
           {"f", "f", "f", "h"},
           {"h", "f", "f", "g"}};
};

void FrozenLake::checkIfValidAction(int action)
{
    std::cout << action <<" action is valid" << std::endl;
}

std::tuple<int, double, bool> FrozenLake::step(int action)
{
    if (action == 0)
    {
        FrozenLake::checkIfValidAction(action);
    } else if (action == 1)
    {
        FrozenLake::checkIfValidAction(action);
    } else if (action == 2)
    {
        FrozenLake::checkIfValidAction(action);
    } else
    {
        FrozenLake::checkIfValidAction(action);
    }
}

FrozenLake::~FrozenLake() = default;
