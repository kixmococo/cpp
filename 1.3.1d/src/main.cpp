#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <limits>
#include <cctype>

std::string toLower(const std::string& s) {
	std::string result = s;
	std::transform(result.begin(), result.end(), result.begin(),
			[](unsigned char c){ return std::tolower(c); });
	return result;
}

int main() {
	int x{0};
	std::cout << x << std::endl;
	std::cout << "Testing case-insensitive behavior\n";
	while(x==0) {
		std::string behavior;
		std::cin >> behavior;
		std::cout << toLower(behavior) << std::endl;
		std::cout << "Again[0] Quit[1]\n";
		std::cin >> x;
	}

	return 0;

}
