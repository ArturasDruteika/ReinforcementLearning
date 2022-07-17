#include <iostream>
#include <utility>
#include <vector>
#include <random>

#include "../headers/environments/frozen_lake/environment.h"
#include "../headers/algorithms/frozen_lake/q_learning_frozen_lake.h"
#include "../headers/utils/utils.h"


int chooseAction(std::vector<double> actionValues, double explorationRate)
{
    std::uniform_real_distribution<> dis(0.0, 1.0);
    std::mt19937 generate = generator();
    double explorationRateThreshold = dis(generate);

    if (explorationRateThreshold >= explorationRate) return getArgMax(std::move(actionValues));
    else return (int) *select_randomly(actionValues.begin(), actionValues.end());

}


int main()
{
    FrozenLake frozenLake(false, true);

    std::vector<int> inputShape = {(int) frozenLake.env.size(), (int) frozenLake.env[0].size()};
    std::vector<std::vector<double>> qTable = initializeQTable(inputShape);

    std::vector<double> x = {0, 1, 2, 3, 10, 1, 2, 8};
    int argMax = getArgMax(x);
    std::cout << chooseAction(x, 0.5);

//    int maxStepsPerEpisode = 100;
//    int nEpisodes = 10000;
//    double learningRate = 0.01;
//    double gamma = 0.99;
//
//    for (int i = 0; i < nEpisodes; i++)
//    {
//        int state = frozenLake.currentPositionOnGrid;
//
//        for (int j = 0; j < maxStepsPerEpisode; j++)
//        {
//            int action = chooseAction(state, 0.5);
//        }
//    }


    return 0;
}
