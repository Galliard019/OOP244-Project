#include <cstddef>
#include <iostream>
#include "../inc/Utils.h"
#include "../inc/constants.h"
#include "../inc/Billable.h"



namespace seneca {

class Food : public Billable {

        bool obj_ordered;
        bool obj_child;
        char* obj_customize = nullptr;


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

}