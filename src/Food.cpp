#include <cstddef>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "constants.h"
#include "Billable.h"
#include "Food.h"



namespace seneca {


        Food::Food() {
                obj_customize = nullptr;
                obj_ordered = false;
                obj_child = false;
        };

        Food::Food(const Food& F) : obj_ordered(F.obj_ordered), obj_child(F.obj_child) {
                *this = F;
        };

        Food& Food::operator=(const Food& F) {
                if (this != &F) {
                        (Billable&) *this = F;
                        ut.alocpy (obj_customize, F.obj_customize);
                        obj_ordered = F.obj_ordered;
                        obj_child = F.obj_child;
                }
                return *this;
        };

        Food::~Food() {
                delete[] obj_customize;
                obj_customize = nullptr;
        };

        std::ostream& Food::print(std::ostream& ostr) const {
                // Print name
                ostr << std::left << std::setw(28) << std::setfill('.')
                     << ((*this) ? (*this) : "Unnamed");

                // Print portion type
                if (ordered()) {
                    ostr << (obj_child ? "Child" : "Adult");
                } else {
                    ostr << ".....";
                }

                // Print price (right-justified, 7 spaces, 2 decimal places)
                ostr << std::right << std::setw(7) << std::setfill(' ')
                     << std::fixed << std::setprecision(2) << price();

                // Print customizations if ostream is cout and obj_customize is not null
                if (&ostr == &std::cout && obj_customize) {
                    ostr << " >> " << std::string(obj_customize).substr(0, 30);
                }

                return ostr;
        };

        bool Food::order() {
                char selection;
                bool valid = false;
    
                std::cout << "         Food Size Selection" << std::endl;
                std::cout << "          1- Adult" << std::endl;
                std::cout << "          2- Child" << std::endl;
                std::cout << "          0- Back" << std::endl;
                std::cout << "         > ";
                std::cin >> selection;
    
                switch (toupper(selection)) {
                    case '1':
                        obj_child = false; // Adult portion
                        obj_ordered = true;
                        valid = true;
                        break;
                    case '2':
                        obj_child = true; // Child portion
                        obj_ordered = true;
                        valid = true;
                        break;
                    case '0':
                        obj_ordered = false; // Back
                        delete[] obj_customize;
                        obj_customize = nullptr;
                        return false;
                        break;
                    default:
                        std::cout << "Invalid selection. Try again." << std::endl;
                        obj_ordered = false;
                        break;
                }
    
                if (valid) {
                    // Prompt for customization
                    std::string customization;
                    std::cout << "Special instructions\n> ";
                    std::cin.ignore(); // Clear input buffer
                    std::getline(std::cin, customization);
    
                    if (customization.empty()) {
                        delete[] obj_customize;
                        obj_customize = nullptr;
                    } else {
                        ut.alocpy(obj_customize, customization.c_str());
                    }
                }

            return true;
        };

        bool Food::ordered() const {
                return obj_ordered;
        };

        std::ifstream& Food::read(std::ifstream& file) {
                char buffer_name[256];
                double buffer_price;

                file.getline(buffer_name, 256, ',');
                if (file.fail()) {
                        return file;
                } 
                else {
                        file >> buffer_price;
                        file.ignore(1000, '\n');
                        Billable::name(buffer_name);
                        Billable::price(buffer_price);

                        obj_child = false;
                        obj_ordered = false;
                        delete[] obj_customize;
                        obj_customize = nullptr;

                }
                return file;
        };

        

        double Food::price() const{
                if (obj_child && ordered()) {
                        return Billable::price() / 2;
                } else {
                        return Billable::price();
                }
        };


}