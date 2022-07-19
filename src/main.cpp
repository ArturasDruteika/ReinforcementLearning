#include <iostream>
#include <utility>
#include <vector>
#include <random>
#include <iterator>

#include "../headers/environments/frozen_lake/environment.h"
#include "../headers/algorithms/frozen_lake/q_learning_frozen_lake.h"
#include "../headers/utils/utils.h"





void learn()
{
    FrozenLake frozenLake(false, true);

    std::vector<int> inputShape = {(int) frozenLake.env.size(), (int) frozenLake.env[0].size()};
    std::vector<std::vector<double>> qTable = initializeQTable(inputShape);

    int maxStepsPerEpisode = 100;
    int nEpisodes = 10000;
    double learningRate = 0.01;
    double gamma = 0.99;

    for (int i = 0; i < nEpisodes; i++)
    {
        int state = frozenLake.currentPositionOnGrid;

        for (int j = 0; j < maxStepsPerEpisode; j++)
        {
            int action = chooseAction(qTable[state], 0.5);
            print(action);
        }
    }
}

void increment(int& a)
{
    a++;
}

int main()
{
//    learn();
    int b = 3;
    increment(b);
    print(b);


    return 0;
}
