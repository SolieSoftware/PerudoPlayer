#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include "Player.h"

int main() {
    std::string name;
    std::cout << "State your name cus!" << std::endl;
    std::cin >> name;
    Player player1(name, 5);
    Player player2("Tom", 5);
    Player player3("Henry", 5);
    Player player4("Steven", 5);
    Player player5("Harold", 5);
    std::unordered_map<std::string, Player> players = {
        {"main",  player1}, 
        {"Tom", player2},
        {"Henry", player3},
        {"Steven", player4},
        {"Harold", player5},
        };

    std::cout << "Welcome to Perudo!!" << std::endl;
    std::cout << "You roll first!" << std::endl;


    std::cout << players["main"].name << std::endl;
}