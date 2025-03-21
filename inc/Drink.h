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
        char* obj_size = nullptr;

    public:
        std::ostream& print(std::ostream& ostr = std::cout) const;
        bool order();
        bool ordered() const;
        std::ifstream& read(std::ifstream& file);

        double price();

    };

} // namespace seneca

#endif // DRINK_H