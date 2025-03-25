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
        char obj_size = '/0';

    public:
        std::ostream& print(std::ostream& ostr = std::cout) const override;
        bool order() override;
        bool ordered() const override;
        std::ifstream& read(std::ifstream& file) override;

        double price() const override;

    };

} // namespace seneca

#endif // DRINK_H