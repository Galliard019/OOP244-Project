#ifndef BILLABLE_H
#define BILLABLE_H

#include <cstddef>
#include <iostream>
#include "Utils.h"
#include "constants.h"



namespace seneca {

class Billable {
    private:
        char* obj_name;
        double obj_price;
        
    protected:
        void price(double value);
        void name(const char* name);

    public:
        Billable();
        Billable(const Billable&);
        Billable& operator=(const Billable&);
        ~Billable();

        virtual double price() const;
        virtual std::ostream& print(std::ostream& ostr = std::cout) const;
        virtual bool order();
        virtual bool ordered() const;
        virtual std::ifstream& read(std::ifstream& file);

        friend double operator+(double money, const Billable& B);
        friend double& operator+=(double& money, const Billable& B);
        operator const char*() const;

    };

} // namespace seneca

#endif // BILLABLE_H