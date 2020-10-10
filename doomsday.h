#include <array>

const std::array<char,12> DEF_MONTHS = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date
{
    public:
        Date (char d, char m, int y);
        char getDay () const { return d; }
        char getMonth () const { return m; }
        int getYear () const { return y; }
        // Compute the name of the day (e.g. monday, tuesday, etc...)
        char computeDay () const;

    private:
        std::array<char,12> MONTHS;
        char d,m;
        int y;
        bool check () const;
};
