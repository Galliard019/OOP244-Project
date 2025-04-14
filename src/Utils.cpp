/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.1
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utils.h"
#include <sstream>
#include <string>
using namespace std;
namespace seneca {
   Utils ut;

   char* Utils::alocpy(const char* src) const{
      char* des{};
      return alocpy(des, src);
   }

   char* Utils::alocpy(char*& des, const char* src)const {
      delete[] des;
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1];
         strcpy(des, src);
      }
      return des;
   }
   char* Utils::strcpy(char* des, const char* src)const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }
   int Utils::strlen(const char* str)const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   bool Utils::isspace(char ch)const {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

   bool Utils::isspace(const char* cstring) const{
      while (cstring && isspace(*cstring)) {
         cstring++;
      }
      return cstring && *cstring == 0;
   }

   int Utils::getInt() {
      int value;
      bool valid = false;
      while (!valid) {
         string input;
         getline(cin, input);

         if (input.empty()) {
            std::cout << "You must enter a value: ";
            continue;
         }

         istringstream iss(input);
         iss >> value;

         if (iss.fail() || !iss.eof()) {
            std::cout << (iss.fail() ? "Invalid integer: " : "Only an integer please: ");
            iss.clear();
         } else {
            valid = true;
         }
      }
      return value;
   }

   int Utils::getInt(int min, int max) {
      int value;
      do {
         value = getInt();
         if (value < min || value > max) {
            std::cout << "Invalid value: [" << min << " <= value <= " << max << "], try again: ";
         }
      } while (value < min || value > max);
      return value;
   }

   char* Utils::makeBillFileName(char* filename, size_t billNo)const {
      char billFileName[21] = "bill_";
      size_t temp = billNo;
      int cnt = 5;
      int length;
      // Calculate the number of digits
      do {
         cnt++;
         temp /= 10;
      } while (temp > 0);
      length = cnt;
      // Convert each digit to character from the end
      while (billNo > 0) {
         billFileName[--cnt] = (billNo % 10) + '0';
         billNo /= 10;
      }
      // Handle the case when billNo is 0
      if (billFileName[cnt - 1] == '\0') {
         billFileName[--cnt] = '0';
      }
      // Attach .txt to the end of the file name
      for (int i = 0; ".txt"[i]; i++) {
         billFileName[length++] = ".txt"[i];
      }
      billFileName[length] = '\0';
      strcpy(filename, billFileName);
      return filename;
   }

   std::string Utils::trim(const std::string& str) {
      size_t start = str.find_first_not_of(" \t");
      size_t end = str.find_last_not_of(" \t");
      return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
   }
  

}