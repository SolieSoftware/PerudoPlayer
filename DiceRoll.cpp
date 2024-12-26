#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <random>
#include <ctime>    // For time()
#include <vector>

int roll (std::mt19937& gen, std::uniform_int_distribution<>& distribution) {

    // Generate a random number between 1 and 6
    int die_roll = distribution(gen);

    std::cout << "You rolled a: " << die_roll << std::endl;

    return die_roll;
}

void printVector(const std::vector<int> & vec) {
    for (int element:vec) {
        std::cout << element << " ";
    }
}

int main() {
    // Seed the random number generator with the current time
    std::vector<int> dice_rolls = {};
    int num_dice = 5;
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distribution(1,6);;

    for (int i = 0; i < num_dice; i++) {
        int die = roll(gen, distribution);
        dice_rolls.push_back(die);
    }

    std::cout << "Rolls: ";
    printVector(dice_rolls); 
    std::cout << std::endl;

    return 0;
}
