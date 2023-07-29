#ifndef ARRAY_FILLING
#define ARRAY_FILLING
#include <iostream>
#include <vector>
#include <random>

void fillArrayRand(std::vector<int>& input, int size, bool sortFlag);
void fillArrayCont(std::vector<int>& input, int size);
int insertPattern(std::vector<int>& input, std::vector<int>& pattern);

#endif // !ARRAY_FILLING
