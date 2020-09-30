#include <iostream>

int main()
{
    setlocale(LC_ALL, "RUS");
    std::cout << "¬ведите число: ";
    long long a = 0;
    std::cin >> a;
    long long tmp = a;
    long long count = 1;
    int length = 1;
    while (abs(tmp) > 9)
    {
        tmp /= 10;
        count *= 10;
        length++;
    }
    for (int i = 0; i < length; i++)
    {
        long long digit = a / count;
        a -= count * digit;
        if (a < 0)
            a = abs(a);
        std::cout << digit << std::endl;
        count /= 10;
    }
    return 0;
}