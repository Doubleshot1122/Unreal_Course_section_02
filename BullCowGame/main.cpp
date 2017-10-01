#include <iostream>
#include <string>
#include "FBullCowBull.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame;

//the entry point to application
int main() {
	
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (AskToPlayAgain());
	
	return 0;
}

// introduce the game
void PrintIntro() 
{	
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();  

	// loop for number of turns asking for guesses
	// TODO change from FOR to WHILE once we are validating tries
	for (int count = 0; count < MaxTries; count++)
	{
		std::string Guess = GetGuess();  // TODO make loop check for valid answers
		// submit valid guess to game
		// print number of bulls and cows
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO add a game summary
}

std::string GetGuess() 
{
	
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << CurrentTry << std::endl;

	// get a guess from the player
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}