#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <chrono>   // For system_clock
#include <vector>
#include <string>
#include "Player.h"

// Static member to ensure unique seeds for each player
static int playerCounter = 0;

Player::Player() {
    this->name = "";
    this->num_dice = 0;
    // Use a combination of time and player counter for better randomization
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count() + playerCounter++;
    this->gen = std::mt19937(seed);
}

Player::Player(std::string name, int num_dice) {
    this->name = name;
    this->num_dice = num_dice;
    // Use a combination of time and player counter for better randomization
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count() + playerCounter++;
    this->gen = std::mt19937(seed);
};

int Player::roll(std::uniform_int_distribution<>& distribution) {
    int die_roll = distribution(gen);
    return die_roll;
}

void printVector(const std::vector<int> & vec) {
    for (int element:vec) {
        std::cout << element << " ";
    }
}

void Player::rollDice() {
    std::uniform_int_distribution<> distribution(1,6);
    this->dice.clear();

    for (int i = 0; i < this->num_dice; i++) {
        int die = roll(distribution);
        this->dice.push_back(die);
    }
};

void Player::loseDice() {
    this->num_dice -= 1;
    this->dice.pop_back();
};

void Player::lookAtDice() {
    printVector(this->dice);
};

void Player::makeBet() {
    std::cout << "Guess the number of dice: " << std::endl;
    std::cin >> this->guess[0];
    std::cout << "Guess the value of the dice: " << std::endl;
    std::cin >> this->guess[1];
};

bool Player::callDudo(int* guess) {
    std::cout << "The last player just guessed " << guess[0] << " " << guess[1] << "s." << std::endl;
    char rep;
    std::cout << "Would you like to call Dudo, press Y" << std::endl;
    std::cin >> rep;
    if (rep == 'Y') {
        return true;
    };
    return false;
};
