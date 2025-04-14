/* Citation and Sources...
Final Project Milestone ms5
Module: Ordering
Filename: Ordering.h
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

#ifndef ORDERING_H
#define ORDERING_H

#include <cstddef>
#include <iostream>
#include "Utils.h"
#include "constants.h"
#include "Billable.h"
#include "Food.h"
#include "Drink.h"



namespace seneca {

class Ordering {
    private:
        size_t obj_foodCounter;
        size_t obj_drinkCounter;
        size_t obj_billableCounter;

        size_t obj_billNumber;

        Food* obj_foodArray;   // Dynamic array of Food items
        Drink* obj_drinkArray; // Dynamic array of Drink items

        Billable* obj_billItems[MaximumNumberOfBillItems]; // Array of Billable pointers

    public:

        Ordering(const char* drinksFile, const char* foodsFile);
        ~Ordering();

        std::ostream& billTitle(std::ostream& ostr) const;
        std::ostream& billFooter(std::ostream& ostr, double totalDue) const;
        size_t countRecords(const char* file) const;

        operator bool() const;
        size_t noOfBillItems() const;
        bool hasUnsavedBill() const;

        std::ostream& listFoods(std::ostream& ostr = std::cout) const;
        std::ostream& listDrinks(std::ostream& ostr = std::cout) const;
        std::ostream& ListDrinks(std::ostream& ostr = std::cout) const;
        bool orderFood();
        bool orderDrink();
        std::ostream& printBill(std::ostream& ostr) const;
        void resetBill();

    };

} // namespace seneca

#endif // ORDERING_H