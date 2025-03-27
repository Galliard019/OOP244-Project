#include <cstddef>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "../inc/Utils.h"
#include "../inc/constants.h"
#include "../inc/Billable.h"
#include "../inc/Food.h"



namespace seneca {


        Food::Food() {
                obj_customize = nullptr;
        };

        Food::Food(const Food& F) : obj_ordered(F.obj_ordered), obj_child(F.obj_child) {
                if(obj_customize) {
                        ut.alocpy(obj_customize, F.obj_customize);
                }
        };

        Food& Food::operator=(const Food& F) {
                if (this != &F) {
                        ut.alocpy (obj_customize, F.obj_customize);
                        obj_ordered = F.obj_ordered;
                        obj_child = F.obj_child;
                }
        };

        Food::~Food() {
                delete[] obj_customize;
                obj_customize = nullptr;
        };

        std::ostream& Food::print(std::ostream& ostr = std::cout) const {
                // Print name
                ostr << std::left << std::setw(28) << std::setfill('.')
                     << (static_cast<const char*>(*this) ? static_cast<const char*>(*this) : "Unnamed");

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
            char portion;
            std::string customization;

            // Display menu for portion selection
            std::cout << "   Select portion size:\n"
                      << "      1- Child\n"
                      << "      2- Adult\n"
                      << "      0- Back\n"
                      << "   > ";
            std::cin >> portion;
            portion = std::toupper(portion);

            // Handle portion selection
            if (portion == '0') {
                obj_ordered = false;
                delete[] obj_customize;
                obj_customize = nullptr;
                return false;
            }

            if (portion == '1' || portion == '2') {
                obj_child = (portion == '1');
                obj_ordered = true;
            } else {
                std::cout << "Invalid selection. Order canceled.\n";
                obj_ordered = false;
                return false;
            }

            // Prompt for customization
            std::cout << "   Special instructions\n   > ";
            std::cin.ignore(); // Clear input buffer
            std::getline(std::cin, customization);

            if (customization.empty()) {
                delete[] obj_customize;
                obj_customize = nullptr;
            } else {
                ut.alocpy(obj_customize, customization.c_str());
            }

            return true;
        };

        bool Food::ordered() const {
                return obj_ordered;
        };

        std::ifstream& Food::read(std::ifstream& file) {
                char buffer_name[256];
                double buffer_price;

                if (file.getline(buffer_name, 256, ',') && file >> buffer_price)  {
                        file.ignore();
                        name(buffer_name);
                        Billable::price(buffer_price);

                        obj_child = false;
                        obj_ordered = false;
                        obj_customize = nullptr;
                }
                return file;
        };

        

        double Food::price() const{
                double priceRT;
                if (obj_child && obj_ordered) {
                        priceRT = Billable::price() / 2;
                } else {
                        priceRT = Billable::price();
                }

                return priceRT;
        };


}