//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#ifndef TIME_BANK_APP_MEMBER_H
#define TIME_BANK_APP_MEMBER_H
#include <string>
#include <vector>
#include "Skill.h"
#include "Service.h"

class Member {
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
    std::vector <Skill> skills;

    std::vector<Service> listedService;

public:
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

            std::vector<Service> listedService={});

    Member(

            std::string username,
            std::string password);

    void addSkill(Skill *skill);

    void checkLogIn();

    // Return the address of the array to display profile info
    int *profileInfo();

    void addCD();
};


#endif //TIME_BANK_APP_MEMBER_H
