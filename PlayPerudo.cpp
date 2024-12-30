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
#include "GlobalGame.h"

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
    return order_of_players;
}

void InitialiseGameSetup() {
    int num_players;
    int num_dice;
    std::cout << "How many Players in this game?" << std::endl;
    std::cin >> num_players;
    std::cout << "How many dice per players?" << std::endl;
    std::cin >> num_dice;

    if (num_dice > 3 && num_dice <= 6 && num_players >=3 && num_players <= 10) {
        //Use Standard setup for now
        GlobalGame();
    } else {
        GlobalGame();
    }

    GlobalGame obj;
    std::cout << obj.num_players;
}

int main() {
    // Initialise Game Setup
    InitialiseGameSetup();

    return 0;




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