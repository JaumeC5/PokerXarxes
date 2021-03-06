// Poker.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <time.h>
#include <iostream>
#include <tuple>

using namespace std;

/*
bool apair(int cards[]);
bool twopair(int cards[]);
bool threekind(int cards[]);
bool straight(int cards[]);
bool fullhouse(int cards[]);
bool fourkind(int cards[]);
*/
int highcard(int cards[]);


const int TABLECARDS = 3;
const int YOURCARDS = 2;
const int NUMCARDS = TABLECARDS + YOURCARDS;

std::tuple<bool, int> apair(int cards[]) {
	int numPair = -1;
	for (int cardsIndex = 0; cardsIndex < NUMCARDS; cardsIndex++) {
		for (int comparisonIndex = cardsIndex + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {
			if (cards[cardsIndex] == cards[comparisonIndex]) {
				numPair = cards[cardsIndex];
				return std::make_tuple(true, numPair);
			}
		}
	}
	return std::make_tuple(false, 0);
}

std::tuple<bool, int, int> twopair(int cards[]) {
	int numPair[2] = { -1, -1 };
	int matchingCards = 0;

	for (int cardsIndex = 0; cardsIndex < NUMCARDS; cardsIndex++) {
		for (int comparisonIndex = cardsIndex + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {

			if (cards[cardsIndex] == cards[comparisonIndex]) {
				matchingCards++;
				if (matchingCards == 1) { numPair[0] = cards[cardsIndex]; }
				if (matchingCards == 2) { numPair[1] = cards[cardsIndex]; }
			}
		}
	}
	if (matchingCards == 2) {
		return std::make_tuple(true, numPair[0], numPair[1]);
	}
	else {
		return std::make_tuple(false, 0, 0);
	}
}

std::tuple<bool, int> threekind(int cards[]) {
	int numTrio = -1;

	for (int cardsIndex = 0; cardsIndex < NUMCARDS; cardsIndex++) {
		int matchingCards = 0;
		for (int comparisonIndex = cardsIndex + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {

			if (cards[cardsIndex] == cards[comparisonIndex]) {
				numTrio = cards[cardsIndex];
				matchingCards++;
			}
			if (matchingCards == 2) {
				
				return std::make_tuple(true, numTrio);
			}
		}
	} return std::make_tuple(false, 0);
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

std::tuple<bool, int, int> fullhouse(int cards[]) {
	int numC[2] = { -1, -1 };

	int threeofkind = 0;

	for (int i = 0; i < NUMCARDS; i++) {
		int matchingCards = 0;

		for (int comparisonIndex = i + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {
			if (cards[i] == cards[comparisonIndex]) {
				matchingCards++;
				numC[0] = cards[i];
			}

			if (matchingCards == 2) {
				threeofkind = cards[i];
				break;
			}
		}
	}
	if (threeofkind == 0) {
		return std::make_tuple(false, 0, 0);
	}
	
	for (int i = 0; i < NUMCARDS; i++) {
		for (int comparisonIndex = i + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {
			if (cards[i] == cards[comparisonIndex] && cards[i] != threeofkind) {
				numC[1] = cards[i];
				return std::make_tuple(true, numC[0], numC[1]);
			}
		}
	}
	return std::make_tuple(false, 0, 0);
}

std::tuple<bool, int> fourkind(int cards[]) {
	int numPoker = -1;

	for (int cardsIndex = 0; cardsIndex < NUMCARDS; cardsIndex++) {
		int matchingCards = 0;
		for (int comparisonIndex = cardsIndex + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {

			if (cards[cardsIndex] == cards[comparisonIndex]) {
				numPoker = cards[cardsIndex];
				matchingCards++;
			}
			if (matchingCards == 3) {
				return std::make_tuple(true, numPoker);
			}
		}
	} return std::make_tuple(false, 0);
}

std::tuple<bool, int> fivekind(int cards[]) {
	int numRepoker = -1;

	for (int cardsIndex = 0; cardsIndex < NUMCARDS; cardsIndex++) {
		int matchingCards = 0;
		for (int comparisonIndex = cardsIndex + 1; comparisonIndex < NUMCARDS; comparisonIndex++) {

			if (cards[cardsIndex] == cards[comparisonIndex]) {
				matchingCards++;
			}
			if (matchingCards == 4) {
				return std::make_tuple(true, numRepoker);
			}
		}
	} return std::make_tuple(false, 0);
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
	int handRank;

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

	bool apairIsTrue, twopairIsTrue, threekindIsTrue, fullhouseIsTrue, fourkindIsTrue, fivekindIsTrue;
	int aPairCardNum1, twoPairCardNum1, twoPairCardNum2, threekindCardNum1, fullhouseCardNum1, fullhouseCardNum2, fourkindCardNum1, fivekindCardNum1;
	int cardNum2;

	std::tie(fivekindIsTrue, fivekindCardNum1) = fivekind(cards);
	std::tie(fourkindIsTrue, fourkindCardNum1) = fourkind(cards);
	std::tie(fullhouseIsTrue, fullhouseCardNum1, fullhouseCardNum2) = fullhouse(cards);
	std::tie(threekindIsTrue, threekindCardNum1) = threekind(cards);
	std::tie(twopairIsTrue, twoPairCardNum1, twoPairCardNum2) = twopair(cards);
	std::tie(apairIsTrue, aPairCardNum1) = apair(cards);

	

	if (fivekindIsTrue) {
		cout << "Five of a kind" << endl;
		cout << "The card number of the repoker is " << fivekindCardNum1 << endl;
		handRank = 7;
	}
	else if (fourkindIsTrue) {
		cout << "Four of a kind" << endl;
		cout << "The card number of the poker is " << fourkindCardNum1 << endl;
		handRank = 6;
	}
	else if (fullhouseIsTrue) {
		cout << "Full house" << endl;
		cout << "The card numbers of the fullhouse are " << fullhouseCardNum1 << " and " << fullhouseCardNum2 << endl;
		handRank = 5;
	}
	else if (straight(cards)) {
		cout << "Straight" << endl;
		handRank = 4;
	}
	else if (threekindIsTrue) {
		cout << "Three of a kind" << endl;
		cout << "The card number of the trio is " << threekindCardNum1 << endl;
		handRank = 3;
	}
	else if (twopairIsTrue) {
		cout << "Two Pair of Cards" << endl;
		cout << "The cards numbers of the pairs are " << twoPairCardNum1 << " and " << twoPairCardNum2 << endl;
		handRank = 2;
	}
	else if (apairIsTrue) {
		cout << "Pair of Cards" << endl;
		cout << "The card number of the pair is " << aPairCardNum1 << endl;
		handRank = 1;
	}
	else {
		cout << "Your Highest Card is: " << highcard(cards) << endl;
		handRank = 0;
	}

	cout << "Make your bet: ";
	cin >> bet;
    
	return 0;
}

