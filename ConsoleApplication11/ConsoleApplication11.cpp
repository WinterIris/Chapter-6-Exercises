/*
File Name: Rock Paper Scissors 2
Programmer: Christopher Wilson
Date: 4/25
Requirements: Create a program that plays rock paper scissors with the user
*/

#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <string>

using namespace std;


string getComputerChoice() {
    int randomNum = rand() % 3 + 1; 
    if (randomNum == 1)
        return "rock";
    else if (randomNum == 2)
        return "paper";
    else
        return "scissors";
}


string getUserChoice() {
    string choice;
    cout << "Enter your choice (rock, paper, or scissors): ";
    cin >> choice;

    // Convert to lowercase
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


bool askToPlayAgain() {
    string answer;
    cout << "\nDo you want to play again? (yes/no): ";
    cin >> answer;

    // Convert to lowercase
    for (auto& c : answer) {
        c = tolower(c);
    }

    while (answer != "yes" && answer != "no") {
        cout << "Invalid input. Please enter 'yes' or 'no': ";
        cin >> answer;
        for (auto& c : answer) {
            c = tolower(c);
        }
    }

    return (answer == "yes");
}


void playGame(const string& playerName) {
    int playerWins = 0;
    bool doAgain = true;

    while (doAgain) {
        string userChoice = getUserChoice();
        string computerChoice = getComputerChoice();
        string winner = determineWinner(userChoice, computerChoice);

        if (winner == "user") {
            playerWins++;
        }

        doAgain = askToPlayAgain();
    }

    cout << "\nThanks for playing, " << playerName << "!" << endl;
    cout << "Total games you won: " << playerWins << endl;
}

int main() {
    srand(time(0)); 

    string playerName;
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "Please enter your name: ";
    getline(cin, playerName);

    playGame(playerName);

    return 0;
}
