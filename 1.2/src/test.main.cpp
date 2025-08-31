#include <iostream>
int main() {
	int year{2025};
	std::cout << "What year is it currently?" << std::endl;
	std::cout << "Please input a number: ";
	std::cin >> year;
	std::cout << "What is your age?" << std::endl;
	int age{0};
	std::cout << "Please input a number: ";
	std::cin >> age;
	std::cout << "You were born in the year " << (year - age) << std::endl;
	int wish{0};
	int bYear{year - age};
	std::cout << "How old do you wish to be? ";
	std::cin >> wish;
	std::cout << "You will be " << wish << " in the year " << (bYear + wish) << "." << std::endl;
	return 0;
}
