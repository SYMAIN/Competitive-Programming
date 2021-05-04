/*
Author: Simon Yang
Problem: https://dmoj.ca/problem/ccc99s1
Explanation
-------------------------------------------
In this problem, we are asked to simulate a card game between 2 player, A and B, and calculate thoses score
between thoses player. To solve problem, we can loop through the entire deck of cards and keep track of
which card is the higher level card and count until the amount of card flip is met. For example, if we flip
a "ace", we would have a counter of 4 and decrement until zero. If none other highlevel card were flip, we
would give the points to the player that fliped the "ace". Lastly, we would print out the points gained and
the total amount of points at the end.
*/

//CODE
//-----------------------------------------------
#include <iostream>
#include <string>

void solve(std::string deck[52]) {
	// init variables for keeping track
	int playerA = 0, playerB = 0;
	int currentPlayer = 0;
	int cnt = 0, highLevelPoint = 0, player = 0;

	std::string highLevel[4] = { "jack", "queen", "king", "ace" };

	// loop through the deck
	for (int i = 0; i < 52; i++) {
		std::string card = deck[i];

		// check if the current card is a highlevel
		for (int j = 0; j < 4; j++) {
			if (card == highLevel[j]) {
				cnt = j + 1;
				highLevelPoint = j + 1;
				player = currentPlayer;
				goto changePlayer;
			}
		}

		// decrement counting
		if (cnt > 0) {
			cnt--;
		}
		// counting has reach the end
		if (cnt == 0 && highLevelPoint > 0) {
			if (player == 0) {
				playerA += highLevelPoint;
				std::cout << "Player A scores " << highLevelPoint << " point(s).\n";
			}
			else if (player == 1) {
				playerB += highLevelPoint;
				std::cout << "Player B scores " << highLevelPoint << " point(s).\n";
			}
			highLevelPoint = 0;
		}

	changePlayer:
		if (currentPlayer == 0) {
			currentPlayer = 1;
		}
		else if (currentPlayer == 1) {
			currentPlayer = 0;
		}
	}
	std::cout << "Player A: " << playerA << " point(s).\n";
	std::cout << "Player B: " << playerB << " point(s).\n";
}

int main() {
	// init an array with the size of 52
	std::string deck[52] = {};

	// get inputs
	for (int i = 0; i < 52; i++) {
		std::cin >> deck[i];
	}
	solve(deck);

}