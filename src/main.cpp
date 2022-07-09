#include <iostream>
#include <string>
#include <set>

#include "../headers/frozen_lake/environment.h"
#include "../headers/utils/utils.h"


int main()
{
    FrozenLake frozenLake;
    frozenLake.currentPositionOnGrid = 0;

    int nextState;
    double reward;
    bool isDone;

    std::tie(nextState, reward, isDone) = frozenLake.step(3);
    std::cout << nextState << " " << reward << " " << isDone << std::endl;
    std::tie(nextState, reward, isDone) = frozenLake.step(3);
    std::cout << nextState << " " << reward << " " << isDone << std::endl;
    std::tie(nextState, reward, isDone) = frozenLake.step(2);
    std::tie(nextState, reward, isDone) = frozenLake.step(2);
    std::tie(nextState, reward, isDone) = frozenLake.step(2);
    std::tie(nextState, reward, isDone) = frozenLake.step(3);
    std::cout << nextState << " " << reward << " " << isDone << std::endl;


    return 0;
}
