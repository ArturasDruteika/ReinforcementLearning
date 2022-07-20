#include <vector>
#include <random>
#include <cmath>

#include "../../../headers/algorithms/frozen_lake/q_learning_frozen_lake.h"
#include "../../../headers/utils/utils.h"


std::vector<std::vector<double>> initializeQTable(const std::vector<int> &inputShape)
{
    std::vector<std::vector<double>> qTable;
    for (int i = 0; i < inputShape[0]; i++)
    {
        std::vector<double> rowVector;
        for (int j = 0; j < inputShape[1]; j++)
        {
            rowVector.push_back(0);
        }
        qTable.push_back(rowVector);
    }

    return qTable;
}


int chooseAction(const std::vector<double> &actionValues, double explorationRate)
{
    std::uniform_real_distribution<> dis(0.0, 1.0);
    std::mt19937 generate = generator();
    double explorationRateThreshold = dis(generate);

    if (explorationRateThreshold >= explorationRate)
    {
        return getArgMax(actionValues);
    } else
    {
        int rangeSize = (int) (actionValues.size());
        int randomIndex = std::rand() % rangeSize;
        return randomIndex;
    }
}

double updateExplorationRate(double minExplorationRate, double maxExplorationRate, double explorationRateDecay, int episode)
{
    return minExplorationRate + (maxExplorationRate - minExplorationRate) * std::exp(-explorationRateDecay * episode);
}
