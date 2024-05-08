#include "Player.h"

Player::Player() : name("Anonymous") {} // Constructor initializes player's name "Anonymous"

void Player::setName(const std::string& name) { // Set player's name
    this->name = name; // Assign provided name to player's name
}

std::string Player::getName() const { // Get player's name
    return name;
}
