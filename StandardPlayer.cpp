#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>
#include <unordered_map>
#include "StandardPlayer.h"

StandardPlayer::StandardPlayer() : Player() {}

StandardPlayer::StandardPlayer(std::string name, int num_dice) : Player(name, num_dice) {}

std::pair<int, int> StandardPlayer::getMode(std::vector<int>& dice) {
    std::unordered_map<int, int> freq = {
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
        {5, 0},
        {6, 0}
    };

    for (int die: dice) {
        freq[die]++;
    };

    int maxNum = 0;
    int mode;

    for (const auto& entry: freq) {
        if (entry.second > maxNum) {
            maxNum = entry.second;
            mode = entry.first;
        }
    }
    return { mode, maxNum };
}

void StandardPlayer::makeBet() {

    int prevGuessNumDice = this->last_guess[0];
    int prevGuessDiceValue = this->last_guess[1];

    // The guess has to either be an increase in quantitiy from the previous guess or an increase in value

    if (prevGuessNumDice == 0) {
        std::pair<int, int> result = this->getMode(this->dice);
        int diceValue = result.first;
        int maxFreq = result.second;
        this->guess[0] = maxFreq + (this->num_all_dice - this->num_dice) / 6;
        this->guess[1] = diceValue;
    } else {
        this->guess[0] = this->last_guess[0] + 1;
        this->guess[1] = this->last_guess[1];
    }

    std::cout << this->name << " guesses " << this->guess[0] << " " << this->guess[1] << "s. " << std::endl;
}

bool StandardPlayer::callDudo(int* guess) {
    if (guess[0] > this->num_players) {
        return true;
    }
    return false;
}
