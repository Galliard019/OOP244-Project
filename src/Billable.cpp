#include <cstddef>
#include <iostream>
#include "Billable.h"
#include "constants.h"



namespace seneca {
        
    std::ostream& Billable::print(std::ostream& ostr) const {
        // Provide implementation
        return ostr;
    }

    bool Billable::order() {
        // Provide implementation
        return false;
    }

    bool Billable::ordered() const {
        // Provide implementation
        return false;
    }

    std::ifstream& Billable::read(std::ifstream& file) {
        // Provide implementation
        return file;
    }
    
    void Billable::price(double value) {
        obj_price = value;
    };

    void Billable::name(const char* name){
        ut.alocpy(obj_name, name);
    };


    Billable::Billable() : obj_name(nullptr), obj_price(0.0) {
    };

    Billable::Billable(const Billable& B) : obj_name(nullptr), obj_price(B.obj_price) {
        if (B.obj_name) {
            ut.alocpy(obj_name, B.obj_name);
        }
    };

    Billable& Billable::operator=(const Billable& B) {
        if (this != &B) {
            obj_price = B.obj_price;
            ut.alocpy (obj_name, B.obj_name);
        }

        return *this;
    };

    Billable::~Billable() {
        delete[] obj_name;
        obj_name = nullptr;
    };


    double Billable::price() const {
        return obj_price;
    };

    double operator+(double money, const Billable& B) {
        return money + B.price();
    };

    double& operator+=(double& money, const Billable& B) {
        money += B.price();
        return money;
    };

    Billable::operator const char*() const {
        return obj_name ? obj_name : "";
    }


}