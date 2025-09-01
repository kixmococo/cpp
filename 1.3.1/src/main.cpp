#include <iostream>
#include <random>
#include <cmath>

int main() {
	int x{1};
	int y{1};
	std::cout << x;
	std::cout << y;
	std::cin >> x;
	std::cin >> y;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),\'\n');
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(x, y);
	//
	return 0;
}
