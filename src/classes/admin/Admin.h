//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#ifndef TIME_BANK_APP_ADMIN_H
#define TIME_BANK_APP_ADMIN_H
#include <string>
#include "../member/Member.h"

class Admin
{
private:
    std::string adminId;
    std::string adminName;
    std::string adminPassword;

public:
    // Constructor
    Admin(std::string adminId, std::string adminName, std::string adminPassword);

    void checkLogIn(std::string adminName, std::string adminPassword);

    // Return the address of the array to display profile info
    int *profileInfo();
    void changeMemberPassword(Member *member, std::string newPassword);
};

#endif // TIME_BANK_APP_ADMIN_H
