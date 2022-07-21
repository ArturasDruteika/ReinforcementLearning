#include <algorithm>
#include <iostream>
#include <list>
#include <random>
#include <set>
#include <string>
#include <vector>

#include "../../../headers/environments/frozen_lake/environment.h"
#include "../../../headers/utils/utils.h"


FrozenLake::FrozenLake(bool isSlippery, bool ifShowGame)
{
    this->observationSpace = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    this->actionSpace = {0, 1, 2, 3};
    this->transitionProbability = 0.3333;
    this->currentPositionOnGrid = 0;
    this->finalStateID = 15;
    this->isSlippery = isSlippery;
    this->ifShowGame = ifShowGame;
    this->agentIcon = "\033[0;34;41m@\033[0m";

    this->leftSideIDs = {0, 4, 8, 12};
    this->rightSideIDs = {3, 7, 11, 15};
    this->holeIDs = {5, 7, 11, 12};

    this->env = {{"S", "F", "F", "F"},
                 {"F", "H", "F", "H"},
                 {"F", "F", "F", "H"},
                 {"H", "F", "F", "G"}};

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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    double transitionProb = dis(gen);

    if (transitionProb <= this->transitionProbability)
    {
        this->stepWithoutSlipperiness(action);
    } else
    {
        int randomActionId = (int) (std::rand() % this->actionSpace.size());
        int randomAction = this->actionSpace[randomActionId];
        this->stepWithoutSlipperiness(randomAction);
    }
}

void FrozenLake::refreshEnvValues()
{
    this->env = {{"S", "F", "F", "F"},
                 {"F", "H", "F", "H"},
                 {"F", "F", "F", "H"},
                 {"H", "F", "F", "G"}};
}

[[maybe_unused]] void FrozenLake::showGame()
{
    int row = (int) (this->currentPositionOnGrid / this->env.size());
    int col = (int) (this->currentPositionOnGrid % this->env[0].size());

    this->refreshEnvValues();
    this->env[row][col] = this->agentIcon;
    printMatrixContent(this->env);
}

std::tuple<int, double, bool> FrozenLake::step(int action)
{
    double reward = 0.0;
    bool isDone = false;

    if (not this->isSlippery) this->stepWithoutSlipperiness(action);
    else this->stepWithSlipperiness(action);

    if (this->ifShowGame) this->showGame();

    reward = this->getReward();
    isDone = this->checkIfGameEnded();

    return std::make_tuple(this->currentPositionOnGrid, reward, isDone);
}


void FrozenLake::reset()
{
    this->currentPositionOnGrid = 0;
}

FrozenLake::~FrozenLake() = default;
