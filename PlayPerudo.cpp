#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include "Player.h"
#include "StandardPlayer.h"

void StartGame(std::unordered_map <std::string, Player>& players) {
    for (auto &player: players) {
        player.second.rollDice();
    };
}


std::vector<std::string> SetOrder() {
    std::vector<std::string> order_of_players = {"Tom", "Henry", "Steven", "Harold", "main"};
    return order_of_players;
}

std::vector<std::string> ShuffleOrder(std::vector<std::string> order_of_players) {
    order_of_players.push_back(order_of_players[0]);
    order_of_players.erase(order_of_players.begin());
    return order_of_players;
}

int main() {
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


    bool win = false;

    std::cout << "Welcome to Perudo!!" << std::endl;
    std::cout << "Roll Your Dice!" << std::endl;

    StartGame(players);
    std::vector<std::string> order_of_players = SetOrder();

    std::cout << "You rolled: " << std::endl;
    players["main"].lookAtDice();


    std::cout << "Your turn first! Make your bet! " << std::endl;
    players["main"].makeBet();
    int last_guess[2] = {players["main"].guess_num,players["main"].guess_value};
    while (!win) {
        players[order_of_players[0]].callDudo(last_guess);
        order_of_players = ShuffleOrder(order_of_players);
        players[order_of_players[0]].makeBet();
        last_guess[0], last_guess[1] = players[order_of_players[0]].guess_num, players[order_of_players[0]].guess_value;
    };

}