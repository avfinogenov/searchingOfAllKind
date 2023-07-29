#include "arrayFilling.h"


void fillArrayCont(std::vector<int>& input, int size)
{
	for (int i = 0; i < size; ++i)
	{
		input.push_back(i);
	}

}

void fillArrayRand(std::vector<int>& input, int size, bool sortFlag)
{
	static bool firstRun = true;
	if (firstRun)
	{
		srand(time(0));
		firstRun = false;
	}

	if (!input.empty())
	{
		input.erase(input.begin(), input.end());
	}
	for (int i = 0; i < size; ++i)
	{
		input.push_back(rand() % 50);
	}
	if (sortFlag)
	{
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
	
}


int insertPattern(std::vector<int>& input, std::vector<int> &pattern)
{
	static bool firstRun = true;
	if (firstRun)
	{
		srand(time(0));
		firstRun = false;
	}

	int insertPosition = rand() % input.size();

	for (int i = 0; i < pattern.size(); ++i)
	{
		input.insert(input.begin() + insertPosition, 
			pattern.begin(), pattern.end());
		
	}
	return insertPosition;
	

}



