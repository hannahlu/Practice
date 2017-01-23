/* This is the console executable, that makes use of the BullCow class.
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/
#include <iostream>
#include <string>
#include "main.h"
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //Instantiate a new game

//Entry point for application
int main()
{
	PrintIntro();

	do
	{
		PlayGame();

	} while (AskToPlayAgain() == true);

	return 0;
}


void PrintIntro()
{
	// Introduce the game
	constexpr int32 NumLetters{ 5 };
	std::cout << "Welcome to Bulls and Cows.\n";
	std::cout << "Can you guess the " << NumLetters << " letter isogram I'm thinking of?\n";
	return;
}

void PlayGame()
{	
	BCGame.Reset();
	
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	// Loop for Number of Rounds, asking for player guess
	// TODO change from FOR to WHILE loop
	for (int32 Counter = 1; Counter <= MaxTries; Counter++)
	{
		FText Guess = GetGuess(); // TODO make loop checking validity
		
		// Submit valid guess to the game
		// Print number of bulls and cows
		std::cout << "You guessed " << Guess << ".\n";
		std::cout << std::endl;
	}
	// TODO summarise game
}

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	// Player enters Guess
	FText Guess = "";
	std::cout << "Try " << CurrentTry << ". Enter your guess:\n";
	std::getline(std::cin, Guess);

	return Guess;

}

bool AskToPlayAgain()
{
	std::cout << "Would you like to play again?\n";
	FText Response = "";
	std::getline(std::cin, Response);

	if (Response[0] == 'y' || Response[0] == 'Y')
	{
		return true;
	}
	else if (Response[0] == 'n' || Response[0] == 'N')
	{
		std::cout << "Goodbye.\n";
		return false;
	}

	else
	{
		std::cout << "I'm sorry, I did not understand your answer.\n";
		AskToPlayAgain();
	}

	return false;
}