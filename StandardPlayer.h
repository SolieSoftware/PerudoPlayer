#ifndef STANDARD_PLAYER_H
#define STANDARD_PLAYER_H

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>
#include "Player.h"

class StandardPlayer: public Player {
    public:
        StandardPlayer();
        StandardPlayer(std::string name, int num_dice);
        void makeBet() override;
        bool callDudo(int* guess) override; 
};

#endif