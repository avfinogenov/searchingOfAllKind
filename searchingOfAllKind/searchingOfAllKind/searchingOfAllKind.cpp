﻿
#include <iostream>
#include <vector>
#include <random>

int linearSearch(std::vector<int>& input, int key);
void fillArrayRand(std::vector<int>& input, int size);
void fillArrayCont(std::vector<int>& input, int size);

int main()
{
	std::vector<int> arrayForSearch;
	int mode = -1;
	while (mode != 1 && mode != 2)
	{
		std::cout << "enter mode: 1 - continious, 2 - random filling\n";

		std::cin >> mode;
	}
	mode == 1 ? fillArrayCont(arrayForSearch, 100) : fillArrayRand(arrayForSearch, 100);
	
	
	int input = -1;
	while (input != 0)
	{
		std::cout << "input value for search\n";
		std::cin >> input;

		std::cout << "value at index: " << linearSearch(arrayForSearch, input);
		std::cout << "\n";
	}
	



}



int linearSearch(std::vector<int>& input, int key)
{
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == key)
		{
			return i;
		}
	}
	return -1;
}



void fillArrayCont(std::vector<int>& input, int size)
{
	for (int i = 0; i < size; ++i)
	{
		input.push_back(i);
	}

}

void fillArrayRand(std::vector<int>& input, int size)
{
	srand(time(0));
	for (int i = 0; i < size; ++i)
	{
		input.push_back(rand() % 50);
	}
	for (int i = 0; i < input.size(); ++i)
	{
		for (int j = 0; j < input.size() - 1; ++j)
		{
			if (input[j] > input[j + 1])
			{
				std::swap(input[j], input[j + 1]);
			}
		}
	}
}


