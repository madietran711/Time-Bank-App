

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
    // Constructors
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

    // Getter functions
    std::string getMemberId() const;
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getFullName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::string getHomeAddress() const;
    double getHostScore() const;
    double getSupporterScore() const;
    int getCreditPoint() const;
    const std::vector<Skill> &getSkills() const;
    const std::vector<Member> &getBlockedList() const;
    const std::vector<Service> &getListedService() const;
    const std::vector<Request> &getAcceptedRequest() const;

    // Setter functions
    void setMemberId(std::string memberId);
    void setUsername(std::string username);
    void setPassword(std::string password);
    void setFullName(std::string fullName);
    void setPhoneNumber(std::string phoneNumber);
    void setEmail(std::string email);
    void setHomeAddress(std::string homeAddress);
    void setHostScore(double hostScore);
    void setSupporterScore(double supporterScore);
    void setCreditPoint(int creditPoint);
    void setSkills(const std::vector<Skill> &skills);
    void setBlockedList(const std::vector<Member> &blockedList);
    void setListedService(const std::vector<Service> &listedService);
    void setAcceptedRequest(const std::vector<Request> &acceptedRequest);

    // Member functions
    bool addSkill(Skill *skill);
    void checkLogIn();
    int *profileInfo();
    void addCD();

    // declare friend class
    friend class Request;
    friend class Service;
    friend class Skill;
};

#endif // TIME_BANK_APP_MEMBER_H
;

#endif // TIME_BANK_APP_MEMBER_H

iend class Skill;
}
;

#endif // TIME_BANK_APP_MEMBER_H
iend class Skill;
}
;

#endif // TIME_BANK_APP_MEMBER_H
