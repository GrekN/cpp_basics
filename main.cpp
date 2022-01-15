#include <iostream>
#include <fstream>
#include <clocale>
#include "mylib.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    // 1. �������� ������ �� 2� cpp ������ � ������������� (main.cpp, mylib.cpp, mylib.h) �� ������ ������ mylib �������� 3 �������: 
    // ��� ������������� ������� (���� float), ������ ��� �� ����� � �������� ���������� ������������� � ������������� ���������. 
    // ��������� ��� 3-� ������� �� main ��� ������ � ��������.
    // 5.* �������� ������� 1 ������� ���� ��������� �� ������ ������ (������ ������� ����� ����� �� ������).
    {
        const size_t size = 10;
        float arr[size];
        mylib::initArray(arr, size);
        mylib::printFloatArray(arr, size);
        mylib::countPositiveAndNegativeNumbers(arr, size);
    }

    // 2. ������� ������������ (����� ��������� define), �����������, ������ �� ���������� �� ����� (��������� � ����������)
    // � �������� �� ���� (������������) �� ����������� �� ������� ��������� (�������������) � ���������� true ��� false,
    // ������� �� ����� �true� ��� �false�.
    {
        #define IS_POSITIVE_AND_LOWER_THAN(x,y) (x >= 0 && x < y) ? true : false; 
       
        std::cout << "������� �����:\n";
        int n;
        std::cin >> n;
        bool isTruthy = IS_POSITIVE_AND_LOWER_THAN(n, 10);

        if (isTruthy) {
            std::cout << "true";
        } else {
            std::cout << "false";
        }
        std::cout << '\n';
    }

    // 3. ������� ������ ���� int. ����� ��� ������ �������� ����� ��������� ������������� #define. ��������������� ��� ����� ���� � ����������.
    // �������� ��� ���� ���� ������� ���������� (�������� ���������). ���������� ������������ ��������� ��� ������������ SwapINT(a, b). 
    // ��������� �� �� ����� ����������.
    {
        #define ARRSIZE 5
        int arr[ARRSIZE];
        for (size_t i = 0; i < ARRSIZE; i++)
        {
            std::cout << "������� " << i << " ������� �������\n";
            std::cin >> arr[i];
        }

        #define SwapINT(a,b) int temp = a; a = b; b = temp;
        bool isSorted = true;
        for (size_t i = 0; i < ARRSIZE - 1; i++)
        {
            for (size_t j = 0; j < ARRSIZE - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1]) {
                    isSorted = false;
                    SwapINT(arr[j], arr[j + 1]);
                }
            }
            if (isSorted) {
                break;
            }
        }
        mylib::printIntArray(arr, ARRSIZE);
    }

    //  4. * �������� ��������� ��������� � ���������� ������. �������� ��� ��� ���������� ������������ � ������� ��������� pragma pack.
    // �������� ����������� ���������� ����� ����. ��������������� ��. �������� �� �� ����� � �� ������ � ������� sizeof. ��������� ���
    // ��������� � ��������� ����.

    {
        #pragma pack(push,1)
        struct Employee {
            char fullName[50];
            char department[50];
            bool isManager;
            unsigned int age;
            unsigned int grade;
        };
        #pragma pack(pop)

        Employee* CTO = new Employee({"Ivanov Ivan Ivanovich", "Executives", true, 50, 10});
        std::cout << "Full name: " << CTO->fullName << '\n';
        std::cout << "Department: " << CTO->department << '\n';
        std::cout << "Age: " << CTO->age << '\n';
        std::cout << "Grade: " << CTO->grade << '\n';
        std::cout << "Size of structure: " << sizeof(*CTO) << '\n';
    
        std::ofstream fout("result.txt");
        if (fout.is_open()) {
            fout << "Full name: " << CTO->fullName << '\n';
            fout << "Department: " << CTO->department << '\n';
            fout << "Age: " << CTO->age << '\n';
            fout << "Grade: " << CTO->grade << '\n';
            fout.close();
        }
    }
}
