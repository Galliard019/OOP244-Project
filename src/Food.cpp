#include <cstddef>
#include <iostream>
#include "../inc/Utils.h"
#include "../inc/constants.h"
#include "../inc/Billable.h"
#include "../inc/Food.h"



namespace seneca {


        Food::Food() {

        };

        Food::Food(const Food&) {

        };

        Food& Food::operator=(const Food&) {

        };

        Food::~Food() {

        };

        std::ostream& Food::print(std::ostream& ostr = std::cout) const {

        };

        bool Food::order() {

        };

        bool Food::ordered() const {

        };

        std::ifstream& Food::read(std::ifstream& file) {

        };

        double Food::price() {

        };


}