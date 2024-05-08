// Samuel Castro
// Casino number Guessing game
// SP2024
/* Description: This is an amazing project where you will learn about random number guessing. The
application includes the user inputting a wager amount and then guessing what the number on rolling would be.
You win in this game when the random number matches with the number you input. But if it doesn’t you lose your bet.
You can keep going until you run out of money or don’t want to play more.*/

#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include "Game.h"

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0))); // Random number generator

    Game game; // Create game instance
    game.start(); // Begin game

    return 0; // Successful completion
}
