/* Citation and Sources...
Final Project Milestone ms5
Module: Drink
Filename: Drink.h
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

#ifndef DRINK_H
#define DRINK_H

#include <cstddef>
#include <iostream>
#include "Utils.h"
#include "constants.h"
#include "Billable.h"



namespace seneca {

class Drink : public Billable {
    private:
        char obj_size = '\0';

    public:
        std::ostream& print(std::ostream& ostr = std::cout) const override;
        bool order() override;
        bool ordered() const override;
        std::ifstream& read(std::ifstream& file) override;

        double price() const override;

    };

} // namespace seneca

#endif // DRINK_H