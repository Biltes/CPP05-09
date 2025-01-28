#include "Array.hpp"

int main() {
	try {
		Array<int> arr(10);
		std::cout << "Initial values:" << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i] << std::endl;
			arr[i] = i;
		}
		std::cout << "After increment:" << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Array<int> arr(10);
		std::cout << "O.O.B. test:" << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i] << std::endl;
			arr[i] = i;
		}
		arr[11] = 1;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Array<int> arr(10);
		std::cout << "Array 1 values:" << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i] << std::endl;
			arr[i] = i;
		}
		Array<int> arr2 = arr;
		arr2[3] = 100;
		std::cout << "Array 2 values after [3] = 100:" << std::endl;
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

/*#define MAX_VAL 750
#include <math.h>
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			delete [] mirror;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}*/
