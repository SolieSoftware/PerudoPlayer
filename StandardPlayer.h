#ifndef STANDARDPLAYER_H
#define STANDARDPLAYER_H

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>
#include <unordered_map>
#include "Player.h"

class StandardPlayer : public Player {
    public:
        StandardPlayer();
        StandardPlayer(std::string name, int num_dice);
        virtual void makeBet() override;
        virtual bool callDudo(int* guess) override;
        std::pair<int, int> getMode(std::vector<int>& dice);
};

#endif