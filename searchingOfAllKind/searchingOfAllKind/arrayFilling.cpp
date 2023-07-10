#include "arrayFilling.h"


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