#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player { // Declaration of the Player class
public:
    Player();
    void setName(const std::string& name); // Method to set the player's name
    std::string getName() const; // Method to get the player's name

private:
    std::string name; // Private data member to store the player's name
};

#endif

