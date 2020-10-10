#include "doomsday.h"
#include <stdexcept>

Date::Date (char d_, char m_, int y_)
    : d(d_), m(m_), y(y_)
{
    MONTHS = DEF_MONTHS;
    if (y%4 == 0)
        MONTHS[1] = 29;
    if (!check())
        throw std::invalid_argument("Invalid date");
}

char Date::computeDay () const
{
    char dec = y%100;
    int cent = y/100;
    char s = (9 - cent%4)%7;
    char q = dec / 12;
    char r = dec % 12;
    char b = r/4;
    char pivot = (s+q+r+b)%7;
    char ret = 0;
    switch (m)
    {
    case (1):
        if (y%4 == 0)
            return (pivot+d+4)%7;
        ret = (pivot+d+3)%7;
        break;
    case (2):
        ret = (pivot + d - MONTHS[2] + 35)%7;
        break;
    case (3):
        ret = (pivot + d)%7;
        break;
    case (4):
        ret = (pivot + d + 3)%7;
        break;
    case (5):
        ret = (pivot + d + 5)%7;
        break;
    case (6):
        ret = (pivot + d + 1)%7;
        break;
    case (7):
        ret = (pivot + d + 3)%7;
        break;
    case (8):
        ret = (pivot + d + 6)%7;
        break;
    case (9):
        ret = (pivot + d + 2)%7;
        break;
    case (10):
        ret = (pivot + d + 4)%7;
        break;
    case (11):
        ret = (pivot + d)%7;
        break;
    case (12):
        ret = (pivot + d + 2)%7;
        break;
    }
    return ret;
}

bool Date::check () const
{
    bool ret = true;
    ret = ret && (1 <= m) && (m <= 12) && (d <= MONTHS[m-1]) && (d >= 1);
    return ret;
}
