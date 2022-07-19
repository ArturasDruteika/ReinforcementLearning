#pragma once

#include <iostream>
#include <vector>


std::vector<std::vector<double>> initializeQTable(const std::vector<int> &inputShape);
int chooseAction(const std::vector<double>& actionValues, double explorationRate);