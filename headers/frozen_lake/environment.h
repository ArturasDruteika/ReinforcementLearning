#pragma once

#include <tuple>
#include <vector>
#include <list>
#include <set>


class FrozenLake
    {

    private:
        [[nodiscard]] bool checkIfValidAction(int action) const;
        double getReward();
        [[nodiscard]] bool checkIfGameEnded() const;

    public:
        FrozenLake();

        int observationSpace;
        int actionSpace;
        bool isSlippery;
        double transitionProbability;
        int startingPositionOnGrid;
        int currentPositionOnGrid;
        int finalStateID;

        std::set<int> leftSideIDs;
        std::set<int> rightSideIDs;
        std::set<int> holeIDs;

        std::vector<std::vector<std::string>> env;

        std::tuple<int, double, bool> step(int action);

        ~FrozenLake();
    };
