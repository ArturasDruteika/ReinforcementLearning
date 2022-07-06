#include <iostream>
#include <string>
#include <set>

#include "../headers/frozen_lake/environment.h"
#include "../headers/utils/utils.h"


int main()
{
    FrozenLake frozenLake;
    frozenLake.currentPositionOnGrid = 16;
    frozenLake.step(0);
    frozenLake.step(1);
    frozenLake.step(2);
    frozenLake.step(3);

    return 0;
}
