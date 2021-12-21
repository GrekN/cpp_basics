#include <iostream>

int main()
{
    //  1. �������� ���������, ����������� ��������� a* (b + (c / d)) � ��������� ��������� � ��������� ������, ��� a, b, c, d � ������������� ���������.
    //  ����������� static_cast ��� � - Style cast � float ����� ��������� ������ �������.
    //  4. �������� ���������, ����������� ��������� �� ������� �������, � ���������� ��� �� ��������� � ���������������� � ������ cpp �����. ����������� extern.
    {
        extern const int a, b, c ,d;
        std::cout << "a * (b + (c / d)): " << a * (b + (static_cast<float>(c) / d)) << "\n";
    } 
    //   2. ���� ����� �����.���� ��� ������ ��� ����� 21, �� �������� �� ����� ������� ����� ���� ������ � ������ 21. ���� �� �������� ����� ������, ��� 21,
    //���������� ������� ��������� ������� ����� ���� ������ � 21. ��� ���������� ������� ������� ������������ ��������� ��������(? : ).
    {
        std::cout << "Enter an integer:\n";
        int n = 0;
        std::cin >> n;
        int answer = (n > 21) ? 2 * (n - 21) : (21 - n);
        std::cout << answer << '\n';
    }
    // 3. ������� ��������� ������������� ������, �������� 3�3�3 � ��������� �� �������� ������ ������� � ��� ������ �������� ������������� ������� �� �����
    // �������� ����������� ������ ������������� ���� [1][1][1].
    {
        int arr[3][3][3]{
            0, 0, 0 ,
            0, 0, 0 ,
            0, 0, 0 ,
            0, 0, 0 ,
            0, 8, 0 ,
            0, 0, 0 ,
            0, 0, 0 ,
            0, 0, 0 ,
            0, 0, 0 ,
        };
        int* ptr = &arr[0][0][0];
        std::cout << *(ptr+13) << " \n";

    }
}