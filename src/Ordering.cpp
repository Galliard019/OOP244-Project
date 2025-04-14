/* Citation and Sources...
Final Project Milestone ms5
Module: Ordering
Filename: Ordering.cpp
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

#include <cstddef>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "constants.h"
#include "Ordering.h"
#include "Menu.h"



namespace seneca {

    std::ostream& Ordering::billTitle(std::ostream& ostr) const {
        ostr << "Bill # " << std::setw(3) << std::setfill('0') << obj_billNumber
             << " =============================" << std::endl;
        return ostr;
    };

    std::ostream& Ordering::billFooter(std::ostream& ostr, double totalDue) const {
        double grandTotal = totalDue + Tax;
        
        ostr << std::setw(21) << std::setfill(' ') << "" << "Total:        " 
             << std::fixed << std::setprecision(2) << totalDue << std::endl;

        ostr << std::setw(21) << std::setfill(' ') << "" << "Tax:           " 
             << std::fixed << std::setprecision(2) << Tax << std::endl;

        ostr << std::setw(21) << std::setfill(' ') << "" << "Total+Tax:    " 
             << std::fixed << std::setprecision(2) << grandTotal << std::endl;

        ostr << "========================================" << std::endl;

        return ostr;

    };

    size_t Ordering::countRecords(const char* file) const {
        size_t newlineCounter = 0;
        std::ifstream inputFile(file);

        if (!inputFile) {
            std::cerr << "Error: Unable to open file: " << file << std::endl;
            return 0;
        }

        char ch;
        while (inputFile.get(ch)) { // Read one character at a time
            if (ch == '\n') { // Check if the character is a newline
                newlineCounter++;
            }
        }

        return newlineCounter;
    };

    Ordering::Ordering(const char* drinksFile, const char* foodsFile)
        : obj_foodCounter(0), obj_drinkCounter(0), obj_billableCounter(0),
          obj_billNumber(1), obj_foodArray(nullptr), obj_drinkArray(nullptr) {
        
        size_t drinkRecords = countRecords(drinksFile);
        size_t foodRecords = countRecords(foodsFile);

        // Open the files for reading
        std::ifstream drinksInput(drinksFile);
        std::ifstream foodsInput(foodsFile);

        if (!drinksInput || !foodsInput) {
            std::cerr << "Error: Unable to open one or both files." << std::endl;
            return;
        }

        obj_drinkArray = new Drink[drinkRecords];
        obj_foodArray = new Food[foodRecords];

        // Read drinks data
        size_t drinksRead = 0;
        for (size_t i = 0; i < drinkRecords; ++i) {
            if (obj_drinkArray[i].read(drinksInput)) {
                drinksRead++;
            } else {
                break;
            }
        }

        // Read foods data
        size_t foodsRead = 0;
        for (size_t i = 0; i < foodRecords; ++i) {
            if (obj_foodArray[i].read(foodsInput)) {
                foodsRead++;
            } else {
                break;
            }
        }

        // Validate the number of records read
        if (drinksRead != drinkRecords || foodsRead != foodRecords) {
            delete[] obj_drinkArray;
            delete[] obj_foodArray;
            obj_drinkArray = nullptr;
            obj_foodArray = nullptr;
            std::cerr << "Error: Failed to read all records from files." << std::endl;
        } else {
            obj_drinkCounter = drinksRead;
            obj_foodCounter = foodsRead;
        }
    };

    Ordering::~Ordering() {
        delete[] obj_foodArray;
        obj_foodArray = nullptr; // Set pointer to nullptr for safety

        delete[] obj_drinkArray;
        obj_drinkArray = nullptr; // Set pointer to nullptr for safety

        for (size_t i = 0; i < obj_billableCounter; ++i) {
            delete obj_billItems[i];
            obj_billItems[i] = nullptr; // Set pointer to nullptr for safety
        }
    };

    Ordering::operator bool() const {
        return obj_drinkArray == nullptr && obj_foodArray == nullptr;
    };

    size_t Ordering::noOfBillItems() const {
        return obj_billableCounter;
    };

    bool Ordering::hasUnsavedBill() const {
        return obj_billableCounter > 0;
    };

    std::ostream& Ordering::listFoods(std::ostream& ostr) const {
        ostr << "List Of Avaiable Meals" << std::endl;
        ostr << "========================================" << std::endl;

        // Loop through the foods array and print each item
        for (size_t i = 0; i < obj_foodCounter; ++i) {
            // ostr << i + 1 << ". "; // Print the index (1-based)
            obj_foodArray[i].print(ostr) << std::endl;
        }

        ostr << "========================================" << std::endl;

        return ostr;
    }

    std::ostream& Ordering::listDrinks(std::ostream& ostr) const {
        ostr << "List Of Avaiable Drinks" << std::endl;
        ostr << "========================================" << std::endl;

        // Loop through the drinks array and print each item
        for (size_t i = 0; i < obj_drinkCounter; ++i) {
            // ostr << i + 1 << ". "; // Print the index (1-based)
            obj_drinkArray[i].print(ostr) << std::endl;
        }

        ostr << "========================================" << std::endl;

        return ostr;
    };

    std::ostream& Ordering::ListDrinks(std::ostream& ostr) const {
        ostr << "List Of Avaiable Drinks" << std::endl;
        ostr << "========================================" << std::endl;

        // Loop through the drinks array and print each item
        for (size_t i = 0; i < obj_drinkCounter; ++i) {
            // ostr << i + 1 << ". "; // Print the index (1-based)
            obj_drinkArray[i].print(ostr) << std::endl;
        }

        ostr << "========================================" << std::endl;

        return ostr;
    };

    bool Ordering::orderFood() {
        Menu foodMenu("Food Menu", "Back to Order", 2);

        // Populate the menu with food items
        for (size_t i = 0; i < obj_foodCounter; ++i) {
            foodMenu.addMenuItem(static_cast<const char*>(obj_foodArray[i]));
        }

        // Display the menu and get the waiter's selection
        size_t selection = foodMenu.select();

        if (selection != 0) { // If the selection is not "Back to Order"
            // Create a dynamic copy of the selected food item
            Food* selectedFood = new Food(obj_foodArray[selection - 1]);

            // Assign it to the next available element in the Bill Items array
            obj_billItems[obj_billableCounter] = selectedFood;

            // Call the order method to customize the order
            if (selectedFood->order()) {
                ++obj_billableCounter; // Increment the number of bill items
                return true;
            } else {
                // Revert the operation if order fails
                delete selectedFood;
                obj_billItems[obj_billableCounter] = nullptr;
            }
        }

        return false;
    }

    bool Ordering::orderDrink() {
        Menu drinkMenu("Drink Menu", "Back to Order", 2);

        // Populate the menu with drink items
        for (size_t i = 0; i < obj_drinkCounter; ++i) {
            drinkMenu.addMenuItem(static_cast<const char*>(obj_drinkArray[i]));
        }

        // Display the menu and get the waiter's selection
        size_t selection = drinkMenu.select();

        if (selection != 0) { // If the selection is not "Back to Order"
            // Create a dynamic copy of the selected drink item
            Drink* selectedDrink = new Drink(obj_drinkArray[selection - 1]);

            // Assign it to the next available element in the Bill Items array
            obj_billItems[obj_billableCounter] = selectedDrink;

            // Call the order method to customize the order
            if (selectedDrink->order()) {
                ++obj_billableCounter; // Increment the number of bill items
                return true;
            } else {
                // Revert the operation if order fails
                delete selectedDrink;
                obj_billItems[obj_billableCounter] = nullptr;
            }
        }

        return false;
    }

    std::ostream& Ordering::printBill(std::ostream& ostr) const {
        double totalPrice = 0.0;

        billTitle(ostr);

        // Loop through the Bill Items array and print each item
        for (size_t i = 0; i < obj_billableCounter; ++i) {
            obj_billItems[i]->print(ostr) << std::endl; // Print each item
            totalPrice += obj_billItems[i]->price();    // Add the price of the item to the total
        }

        billFooter(ostr, totalPrice);

        return ostr;
    };

    void Ordering::resetBill() {
        char billFileName[256];
        ut.makeBillFileName(billFileName, obj_billNumber);

        // Open a file for writing using the generated file name
        std::ofstream billFile(billFileName);
        if (!billFile) {
            std::cerr << "Error: Unable to open file for writing: " << billFileName << std::endl;
            return;
        }

        printBill(billFile);

        std::cout << "Saved bill number " << obj_billNumber << std::endl;
        std::cout << "Starting bill number " << (obj_billNumber + 1) << std::endl;

        // Delete all dynamically created elements in the Bill Items array
        for (size_t i = 0; i < obj_billableCounter; ++i) {
            delete obj_billItems[i];
            obj_billItems[i] = nullptr; // Set pointer to nullptr for safety
        }

        obj_billNumber++;

        obj_billableCounter = 0;
    };



    

}