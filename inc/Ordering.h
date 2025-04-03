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

        Ordering();
        ~Ordering();

        std::ostream& billTitle(std::ostream& ostr) const;
        /* Food();
        Food(const Food&);
        Food& operator=(const Food&);
        ~Food();

        std::ostream& print(std::ostream& ostr = std::cout) const override;
        bool order() override;
        bool ordered() const override;
        std::ifstream& read(std::ifstream& file) override;

        double price() const override; */

    };

} // namespace seneca

#endif // ORDERING_H