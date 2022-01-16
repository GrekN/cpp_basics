#include <iostream>
#include <fstream>
#include <clocale>
#include "mylib.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    // 1. Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: 
    // для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов. 
    // Вызывайте эти 3-и функции из main для работы с массивом.
    // 5.* Сделайте задание 1 добавив свой неймспейс во втором модуле (первое задание тогда можно не делать).
    {
        const size_t size = 10;
        float arr[size];
        mylib::initArray(arr, size);
        mylib::printFloatArray(arr, size);
        mylib::countPositiveAndNegativeNumbers(arr, size);
    }

    // 2. Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры)
    // в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и возвращает true или false,
    // вывести на экран «true» или «false».
    {
        #define IS_POSITIVE_AND_LOWER_THAN(x,y) (x >= 0 && x < y) ? true : false; 
       
        std::cout << "Введите число:\n";
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

    // 3. Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. Инициализируйте его через ввод с клавиатуры.
    // Напишите для него свою функцию сортировки (например Пузырьком). Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). 
    // Вызывайте ее из цикла сортировки.
    {
        #define ARRSIZE 5
        int arr[ARRSIZE];
        for (size_t i = 0; i < ARRSIZE; i++)
        {
            std::cout << "Введите " << i << " элемент массива\n";
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

    //  4. * Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack.
    // Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof. Сохраните эту
    // структуру в текстовый файл.

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
