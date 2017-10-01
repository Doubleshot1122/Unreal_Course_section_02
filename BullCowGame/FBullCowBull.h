#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value
	bool CheckGuessValidity(std::string); //TODO make a more rich return value
	// provide a method for counting bulls and cows and incrementing turn number

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};
