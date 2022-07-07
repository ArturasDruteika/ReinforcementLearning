#include <iostream>
#include <string>
#include <set>

#include "../headers/frozen_lake/environment.h"
#include "../headers/utils/utils.h"


int main()
{
    FrozenLake frozenLake;
    frozenLake.currentPositionOnGrid = 5;

    int nextState;
    double reward;
    bool isDone;

    std::tie(nextState, reward, isDone) = frozenLake.step(3);
    printValue(frozenLake.currentPositionOnGrid);


    return 0;
}
