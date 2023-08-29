#include <iostream>
#include <ctime>
#include <cstdlib>

auto game(int maxnum) -> int {
    // Nowadays, you'd use the C++11 <random> to generate a random number:
    //
    //  #include <random>
    //  auto gen = std::mt19937{std::random_device{}()};
    //  auto dis = std::uniform_int_distribution<>{1, maxnum};
    //  int answer = dis(gen);
    //
    // But for the sake of this assignment, I'll use the C way.

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int answer = std::rand() % maxnum + 1;
    int player_guess = 0;
    int guesses = 0;

    while (true) {
        std::cout << "Arvaa luku välillä 1-" << maxnum << ": ";
        std::cin >> player_guess;
        guesses++;

        if (player_guess < answer) {
            std::cout << "luku on suurempi\n";
        } else if (player_guess > answer) {
            std::cout << "luku on pienempi\n";
        } else {
            std::cout << "oikea vastaus\n";
            return 0;
        }
    }
}

auto main() -> int {
    int maxnum;
    std::cout << "Anna suurin mahdollinen luku: ";
    std::cin >> maxnum;
    game(maxnum);
}