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
    this->guess_num = maxFreq + 3;
    this->guess_value = mode;
}
