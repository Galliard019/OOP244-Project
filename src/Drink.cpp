#include <cstddef>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "constants.h"
#include "Billable.h"
#include "Drink.h"



namespace seneca {

    
    std::ostream& Drink::print(std::ostream& ostr) const {
        ostr << std::left << std::setw(28) << std::setfill('.') 
             << (static_cast<const char*>(*this) ? static_cast<const char*>(*this) : "Unnamed");

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
        char selection;
        bool valid = false;

        std::cout << "         Drink Size Selection" << std::endl;
        std::cout << "          1- Small" << std::endl;
        std::cout << "          2- Medium" << std::endl;
        std::cout << "          3- Larg" << std::endl;
        std::cout << "          4- Extra Large" << std::endl;
        std::cout << "          0- Back" << std::endl;
        std::cout << "         > ";
        std::cin >> selection;

        switch (toupper(selection)) {
            case '1':
            obj_size = 'S';
                valid = true;
                break;
            case '2':
                obj_size = 'M';
                valid = true;
                break;
            case '3':
                obj_size = 'L';
                valid = true;
                break;
            case '4':
                obj_size = 'X';
                valid = true;
                break;
                obj_size = toupper(selection);
                valid = true;
                break;
            case '0':
                obj_size = '\0';
                break;
            default:
                std::cout << "Invalid selection. Try again." << std::endl;
                obj_size = '\0';
                break;
        }

        return valid;
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
            Billable::price(buffer_price);
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

}