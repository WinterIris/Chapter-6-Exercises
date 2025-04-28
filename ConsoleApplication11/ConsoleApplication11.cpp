/*
File Name: Rock Paper Scissors
Programmer: Christopher Wilson
Date: 4/25
Requirements: Create a program that plays rock paper scissors with the user
*/

#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <string>
#include <algorithm>

using namespace std;

// Function prototypes
string getComputerChoice();
string getUserChoice();
string determineWinner(const string& userChoice, const string& computerChoice);
void displayResult(const string& winner, const string& computerChoice);
void playRound();
void toLowerCase(string& input);
bool isValidChoice(const string& choice);

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    playRound();
    return 0;
}

// Gets a random choice for the computer
string getComputerChoice() {
    int randomNum = rand() % 3; // 0, 1, 2
    const string choices[3] = { "rock", "paper", "scissors" };
    return choices[randomNum];
}

// Gets and validates the user's choice
string getUserChoice() {
    string choice;
    cout << "Enter your choice (rock, paper, or scissors): ";
    cin >> choice;
    toLowerCase(choice);

    while (!isValidChoice(choice)) {
        cout << "Invalid input. Please enter rock, paper, or scissors: ";
        cin >> choice;
        toLowerCase(choice);
    }
    return choice;
}

// Converts a string to lowercase
void toLowerCase(string& input) {
    transform(input.begin(), input.end(), input.begin(), ::tolower);
}

// Checks if the choice is valid
bool isValidChoice(const string& choice) {
    return choice == "rock" || choice == "paper" || choice == "scissors";
}

// Determines the winner based on choices
string determineWinner(const string& userChoice, const string& computerChoice) {
    if (userChoice == computerChoice) {
        return "tie";
    }
    else if ((userChoice == "rock" && computerChoice == "scissors") ||
        (userChoice == "scissors" && computerChoice == "paper") ||
        (userChoice == "paper" && computerChoice == "rock")) {
        return "user";
    }
    else {
        return "computer";
    }
}

// Displays the result of the round
void displayResult(const string& winner, const string& computerChoice) {
    cout << "Computer chose: " << computerChoice << endl;
    if (winner == "tie") {
        cout << "It's a tie! Play again.\n" << endl;
    }
    else if (winner == "user") {
        cout << "You win!" << endl;
    }
    else {
        cout << "Computer wins!" << endl;
    }
}

// Plays rounds until there is a winner (no tie)
void playRound() {
    string winner = "tie";
    while (winner == "tie") {
        string userChoice = getUserChoice();
        string computerChoice = getComputerChoice();
        winner = determineWinner(userChoice, computerChoice);
        displayResult(winner, computerChoice);
    }
}
