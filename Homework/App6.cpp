#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "������� �����: ";
    char ch = 0;
	while (ch != '\n') {
		std::cin.get(ch);
		std::cout << ch << std::endl;
	}
}