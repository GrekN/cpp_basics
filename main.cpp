#include <iostream>
#include <clocale>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

void fillArrayWithPowerOfTwo(int* arr, const size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = std::pow(2,i);
    }
}

void fillMatrixWithRandomNumbers(int** arr, const size_t size) {
    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            arr[i][j] = std::rand() % 100;
        }
    }
}

void printArray(const int* arr, const size_t size) {
    for (size_t i = 0; i < size ; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

void printMatrix(int** arr, const size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // 1. �������� � ������ ������������ ���������� ������ ���� int. ������ ������� ��������� � ������������. ���������������� ��� �������
    // ��������� ������: 1, 2, 4, 8, 16, 32, 64, 128 ... ������� ������ �� �����. �� ������ ���������� ������. =) ������� ��������� �� �������.
    {
        std::cout << "������� ������ �������:\n";
        size_t n;
        std::cin >> n;
        int* pArr = new int[n];

        fillArrayWithPowerOfTwo(pArr, n);

        std::cout << "������ �������� �����:\n";
        printArray(pArr, n);

        delete[] pArr;
    }

    // 2. ����������� �������� ������� 4�4 ���� int. ���������������� �� ���������������� ������� ����� ������� rand. ������� �� �����.
    // �������� ���� ��������� �� ������� ������� ���������� �� main.
    {
        const size_t size = 4;

        int** pMatrix = new int*[size];
        for (size_t i = 0; i < size; i++)
        {
            pMatrix[i] = new int[size];
        }

        fillMatrixWithRandomNumbers(pMatrix, size);
        std::cout << "������� ��������� �����:\n";
        printMatrix(pMatrix, size);

        for (size_t i = 0; i < size; i++)
        {
            delete[] pMatrix[i];
        }
        delete[] pMatrix;
    }

    // 3. �������� ���������, ������� ������� ��� ��������� ����� (*.txt), �������� �� 50-100 �������� � ������
    // (������� �������� �� ����� � ����� ������ ����������). ����� ������ ��������� � �������������.

    {
        std::cout << "������� ��� ����� 1:\n";
        std::string fileName1;
        std::cin >> fileName1;
        std::ofstream fout1(fileName1 + ".txt");
        fout1 << "The class template basic_ofstream implements high-level output operations on file based streams. ";
        fout1.close();

        std::cout << "������� ��� ����� 2:\n";
        std::string fileName2;
        std::cin >> fileName2;
        std::ofstream fout2(fileName2 + ".txt");
        fout2 << "It interfaces a file-based streambuffer (std::basic_filebuf) with the high-level interface of (std::basic_ostream)";
        fout2.close();
    }

    // 4. * �������� �������, ������������� ��� ����� � ������ ��������� ���� (��� ������ �������� � ������������).
    {
        std::cout << "������� �������� ������, ������� ��������� �������:\n";
        std::string fileName1, fileName2;
        std::cin >> fileName1 >> fileName2;

        std::string result = "";
        std::ifstream fin1(fileName1 + ".txt");
        while (!fin1.eof()) {
            std::string buf;
            std::getline(fin1, buf);
            result += buf;
        }

        std::ifstream fin2(fileName2 + ".txt");
        while (!fin2.eof()) {
            std::string buf;
            std::getline(fin2, buf);
            result += buf;
        }

        std::cout << "������� �������� ��������� �����:\n";
        std::string resultFileName;
        std::cin >> resultFileName;
        std::ofstream fout(resultFileName + ".txt", std::ios::app);
        fout << result;
    }

    // 5. * �������� ���������, ������� ��������� ������������ �� ��������� ������������� ��� ������� ��������� ����� � ���������
    //  ������������� ����� (��� �������� �������� ������ � ���������). ���������� ������� find ������� ���� � ������� std::string 
    {
        std::cout << "������� �������� �����:\n";
        std::string fileName;
        std::cin >> fileName;

        std::cout << "������� ������� �����:\n";
        std::string word;
        std::cin >> word;

        std::ifstream fin(fileName + ".txt");
        bool wordFound = false;
        while (!fin.eof()) {
            std::string buf;
            std::getline(fin, buf);
            if (buf.find(word) != std::string::npos) {
                std::cout << buf;
                wordFound = true;
                break;
            }
        }
        if (wordFound)
        {
            std::cout << "����� �������:\n";
        }
        else
        {
            std::cout << "����� �� �������:\n";
        }
    
    }
}
