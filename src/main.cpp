#include <vector>


#include "../headers/environments/frozen_lake/environment.h"
#include "../headers/algorithms/frozen_lake/q_learning_frozen_lake.h"
#include "../headers/utils/utils.h"


void learn()
{
    FrozenLake frozenLake(false, true);

    int nStates = frozenLake.env.size() * frozenLake.env[0].size();
    std::vector<int> inputShape = {nStates, (int) frozenLake.env[0].size()};
    std::vector<std::vector<double>> qTable = initializeQTable(inputShape);

    int maxStepsPerEpisode = 100;
    int nEpisodes = 10;
    double learningRate = 0.01;

    double gamma = 1.0;
    double gammaMax = 1.0;
    double gammaMin = 0.01;
    double gammaDecay = 0.001;

    int nextState;
    double reward;
    bool done;

    for (int episode = 0; episode < nEpisodes; episode++)
    {
        int state = frozenLake.currentPositionOnGrid;

        for (int step = 0; step < maxStepsPerEpisode; step++)
        {
            int action = chooseAction(qTable[state], 0.5);
            std::tie(nextState, reward, done) = frozenLake.step(action);
            auto maxValue = std::max_element(std::begin(qTable[nextState]), std::end(qTable[nextState]));
            qTable[state][action] = qTable[state][action] + learningRate * (reward + gamma * *maxValue - qTable[state][action]);

            if (done) break;

        }
        gamma = updateExplorationRate(gammaMin,
                                      gammaMax,
                                      gammaDecay,
                                      episode);
    }
}


void increment(int &value)
{
    value++;
}


int main()
{
//    int a = 3;
//    int* b = &a;
//
//    *b = 10;
//    print(a);
//    increment(a);
//    print(a);




    learn();


    return 0;
}
