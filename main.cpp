#include <iostream>
#include <clocale>
#include <vector>

// 1. �������� ������� ������� ������� ������ double ����� �� �����. ��������� ������� ��� ��� ������ � ��� ������.
// ������� ��� ������� �� main.
void printDoubleArray(const double* arr, const size_t n) {
	for (size_t i = 0; i < n; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

// 2. ������ ������������� ������, ��������� �� ��������� 0 � 1. ��������: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ].
// �������� �������, ���������� � �������� ������� 0 �� 1, 1 �� 0. �������� �� ����� ������ �� ��������� � �����.
void revertElements(int* arr, const size_t n) {
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = !arr[i];
	}
}
void printIntArray(const int* arr, const size_t n) {
	for (size_t i = 0; i < n; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

// 3. ������ ������ ������������� ������ �������� 8. �������� �������, ������� � ������� ����� �������� ��� ����������
// 1 4 7 10 13 16 19 22. ������� ������ �� �����.
void initArrray(int* arr, const size_t n ) {
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = 1 + i * 3;
	}
}

// 4. �������� �������, ������� �� ���� ������� ���������� ������ � ����� n (����� ���� �������������, ��� �������������),
// ��� ���� ����� ������ ���������� �������� ��� �������� ������� �� n �������.
void moveArrayValues(std::vector<int>& arr, const int n) {
	size_t size = arr.size();
	std::vector<int> newArr(size);
	for (size_t i = 0; i < size; i++)
	{
		int posInNewArr;
		posInNewArr = (static_cast<int>(i) + n) % static_cast<int>(size);
		if (posInNewArr < 0)
		{
			newArr[size + posInNewArr] = arr[i];
		}
		else
		{
			newArr[posInNewArr] = arr[i];
		}
	
	}
	arr = newArr;
}
void printIntVector(const std::vector<int>& arr) {
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

// 5. �������� �������, ������� ���������� �� ������ ���������� ������������� ������, ��� ������ ������� ������ ���� � ������� ���� �����,
// � ������� ����� ����� � ������ ����� ������� �����. �������: checkBalance([1, 1, 1, || 2, 1]) = true, checkBalance ([2, 1, 1, 2, 1]) = false,
// checkBalance ([10, || 1, 2, 3, 4]) = true. ����������� ������� �������� ��������� ||, ��� ������� � ������ �� ������.
bool checkBalance(std::vector<int>& arr) {
	size_t n = arr.size();
	if (n < 2) {
		return false;
	}
	int sum1 = arr[0];
	int sum2 = arr[n-1];
	size_t left = 0;
	size_t right = n-1;
	while (left < right -1) {
		if (sum1 > sum2) 
		{
			sum2 += arr[right - 1];
			right--;
		} else if (sum1 < sum2) 
		{
			sum1 += arr[left + 1];
			left++;
		} else
		{
			std::vector<int> subArr = { arr.begin() + left + 1, arr.begin() + right };
			return checkBalance(subArr);
		}
	}
	if (sum1 == sum2) {
		return true;
	}
	return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");

	{
		double testDoubleArr[] = { 5.6, 9.0, 7.8 , 3.14 };
		printDoubleArray(testDoubleArr, std::size(testDoubleArr));
	}

	{
		int testIntArr[] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
		size_t intArrSize = std::size(testIntArr);
		printIntArray(testIntArr, intArrSize);
		revertElements(testIntArr, intArrSize);
		printIntArray(testIntArr, intArrSize);
	}

	{
		const size_t SIZE = 8;
		int arr[SIZE];
		initArrray(arr, SIZE);
		printIntArray(arr, SIZE);
	}

	{
		std::vector<int> arr = { 5,8,9,1,2 };
		printIntVector(arr);
		moveArrayValues(arr, 102); // {1,2,5,8,9}
		printIntVector(arr);
		moveArrayValues(arr, -12); // {5,8,9,1,2}
		printIntVector(arr);
	}

	{
		std::vector<int> testBalanceArr = { 2, 1, 1, 2, 1 };
		std::cout << checkBalance(testBalanceArr);
	}

}