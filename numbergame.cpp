#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Score {
    string name;
    int attempts;
};

bool compareScores(const Score &a, const Score &b) {
    return a.attempts < b.attempts;
}

string toLowerCase(const string &input) {
    string result = input;
    transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return tolower(c); });
    return result;
}

void saveScores(const vector<Score> &scores) {
    ofstream outputFile("leaderboard.txt");
    if (outputFile.is_open()) {
        for (const Score &score : scores) {
            outputFile << score.name << " " << score.attempts << endl;
        }
        outputFile.close();
    } else {
        cout << "Unable to save leaderboard." << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    bool hasGuessed = false;

    vector<Score> leaderboard;

    // Load existing leaderboard from file
    ifstream inputFile("leaderboard.txt");
    if (inputFile.is_open()) {
        Score score;
        while (inputFile >> score.name >> score.attempts) {
            leaderboard.push_back(score);
        }
        inputFile.close();
    }

    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "I have selected a number between 1 and 100. Try to guess it." << endl;

    while (!hasGuessed) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess == secretNumber) {
            hasGuessed = true;
            cout << "Congratulations! You've guessed the number " << secretNumber << " in " << attempts;

            if (attempts == 1) {
                cout << " attempt." << endl;
            } else {
                cout << " attempts." << endl;
            }

            cout << "Enter your name for the leaderboard: ";
            string playerName;
            cin.ignore(); // Clear newline from previous input
            getline(cin, playerName);

            string lowerPlayerName = toLowerCase(playerName);

            bool found = false;
            for (Score &score : leaderboard) {
                if (toLowerCase(score.name) == lowerPlayerName) {
                    found = true;
                    if (attempts < score.attempts) {
                        score.attempts = attempts;
                    }
                    break;
                }
            }

            if (!found) {
                Score newScore = {playerName, attempts};
                leaderboard.push_back(newScore);
            }

            sort(leaderboard.begin(), leaderboard.end(), compareScores);
            saveScores(leaderboard);

            cout << "Leaderboard:" << endl;
            for (const Score &score : leaderboard) {
                cout << score.name << ": " << score.attempts;

                if (score.attempts == 1) {
                    cout << " attempt" << endl;
                } else {
                    cout << " attempts" << endl;
                }
            }
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }
    }

    return 0;
}