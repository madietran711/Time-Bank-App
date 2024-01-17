

#ifndef TIME_BANK_APP_MEMBER_H
#define TIME_BANK_APP_MEMBER_H

#include <string>
#include <vector>
#include "../skill/Skill.h"
#include "../service/Service.h"
#include "../request/Request.h"
#include "../date/Date.h"
class Skill;
class Service;
class Request;
class Date;
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
    Member() = default; // default constructor
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
        int creditPoint = 20,
        std::vector<Skill> skills={},
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
    Member *signUp();
    Member *login();
    bool logout();
    bool addSkill(Skill *skill);
    void showSkills();
    void showListedService();
    void showAcceptedRequest();
    void showBlockedList();
    void checkLogIn();
    void viewProfile();
    void addCD();
    bool blockMember(Member *member);
    bool unblockMember(Member *member);

    // as a supporter
    bool addService(Service *service);
    bool removeService(Service *service);
    bool acceptRequest(Request *request);
    void rateHost(Member *host, double score);
    void showAllRequest();
    void showAllRequestFilterBySkill(Skill *skill);

    // as a host
    void requestService(Service *service);
    void addSupporterReview(Member *supporter, std::string comment, int supporterRating, Request *request);
    void rateSkill(Skill *skill, double score, Request *request);
    void showAllService();
    void showAllServiceFilterBySkill(Skill *skill);
    void showAllServiceFilterByTime(Date startTime, Date endTime);
    void showAllServiceFilterByLocation(std::string location);
    void viewSupporterReview(Member *supporter);

    // declare friend class
    friend class Request;
    friend class Service;
    friend class Skill;
};

#endif // TIME_BANK_APP_MEMBER_H




