#ifndef MEMBER_H
#define MEMBER_H

#include "Skill.h"
#include "Service.h"
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
    std::string memberId;
    std::string username;
    std::string password;
    std::string fullName;
    std::string phoneNumber;
    std::string email;
    std::string homeAddress;
    double hostScore;
    double supporterScore;
    std::vector<Skill> skills;

    std::vector<Service> listedService;

public:
    Member();
    Member(
        std::string memberId,
        std::string username,
        std::string password,
        std::string fullName,
        std::string phoneNumber,
        std::string email,
        std::string homeAddress,
        double hostScore,
        double supporterScore,
        std::vector<Skill> skills,

        std::vector<Service> listedService = {});

    Member(
        bool is_admin,
        string username,
        string password);

    void addSkill(Skill *);
    void addService(Service *);

    void checkLogIn();

    // Return the address of the array to display profile info
    int *profileInfo();

    void addCD();

    friend class System;
};
#endif