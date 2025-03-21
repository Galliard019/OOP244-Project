#include <cstddef>
#include <iostream>
#include "../inc/Billable.h"
#include "../inc/constants.h"



namespace seneca {

class Billable {

    char* obj_name {

    };

    double obj_price {

    };
        
    
    void price(double value) {

    };

    void name(const char* name){

    };


    Billable() {

    };

    Billable(const Billable&) {

    };

    Billable& operator=(const Billable&) {

    };

    ~Billable() {

    };


    virtual double price() const {

    };

    virtual std::ostream& print(std::ostream& ostr = std::cout) const {

    };

    virtual bool order() {

    };

    virtual bool ordered() const {

    };

    virtual std::ifstream& read(std::ifstream& file) {

    };


    double operator+(double money, const Billable& B) {

    };

    double& operator+=(double& money, const Billable& B) {

    };

};

}