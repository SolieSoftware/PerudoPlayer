#ifndef GLOBALGAME_H
#define GLOBALGAME_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

class GlobalGame {
    public: 
        int static num_players;
        int static init_num_dice;
        int static last_guess[2];
        std::vector<std::string> static playing_order;
        bool static dudo_called;
        bool static win_round;
        bool static win_game;5

        GlobalGame();

        GlobalGame(int num_players, int init_num_dice);

        void ShuffleOrder();

        void CheckRoundWin(std::vector<int> dice);

        void CheckGameWin();

};

#endif