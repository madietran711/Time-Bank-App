//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#ifndef TIME_BANK_APP_UTILITIES_H
#define TIME_BANK_APP_UTILITIES_H

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>
#include "../classes/system/System.h"
using namespace std;
class Utilities
{
public:
    static bool validateUsername(std::string &str);
    static bool validatePassword(std::string &str);
    static bool validateFullName(std::string &str);
    static bool validatePhoneNumber(std::string &str);
    static bool validateEmail(std::string &str);
    static bool validateUserRating(int &rating);
    static string generateId();
};

#endif // TIME_BANK_APP_UTILITIES_H
