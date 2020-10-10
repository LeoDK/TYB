#include "doomsday.h"
#include <iostream>

int main ()
{
    Date date = Date (10,10,2020);
    std::cout << (int)date.getDay() << "/" << (int)date.getMonth() << "/" << date.getYear() << std::endl;
    std::cout << (int)date.computeDay() << std::endl;
    return 0;
}
