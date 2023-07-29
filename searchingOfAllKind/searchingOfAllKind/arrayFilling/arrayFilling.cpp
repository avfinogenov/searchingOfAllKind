#include "arrayFilling.h"






int insertPattern(std::string& input, std::string& pattern)
{

	int insertPosition = rand() % input.size();

	for (int i = 0; i < pattern.size(); ++i)
	{
		input.insert(input.begin() + insertPosition,
			pattern.begin(), pattern.end());

	}
	return insertPosition;
}



