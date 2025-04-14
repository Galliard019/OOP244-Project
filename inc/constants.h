/* Citation and Sources...
Final Project Milestone ms5
Module: constant
Filename: constant.h
Version 1.0
Author: João Marcos Freire de Castro, StNo: 173962234, Email: jmfreire-de-castro@myseneca.ca
Revision History
-----------------------------------------------------------
Date       Reason
2024/04/11 final version
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_CONSTANTS_H
#define SENECA_CONSTANTS_H

#include <cstddef>

namespace seneca {
   const int MaximumNumberOfMenuItems = 20; //I had to modify to int due to the comparisson in the MenuItem constructor
   const double Tax = 1.85;
   const size_t MaximumNumberOfBillItems = 20u;
}

#endif // !SENECA_CONSTANTS_H
