
#ifndef TIME_BANK_APP_SYSTEM_H
#define TIME_BANK_APP_SYSTEM_H

#define MEMBER_FILE "./data/member.dat"
#define SKILL_FILE "./data/skill.dat"
#define SERVICE_FILE "./data/service.dat"
#define REQUEST_FILE "./data/request.dat"
#define REVIEW_FILE "./data/review.dat"

#include "../../utils/colors.h"
#include "../../utils/Utilities.h"
#include "../member/Member.h"
#include "../guest/Guest.h"
#include "../service/Service.h"
#include "../request/Request.h"
#include "../skill/Skill.h"
#include "../review/Review.h"
#include <fstream>
#include <iomanip>
using namespace std;

class System
{

public:
    std::vector<Member *> member_list;
    std::vector<Service *> service_list;
    std::vector<Request *> request_list;
    std::vector<Skill *> skill_list;
    std::vector<Review *> review_list;

    // Current user data
    std::string adminUsername = "admin";
    std::string adminPassword = "admin123";
    Member *currentMember = nullptr;
    bool isUserLoggedIn = false;
    bool isUserAdmin = false;

    std::vector<std::string> availableLocations = {"HANOI", "SAIGON"};

    // Constructors
    System() = default; // default constructor

    std::vector<std::string> splitStr(std::string &, std::string);

    // save data to file
    bool saveAllData();
    bool saveAllMembers();
    bool saveAllServices();
    bool saveAllRequests();
    bool saveAllSkills();
    bool saveAllReviews();

    // Run when updateData() run, update each object to each data file
    bool loadAllData();
    bool loadAllMembers();
    bool loadAllServices();
    bool loadAllRequests();
    bool loadAllSkills();
    bool loadAllReviews();

    // getByID
    string System::generateId();
    Member *getMemberByID(std::string memberID);
    Skill *getSkillByID(std::string skillID);
    Service *getServiceByID(std::string serviceID);
    Request *getRequestByID(std::string requestID);
    Review *getReviewByID(std::string reviewID);

    // display menu
    void run();
    void displayWelcomeMenu();
    void displayGuestMenu();
    void displayMemberMenu();
    void displayAdminMenu();

    // AdminMenu Functions
    void displayAllMember();

    // GuestMenu Functions

    // MemberMenu Functions
    void displayMemberProfile(Member *member);
    void manageProfile(Member *member);
    void displayMemberSkillList(Member *member);
    void manageReviews();
    void manageSkills(Member *member);
    void displayAvailableServices(Member *member);
    void displayServiceListing(Member *member);
    void viewReviews();
    void manageRequest();
    void topUp();
    void manageBlockList();
    Review *inputReview(Request *request, string reviewID);

    void rateHost(Member *host, double score, Request *request, bool isNewReview);
    void rateSupporter(Member *supporter, double score, Request *request, bool isNewReview, double skillScore);

    void hostRatingFunction();
    // void topUpCD(Member *member, int cd);
    void manageBlockList(Member *member);

    // after done debugging delete this function
    void printAllData();
};

#endif // TIME_BANK_APP_SYSTEM_H
