#include <cstddef>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "../inc/Utils.h"
#include "../inc/constants.h"
#include "../inc/Billable.h"
#include "../inc/Drink.h"



namespace seneca {

    
    std::ostream& Drink::print(std::ostream& ostr = std::cout) const {
        ostr << std::left << std::setw(28) << std::setfill('.') 
             << (obj_name ? obj_name : "Unnamed");

        // Print size
        if (ordered()) {
            switch (obj_size) {
                case 'S': ostr << "SML.."; break;
                case 'M': ostr << "MID.."; break;
                case 'L': ostr << "LRG.."; break;
                case 'X': ostr << "XLR.."; break;
            }
        } else {
            ostr << ".....";
        }

        // Print price (right-justified, 7 spaces, 2 decimal places)
        ostr << std::right << std::setw(7) << std::setfill(' ') 
             << std::fixed << std::setprecision(2) << price();

        return ostr;
    };

    bool Drink::order() {
        
    };

    bool Drink::ordered() const {
        return obj_size != '\0';
    };

    std::ifstream& Drink::read(std::ifstream& file) {
        char buffer_name[256];
        double buffer_price;

        if (file.getline(buffer_name, 256, ',') && file >> buffer_price) {
            file.ignore();
            name(buffer_name);
            price();
            obj_size = '\0';
        }

        return file;
    };

    double Drink::price() const {
        if (!ordered() || obj_size == 'L') {
            return Billable::price();
        }

        switch (obj_size) {
            case 'S': return Billable::price() * 0.5; // Small: Half price
            case 'M': return Billable::price() * 0.75; // Medium: 3/4 price
            case 'X': return Billable::price() * 1.5; // Extra Large: 1.5x price
            default: return Billable::price();
        }
    }

    };


}