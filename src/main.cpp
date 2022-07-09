#include <iostream>
#include <string>
#include <set>

#include "../headers/frozen_lake/environment.h"
#include "../headers/utils/utils.h"


int main()
{
    FrozenLake frozenLake(false, false);

    int nextState;
    double reward;
    bool isDone;

    std::tie(nextState, reward, isDone) = frozenLake.step(0);
    std::tie(nextState, reward, isDone) = frozenLake.step(0);
    std::tie(nextState, reward, isDone) = frozenLake.step(0);
    std::tie(nextState, reward, isDone) = frozenLake.step(3);

    std::cout << frozenLake.currentPositionOnGrid;



    return 0;
}
