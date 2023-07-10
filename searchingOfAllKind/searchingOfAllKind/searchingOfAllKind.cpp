
#include <iostream>
#include <vector>

#include "arrayFilling.h"



int linearSearch(std::vector<int>& input, int key);
int binarySearch(int* input, int key, int size);

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
		std::cout << "linear search value at index: " << linearSearch(arrayForSearch, input) << "\n";
		std::cout << "binary search value at index: " << binarySearch(&arrayForSearch[0], input, arrayForSearch.size());
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
		int tmp = binarySearch(&input[middlePosition + 1], key, size - middlePosition - 1);
		return tmp == -1 ? -1 : middlePosition + tmp + 1;
	}



}

