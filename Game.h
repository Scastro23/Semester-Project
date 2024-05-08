#ifndef GAME_H
#define GAME_H

class Game { // Declaration of the Game class
public:
    Game();
    void start(); // Method to start the game

private:
    void displayMenu();
    void playGame();
    void gameRules();
    void showHighScore();
    void updateHighScore(double balance);

    double generateRandomNumber(int min, int max); // Helper method to generate a random number

    double balance; // Private data member to store the player's balance
    double highScore; // Private data member to store the high score
};

#endif
