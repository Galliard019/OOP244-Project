/* Citation and Sources...
Final Project Milestone ms5
Module: Billable
Filename: Billable.cpp
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
#include <iostream>
#include "Billable.h"
#include "constants.h"



namespace seneca {
        
    std::ostream& Billable::print(std::ostream& ostr) const {
        // Provide implementation
        return ostr;
    }

    bool Billable::order() {
        // Provide implementation
        return false;
    }

    bool Billable::ordered() const {
        // Provide implementation
        return false;
    }

    std::ifstream& Billable::read(std::ifstream& file) {
        // Provide implementation
        return file;
    }
    
    void Billable::price(double value) {
        obj_price = value;
    };

    void Billable::name(const char* name){
        ut.alocpy(obj_name, name);
    };


    Billable::Billable() : obj_name(nullptr), obj_price(0.0) {
    };

    Billable::Billable(const Billable& B) : obj_name(nullptr), obj_price(B.obj_price) {
        if (B.obj_name) {
            ut.alocpy(obj_name, B.obj_name);
        }
    };

    Billable& Billable::operator=(const Billable& B) {
        if (this != &B) {
            obj_price = B.obj_price;
            ut.alocpy (obj_name, B.obj_name);
        }

        return *this;
    };

    Billable::~Billable() {
        delete[] obj_name;
        obj_name = nullptr;
    };


    double Billable::price() const {
        return obj_price;
    };

    double operator+(double money, const Billable& B) {
        return money + B.price();
    };

    double& operator+=(double& money, const Billable& B) {
        money += B.price();
        return money;
    };

    Billable::operator const char*() const {
        return obj_name ? obj_name : "";
    }


}