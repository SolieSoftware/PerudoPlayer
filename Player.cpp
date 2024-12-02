#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>
#include <string>

int roll (std::mt19937& gen, std::uniform_int_distribution<>& distribution) {
    int die_roll = distribution(gen);
    std::cout << "You rolled a: " << die_roll << std::endl;
    return die_roll;
}

void printVector(const std::vector<int> & vec) {
    for (int element:vec) {
        std::cout << element << " ";
    }
}

class Player {
    public:
    std::string name;
    int num_dice;
    std::vector<int> dice;
    Player(std::string x, int y);
    void rollDice();
    void loseDice();
    void lookAtDice();

};

Player::Player(std::string x, int y = 5) {
    name = x;
    num_dice = y;
}

void Player::rollDice() {
    std::vector<int> dice_rolls = {};
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distribution(1,6);;

    for (int i = 0; i < this->num_dice; i++) {
        int die = roll(gen, distribution);
        this->dice.push_back(die);
    }
};

void Player::loseDice() {
    this->num_dice -= 1;
};

void Player::lookAtDice() {
    printVector(this->dice);
};

int main() {
    Player Sol("Sol");
    std::cout << Sol.name;
}
