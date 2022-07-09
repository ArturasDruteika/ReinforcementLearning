#include <iostream>

#include "../headers/frozen_lake/environment.h"


int main()
{
    FrozenLake frozenLake(false, true);

    int nextState;
    double reward;
    bool isDone;

    frozenLake.currentPositionOnGrid = 15;

    std::tie(nextState, reward, isDone) = frozenLake.step(0);
    std::cout << reward << std::endl;
    std::tie(nextState, reward, isDone) = frozenLake.step(1);
    std::cout << reward << std::endl;
    std::tie(nextState, reward, isDone) = frozenLake.step(2);
    std::cout << reward << std::endl;
    std::tie(nextState, reward, isDone) = frozenLake.step(3);
    std::cout << reward << std::endl;

    return 0;
}
