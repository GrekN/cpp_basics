#include <iostream>

int main()
{
    // 1. ������� � ���������������� ���������� ���������� ����� ������(short int, int, long long, char, bool, float, double).
    {
        short int grade = 5;
        int x = - 1'000'000;
        unsigned int income = 1'000'000;
        long long capitalization = 1'000'000'000'000;
        char plusSymbol = '+';
        bool isEmpty = true;
        float distance = 5.2f;
        double angle = 17.234;
    } 

    // 2. ������� ������������ (enum) � ���������� ���������� �������� ��� ���� � ��������-������.

    enum class TicTacToeSymbol {
        EMPTY,
        CROSS,
        ZERO
    };

    // 3. ������� ������ (���� ��� ���� � �������� ������), ��������� ��������� �������� ������ ������������ � ���������������� ���.

    TicTacToeSymbol ticTacToeField[3][3]{
        {TicTacToeSymbol::EMPTY, TicTacToeSymbol::EMPTY, TicTacToeSymbol::EMPTY} ,
        {TicTacToeSymbol::EMPTY, TicTacToeSymbol::EMPTY, TicTacToeSymbol::EMPTY},
        {TicTacToeSymbol::EMPTY, TicTacToeSymbol::EMPTY, TicTacToeSymbol::EMPTY}
    };

    // 4. ������� ��������� (struct) ������ ����� ��� ���� � ��������-������ � �������� ��� ����� ������������ ���������� (��������� ��� ����� ������������).

    struct Player {
        int id;
        char name[10];
        char ipAddress[50];
        TicTacToeSymbol symbol;
    };

    struct TicTacToeGame {
        TicTacToeSymbol field[3][3];
        int turnNumber;
        bool isFinished;
        bool isStarted;
        Player players[2];
        int winnerId;
    };

    // 5. ������� ��������� (struct MyVariant) ������������: union MyData (int, float, char) � 3-� ������� ���� (�����) ������������ ������ ���� �������� � ������
    // ������ ���������� � ����������� (isInt, isFloat, isChar). ������������������ ������ ������������� � ���� ���� ���������.
    
    union MyData {
        int i;
        float f;
        char c;
    };

    struct MyVariant
    {
        MyData data;
        int isInt : 1;
        int isFloat : 1;
        int isChar : 1;
    };

    MyVariant test;
    test.data.i = 5;
    test.isInt = 1;
    test.isFloat = 0;
    test.isChar = 0;
}
