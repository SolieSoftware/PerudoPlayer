#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>
#include "GlobalGame.h"



class Player: public GlobalGame {
    public:
        std::string name;
        int num_dice;
        std::vector<int> dice;
        int guess[2];
        void rollDice();
        void loseDice();
        void lookAtDice();
        virtual void makeBet();
        virtual bool callDudo(int* guess);

        Player();

        Player(std::string name, int num_dice);

};

#endif