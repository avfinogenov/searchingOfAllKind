#include "testing_module.h"


void test()
{
	
	std::vector<int> arrayForSearch;
	int mode = -1;
	while (mode != 1 && mode != 2)
	{
		std::cout << "enter mode: 1 - continious, 2 - random filling\n";

		std::cin >> mode;
	}
	mode == 1 ? fillArrayCont(arrayForSearch, 100) :
		fillArrayRand(arrayForSearch, 100, true);


	int input = -1;
	while (input != 0)
	{
		std::cout << "input value for search\n";
		std::cin >> input;
		std::cout << "linear search value at index: " << 
			linearSearch(arrayForSearch, input) << "\n";
		std::cout << "binary search value at index: " << 
			binarySearch(&arrayForSearch[0], input, arrayForSearch.size());
		std::cout << "\n";
	}
	//i know thats bad testing, better version will be later

	//std::vector<int> arrayForSearch;
	std::vector<int> pattern;
	fillArrayRand(arrayForSearch, 1000, true);
	//fillArrayRand(pattern, 2, false);
	int max = findMax(arrayForSearch);
	int min = findMin(arrayForSearch);
	int tmp;
	int index = 0;
	index = binarySearch(&arrayForSearch[0], max, arrayForSearch.size());
	std::cout << max << " " << arrayForSearch[index] << "\n";
	index = binarySearch(&arrayForSearch[0], min, arrayForSearch.size());
	std::cout << min << " " << arrayForSearch[index] << "\n";

	/*while (-1 == (tmp = kmpSearch(arrayForSearch, pattern)))
	{
		fillArrayRand(pattern, 5, false);
	}*/
	//std::cout << tmp;
	int tmp2 = 0;

}