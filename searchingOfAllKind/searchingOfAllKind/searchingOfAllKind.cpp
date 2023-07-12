
#include <iostream>
#include <vector>

#include "arrayFilling.h"



int linearSearch(std::vector<int>& input, int key);
int binarySearch(int* input, int key, int size);
int kmpSearch(std::vector<int>& array, std::vector<int>& templateArray);


int main()
{

	//old
	/*std::vector<int> arrayForSearch;
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
	}*/
	//i know thats bad testing, better version will be later
	
	std::vector<int> arrayForSearch;
	std::vector<int> pattern;
	fillArrayRand(arrayForSearch, 1000, false);
	fillArrayRand(pattern, 2, false);
	int tmp;
	while (-1 == (tmp = kmpSearch(arrayForSearch, pattern)))
	{
		fillArrayRand(pattern, 5, false);
	}
	std::cout << tmp;
	int tmp2 = 0;


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

//it should be string, but i'm lazy
int kmpSearch(std::vector<int> &array, std::vector<int> &templateArray)
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