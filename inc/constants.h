#ifndef SENECA_CONSTANTS_H
#define SENECA_CONSTANTS_H

#include <cstddef>

namespace seneca {
   const int MaximumNumberOfMenuItems = 20; //I had to modify to int due to the comparisson in the MenuItem constructor
   const double Tax = 0.13;
   const size_t MaximumNumberOfBillItems = 20u;
}

#endif // !SENECA_CONSTANTS_H
