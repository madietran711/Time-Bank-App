//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#ifndef TIME_BANK_APP_MEMBER_H
#define TIME_BANK_APP_MEMBER_H
#include <string>
#include <vector>
#include "Skill.h"
#include "Service.h"
#include "Request.h"

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
    int creditPoint;
    std::vector<Skill> skills;
    std::vector<Member> blockedList;
    std::vector<Service> listedService;
    std::vector<Request> acceptedRequest;

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
        int creditPoint,
        std::vector<Skill> skills,
        std::vector<Member> blockedList = {},
        std::vector<Service> listedService = {},
        std::vector<Request> acceptedRequest = {});

    Member(

        std::string username,
        std::string password);

    bool addSkill(Skill *skill);

    void checkLogIn();

    // Return the address of the array to display profile info
    int *profileInfo();

    void addCD();

    // declare friend class
    friend class Request;
    friend class Service;
    friend class Skill;
};

#endif // TIME_BANK_APP_MEMBER_H

iend class Skill;
}
;

#endif // TIME_BANK_APP_MEMBER_H
