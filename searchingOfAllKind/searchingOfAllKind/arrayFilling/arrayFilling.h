/**
	������ ������ �������������� ������� ��� ����������� �������������.
	�� ������ ������ ���� �������� ��������� ��������������� � ��������� ���������� �������.
	��� �� ���� ����� �������� ������������ ������.
	������ ������������ � ������������.
*/

#ifndef ARRAY_FILLING
#define ARRAY_FILLING
#include <iostream>
#include <vector>
#include <string>
#include <random>

int insertPattern(std::string& input, std::string& pattern);


// ��������� ������ ����������������� ������� �� 0 �� size
template <typename T>
void fillArrayCont(std::vector<T>& input, int size)
{
	for (int i = 0; i < size; ++i)
	{
		input.push_back((T)i);
	}
}



// ��������� ������ ���������� ������� �� 0 �� 50. size - ������ ���������� �������,
// sortFlag - ����������� �� ������ ����� ����������
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



// ��������� pattern � input. �������� �������� ���� � ���������� ��� ��������

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
