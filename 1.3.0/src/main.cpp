#include <iostream>
#include <cmath>
#include <random>

int main() {
	std::cout << "Do you want to play the number game?\n";
	std::cin.get();
	std::cout << "Guess a number between 1-100!\n";
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(1, 100);
	int x = distr(gen);
	
	int guess{0};
	std::cout << "Guess ... ";
	while (guess != x) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cin >> guess;
		if (guess > x) {
			std::cout << "lower\n";
		} else if (guess < x) {
			std::cout << "higher\n";
		}
	}
	
	std::cout << "You did it!!\n";

	//for (int i = 0; i < 5; i++) {
	//	std::cout << << i;
	//}
	

	std::cout << "The random number was: " << x << std::endl;

	return 0;
}
