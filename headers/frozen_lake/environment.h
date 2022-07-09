#pragma once

#include <tuple>
#include <vector>
#include <list>
#include <set>


class FrozenLake
    {

    private:
        double getReward();

        [[nodiscard]] bool checkIfValidAction(int action) const;

        [[nodiscard]] bool checkIfGameEnded() const;

        [[maybe_unused]] void showGame();

        void stepWithoutSlipperiness(int action);
        void stepWithSlipperiness(int action);

    public:
        FrozenLake(bool isSlippery, bool ifShowGame);

        int observationSpace;
        int actionSpace;
        bool isSlippery;
        bool ifShowGame;
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
