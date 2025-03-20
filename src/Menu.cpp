/*
Citation and Sources...
Milestone 1
Module: Menu
Filename: Menu.h
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

#include "Menu.h"
#include "constants.h"
#include "Utils.h"
#include <iostream>

using namespace std;

namespace seneca {


// Constructor
MenuItem::MenuItem(const char* content, size_t indentation, size_t indentationSize, int rowNumber)
: obj_indentations(indentation), obj_indentationSize(indentationSize), obj_menuItemNumber(rowNumber) {

    if (ut.isspace(content) || indentation > 4 || indentationSize > 4 || rowNumber > MaximumNumberOfMenuItems) {
        
        obj_menuItemContent = nullptr;
        obj_indentations = 0;
        obj_indentationSize = 0;
        obj_menuItemNumber = 0;

    } else {
        
        obj_menuItemContent = ut.alocpy(content);

    }

}

// Copy Constructor
/*MenuItem::MenuItem(const MenuItem& other)
: obj_indentations(other.obj_indentations), obj_indentationSize(other.obj_indentationSize), obj_menuItemNumber(other.obj_menuItemNumber) {

    obj_menuItemContent = ut.alocpy(other.obj_menuItemContent);

}*/

// Destructor
MenuItem::~MenuItem() {
    
    delete[] obj_menuItemContent;
    obj_menuItemContent = nullptr;

}


// Display function
ostream& MenuItem::display() const {
	ostream& os = cout;
    if (*this) {

        for (size_t i = 0; i < obj_indentations * obj_indentationSize; ++i) {

            os << ' ';

        }

        if (obj_menuItemNumber >= 0) {

            os.width(2);
            os << obj_menuItemNumber << "- ";

        }

        const char* content = obj_menuItemContent;

        // Skip leading whitespace in content
        while (*content && ut.isspace(*content)) {

            ++content;

        }

        os << content;

    } else {

        os << "??????????";

    }

    return os;
}


// Copy Assignment Operator
/*MenuItem& MenuItem::operator=(const MenuItem& other) {

    if (this != &other) {

        delete[] obj_menuItemContent;
        obj_indentations = other.obj_indentations;
        obj_indentationSize = other.obj_indentationSize;
        obj_menuItemNumber = other.obj_menuItemNumber;
        obj_menuItemContent = ut.alocpy(other.obj_menuItemContent);

    }

    return *this;

}*/

// Conversion operator to bool
MenuItem::operator bool() const {

    return obj_menuItemContent != nullptr;

}


// Constructor with four arguments
Menu::Menu(const char* title, const char* exitOption, size_t indentation, size_t indentationSize)
    : Title(title, indentation, indentationSize, -1),
      ExitOption(exitOption, indentation, indentationSize, 0),
      SelectionPrompt("> ", indentation, indentationSize, -1) {
    for (size_t i = 0; i < MaximumNumberOfMenuItems; ++i) {
        
        MenuItems[i] = nullptr;

    }

    obj_identationsNum = indentation;
    obj_identationsSize = indentationSize;

}

// Function to add a MenuItem
bool Menu::addMenuItem(const char* content) {
    if (obj_menuItemCount < MaximumNumberOfMenuItems) {
        
        MenuItems[obj_menuItemCount++] = new MenuItem(content);
        return true;

    }
    
    return false; // Cannot add more MenuItem objects

}

// Destructor to clean up dynamically allocated MenuItem objects
Menu::~Menu() {
    
    for (size_t i = 0; i < obj_menuItemCount; ++i) {
        
        delete MenuItems[i];
        MenuItems[i] = nullptr; // Set pointer to nullptr after deletion

    }

}

size_t Menu::select() const {
    
    // Display the title if it exists
    if (Title) {
        
        Title.display();
        std::cout << std::endl;

    }

    // Display all MenuItem objects
    for (size_t i = 0; i < obj_menuItemCount; ++i) {
        
        if (MenuItems[i]) {

            MenuItems[i]->display();
            std::cout << std::endl;

        }

    }

    // Display the exit option
    if (ExitOption) {

        ExitOption.display();
        std::cout << std::endl;

    }

    // Display the selection prompt
    if (SelectionPrompt) {

        SelectionPrompt.display();

    }

    // Get and validate user input
    size_t selection = 0;
    do {

        selection = ut.getInt(0, obj_menuItemCount);

    } while (selection > obj_menuItemCount);

    return selection;

}


// Overload << operator for Menu class
size_t operator<<(std::ostream& ostr, const Menu& m) {
    size_t rt = 0;

    if (&ostr == &std::cout) {

        rt = m.select(); // Display menu and get user selection

    }

    return rt; // Return 0 for non-cout streams

}

// Overload << operator to add MenuItem objects
Menu& Menu::operator<<(const char* menuItemContent) {

    if (obj_menuItemCount < MaximumNumberOfMenuItems) {

        MenuItems[obj_menuItemCount] = new MenuItem(
            menuItemContent, obj_identationsNum , obj_identationsSize, obj_menuItemCount + 1);
        ++obj_menuItemCount;

    }

    return *this; // Allow chaining
    
}


} // namespace seneca


// problems to fix: Title, Exitpoint and test title with number when it shouldn't, menu items not identing correctly (but the rest are apperently identing correclty)