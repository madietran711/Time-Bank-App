#ifndef TIME_BANK_APP_MEMBER_H
#define TIME_BANK_APP_MEMBER_H

#include <string>
#include <vector>
#include "../skill/Skill.h"
#include "../service/Service.h"
#include "../request/Request.h"
#include "../review/Review.h"
#include "../date/Date.h"
#include "../../utils/colors.h"

#include <iomanip>
#include <algorithm>
class Skill;
class Service;
class Request;
class Date;
class Review;
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
    std::string city;
    double hostScore;
    double supporterScore;
    int creditPoint;
    std::vector<Skill *> skills;
    std::vector<Member *> blockedList;
    std::vector<Request *> acceptedRequest;
    std::vector<Service *> listedService;
    std::vector<Request *> myRequest;

public:
    // Constructors

    Member(); // default constructor
    Member(
        std::string memberId,
        std::string username,
        std::string password,
        std::string fullName,
        std::string phoneNumber,
        std::string email,
        std::string homeAddress,
        std::string city,
        double hostScore,
        double supporterScore,
        int creditPoint = 20);

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
    std::string getCity() const;
    double getHostScore() const;
    double getSupporterScore() const;
    int getCreditPoint() const;
    const std::vector<Skill *> &getSkills() const;
    const std::vector<Member *> &getBlockedList() const;
    const std::vector<Service *> &getListedService() const;
    const std::vector<Request *> &getAcceptedRequest() const;
    const std::vector<Request *> &getMyRequest() const;

    // Setter functions
    void setMemberId(std::string memberId);
    void setUsername(std::string username);
    void setPassword(std::string password);
    void setFullName(std::string fullName);
    void setPhoneNumber(std::string phoneNumber);
    void setEmail(std::string email);
    void setHomeAddress(std::string homeAddress);
    void setCity(std::string city);
    void setHostScore(double hostScore);
    void setHostScore(double hostScore, Request *request);
    void setSupporterScore(double supporterScore);
    void setCreditPoint(int creditPoint);
    void setSkills(const std::vector<Skill *> &skills);
    void setBlockedList(const std::vector<Member *> &blockedList);
    void setListedService(const std::vector<Service *> &listedService);
    void setAcceptedRequest(const std::vector<Request *> &acceptedRequest);
    void setMyRequest(const std::vector<Request *> &myRequest);
    // Member functions
    Member *signUp();
    Member *login();
    bool logout();
    bool addSkill(Skill *skill);
    bool removeSkill(Skill *skill);
    void showSkills();
    void showListedService();
    void showAcceptedRequest();
    void showBlockedList();
    void checkLogIn();
    void viewProfile();
    void addCD(int cd);
    bool blockMember(Member *member);
    bool unblockMember(Member *member);
    std::vector<Member *> getInteractedMembers();
    std::vector<Review *> getReviews(std::vector<Review *> review_list);

    // Member - Supporter functions
    bool addService(Service *service);
    bool removeService(Service *service);
    bool acceptRequest(Request *request);
    bool rejectRequest(Request *request);

    void showAllRequest();
    void showAllRequestFilterBySkill(Skill *skill);

    // Member - Host functions
    bool addRequest(Request *request);
    void requestService(Service *service);
    void rateSkill(Skill *skill, double score, Request *request);
    void showAllService();
    void showAllServiceFilterBySkill(Skill *skill);
    void showAllServiceFilterByTime(Date startTime, Date endTime);
    void showAllServiceFilterByLocation(std::string location);
    void viewSupporterReview(Member *supporter);
    void viewMyRequest();
    void deductCD(int cd);

    // declare friend class
    friend class Request;
    friend class Service;
    friend class Skill;
};

#endif // TIME_BANK_APP_MEMBER_H