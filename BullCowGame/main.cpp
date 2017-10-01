/* This is the console executable that makes use of the BullCowClass
This acts as the view in a MVC pattern, and is resposible for all
user interaction.  For game logic see the FBullCowGame

*/

#include <iostream>
#include <string>
#include "FBullCowBull.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
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
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();  

	// loop for number of turns asking for guesses
	// TODO change from FOR to WHILE once we are validating tries
	for (int32 count = 0; count < MaxTries; count++)
	{
		FText Guess = GetGuess();  // TODO make loop check for valid answers
		// submit valid guess to game
		// print number of bulls and cows
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO add a game summary
}

FText GetGuess() 
{
	
	int32 CurrentTry = BCGame.GetCurrentTry();

	// get a guess from the player
	std::cout << "Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}