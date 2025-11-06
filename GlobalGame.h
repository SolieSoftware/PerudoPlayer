#ifndef GLOBALGAME_H
#define GLOBALGAME_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <memory>  // For std::shared_ptr

// Forward declaration of Player class
class Player;

class GlobalGame {
    public: 
        int static num_players;
        int static init_num_dice;
        int static num_all_dice;
        int static last_guess[2];
        int static bet_ptr;
        int static dudo_ptr;
        std::vector<std::string> static playing_order;
        bool static dudo_called;
        bool static win_round;
        bool static win_game;

        GlobalGame();

        GlobalGame(int num_players, int init_num_dice);

        void ShuffleOrder();

        void CheckRoundWin(std::vector<int> dice);

        void CheckGameWin();

        void NextRound();

        void RemovePlayer(std::string player_name);

        void CountAllDice(std::map<std::string, std::shared_ptr<Player>>& players);

};

#endif