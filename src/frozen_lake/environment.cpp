#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>

#include "../../headers/frozen_lake/environment.h"


FrozenLake::FrozenLake()
{
    observationSpace = 4;
    actionSpace = 4;
    isSlippery = false;
    transitionProbability = 33.3333;
    startingPositionOnGrid = 0;
    currentPositionOnGrid = 0;

    leftSideIDs = {0, 4, 8, 12};
    rightSideIDs = {3, 7, 11, 15};

    env = {{"s", "f", "f", "f"},
           {"f", "h", "f", "h"},
           {"f", "f", "f", "h"},
           {"h", "f", "f", "g"}};

}

bool FrozenLake::checkIfValidAction(int action) const
{

    if (action == 0 && this->currentPositionOnGrid < 4) return false;
    else if (action == 1 && leftSideIDs.find(this->currentPositionOnGrid) != leftSideIDs.end()) return false;
    else if (action == 2 && this->currentPositionOnGrid > 11) return false;
    else if (action == 3 && rightSideIDs.find(this->currentPositionOnGrid) != rightSideIDs.end()) return false;
    else return true;
}

double FrozenLake::getReward(int state)
{

}

bool FrozenLake::checkIfGameEnded(int state)
{

}

std::tuple<int, double, bool> FrozenLake::step(int action)
{
    double reward = 0.0;
    bool isDone = false;

    if (this->checkIfValidAction(action))
    {
        if (action == 0) this->currentPositionOnGrid -= 4;
        else if (action == 1) this->currentPositionOnGrid -= 1;
        else if (action == 2) this->currentPositionOnGrid += 4;
        else this->currentPositionOnGrid += 1;
    }

    reward - this->getReward(this->currentPositionOnGrid);
    isDone = this->checkIfGameEnded(this->currentPositionOnGrid);

    return std::make_tuple(this->currentPositionOnGrid, reward, isDone);
}

FrozenLake::~FrozenLake() = default;
