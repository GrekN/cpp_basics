#include <iostream>
#include <cstdlib>
#include <ctime>

namespace mylib {

	void initArray(float* arr, const size_t size) {
		std::srand(time(nullptr));
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = ((std::rand() % 100) - 50) / 50.0f;
		}
	}

	void printFloatArray(const float* arr, const size_t size) {
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
	}

	void printIntArray(const int* arr, const size_t size) {
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
	}

	void countPositiveAndNegativeNumbers(const float* arr, const size_t size) {
		unsigned int numberOfPositive = 0;
		unsigned int numberOfNegative = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] > 0) {
				numberOfPositive++;
			}
			else if (arr[i] < 0) {
				numberOfNegative++;
			}
		}
		std::cout << numberOfPositive << " positive numbers\n";
		std::cout << numberOfNegative << " negative numbers\n";
	}
}
