#include <iostream>
#include <limits>
#include "Game.h"
#include "Player.h"

using namespace std;

// Constructor for Game class
Game::Game() : balance(1000.0), highScore(1000.0) {}

// Start method to begin the game
void Game::start() {
    cout << "Welcome to the Money Rand Number Guessing Game!" << endl; // Display welcome message

    int choice;
    do {
        displayMenu(); // Display menu
        cout << "Enter your choice: "; // Prompt user for input
        cin >> choice;

        switch (choice) {
        case 1:
            playGame(); // Start the game
            break;
        case 2:
            gameRules(); // Display game rules
            break;
        case 3:
            showHighScore(); // Display high score
            break;
        case 4:
            cout << "Thank you for playing. Exiting the game." << endl; // Exit the game
            break;
        default:
            cout << "Invalid choice. Please try again." << endl; // Display invalid choice message
            cin.clear(); // Clear input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
    } while (choice != 4);
}

// Display menu options
void Game::displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. Game Rules" << endl;
    cout << "3. Show High Score" << endl;
    cout << "4. Exit Game" << endl;
}

// Play the game
void Game::playGame() {
    double betAmount; // Declare variable to store bet amount

    cout << "\nYour current balance: $" << balance << endl; // Display current balance
    cout << "Enter your bet amount: $"; // Prompt user for bet amount
    cin >> betAmount;

    if (cin.fail() || betAmount <= 0 || betAmount > balance) { // Check for invalid input
        cout << "Invalid input. Please enter a valid amount." << endl; // Display invalid input message
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        return;
    }

    int minRange, maxRange; // Declare variables to store min and max range
    cout << "Enter the minimum range for the number (e.g., 1): "; // Prompt user for min range
    cin >> minRange; // Take user input for min range
    cout << "Enter the maximum range for the number (e.g., 10): "; // Prompt user for max range
    cin >> maxRange; // Take user input for max range

    if (minRange >= maxRange || minRange <= 0 || maxRange <= 0) { // Check for invalid range
        cout << "Invalid range. Please enter valid numbers." << endl; // Display invalid range message
        return;
    }

    int userGuess = 0; // Declare variable to store user guess
    while (userGuess < minRange || userGuess > maxRange) { // Validate user guess
        cout << "Enter your guess (between " << minRange << " and " << maxRange << "): ";
        cin >> userGuess;
        if (cin.fail()) { // Check for invalid input
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear(); // Clear input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            userGuess = 0;
        }
    }

    int randomNum = generateRandomNumber(minRange, maxRange); // Generate random number
    cout << "The random number is: " << randomNum << endl;

    if (userGuess == randomNum) { // Check if guess is correct
        cout << "Congratulations! You guessed the correct number." << endl;
        balance += betAmount; // Update balance
    }
    else {
        cout << "Sorry, your guess was incorrect." << endl;
        balance -= betAmount; // Update balance
    }

    cout << "Your updated balance: $" << balance << endl;
    updateHighScore(balance); // Update high score
}

// Display game rules
void Game::gameRules() {
    cout << "\nGame Rules:" << endl;
    cout << "1. You start with an initial balance of $1000." << endl;
    cout << "2. Enter the amount you want to bet (between $1 and your current balance)." << endl;
    cout << "3. Enter the range of numbers you want to guess from." << endl;
    cout << "4. Guess a number within the specified range." << endl;
    cout << "5. If your guess matches the random number, you win the bet amount." << endl;
    cout << "6. If your guess is incorrect, the bet amount is deducted from your balance." << endl;
    cout << "7. Keep playing until you run out of money." << endl;
}

// Show high score
void Game::showHighScore() {
    cout << "\nHigh Score: $" << highScore << endl; // Display high score
}

// Update high score
void Game::updateHighScore(double balance) {
    if (balance > highScore) { // Check if new high score achieved
        highScore = balance; // Update high score
        cout << "Congratulations! You've achieved a new high score!" << endl; // Display new high score message
    }
}

// Generate random number within given range
double Game::generateRandomNumber(int min, int max) {
    return min + (rand() % (max - min + 1));
}
