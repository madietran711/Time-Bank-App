
#ifndef TIME_BANK_APP_SYSTEM_H
#define TIME_BANK_APP_SYSTEM_H
#include <vector>
#include "../../utils/colors.h"
#include "../member/Member.h"
#include "../service/Service.h"
#include "../request/Request.h"
#include "../skill/Skill.h"
#include "../review/Review.h"

class System
{

public:
    std::vector<Member> member_list;
    std::vector<Service> service_list;
    std::vector<Request> request_list;
    std::vector<Skill> skill_list;
    std::vector<Review> review_list;

    // Current user data
    string adminUsername = "admin";
    string adminPassword = "admin123";
    Member *currentMember = nullptr;
    bool isUserLoggedIn = false;
    bool isUserAdmin = false;

    vector<string> availableLocations = {"HANOI", "SAIGON"};

    // Constructors
    System() = default; // default constructor

    // display menu
    void run();
    void displayWelcomeMenu();
    void displayGuestMenu();
    void displayMemberMenu();
    void displayAdminMenu();

    // GuestMenu Functions

    // MemberMenu Functions
    void displayMemberProfile(Member *member);
};

#endif // TIME_BANK_APP_SYSTEM_H
