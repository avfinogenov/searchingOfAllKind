/**
*	Модуль поиска. 
*/

#pragma once
#include <iostream>
#include <vector>



int kmpSearch(std::string& array, std::string& templateArray);


// ищет элемент проходя массив последовательно, возвращает индекс.
// если не нашел, то -1.
template <typename T>
int linearSearch(std::vector<T>& input, T key)
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



// рекурсивно ищет в упорядоченном массиве key
template <typename T>
int binarySearch(T* input, T key, int size)
{
	// идея в том, что если текущий элемент(начиная с середины масссива)
	// равен искомому, то его и возвращаем
	// иначе если меньше то идем в половину меньшего подмассива
	// иначе в большую
	// если размер подмассива 0, возвращаем -1(нету такого элемента)
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
template <typename T>
int kmpSearch(std::vector<T>& array, std::vector<T>& templateArray)
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



template <typename T>
T  findMax(std::vector<T>& input)
{
	T max = input[0];
	for (int i = 1; i < input.size(); ++i)
	{
		if (input[i] > max)
		{
			max = input[i];
		}
	}
	return max;
}



template <typename T>
T  findMin(std::vector<T>& input)
{
	T min = input[0];
	for (int i = 1; i < input.size(); ++i)
	{
		if (input[i] < min)
		{
			min = input[i];
		}
	}
	return min;
}