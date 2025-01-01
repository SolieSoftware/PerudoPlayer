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

int getMode(std::vector<int>& dice) {
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
    return mode, maxNum;

}

void StandardPlayer::makeBet() {
    int mode, maxFreq = getMode(this->dice);
    this->guess[0] = maxFreq + (this->num_players - 2);
    this->guess[1] = mode;
    std::cout << "I guess " << this->guess[0] << " " << this->guess[1] << "s. " << std::endl;
}

bool StandardPlayer::callDudo(int* guess) {
    if (guess[0] > this->num_players) {
        return true;
    }
    return false;
}
