#include <iostream>
#include <random>
#include <cmath>

int main() {
	int x{1};
	int y{1};
	std::cout << x;
	std::cout << y;
	std::cout << std::endl;
	std::cout << "Enter for x ... ";
	std::cin >> x;
	std::cout << "Enter for y ... ";
	std::cin >> y;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(x, y);
	int z = distr(gen);
	int guess{0};
	int attempts{0};
	
	while (guess != z) {
		attempts ++;
		std::cin >> guess;
		if (guess > z) {
			std::cout << "lower\n";
		} else if (guess < z) {
			std::cout << "higher\n";
		}
	}
	std::cout << "Good Job!" << std::endl;
	std::cout << "It took you " << attempts << " attempts" << std::endl;
	std::cout << "The number was: " << z << std::endl;
	return 0;
}
