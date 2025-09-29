#include <iostream>
#include <limits>
#include <string>
#include <algorithm>

int main() {
	int age{0};
	std::cout << "What is your age?\n";
	std::cin >> age;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
	if (age >= 18) {
		std::cout << "You are an adult\n";
	} else {
		std::cout << "You are a kid\n";
	}
	int newNum{0};
	std::cout << "What would you like your number to be?\n";
	std::cin >> newNum;
	if (newNum == 0) {
		std::cout << "Your number is 0\n";
	} else if (newNum % 2 == 1) {
		std::cout << "Odd\n";
	} else if (newNum % 2 == 0) {
		std::cout << "Even\n";
	}
	std::string newInput;
	std::cout << "Enter yes or no\n";
	std::cin >> newInput;
	std::transform(newInput.begin(), newInput.end(), newInput.begin(),
			[](unsigned char c){ return std::tolower(c); });
	if (newInput == "yes") {
		std::cout << "yes\n";
	} else if (newInput == "no") {
		std::cout << "no\n";
	} else {
		std::cout << "unrecognized input\n";
	}
	int testScore{0};
	std::cout << "What score did you get on your test?\n";
	std::cin >> testScore;
	if (testScore <= 40) {
		std::cout << "You are retarded\n";
	} else if (testScore <= 59) {
		std::cout << "You failed\n";
	} else if (testScore <= 69) {
		std::cout << "You scored a D\n";
	} else if (testScore <= 79) {
		std::cout << "You scored a C\n";
	} else if (testScore <= 89) {
		std::cout << "You scored a B\n";
	} else if (testScore <= 99) {
		std::cout << "You scored an A\n";
	} else if (testScore >= 100) {
		std::cout << "You scored an A+. Good job\n";
	}

	return 0;
}
