#include <iostream>

int main()
{
    setlocale(LC_ALL, "RUS");
    std::cout << "������� ��������� ������: ";
    int a = 0;
    std::cin >> a;
    std::cout << a << " ������ ����� " << (double)a / 1000 << " ����������" << std::endl;
    return 0;
}