#include "GlobalGame.h"



GlobalGame::GlobalGame() {
    this->num_players = 5;
    this->init_num_dice = 5;
}

GlobalGame::GlobalGame(int num_players, int init_num_dice) {
    this->num_players = num_players;
    this->init_num_dice = init_num_dice;
}


