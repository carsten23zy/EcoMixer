#ifndef FINDWEIGHTS_H
#define FINDWEIGHTS_H

#include <vector>

std::vector<float> solveLeastSquares(const std::vector<std::vector<float>>& A, const std::vector<float>& b);
std::vector<float> findWeights(const std::vector<float>& rgb1, 
                               const std::vector<float>& rgb2, 
                               const std::vector<float>& rgb3, 
                               const std::vector<float>& target_rgb);
#endif