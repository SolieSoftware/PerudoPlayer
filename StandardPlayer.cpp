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

std::pair<int, int> getMode(std::vector<int>& dice) {
    std::unordered_map<int, int> freq = {
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
        {5, 0},
        {6, 0}
    };

    for (int die: this->dice) {
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
    std::pair<int, int> result = getMode();
    int diceValue = result.first;
    int maxFreq = result.second;
    int prevGuessNumDice = this->guess[0];
    int prevGuessDiceValue = this->guess[1];

    // The guess has to either be an increase in quantitiy from the previous guess or an increase in value
    // 

    if (prevGuessNumDice >= maxFreq && prevGuessDiceValue >= diceValue) {
        this->guess[0] = maxFreq + 1;
    } else {
        this->guess[0] = maxFreq + (this->num_players - 2);
    }

    this->guess[0] = maxFreq + (this->num_players - 2);
    this->guess[1] = diceValue;
    std::cout << this->name << " guesses " << this->guess[0] << " " << this->guess[1] << "s. " << std::endl;
}

bool StandardPlayer::callDudo(int* guess) {
    if (guess[0] > this->num_players) {
        return true;
    }
    return false;
}
