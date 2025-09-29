#include <iostream>
#include <random>
#include <cctype>

struct PlayerInfo {
	int iniBank     = 100;
	int pBank       = 0;

	int betEx       = 0;
	int betClose    = 0;
	int betEven     = 0;
	int betAmount   = 0;

	int grossNet    = 0;

	int roundNum    = 0;

	int betWins     = 0;
	int betLosses   = 0;
};

bool wantToPlayAgain() {

	int choice;
	while (true) {
		std::cout << "Would you like to play again?\n";
		std::cout << "[1]Yes [2]No";
		std::cin >> choice;

		if (choice != 1 && choice != 2) {
			std::cout << "Unexpected input...\n";
		}
		else {
			return choice == 1;
		}
	}
}

void highOrLowGame(PlayerInfo playerInfo) {
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distInt(1,10);

	while (true) {
		int luckyNum = distInt(rng);

		int wager = 0;
		std::cout << "Place your bets...\n";
		std::cin >> wager;
		std::cout << "You are betting " << wager << "\n";

		int betHL = 0;
		std::cout << "[1]High [2]Low\n";
		std::cin >> betHL;

		if (betHL != 1 && betHL != 2) {
			std::cout << "Unexpected input...\n";
			break;
		}

		std::cout << "The number was " << luckyNum << ".\n";

		if ((betHL == 1 && luckyNum > 5) || (betHL == 2 && luckyNum <= 5)) {
			std::cout << "Congratulations. You won!\n";
			playerInfo.betWins++;
			playerInfo.pBank += wager * 2;
			std::cout << "You won $" << (wager * 2) << ".\n";
		}
		else {
			std::cout << "Sorry. You lost.\n";
			playerInfo.betLosses++;
			playerInfo.pBank -= wager;
			std::cout << "You lost $" << wager << ".\n";
		}

		if (!wantToPlayAgain()) {
			return;
		}
	}
}

void rouletteMenu(PlayerInfo playerInfo) {

	int choice;
	while (true) {
		std::cout << "Roulette Menu...\n";
		std::cout << "[1]High/Low\n[2]Exact\n[3]Close\n[4]Odds or Evens\n[5]Rules\n[6]Main Menu\n";
		std::cin >> choice;

		if (choice == 6) {
			std::cout << "Backing to Main Menu...\n";
			return;
		}
		else if (choice == 1) {
			std::cout << "Entering High or Low game...\n";
			highOrLowGame(playerInfo);
		}
		else {
			std::cout << "Unexpected input...\n";
		}
	}
}

void statsMenu(int iniBank, int pBank, int grossNet, int roundNum, int betWins, int betLosses) {
	std::cout << "\nStats Menu...\n";
	std::cout << "You have $" << pBank << " in your bank. You started at $" << iniBank << ". You have netted $" << grossNet << ". You have played a total of " << roundNum << " rounds. Of those, you have won " << betWins << " and have lost " << betLosses << ".\n";
}

void mainMenu(PlayerInfo playerInfo) {

	int choice;
	while (true) {
		std::cout << "\nMain Menu...\n";
		std::cout << "[1]Play Roulette\n[2]Check Stats\n[3]Quit\n";
		std::cin >> choice;

		if (choice == 3) {
			std::cout << "Exiting Game...\nThank you for playing. Goodbye.\n";
			return;
		}
		else if (choice == 2) {
			statsMenu(playerInfo.iniBank, playerInfo.pBank, playerInfo.grossNet, playerInfo.roundNum, playerInfo.betWins, playerInfo.betLosses);
		}
		else if (choice == 1) {
			std::cout << "Entering Roulette Menu... What would you like to play?\n";
			rouletteMenu(playerInfo);
		}
		else {
			std::cout << "Unexpected input...\n";
		}
	}
}

int main() {
	PlayerInfo playerInfo;

	std::cout << "How much money are you bringing to the Casino?\n";
	std::cin >> playerInfo.iniBank;

	std::cout << "\nWelcome to the Casino... What would you like to do?\n";

	mainMenu(playerInfo);
	return 0;
}
