#include <cstddef>
#include <iostream>
#include "../inc/Billable.h"
#include "../inc/constants.h"



namespace seneca {
        
    
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


    double Billable::operator+(double money) const {
        return money + price();
    };

    double& Billable::operator+=(double& money) const {
        money += price();
        return money;
    };

    Billable::operator const char*() const {
        return obj_name ? obj_name : "";
    }


}