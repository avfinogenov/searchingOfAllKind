#include "searching_module.h"


int kmpSearch(std::string& array, std::string& templateArray)
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



