/*
File Name: Rock Paper Scissors 3
Programmer: Christopher Wilson
Date: 4/25
Requirements: Create a program that plays rock paper scissors with the user
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>

using namespace std;

// ===== Module 1: Handles file operations (load, save, delete) =====

// Loads existing scores from the file into a map
void loadScores(map<string, int>& scores) {
    ifstream file("scores.txt");
    string name;
    int score;

    while (file >> name >> score) {
        scores[name] = score;
    }

    file.close();
}

// Saves all scores back into the file
void saveScores(const map<string, int>& scores) {
    ofstream file("scores.txt");

    for (const auto& entry : scores) {
        file << entry.first << " " << entry.second << endl;
    }

    file.close();
}

// Clears the file (deletes all scores)
void clearScores() {
    ofstream file("scores.txt", ios::trunc); // Open and immediately truncate
    file.close();
    cout << "All scores have been deleted.\n";
}

// ===== Module 2: Game play logic =====

// Returns the computer's random choice
string getComputerChoice() {
    int randomNum = rand() % 3 + 1;
    if (randomNum == 1)
        return "rock";
    else if (randomNum == 2)
        return "paper";
    else
        return "scissors";
}

// Prompts the user for their choice
string getUserChoice() {
    string choice;
    cout << "Enter your choice (rock, paper, or scissors): ";
    cin >> choice;

    for (auto& c : choice) {
        c = tolower(c);
    }

    while (choice != "rock" && choice != "paper" && choice != "scissors") {
        cout << "Invalid input. Please enter rock, paper, or scissors: ";
        cin >> choice;
        for (auto& c : choice) {
            c = tolower(c);
        }
    }
    return choice;
}

// Determines and announces the winner
string determineWinner(string userChoice, string computerChoice) {
    cout << "Computer chose: " << computerChoice << endl;

    if (userChoice == computerChoice) {
        cout << "It's a tie! Play again.\n" << endl;
        return "tie";
    }
    else if ((userChoice == "rock" && computerChoice == "scissors") ||
        (userChoice == "scissors" && computerChoice == "paper") ||
        (userChoice == "paper" && computerChoice == "rock")) {
        cout << "You win this round!" << endl;
        return "user";
    }
    else {
        cout << "Computer wins this round!" << endl;
        return "computer";
    }
}

// Runs a full game session for a player
void playGame(map<string, int>& scores) {
    string playerName;
    cout << "Please enter your name: ";
    cin >> playerName;

    int playerWins = 0;
    bool doAgain = true;
    string answer;

    do {
        string userChoice = getUserChoice();
        string computerChoice = getComputerChoice();
        string winner = determineWinner(userChoice, computerChoice);

        if (winner == "user") {
            playerWins++;
        }

        cout << "Do you want to play again? (yes/no): ";
        cin >> answer;
        for (auto& c : answer) c = tolower(c);
        doAgain = (answer == "yes");

    } while (doAgain);

    cout << "Total wins for " << playerName << ": " << playerWins << endl;

    // Update the best score if this session's wins are higher
    if (scores.find(playerName) == scores.end() || playerWins > scores[playerName]) {
        scores[playerName] = playerWins;
    }

    saveScores(scores); // Save updated scores
}

// ===== Module 3: Main module with menu =====

void showMenu() {
    cout << "\n=== Rock, Paper, Scissors Menu ===\n";
    cout << "1. Show previous scores\n";
    cout << "2. Start a new game\n";
    cout << "3. Delete all scores\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    srand(time(0)); // Seed random number generator
    map<string, int> scores;
    int choice;

    loadScores(scores);

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n--- Previous Scores ---\n";
            for (const auto& entry : scores) {
                cout << "Player: " << entry.first << " | Best Wins: " << entry.second << endl;
            }
            break;
        case 2:
            playGame(scores);
            break;
        case 3:
            clearScores();
            scores.clear(); // Also clear from memory
            break;
        case 4:
            cout << "Thank you for playing!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
