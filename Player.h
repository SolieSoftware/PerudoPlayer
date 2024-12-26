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
    void rollDice();
    void loseDice();
    void lookAtDice();
    void makeBet();
    void callDudo();

    Player() : name(""), num_dice(0) {}

    Player(std::string name, int num_dice);

};