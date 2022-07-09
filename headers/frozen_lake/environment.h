#pragma once

#include <list>
#include <set>
#include <tuple>
#include <vector>


class FrozenLake
{

private:
    double getReward();

    [[nodiscard]] bool checkIfValidAction(int action) const;

    [[nodiscard]] bool checkIfGameEnded() const;

    [[maybe_unused]] void showGame();

    void stepWithoutSlipperiness(int action);

    void stepWithSlipperiness(int action);

    void refreshEnvValues();

public:
    FrozenLake(bool isSlippery, bool ifShowGame);

    bool isSlippery;
    bool ifShowGame;
    double transitionProbability;
    int currentPositionOnGrid;
    int finalStateID;
    std::string agentIcon;

    std::set<int> leftSideIDs;
    std::set<int> rightSideIDs;
    std::set<int> holeIDs;
    std::vector<int> observationSpace;
    std::vector<int> actionSpace;
    std::vector<std::vector<std::string>> env;

    std::tuple<int, double, bool> step(int action);

    ~FrozenLake();
};
