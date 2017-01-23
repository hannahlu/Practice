#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset() 
{	
	constexpr int32 Max_TRIES = 8;
	MyMaxTries = Max_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	constexpr int32 CURRENT_TRY = 1;
	MyCurrentTry = CURRENT_TRY;

	return;
	
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValid(FString) 
{
	return false;
}

// Recieves a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	// Increment the try number
	MyCurrentTry++;

	// Setup a return variable
	FBullCowCount BullCowCount;
	
	// loop through all letters in guess
		// compare letters against the hidden word

	return BullCowCount;
}