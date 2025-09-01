//TEST
//if/else/else if
#include <iostream>

int main() {
	int x{0};
	std::cout << "Enter your number\n";
	std::cin >> x;
	std::cout << "Your number is " << x << ".\n";
	if (x > 0) {
		std::cout << "Positive\n";
	} else if (x == 0) {
		std::cout << "Zero\n";
	} else {
		std::cout << "Negative\n";
	}
	int y{x};
	while (x > 0) {
		std::cout << x << " . ";
		x--;
	}
	std::cout << "\n";
	
	for (int i{5}; i > 0; i--) {
		std::cout << (i << " ";
		std::cout << y << " ";
	}
	std::cout << "\n";
	return 0;
}
