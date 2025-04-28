/*
File Name: Paint Estimation
Programmer: Christopher Wilson
Date: 4/25
Requirements: Create a repeatable program for a painting company where the user can enter the number of gallons of paint required, hours of labor required, the cost of the paint, labor charges and total cost of the paint job
This also includes input validation.
*/

#include <iostream>
#include <iomanip> 
using namespace std;

// ===== Function Prototypes =====
int getNumberOfRooms();
double getPricePerGallon();
double getTotalWallSpace(int rooms);
void calculateAndDisplayResults(double totalWallSpace, double pricePerGallon);
bool askToRunAgain();

// ===== Main Program =====
int main() {
    do {
        int rooms = getNumberOfRooms();
        double pricePerGallon = getPricePerGallon();
        double totalWallSpace = getTotalWallSpace(rooms);

        calculateAndDisplayResults(totalWallSpace, pricePerGallon);
    } while (askToRunAgain());

    cout << "Thank you for using the Painting Cost Estimator!\n";
    return 0;
}

// ===== Module 1: Get number of rooms =====
int getNumberOfRooms() {
    int rooms;
    cout << "Enter the number of rooms to be painted: ";
    cin >> rooms;

    while (rooms < 1) {
        cout << "Error! Number of rooms must be at least 1. Try again: ";
        cin >> rooms;
    }

    return rooms;
}

// ===== Module 2: Get price per gallon =====
double getPricePerGallon() {
    double price;
    cout << "Enter the price of the paint per gallon: $";
    cin >> price;

    while (price < 10.00) {
        cout << "Error! Price must be at least $10.00. Try again: $";
        cin >> price;
    }

    return price;
}

// ===== Module 3: Get total wall space for all rooms =====
double getTotalWallSpace(int rooms) {
    double totalWallSpace = 0.0;
    double wallSpace;

    for (int i = 1; i <= rooms; i++) {
        cout << "Enter the square feet of wall space for room #" << i << ": ";
        cin >> wallSpace;

        while (wallSpace < 0) {
            cout << "Error! Wall space cannot be negative. Try again: ";
            cin >> wallSpace;
        }

        totalWallSpace += wallSpace;
    }

    return totalWallSpace;
}

// ===== Module 4: Calculate and Display Results =====
void calculateAndDisplayResults(double totalWallSpace, double pricePerGallon) {
    const double COVERAGE_PER_GALLON = 110.0;
    const double HOURS_PER_GALLON = 8.0;
    const double LABOR_RATE_PER_HOUR = 25.00;

    double gallonsNeeded = totalWallSpace / COVERAGE_PER_GALLON;
    double laborHours = gallonsNeeded * HOURS_PER_GALLON;
    double paintCost = gallonsNeeded * pricePerGallon;
    double laborCharges = laborHours * LABOR_RATE_PER_HOUR;
    double totalCost = paintCost + laborCharges;

    cout << fixed << setprecision(2); 
    cout << "\n=== Painting Job Estimate ===\n";
    cout << "Gallons of paint required: " << gallonsNeeded << endl;
    cout << "Hours of labor required: " << laborHours << endl;
    cout << "Cost of paint: $" << paintCost << endl;
    cout << "Labor charges: $" << laborCharges << endl;
    cout << "Total cost of the paint job: $" << totalCost << endl;
    cout << "==============================" << endl;
}

// ===== Module 5: Ask if user wants to run again =====
bool askToRunAgain() {
    string choice;
    cout << "\nWould you like to estimate another paint job? (yes/no): ";
    cin >> choice;

    for (auto& c : choice) {
        c = tolower(c);
    }

    while (choice != "yes" && choice != "no") {
        cout << "Invalid input. Please enter 'yes' or 'no': ";
        cin >> choice;
        for (auto& c : choice) {
            c = tolower(c);
        }
    }

    return (choice == "yes");
}