// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

//Global variables defined at the top of the class are bad practice. We define them in the Header file. It relates the instancing of the variable. If I've defined a global var here, and play the game I am given a hidden word. If I then start a new game and get a new hidden word, the word in the first game will change. 

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    //PrintLine(FString::Printf(TEXT("The hidden word is: %s"), *Var)) -- for our code, PrintLine includes FString::Printf(), so we do not need to use it

    PrintLine(TEXT("The hidden word is: %s. \nIt is %i characters long."), *HiddenWord, HiddenWord.Len())

    SetupGame();

    PrintLine(TEXT("Welcome to our farm, Stranger! Let's play a game of Bull Cows."));
    PrintLine(TEXT("Press TAB to interact with the sign."));
    PrintLine(TEXT("Guess the 4 letter word and press Enter.")); //4 is a hard coded letter count. Change to be dynamic later
    

    //Prompt player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    HiddenWord.Len();

    if(Input == HiddenWord)
    {
        PrintLine(TEXT("You win!"));
    }
    else 
    {
        if(Input != HiddenWord && Lives > 0)
        {
            PrintLine(TEXT("That's a life, bitch!"));
        }

        PrintLine(TEXT("We're sorry, you lose."));
    }
        
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cake"); //Variable storing the word that must be guessed
    //here we encode our string with the TEXT macro - macros are all caps. This is for Unreal during encoding to ensure they are encoded properly for more platforms

    //Set our lives variable
    int32 Lives = 4;

}