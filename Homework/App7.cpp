#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(unsigned(time(0)));
    setlocale(LC_ALL, "RUS");
    std::cout << "�������� ����� �� 1 �� 15: ";
    int a = rand() % 15 + 1;
    int b = 0;
    std::cin >> b;
    while (true)
    {
        if (b == a)
        {
            std::cout << "�����������, �� ������� �����!";
            return 0;
        }
        else if (b > a)
        {
            std::cout << "���������� ����� ������, ��� " << b << std::endl;
            std::cin >> b;
        }
        else
        {
            std::cout << "���������� ����� ������, ��� " << b << std::endl;
            std::cin >> b;
        }
    }
}