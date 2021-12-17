#include <iostream>

int main()
{
    // 1. Создать и инициализировать переменные пройденных типов данных(short int, int, long long, char, bool, float, double).
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

    // 2. Создать перечисление (enum) с возможными вариантами символов для игры в крестики-нолики.

    enum class TicTacToeSymbol {
        EMPTY,
        CROSS,
        ZERO
    };

    // 3. Создать массив (поле для игры в крестики нолики), способный содержать значения такого перечисления и инициализировать его.

    TicTacToeSymbol ticTacToeField[3][3]{
        {TicTacToeSymbol::EMPTY, TicTacToeSymbol::EMPTY, TicTacToeSymbol::EMPTY} ,
        {TicTacToeSymbol::EMPTY, TicTacToeSymbol::EMPTY, TicTacToeSymbol::EMPTY},
        {TicTacToeSymbol::EMPTY, TicTacToeSymbol::EMPTY, TicTacToeSymbol::EMPTY}
    };

    // 4. Создать структуру (struct) данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами (подумайте что может понадобиться).

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

    // 5. Создать структуру (struct MyVariant) объединяющую: union MyData (int, float, char) и 3-и битовых поля (флага) указывающими какого типа значение в данный
    // момент содержится в объединении (isInt, isFloat, isChar). Продемонстрировать пример использования в коде этой структуры.
    
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
