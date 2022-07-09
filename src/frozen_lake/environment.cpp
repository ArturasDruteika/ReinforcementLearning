#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>

#include "../../headers/frozen_lake/environment.h"


FrozenLake::FrozenLake(bool isSlippery = false, bool ifShowGame = false)
{
    this->observationSpace = 4;
    this->actionSpace = 4;
    this->transitionProbability = 33.3333;
    this->startingPositionOnGrid = 0;
    this->currentPositionOnGrid = 0;
    this->finalStateID = 15;
    this->isSlippery = isSlippery;
    this->ifShowGame = ifShowGame;

    this->leftSideIDs = {0, 4, 8, 12};
    this->rightSideIDs = {3, 7, 11, 15};
    this->holeIDs = {5, 7, 11, 12};

    this->env = {{"s", "f", "f", "f"},
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

[[maybe_unused]] void FrozenLake::showGame()
{

}

void FrozenLake::stepWithoutSlipperiness(int action)
{
    if (this->checkIfValidAction(action))
    {
        if (action == 0) this->currentPositionOnGrid -= 4;
        else if (action == 1) this->currentPositionOnGrid -= 1;
        else if (action == 2) this->currentPositionOnGrid += 4;
        else this->currentPositionOnGrid += 1;
    }
}

void FrozenLake::stepWithSlipperiness(int action)
{

}

std::tuple<int, double, bool> FrozenLake::step(int action)
{
    double reward = 0.0;
    bool isDone = false;

    if (this->isSlippery == 0) this->stepWithoutSlipperiness(action);
    else this->stepWithSlipperiness(action);


    if (this->ifShowGame)
    {
        this->showGame();
    }

    reward = this->getReward();
    isDone = this->checkIfGameEnded();

    return std::make_tuple(this->currentPositionOnGrid, reward, isDone);
}

FrozenLake::~FrozenLake() = default;
