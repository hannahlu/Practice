#pragma once

#include <string>
#include <iostream>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor 

	// Functions are public
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValid(FString);
	FBullCowCount SubmitGuess(FString);

private:
	// See constructor for intialisation
	// Variables are private
	int32 MyCurrentTry = 1;
	int32 MyMaxTries = 5;
	FString MyHiddenWord = "";
};