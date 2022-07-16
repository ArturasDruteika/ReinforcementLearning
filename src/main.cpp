#include <iostream>
#include <vector>

#include "../headers/environments/frozen_lake/environment.h"
#include "../headers/algorithms/frozen_lake/q_learning_frozen_lake.h"


int main()
{
    FrozenLake frozenLake(false, true);

    std::vector<int> inputShape = {(int) frozenLake.env.size(), (int) frozenLake.env[0].size()};
    std::vector<std::vector<double>> qTable = initializeQTable(inputShape);

    int maxStepsPerEpisode = 100;
    int nEpisodes = 10000;
    double learningRate = 0.01;
    double gamma = 0.99;




    return 0;
}
