#ifndef SYSTEM_H
#define SYSTEM_H

#include "Member.h"
#include "Service.h"
#include "Request.h"

#define MEMBER_FILE "../../../Data/member.txt"
#define SKILL_FILE "./Data/skills.txt"
#define SERVICE_FILE "./Data/service.txt"
#define REQUEST_FILE "./Data/request.txt"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

class System
{
private:
    vector<Member *> member_list;
    vector<Service *> service_list;
    vector<Skill *> skill_list;
    vector<Request *> request_list;
    Member CurentMember;

public:
    System(std::vector<Member *> member_list = {},
           std::vector<Service *> service_list = {},
           std::vector<Request *> request_list = {},
           std::vector<Skill *> skill_list = {});

    Member *getMember(string memID);
    Service *getService(string servID);
    // When Member and Skill are initialized, add skill to member's skill list
    void linkSkillToMember(Skill *);

    // Initialize all objects
    void initData();
    // Update all datas to databases
    void updateData();

    // Run when initdata() run, init data
    vector<string> splitStr(string &, string);
    void initMembers();
    void initServices();
    void initRequests();
    void initSkills();

    // Run when updateData() run, update each object to each data file
    void updateMemberFile();
    void updateServiceFile();
    void updateSkillsFile();
    void updateRequestFile();

    // Print option to get user's input (0/x means exit or return to last page)
    int getUserInput();

    // Display basic welcome screen
    void welcomeScreen();

    // Run immediately after welcomeScreen()
    void mainMenu();

    // Options display in mainMenu()
    void loginPage();
    void registerPage();
    void guestMenu();

    // Check if the credentials matches
    void verifyLogin();
    // Check for regex and topup
    void verifyRegister();

    // Login success, display menu
    void memberMenu();

    // Options in memberMenu()
    void displayProfile();
    void blockPage(); // Need idea
    void topUpPage();
    void supporterPage();
    void hostPage();

    // Options in supporterPage()
    void listService();
    void viewYourService();
    void deleteService(); // Destructor
    void listSkill();
    void viewSkill();
    void deleteSkill();
    void viewHostRatingRequest(); // Need idea

    // Options in hostPage()
    void viewServices();
    void viewSuppRatingRequest(); // Need idea

    // Display services for Guest
    void guestViewServices(); // Need idea
};

#endif