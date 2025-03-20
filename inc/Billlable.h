#ifndef MENU_H
#define MENU_H

#include <cstddef>
#include <iostream>
#include "Utils.h"
#include "constants.h"



namespace seneca {

class Billable {
    private:
        char* m_name;
        double m_price;
        
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

        double operator+(double money, const Billable& B);
        double& operator+=(double& money, const Billable& B);

    };

} // namespace seneca

#endif // MENU_H