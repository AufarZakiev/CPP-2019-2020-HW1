#include <iostream>

int main()
{
    setlocale(LC_ALL, "RUS");
    std::cout << "������� 1 �����: ";
    int a = 0;
    std::cin >> a;
    std::cout << "������� 2 �����: ";
    int b = 0;
    std::cin >> b;
    std::cout << "������� 3 �����: ";
    int c = 0;
    std::cin >> c;
    if (!(a == b || a == c || b == c))
    {
        std::cout << "��� ��� ����� ������";
        return 1;
    }
    std::cout << "1 ����� = " << a + 5 << std::endl;
    std::cout << "2 ����� = " << b + 5 << std::endl;
    std::cout << "3 ����� = " << c + 5 << std::endl;
    return 0;
}