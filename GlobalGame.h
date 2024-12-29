#include <iostream>
#include <vector>
#include <string>

class GlobalGame {
    public: 
        int num_players;
        int init_num_dice;
        int last_guess[2];
        std::vector<std::string> playing_order;
        bool win_round;
        bool win_game;

        GlobalGame();

        GlobalGame(int num_players, int init_num_dice);
};