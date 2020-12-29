#include <iostream>

int main()
{
    setlocale(LC_ALL, "RUS");
    std::cout << "Введите количство метров: ";
    int a = 0;
    std::cin >> a;
    std::cout << a << " метров будет " << (double)a / 1000 << " километров" << std::endl;
    return 0;
}