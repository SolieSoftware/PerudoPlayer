#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>
#include "Player.h"

Player::Player() {
    this->name = "";
    this->num_dice = 0;
}

Player::Player(std::string name, int num_dice) {
    this->name = name;
    this->num_dice = num_dice;
};

int roll (std::mt19937& gen, std::uniform_int_distribution<>& distribution) {
    int die_roll = distribution(gen);
    return die_roll;
}

void printVector(const std::vector<int> & vec) {
    for (int element:vec) {
        std::cout << element << " ";
    }
}

void Player::rollDice() {
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distribution(1,6);;

    for (int i = 0; i < this->num_dice; i++) {
        int die = roll(gen, distribution);
        this->dice.push_back(die);
        // std::cout << "Die Rolled: " << die << " | Dice: " << this->dice.size() << std::endl;
    }

};

void Player::loseDice() {
    this->num_dice -= 1;
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
