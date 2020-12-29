#include <iostream>

int main()
{
    setlocale(LC_ALL, "RUS");
    std::cout << "Введите 1 число: ";
    int a = 0;
    std::cin >> a;
    std::cout << "Введите 2 число: ";
    int b = 0;
    std::cin >> b;
    std::cout << "Введите 3 число: ";
    int c = 0;
    std::cin >> c;
    if (!(a == b || a == c || b == c))
    {
        std::cout << "Все три числа разные";
        return 1;
    }
    std::cout << "1 число = " << a + 5 << std::endl;
    std::cout << "2 число = " << b + 5 << std::endl;
    std::cout << "3 число = " << c + 5 << std::endl;
    return 0;
}