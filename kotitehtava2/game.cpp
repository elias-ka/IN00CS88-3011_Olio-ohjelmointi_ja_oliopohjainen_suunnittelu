#include "game.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Game::Game(int max_number) : max_number_(max_number) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << "GAME CONSTRUCTOR: object initialized with " << max_number_ << " as a maximum value\n";
}

Game::~Game() {
    std::cout << "GAME DESTRUCTOR: object cleared from stack memory\n";
}

auto Game::play() -> void {
    random_number_ = std::rand() % max_number_ + 1;

    while (true) {
        std::cout << "Give your guess between 1-" << max_number_ << '\n';
        std::cin >> player_guess_;
        num_of_guesses_++;

        if (player_guess_ < random_number_) {
            std::cout << "Your guess is too small\n";
        } else if (player_guess_ > random_number_) {
            std::cout << "Your guess is too big\n";
        } else {
            std::cout << "Your guess is right = " << random_number_ << '\n';
            print_game_result();
            break;
        }
    }
}

auto Game::print_game_result() const -> void {
    std::cout << "You guessed the right answer = " << random_number_ << " with " << num_of_guesses_ << " guesses\n";
}
