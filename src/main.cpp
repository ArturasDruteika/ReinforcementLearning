#include <iostream>
#include <string>
#include <set>

#include "../headers/frozen_lake/environment.h"
#include "../headers/utils/utils.h"


int main()
{
    FrozenLake frozenLake(true, false);

    int nextState;
    double reward;
    bool isDone;

    frozenLake.currentPositionOnGrid = 5;

    std::tie(nextState, reward, isDone) = frozenLake.step(0);
    std::cout << frozenLake.currentPositionOnGrid << std::endl;
    std::tie(nextState, reward, isDone) = frozenLake.step(1);
    std::cout << frozenLake.currentPositionOnGrid << std::endl;
    std::tie(nextState, reward, isDone) = frozenLake.step(2);
    std::cout << frozenLake.currentPositionOnGrid << std::endl;
    std::tie(nextState, reward, isDone) = frozenLake.step(3);
    std::cout << frozenLake.currentPositionOnGrid << std::endl;



    return 0;
}
