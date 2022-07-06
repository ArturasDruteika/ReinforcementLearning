#pragma once

#include <tuple>
#include <vector>


class FrozenLake
    {

    private:
        bool checkIfValidAction(int action) const;

    public:
        FrozenLake();

        int observationSpace;
        int actionSpace;
        bool isSlippery;
        double transitionProbability;
        int startingPositionOnGrid;
        int currentPositionOnGrid;

        std::vector<std::vector<std::string>> env;

        // 14 0.0 False {'prob': 0.3333333333333333}
        std::tuple<int, double, bool> step(int action);

        ~FrozenLake();
    };
