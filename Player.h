#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>



class Player {
    public:
        std::string name;
        int num_dice;
        std::vector<int> dice;
        int guess_value;
        int guess_num;
        void rollDice();
        void loseDice();
        void lookAtDice();
        virtual void makeBet();
        void callDudo();

        Player();

        Player(std::string name, int num_dice);

};

#endif