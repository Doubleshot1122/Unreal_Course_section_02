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
FText GetValidGuess();
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
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of\n";
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
		FText Guess = GetValidGuess();
		
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::OK:
			break;
		case EGuessStatus::Not_Isogram:
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			break;
		default:
			break;
		}
		
		// submit valid guess to game and recive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}

	// TODO add a game summary
}

// loop until player gets a valid guess
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Enter your guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter only non letter repeating letters (ie...isograms).\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all characters as lower case characters.\n";
			break;
		default:
			return Guess;
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);  // keep looping until you get no errors
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}