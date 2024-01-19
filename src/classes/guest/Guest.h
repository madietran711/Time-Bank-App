#ifndef TIME_BANK_APP_GUEST_H
#define TIME_BANK_APP_GUEST_H

#include <string>

class Member;
class Guest
{
private:
public:
    // Constructor
    Guest() = default; // default constructor
                       //* Destructor

    //* Authentication methods
    Member *signUp();
    Member *login();
};

#endif // TIME_BANK_APP_SKILL_H
       // TIME_BANK_APP_SKILL_H
