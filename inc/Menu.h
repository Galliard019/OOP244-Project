/*
Citation and Sources...
Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author: João Marcos Freire de Castro
Revision History
-----------------------------------------------------------
Date      Reason
2025/3/9  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef MENU_H
#define MENU_H

#include <cstddef>
#include <iostream>
#include "Utils.h"
#include "constants.h"



namespace seneca {

class Menu;

class MenuItem {
private:
    
    char* obj_menuItemContent; // dynamically allocated content
    size_t obj_indentations{}; // number of indentations
    size_t obj_indentationSize{}; // size of each indentation in characters
    int obj_menuItemNumber{}; // numbering of MenuItem objects

    
    // Constructor, Copy Constructor and Destructor, 
    MenuItem(const char* content, size_t indentation = 0, size_t indentationSize = 4, int rowNumber = 0);
    MenuItem(const MenuItem& other) = delete;
    virtual ~MenuItem();
    

    // Display function
    std::ostream& display() const;


    // Conversion operator to bool and Copy Assignment Operator
    operator bool() const;
	MenuItem& operator=(const MenuItem& other) = delete;


    friend class Menu;

};

class Menu {
    private:
    
        size_t obj_identationsNum{};
        size_t obj_identationsSize{};
        size_t obj_menuItemNum{};
    
        MenuItem Title; // Title of the menu
        MenuItem ExitOption; // Exit option for the menu
        MenuItem SelectionPrompt; // Selection entry prompt for the menu
    
        MenuItem* MenuItems[MaximumNumberOfMenuItems]{}; // Array of MenuItem pointers
        size_t obj_menuItemCount{}; // Current count of MenuItem objects
    
    public:
    
        // Constructor with four arguments
        Menu(const char* title, const char* exitOption = "Exit", size_t indentation = 0, size_t indentationSize = 3);
    
        // Function to add a MenuItem
        bool addMenuItem(const char* content);
    
        // Destructor to clean up dynamically allocated MenuItem objects
        virtual ~Menu();
    
        // Method to display the menu and get the user's selection
        size_t select() const;
    
        // Overload << operator for Menu class
        friend size_t operator<<(std::ostream& ostr, const Menu& m);

        // Overload << operator to add MenuItem objects
        Menu& operator<<(const char* menuItemContent);
    
    };

} // namespace seneca

#endif // MENU_H


