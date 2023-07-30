/**
	«адача модул€ подготавливать массивы дл€ дальнейшего использовани€.
	Ќа данный момент есть варианты заполнить последовательно и заполнить случайными числами.
	“ак же есть опци€ добавить определенный патерн.
	ћодуль используетс€ в тестировании.
*/

#ifndef ARRAY_FILLING
#define ARRAY_FILLING
#include <iostream>
#include <vector>
#include <string>
#include <random>

int insertPattern(std::string& input, std::string& pattern);


// «аполн€ет массив последовательными числами от 0 до size
template <typename T>
void fillArrayCont(std::vector<T>& input, int size)
{
	for (int i = 0; i < size; ++i)
	{
		input.push_back((T)i);
	}
}



// «аполн€ет массив случайными числами от 0 до 50. size - длинна ожидаемого массива,
// sortFlag - сортировать ли массив после заполнени€
template <typename T>
void fillArrayRand(std::vector<T>& input, int size)
{


	if (!input.empty())
	{
		input.erase(input.begin(), input.end());
	}
	for (int i = 0; i < size; ++i)
	{
		input.push_back((T)(rand() % 50));
	}
	

}



// ¬ставл€ет pattern в input. —лучайно выбирает куда и возвращает это значение

template <typename T>
int insertPattern(std::vector<T>& input, std::vector<T>& pattern)
{

	int insertPosition = rand() % input.size();

	for (int i = 0; i < pattern.size(); ++i)
	{
		input.insert(input.begin() + insertPosition,
			pattern.begin(), pattern.end());

	}
	return insertPosition;
}

#endif // !ARRAY_FILLING
