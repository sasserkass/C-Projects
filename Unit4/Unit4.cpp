#include <iostream>
#include <ctime>
#include <cstdlib>

// Parent class representing a generic dice
class Dice {
public:
    virtual int roll() = 0;
};

// Child class representing a D20 dice
class D20 : public Dice {
public:
    int roll() override {
        return rand() % 20 + 1; // Generate a random number between 1 and 20
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator with the current time

    std::cout << "Welcome to the D20 Dice Rolling Game!" << std::endl;

    // Create an instance of the D20 dice
    D20 d20;

    char playAgain;
    do {
        // Prompt the user to roll the dice
        std::cout << "Press Enter to roll the D20 dice...";
        std::cin.get(); // Wait for the user to press Enter

        // Roll the dice and display the result
        int result = d20.roll();
        std::cout << "You rolled a " << result << "!" << std::endl;

        // Ask if the user wants to play again
        std::cout << "Do you want to roll again? (Y/N): ";
        std::cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    std::cout << "Thank you for playing! Goodbye!" << std::endl;
    return 0;
}

