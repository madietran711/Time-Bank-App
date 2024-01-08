#ifndef MEMBER_H
#define MEMBER_H

#include "Skill.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

class Member
{
private:
    bool is_admin;
    string username;
    string password;
    string full_name;
    string phone_num;
    string email;
    string home_address;
    double host_score;
    double supporter_score;
    Skill skills[10];

    vector<string> listed_service;

public:
    Member(
        bool is_admin,
        string username,
        string password,
        string full_name,
        string phone_num,
        string email,
        string home_address,
        double host_score,
        double supporter_score,
        Skill skills[10],

        vector<string> listed_service);

    Member(
        bool is_admin,
        string username,
        string password);

    void addSkill();

    void checkLogIn();

    // Return the address of the array to display profile info
    int *profileInfo();

    void addCD();
};
#endif