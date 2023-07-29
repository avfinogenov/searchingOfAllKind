#include "searching_module.h"



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



int binarySearch(int* input, int key, int size)
{
	int middlePosition = size / 2;
	if (size <= 0)
	{
		return -1;
	}
	if (input[middlePosition] == key)
	{
		return middlePosition;
	}
	if (input[middlePosition] > key)
	{
		int tmp = binarySearch(&input[0], key, middlePosition);
		return tmp == -1 ? -1 : tmp;
	}
	if (input[middlePosition] < key)
	{
		int tmp = binarySearch(&input[middlePosition + 1], key, 
								size - middlePosition - 1);
		return tmp == -1 ? -1 : middlePosition + tmp + 1;
	}



}

//it should be string, but i'm lazy
int kmpSearch(std::vector<int>& array, std::vector<int>& templateArray)
{
	//simple cases
	if (templateArray.size() > array.size())
	{
		//cant be matching
		return -1;
	}
	if (templateArray.size() == array.size())
	{
		for (int i = 0; i < array.size(); ++i)
		{
			if (array[i] != templateArray[i])
			{
				return -1;
			}
		}
		return 0;
	}
	//main case
	//prepare prefixes
	std::vector<int> prefixes;

	prefixes.push_back(0);
	int counter = 0;
	for (int i = 1; i < templateArray.size(); ++i)
	{
		if (templateArray[i] == templateArray[counter])
		{
			prefixes.push_back(counter);
			counter++;
		}
		else
		{
			counter = 0;
			prefixes.push_back(counter);
		}
	}

	//go through string

	counter = 0;
	for (int i = 0; i < array.size(); ++i)
	{

		if (array[i] == templateArray[counter])
		{
			if (counter == prefixes.size() - 1)
			{
				return i - counter;
			}
			counter++;
		}
		else
		{
			if (counter == 0)
			{
				continue;
			}
			counter = prefixes[counter];
			i -= 1;
		}

	}
	return -1;


}

int  findMax(std::vector<int>& input)
{
	int max = input[0];
	for (int i = 1; i < input.size(); ++i)
	{
		if (input[i] > max)
		{
			max = input[i];
		}
	}
	return max;
}

int  findMin(std::vector<int>& input)
{
	int min = input[0];
	for (int i = 1; i < input.size(); ++i)
	{
		if (input[i] < min)
		{
			min = input[i];
		}
	}
	return min;
}