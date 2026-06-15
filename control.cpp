#include <iostream>
#include <random>

enum Move { ROCK = 0, PAPER = 1, SCISSORS = 2 };

int main() {
    // Set up our fast C++ random engine
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random_move(0, 2); // 1/3 chance for R, P, S

    long long total_rounds = 0;
    int total_games = 1'000'000; // Run 1 million games for precision

    for (int i = 0; i < total_games; ++i) {
        int rounds_in_this_game = 0;
        
        while (true) {
            rounds_in_this_game++;

            // Player 1 and Player 2 make their moves
            Move p1 = static_cast<Move>(random_move(gen));
            Move p2 = static_cast<Move>(random_move(gen));

            // We only care: Is it a tie or did someone win?
            bool is_tie = (p1 == p2);

            if (!is_tie) {
                // Someone won! The game ends immediately.
                break;
            }
            
            // If it WAS a tie, the loop repeats for the next round
        }

        total_rounds += rounds_in_this_game;
    }

    std::cout << "Average Game Length: " 
              << static_cast<double>(total_rounds) / total_games 
              << " rounds." << std::endl;

    return 0;
}