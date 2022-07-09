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
    finalStateID = 15;

    leftSideIDs = {0, 4, 8, 12};
    rightSideIDs = {3, 7, 11, 15};

    holeIDs = {5, 7, 11, 12};


    env = {{"s", "f", "f", "f"},
           {"f", "h", "f", "h"},
           {"f", "f", "f", "h"},
           {"h", "f", "f", "g"}};

}

bool FrozenLake::checkIfValidAction(int action) const
{

    if (action == 0 && this->currentPositionOnGrid < 4) return false;
    else if (action == 1 && this->leftSideIDs.find(this->currentPositionOnGrid) != this->leftSideIDs.end()) return false;
    else if (action == 2 && this->currentPositionOnGrid > 11) return false;
    else if (action == 3 && this->rightSideIDs.find(this->currentPositionOnGrid) != this->rightSideIDs.end()) return false;
    else return true;
}

double FrozenLake::getReward()
{
    if (this->holeIDs.find(this->currentPositionOnGrid) != this->holeIDs.end()) return -100.0;
    else if (this->currentPositionOnGrid == this->finalStateID) return 100;
    else return -1;
}

bool FrozenLake::checkIfGameEnded() const
{
    return (this->currentPositionOnGrid == this->finalStateID || this->holeIDs.find(this->currentPositionOnGrid) != this->holeIDs.end());
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

    reward = this->getReward();
    isDone = this->checkIfGameEnded();

    return std::make_tuple(this->currentPositionOnGrid, reward, isDone);
}

FrozenLake::~FrozenLake() = default;
