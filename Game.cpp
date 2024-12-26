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

void StartRound(std::unordered_map <std::string, Player>& players) {
    for (auto &player: players) {
        player.second.rollDice();
    };
}

int main() {
    std::string name;
    std::cout << "State your name cus!" << std::endl;
    std::cin >> name;
    Player player1(name, 5);
    StandardPlayer player2("Tom", 5);
    StandardPlayer player3("Henry", 5);
    StandardPlayer player4("Steven", 5);
    StandardPlayer player5("Harold", 5);
    std::unordered_map<std::string, Player> players = {
        {"main",  player1}, 
        {"Tom", player2},
        {"Henry", player3},
        {"Steven", player4},
        {"Harold", player5},
        };

    std::cout << "Welcome to Perudo!!" << std::endl;
    std::cout << "Roll Your Dice!" << std::endl;

    StartRound(players);

    std::cout << "You rolled: " << std::endl;
    players["main"].lookAtDice();

    std::cout << "Your turn! Make your bet! " << std::endl;

    for (auto &player: players) {
        player.second.makeBet();
    }






}