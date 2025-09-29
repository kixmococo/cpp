#include <iostream>
#include <limits>
#include <string>
#include <random>
#include <algorithm>

int main() {
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distInt(1,3);
	//int NPC = distInt(rng);
	//std::cout << NPC << std::endl;
	std::cout << "Rock, paper, scissors;\n";
	std::string userInput;
	std::string userPath;
	//int userChoice{0};
	int choiceRock{1};
	int choicePaper{2};
	int choiceScissors{3};
	//int choiceQuit{4};
	//int choiceContinue{5};
	int rounds{0};
	int roundsWin{0};
	int roundsLose{0};
	int roundsTie{0};
	//int rounds{0};

	std::cout << "Would you like to play Rock, Paper, Scissors?\n";
	std::cin >> userPath;

	while (userPath == "Yes") {
		int NPC = distInt(rng);
		std::cout << NPC << std::endl;
		rounds ++;
		std::cout << "Choose; Rock, Paper or Scissors...\n";
		std::cin >> userInput;
		if (userInput == "Rock") {
			std::cout << choiceRock << std::endl;
			std::cout << NPC << std::endl;
			if (NPC == 1) {
				std::cout << "Rock: Tie\n";
				roundsTie ++;
			} else if (NPC == 2) {
				std::cout << "Paper: Lose\n";
				roundsLose ++;
			} else if (NPC == 3) {
				std::cout << "Scissors: Win\n";
				roundsWin ++;
			}
		} else if (userInput == "Paper") {
			std::cout << choicePaper << std::endl;
			std::cout << NPC << std::endl;
			if (NPC == 1) {
				std::cout << "Rock: Win\n";
				roundsWin ++;
			} else if (NPC == 2) {
				std::cout << "Paper: Tie\n";
				roundsTie ++;
			} else if (NPC == 3) {
				std::cout << "Scissors: Lose\n";
				roundsLose ++;
			}
		} else if (userInput == "Scissors") {
			std::cout << choiceScissors << std::endl;
			std::cout << NPC << std::endl;
			if (NPC == 1) {
				std::cout << "Rock: Lose\n";
				roundsLose ++;
			} else if (NPC == 2) {
				std::cout << "Paper: Win\n";
				roundsWin ++;
			} else if (NPC == 3) {
				std::cout << "Scissors: Tie\n";
				roundsTie ++;
			}
		} else {
			std::cout << "Not there yet\n";
		}
		std::cout << "Would you like to play again?\n";
		std::cin >> userPath;
	}
		std::cout << "The game is over\n";
		std::cout << "You played " << rounds << " round(s)"  << std::endl;
		std::cout << "You won " << roundsWin << " round(s)" << std::endl;
		std::cout << "You lost " << roundsLose << " round(s)" << std::endl;
		std::cout << "You tied " << roundsTie << " round(s)" << std::endl;
	return 0;
}
