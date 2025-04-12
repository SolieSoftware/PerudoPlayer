
#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include "GlobalGame.h"

int GlobalGame::num_players;
int GlobalGame::init_num_dice;
std::vector<std::string> GlobalGame::playing_order;
int GlobalGame::last_guess[2];
bool GlobalGame::win_round;
bool GlobalGame::win_game;
bool GlobalGame::dudo_called;


GlobalGame::GlobalGame() {
    GlobalGame::num_players = 5;
    GlobalGame::init_num_dice = 5;
    GlobalGame::playing_order = {"Tom", "Henry", "Steven", "Harold", "main"};
}

GlobalGame::GlobalGame(int num_players, int init_num_dice) {
    GlobalGame::num_players = num_players;
    GlobalGame::init_num_dice = init_num_dice;
}

void GlobalGame::CheckRoundWin(std::vector<int> dice) {
    std::unordered_map<int, int> dice_freq;
    for (int die: dice) {
        dice_freq[die] += 1;
    }

    if (dice_freq[this->last_guess[1]] > this->last_guess[0]) {
        std::cout << "Dudo was called correctly!" << std::endl;
        std::cout << "There are " << dice_freq[this->last_guess[1]] << " " << this->last_guess[1] << "s, on the table!" << std::endl;
        this->win_round = true;
    } else {
        std::cout << "Dudo was called incorrectly!" << std::endl;
        std::cout << "There are only " << dice_freq[this->last_guess[1]] << " " << this->last_guess[1] << "s, on the table." << std::endl;
        this->win_round = false;
    }
}

void GlobalGame::CheckGameWin() {

    if (this->playing_order.size() == 1) {
        this->win_game = true;
        std::cout << this->playing_order[0] << " has won the game! Congratulations!" << std::endl;
    }
}


