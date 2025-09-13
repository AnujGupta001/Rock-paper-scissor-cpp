#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class RockPaperScissors {
private:
    int userWins, computerWins, ties;

    string getChoiceName(int choice) {
        switch (choice) {
            case 1: return "Rock";
            case 2: return "Paper";
            case 3: return "Scissors";
            default: return "Invalid";
        }
    }

    int getComputerChoice() {
        return (rand() % 3) + 1; // Random number between 1 and 3
    }

    void showScoreboard() {
        cout << "\n--- Scoreboard ---\n";
        cout << "You: " << userWins
             << " | Computer: " << computerWins
             << " | Ties: " << ties << endl;
    }

public:
    RockPaperScissors() {
        userWins = 0;
        computerWins = 0;
        ties = 0;
        srand(time(0)); // Seed random generator once
    }

    void play() {
        int userChoice, computerChoice;
        char playAgain;

        cout << "===== Rock Paper Scissors Game =====\n";

        do {
            cout << "\nChoose your move:\n";
            cout << "1. Rock\n2. Paper\n3. Scissors\n";
            cout << "Enter choice (1-3): ";

            if (!(cin >> userChoice)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please enter a number between 1 and 3.\n";
                continue;
            }

            if (userChoice < 1 || userChoice > 3) {
                cout << "Invalid choice! Try again.\n";
                continue;
            }

            computerChoice = getComputerChoice();

            cout << "You chose: " << getChoiceName(userChoice) << endl;
            cout << "Computer chose: " << getChoiceName(computerChoice) << endl;

            if (userChoice == computerChoice) {
                cout << "It's a tie!\n";
                ties++;
            } else if ((userChoice == 1 && computerChoice == 3) ||
                       (userChoice == 2 && computerChoice == 1) ||
                       (userChoice == 3 && computerChoice == 2)) {
                cout << "You win!\n";
                userWins++;
            } else {
                cout << "Computer wins!\n";
                computerWins++;
            }

            showScoreboard();

            cout << "\nPlay again? (y/n): ";
            cin >> playAgain;

        } while (playAgain == 'y' || playAgain == 'Y');

        cout << "\nFinal Scoreboard:\n";
        cout << "You: " << userWins
             << " | Computer: " << computerWins
             << " | Ties: " << ties << endl;

        cout << "\nThanks for playing!\n";
    }
};

int main() {
    RockPaperScissors game;
    game.play();
    return 0;
}
