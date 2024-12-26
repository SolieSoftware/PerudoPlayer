#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>
#include "Player.h"

int roll (std::mt19937& gen, std::uniform_int_distribution<>& distribution) {
    int die_roll = distribution(gen);
    std::cout << "You rolled a: " << die_roll << std::endl;
    return die_roll;
}

void printVector(const std::vector<int> & vec) {
    for (int element:vec) {
        std::cout << element << " ";
    }
}

Player::Player(std::string name, int num_dice) : name(name), num_dice(num_dice) {};

void Player::rollDice() {
    std::vector<int> dice_rolls = {};
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distribution(1,6);;

    for (int i = 0; i < this->num_dice; i++) {
        int die = roll(gen, distribution);
        this->dice.push_back(die);
    }
};

void Player::loseDice() {
    this->num_dice -= 1;
};

void Player::lookAtDice() {
    printVector(this->dice);
};

void Player::makeBet() {
    int guess;
    std::cout << "Guess the number of dice: " << std::endl;
    std::cin >> guess;
};

void Player::callDudo() {
    std::cout << "Dudo!" << std::endl;
};
