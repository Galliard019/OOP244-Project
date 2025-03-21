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

        std::ostream& print(std::ostream& ostr = std::cout) const;
        bool order();
        bool ordered() const;
        std::ifstream& read(std::ifstream& file);

        double price();

    };

} // namespace seneca

#endif // FOOD_H