#pragma once
#include <iostream>
#include <vector>

int linearSearch(std::vector<int>& input, int key);
int binarySearch(int* input, int key, int size);
int kmpSearch(std::vector<int>& array, std::vector<int>& templateArray);
int  findMin(std::vector<int>& input);
int  findMax(std::vector<int>& input);