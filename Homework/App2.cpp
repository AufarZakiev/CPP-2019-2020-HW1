#include <iostream>

int main()
{
    setlocale(LC_ALL, "RUS");
    std::cout << "������� ����������� �����: ";
    int a = 0;
    std::cin >> a;
    int count = 10000;
    for (int i = 0; i < 5; i++)
    {
        int digit = a / count;
        a -= count * digit;
        if (a < 0)
            a = abs(a);
        std::cout << digit << std::endl;
        count /= 10;
    }
    return 0;
}