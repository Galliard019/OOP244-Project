#include <cstddef>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "constants.h"
#include "Ordering.h"



namespace seneca {

    std::ostream& Ordering::billTitle(std::ostream& ostr) const {
        ostr << "Bill # " << std::setw(3) << std::setfill('0') << obj_billNumber
             << " =============================" << std::endl;
        return ostr;
    }

    

}