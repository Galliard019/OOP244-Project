/* Citation and Sources...
Final Project Milestone ms5
Module: Food
Filename: Food.h
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

#ifndef FOOD_H
#define FOOD_H

#include <cstddef>
#include <iostream>
#include "Utils.h"
#include "constants.h"
#include "Billable.h"



namespace seneca {

class Food : public Billable {
    private:
        bool obj_ordered;
        bool obj_child;
        char* obj_customize = nullptr;

    public:
        Food();
        Food(const Food&);
        Food& operator=(const Food&);
        ~Food();

        std::ostream& print(std::ostream& ostr = std::cout) const override;
        bool order() override;
        bool ordered() const override;
        std::ifstream& read(std::ifstream& file) override;

        double price() const override;

    };

} // namespace seneca

#endif // FOOD_H