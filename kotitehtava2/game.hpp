#ifndef KOTITEHTAVA2_GAME_HPP
#define KOTITEHTAVA2_GAME_HPP

class Game {
public:
  explicit Game(int max_number);

  ~Game();

  auto play() -> void;

private:
  auto print_game_result() const -> void;

  int max_number_;
  int player_guess_{};
  int random_number_{};
  int num_of_guesses_{};
};

#endif  // KOTITEHTAVA2_GAME_HPP
