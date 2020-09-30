#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(unsigned(time(0)));
    setlocale(LC_ALL, "RUS");
    std::cout << "Угадайте число от 1 до 15: ";
    int a = rand() % 15 + 1;
    int b = 0;
    std::cin >> b;
    while (true)
    {
        if (b == a)
        {
            std::cout << "Поздравляем, Вы угадали число!";
            return 0;
        }
        else if (b > a)
        {
            std::cout << "Загаданное число меньше, чем " << b << std::endl;
            std::cin >> b;
        }
        else
        {
            std::cout << "Загаданное число больше, чем " << b << std::endl;
            std::cin >> b;
        }
    }
}