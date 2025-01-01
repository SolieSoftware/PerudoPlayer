#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "Player.h"
#include "StandardPlayer.h"
#include "GlobalGame.h"

void PrintVector(std::vector<int>& vec) {
    for (auto l : vec) {
        std::cout << l << std::endl;
    }
}

void StartRound(std::unordered_map <std::string, Player>& players) {
    std::cout << "Start Round. " << std::endl;
    std::cout << "Roll Your Dice!" << std::endl;
    for (auto &player: players) {
        player.second.rollDice();
    };
    std::cout << "You rolled: " << std::endl;
    players["main"].lookAtDice();
}

std::vector<int> RevealDice(std::unordered_map<std::string, Player> players) {
    std::vector<int> all_dice;
    for (auto& player : players) {
        all_dice.insert(all_dice.end(), player.second.dice.begin(), player.second.dice.end());
    }

    std::cout << "Everyone please reveal your dice! " << std::endl;
    std::cout << "We have: " << std::endl;

    PrintVector(all_dice);

    return all_dice;
}

void RemoveZeroDicePlayers(std::unordered_map<std::string, Player> players, GlobalGame game) {
    for (auto &player : players) {
        if (player.second.num_dice == 0) {
            game.playing_order.erase(std::remove(game.playing_order.begin(), game.playing_order.end(), player.second.name), game.playing_order.end());
        }
    }
}

GlobalGame InitialiseGameSetup() {
    int num_players;
    int num_dice;
    std::cout << "How many Players in this game?" << std::endl;
    std::cin >> num_players;
    std::cout << "How many dice per players?" << std::endl;
    std::cin >> num_dice;

    if (num_dice > 3 && num_dice <= 6 && num_players >=3 && num_players <= 10) {
        //Use Standard setup for now
        GlobalGame game();
        return game;
    } else {
        GlobalGame game();
        return game;
    }
}

int main() {
    //State rules and Welcome to Perudo


    // Initialise Game Setup
    GlobalGame game = InitialiseGameSetup();

    //Initalise game object to call/update game variables.
    GlobalGame game;

    // Initialise Players
    std::string name;
    std::cout << "State your name cus!" << std::endl;
    std::cin >> name;
    std::unordered_map<std::string, Player> players = {
        {"main",  Player(name, 5)}, 
        {"Tom", StandardPlayer("Tom", 5)},
        {"Henry", StandardPlayer("Henry", 5)},
        {"Steven", StandardPlayer("Steven", 5)},
        {"Harold", StandardPlayer("Harold", 5)},
        };

    //Start Betting Round
    while(!game.win_game) {
        //Start Game - Begine with roll of dice
        StartRound(players);
        players[game.playing_order[0]].makeBet();
        game.last_guess[0], game.last_guess[1] = players[game.playing_order[0]].guess[0], players[game.playing_order[0]].guess[1];
        game.ShuffleOrder();
        game.dudo_called = players[game.playing_order[0]].callDudo(game.last_guess);
        if (game.dudo_called) {
            game.CheckRoundWin(RevealDice(players));
            if (game.win_round) {
                std::cout << players[game.playing_order[0]].name << " has won the round! " << std::endl;
                std::cout << players[game.playing_order[-1]].name << " loses a die!" << std::endl;
                players[game.playing_order[-1]].loseDice();
            } else {
                std::cout << players[game.playing_order[0]].name << " loses the round and theefore must lose a die! " << std::endl;
                players[game.playing_order[0]].loseDice();
            }
        }
        RemoveZeroDicePlayers(players, game);

        game.CheckGameWin();
    }

}