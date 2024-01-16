//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#ifndef TIME_BANK_APP_ADMIN_H
#define TIME_BANK_APP_ADMIN_H
#include<string>

class Admin {
private:
    std::string adminId;
    std::string adminName;
    std::string adminPassword;

public:
    Admin(std::string adminId, std::string adminName, std::string adminPassword);

    void checkLogIn();

    // Return the address of the array to display profile info
    int *profileInfo();



};


#endif //TIME_BANK_APP_ADMIN_H
