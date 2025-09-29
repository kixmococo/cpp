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
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distInt(1,10);

int main() {
	std::cout << "roulette test demo\n";
	int luckyNum = distInt(rng);
	int betHL{0};
	int betEx{0};
	int betClose{0};
	int betEven{0};
	int betAmount{0};
	int iniBank{100};
	int grossNet{0};
	int pBank{0};
	int roundNum{0};
	int choiceMenu0{0};
	int choiceMenu1{0};
	int choiceMenu2{0};
	int betWins{0};
	int betLosses{0};
	int wager{0};
	std::cout << "debug " << luckyNum << betHL << betEx << betClose << betEven << betAmount << iniBank << grossNet << pBank << roundNum << choiceMenu0 << choiceMenu1 << choiceMenu2 << betWins << betLosses << wager << std::endl << std::endl;
	std::cout << "How much money are you bringing to the Casino?" << std::endl;
	std::cin >> pBank;
	iniBank = pBank;
	std::cout << std::endl << "Welcome to the Casino... What would you like to do?" << std::endl;
	while(choiceMenu0 == 0) {
		std::cout << std::endl << "Main Menu..." << std::endl;
		std::cout << "[1]Play Roulette" << std::endl << "[2]Check Stats" << std::endl << "[3]Quit" << std::endl;
		std::cin >> choiceMenu0;
		if (choiceMenu0 == 2) {
			std::cout << std::endl << "Stats Menu..." << std::endl;
			std::cout << "You have $" << pBank << " in your bank. You started at $" << iniBank << ". You have netted $" << grossNet << ". You have played a total of " << roundNum << " rounds. Of those, you have won " << betWins << " and have lost " << betLosses << "." << std::endl;
			choiceMenu0 = 0;
		} else if (choiceMenu0 == 3) {
			std::cout << std::endl << "Exiting Game..." << std::endl << "Thank you for playing. Goodbye." << std::endl;
			break;
		} else if (choiceMenu0 == 1) {
			std::cout << std::endl << "Entering Roulette Menu... What would you like to play?" << std::endl;
			while (choiceMenu1 == 0) {
				std::cout << std::endl << "Roulette Menu..." << std::endl;
				std::cout << "[1]High/Low" << std::endl << "[2]Exact" << std::endl << "[3]Close" << std::endl << "[4]Odds or Evens" << std::endl << "[5]Rules" << std::endl << "[6]Main Menu" << std::endl;
				std::cin >> choiceMenu1;
			} else if (choiceMenu1 == 1) {
					std::cout << std::endl << "Entering High or Low game..." << std::endl;
					int luckyNum = distInt(rng);
					std::cout << "Place your bets..." << std::endl;
					std::cin >> wager;
					std::cout << "You are betting " << wager << std::endl;
					std::cout << "[1]High [2]Low" << std::endl;
					while (betHL == 0) {
						std::cin >> betHL;
						std::cout << "The number was " << luckyNum << "." << std::endl;
						if (betHL == 1) {
							if (luckyNum >= 6 && luckyNum <= 10) {
								std::cout << "Congratulations. You won!" << std::endl;
								betWins ++;
								pBank = (wager * 2) + pBank;
								std::cout << "You won $" << (wager * 2) << "." << std::endl;
							} else if (luckyNum >= 1 && luckyNum <= 5) {
								std::cout << "Sorry. You lost." << std::endl;
								betLosses ++;
								pBank = (pBank - wager);
								std::cout << "You lost $" << wager << "." << std::endl;
							}
						} else if (betHL == 2) {
							if (luckyNum >= 6 && luckyNum <=10) {
								std::cout << "Sorry. You lost." << std::endl;
								betLosses ++;
								pBank = (pBank - wager);
								std::cout << "You lost $" << wager << "." << std::endl;
							} else if (luckyNum >=1 && luckyNum <= 5) {
								std::cout << "Congratulations. You won!" << std::endl;
								betWins ++;
								pBank = (wager * 2) + pBank;
								std::cout << "You won $" << (wager * 2) << "." << std::endl;
							} else {
								std::cout << "Unexpected input..." << std::endl;
								betHL = 0;
							}
						}
					std::cout << std::endl << "Would you like to play again?" << std::endl;
                    std::cout << "[1]Yes [2]No";
					while (choiceMenu2 == 0) {
                        std::cin >> choiceMenu2;
                        if (choiceMenu2 == 1) {
                            choiceMenu1 = 1;
                        } else if (choiceMenu2 == 2) {
                            choiceMenu1 = 0;
                            break;
                        } else {
                            std::cout << "Unexpected input..." << std::endl;
                            choiceMenu2 = 0;
					    }
					}
					choiceMenu1 = 0;
                    break;
			} else if (choiceMenu1 == 6) {
				std::cout << std::endl << "Backing to Main Menu..." << std::endl;
				choiceMenu1 = 0;
				choiceMenu0 = 0;
				break;
			} else {
					std::cout << std::endl << "Unexpected input..." << std::endl;
					choiceMenu1 = 0;
				}
			}
		} else {
		std::cout << std::endl << "Unexpected input..." << std::endl;
		choiceMenu0 = 0;
		}
	}
	return 0;

}
