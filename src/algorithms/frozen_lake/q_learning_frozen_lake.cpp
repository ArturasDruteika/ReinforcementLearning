#include <vector>

#include "../../../headers/algorithms/frozen_lake/q_learning_frozen_lake.h"


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
