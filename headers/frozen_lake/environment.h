#pragma once

#include <vector>


class FrozenLake
    {

    public:
        FrozenLake();

        int observationSpace;
        int actionSpace;
        bool isSlippery;

        std::vector<std::vector<std::string>> env;

        ~FrozenLake();
    };
