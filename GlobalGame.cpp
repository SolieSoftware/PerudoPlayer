
#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>
#include "GlobalGame.h"

int GlobalGame::num_players;
int GlobalGame::init_num_dice;
std::vector<std::string> GlobalGame::playing_order;

GlobalGame::GlobalGame() {
    GlobalGame::num_players = 5;
    GlobalGame::init_num_dice = 5;
    GlobalGame::playing_order = {"Tom", "Henry", "Steven", "Harold", "main"};
}

GlobalGame::GlobalGame(int num_players, int init_num_dice) {
    GlobalGame::num_players = num_players;
    GlobalGame::init_num_dice = init_num_dice;
}

void GlobalGame::ShuffleOrder() {
    GlobalGame::playing_order.push_back(playing_order[0]);
    GlobalGame::playing_order.erase(playing_order.begin());
}


