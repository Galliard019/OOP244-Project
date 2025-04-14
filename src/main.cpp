/* Citation and Sources...
Final Project Milestone ms5
Module: main
Filename: main.cpp
Version 1.0
Author: João Marcos Freire de Castro, StNo: 173962234, Email: jmfreire-de-castro@myseneca.ca
Revision History
-----------------------------------------------------------
Date       Reason
2024/04/11 final version
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include <limits>
#include "Ordering.h"
#include "Menu.h"

using namespace std;
using namespace seneca;

// Function to handle foolproof input validation
int getValidatedInput(int min, int max) {
    int value;
    bool valid = false;

    while (!valid) {
        cin >> value;

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cout << "Invalid integer: ";
        } else if (cin.peek() != '\n') {
            cout << "Only an integer please: ";
        } else if (value < min || value > max) {
            cout << "Invalid value: [" << min << " <= value <= " << max << "], try again: ";
        } else {
            valid = true;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    return value;
}

int main() {

    // Initialize the Ordering object with the data files
    Ordering ordering("drinks.csv", "foods.csv");

    // Validate if the data files were loaded successfully
    if (ordering) {
        cerr << "Failed to open data files" << endl;
        return 1; // Terminate the program with an error code
    }

    // Main Menu
    Menu mainMenu("Seneca Restaurant ", "End Program", 1);
    mainMenu.addMenuItem("Order");
    mainMenu.addMenuItem("Print Bill");
    mainMenu.addMenuItem("Start a New Bill");
    mainMenu.addMenuItem("List Foods");
    mainMenu.addMenuItem("List Drinks");

    // Sub-Menu for Ordering
    Menu orderMenu("Order Menu", "Back to main menu", 1);
    orderMenu.addMenuItem("Food");
    orderMenu.addMenuItem("Drink");

    // Confirmation Menu
    Menu confirmMenu("You have bills that are not saved. Are you sure you want to exit?", "No", 1);
    confirmMenu.addMenuItem("Yes");

    bool exitProgram = false;

    while (!exitProgram) {
        //cout << "   > ";
        size_t mainSelection = mainMenu.select();
        //getValidatedInput(0, 5);

        switch (mainSelection) {
            case 1: { // Order
                orderMenu.select();
                cout << "> ";
                size_t orderSelection = getValidatedInput(0, 2);
                if (orderSelection == 1) { // Food
                    ordering.orderFood(); // Call orderFood
                } else if (orderSelection == 2) { // Drink
                    ordering.orderDrink(); // Call orderDrink
                }
                break;
            }
            case 2: { // Print Bill
                ordering.printBill(cout); // Call printBill
                break;
            }
            case 3: { // Start a New Bill
                ordering.resetBill(); // Call resetBill
                break;
            }
            case 4: { // List Foods
                ordering.listFoods(cout); // Call listFoods
                break;
            }
            case 5: { // List Drinks
                ordering.listDrinks(cout); // Call listDrinks
                break;
            }
            case 0: { // End Program
                if (ordering.hasUnsavedBill()) {
                    confirmMenu.select();
                    cout << "> ";
                    size_t confirmSelection = getValidatedInput(0, 1);
                    if (confirmSelection == 1) { // Yes
                        exitProgram = true;
                    }
                } else {
                    exitProgram = true; // No unsaved bills, exit directly
                }
                break;
            }
        }
    }

    return 0;
}
