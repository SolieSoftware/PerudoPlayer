#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <memory>
#include "Player.h"
#include "StandardPlayer.h"
#include "GlobalGame.h"

void PrintVector(std::vector<int>& vec) {
    for (auto l : vec) {
        std::cout << l << std::endl;
    }
}

void StartRound(std::map<std::string, std::shared_ptr<Player>>players) {
    std::cout << "Start Round. " << std::endl;
    std::cout << "Roll Your Dice!" << std::endl;

    for (const auto& player: players) {
        player.second->rollDice();
    };

    std::cout << "You rolled: ";
    players["main"]->lookAtDice();
    std::cout << std::endl;
}

std::vector<int> RevealDice(std::map<std::string, std::shared_ptr<Player>> players) {
    std::cout << "Everyone please reveal your dice! " << std::endl;

    std::vector<int> all_dice;
    for (auto& player : players) {
        std::cout << player.second->name << " has the folllowind dice: ";
        player.second->lookAtDice();
        std::cout << std::endl;
        all_dice.insert(all_dice.end(), player.second->dice.begin(), player.second->dice.end());
    }

    return all_dice;
}

void RemoveZeroDicePlayers(std::map<std::string, std::shared_ptr<Player>> players, GlobalGame game) {
    for (auto &player : players) {
        if (player.second->num_dice == 0) {
            std::cout << player.second->name << " has no more dice left and will now leave the game. " << std::endl;
            game.playing_order.erase(std::remove(game.playing_order.begin(), game.playing_order.end(), player.second->name), game.playing_order.end());
            printVector(game.playing_order);
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
        GlobalGame game;
        return game;
    } else {
        GlobalGame game;
        return game;
    }
}

int main() {
    //State rules and Welcome to Perudo


    // Initialise Game Setup
    GlobalGame game = InitialiseGameSetup();

    //Initalise game object to call/update game variables.

    // Initialise Players
    std::string name;
    std::cout << "State your name cus!" << std::endl;
    std::cin >> name;

    //Instatiate Player Classses
    std::map<std::string, std::shared_ptr<Player>> players;

    players["main"] = std::make_shared<Player>(name, 5);
    players["Tom"] = std::make_shared<StandardPlayer>("Tom", 5);
    players["Henry"] = std::make_shared<StandardPlayer>("Henry", 5);
    players["Steven"] = std::make_shared<StandardPlayer>("Steven", 5);
    players["Harold"] = std::make_shared<StandardPlayer>("Harold", 5);

    //Start Betting Round
    game.bet_ptr = 0;
    game.dudo_ptr = 1;
    game.win_round = true;
    while(!game.win_game) {
        //Start Game - Begine with roll of dice
        if (game.win_round) {
            StartRound(players);
            game.win_round = false;
        }


        //Player makes bet and reveals his bet to the table. 
        std::cout << game.playing_order[game.bet_ptr] << " will play his turn. " << std::endl;
        players[game.playing_order[game.bet_ptr]]->makeBet();
        
        game.last_guess[0] = players[game.playing_order[game.bet_ptr]]->guess[0];
        game.last_guess[1] =  players[game.playing_order[game.bet_ptr]]->guess[1];


        game.dudo_called = players[game.playing_order[game.dudo_ptr]]->callDudo(game.last_guess);
        if (game.dudo_called) {
            game.CheckRoundWin(RevealDice(players));
            if (game.win_round) {
                std::cout << players[game.playing_order[game.dudo_ptr]]->name << " has won the round!" << std::endl;
                std::cout << players[game.playing_order[game.bet_ptr]]->name << " loses a die. " << std::endl;
                players[game.playing_order[game.bet_ptr]]->loseDice();
            } else {
                std::cout << players[game.playing_order[game.bet_ptr]]->name << " has won the round!" << std::endl;
                std::cout << players[game.playing_order[game.dudo_ptr]]->name << " loses a die. " << std::endl;
                players[game.playing_order[game.dudo_ptr]]->loseDice();
            }
        }

        RemoveZeroDicePlayers(players, game);

        game.CheckGameWin();

        game.NextRound();
    }

}