// Poker.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <time.h>
#include <iostream>
using namespace std;

bool apair(int cards[]);
bool twopair(int cards[]);
bool threekind(int cards[]);
bool straight(int cards[]);
bool fullhouse(int cards[]);
bool fourkind(int cards[]);
int highcard(int cards[]);

const int TABLECARDS = 3;
const int YOURCARDS = 2;
const int NUMCARDS = TABLECARDS + YOURCARDS;

bool apair(int cards[]) {
	for (int cardsIndex = 0; cardsIndex < NUMCARDS; cardsIndex++) {
		for (int comparisonIndex = cardsIndex + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {
			if (cards[cardsIndex] == cards[comparisonIndex]) {
				return true;
			}
		}
	}
	return false;
}

bool twopair(int cards[]) {
	
	int matchingCards = 0;
	for (int cardsIndex = 0; cardsIndex < NUMCARDS; cardsIndex++) {
		for (int comparisonIndex = cardsIndex + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {

			if (cards[cardsIndex] == cards[comparisonIndex]) {
				matchingCards++;
				
			}
		}
	}
	if (matchingCards == 2) {
		
		return true;
	}
	else {
		return false;
	}
}

bool threekind(int cards[]) {

	for (int cardsIndex = 0; cardsIndex < NUMCARDS; cardsIndex++) {
		int matchingCards = 0;
		for (int comparisonIndex = cardsIndex + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {

			if (cards[cardsIndex] == cards[comparisonIndex]) {
				matchingCards++;
			}
			if (matchingCards == 2) {
				return true;
			}
		}
	} return false;
}

bool straight(int cards[]) {
	int low = cards[0];

	for (int i = 0; i < NUMCARDS; i++) {
		if (cards[i] < low) {
			low = cards[i];
		}
	}

	for (int i = 1; i <= 4; i++) {
		bool hasStraight = false;
		for (int cardsIndex = 0; cardsIndex < NUMCARDS; cardsIndex++) {
			if (cards[cardsIndex] == (low + i)) {
				hasStraight = true;
			}
		}
		if (!hasStraight) {
			return false;
		}
	}
	return true;
}

bool fullhouse(int cards[]) {

	int threeofkind = 0;

	for (int i = 0; i < NUMCARDS; i++) {
		int matchingCards = 0;

		for (int comparisonIndex = i + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {
			if (cards[i] == cards[comparisonIndex]) {
				matchingCards++;
			}

			if (matchingCards == 2) {
				threeofkind = cards[i];
				break;
			}
		}
	}
	if (threeofkind == 0) {
		return false;
	}
	
	for (int i = 0; i < NUMCARDS; i++) {
		for (int comparisonIndex = i + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {
			if (cards[i] == cards[comparisonIndex] && cards[i] != threeofkind) {
				return true;
			}
		}
	}
	return false;
}

bool fourkind(int cards[]) {
	for (int cardsIndex = 0; cardsIndex < NUMCARDS; cardsIndex++) {
		int matchingCards = 0;
		for (int comparisonIndex = cardsIndex + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {

			if (cards[cardsIndex] == cards[comparisonIndex]) {
				matchingCards++;
			}
			if (matchingCards == 3) {
				return true;
			}
		}
	} return false;
}

bool fivekind(int cards[]) {
	for (int cardsIndex = 0; cardsIndex < NUMCARDS; cardsIndex++) {
		int matchingCards = 0;
		for (int comparisonIndex = cardsIndex + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {

			if (cards[cardsIndex] == cards[comparisonIndex]) {
				matchingCards++;
			}
			if (matchingCards == 4) {
				return true;
			}
		}
	} return false;
}

int highcard(int cards[]) {
	int highCard = cards[0];

	for (int i = 0; i < NUMCARDS; i++) {
		if (cards[i] > highCard){
			highCard = cards[i];
		}
	}

	return highCard;
}


int main()
{
	int cards[NUMCARDS];
	srand(time(NULL));
	int card;
	int money = 1000;
	int bet;

	cout << "Current money: " << money << endl;
	cout << "Your cards are: ";
	for (int i = 0; i < YOURCARDS; i++) {
		card = rand() % 9 + 1;
		cards[i] = card;
		cout << cards[i] << " ";
	}
	cout << endl;

	cout << "Table cards are: ";
	for (int i = 2; i < NUMCARDS; i++) {
		card = rand() % 9 + 1;
		cards[i] = card;
		cout << cards[i] << " ";
	}
	cout << endl;

	
	if (fivekind(cards)) {
		cout << "Five of a kind" << endl;
	}
	else if (fourkind(cards)) {
		cout << "Four of a kind" << endl;
	}
	else if (fullhouse(cards)) {
		cout << "Full house" << endl;
	}
	else if (straight(cards)) {
		cout << "Straight" << endl;
	}
	else if (threekind(cards)) {
		cout << "Three of a kind" << endl;
	}
	else if (twopair(cards)) {
		cout << "Two Pair of Cards" << endl;
	}
	else if (apair(cards)) {
		cout << "Pair of Cards" << endl;
	}
	else {
		cout << "Your Highest Card is: " << highcard(cards) << endl;
	}
	cout << "Make your bet: ";
	cin >> bet;
    
	return 0;
}

