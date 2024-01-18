#ifndef SYSTEM_H
#define SYSTEM_H

#include "Member.h"
#include "Service.h"

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

class System
{
private:
    vector<Member *> member_list;
    vector<Service *> service_list;
    Member CurentMember;

public:
    // Initialize all objects
    void initData();
    // Update all datas to databases
    void updateData();

    // Run when initdata() run, init data
    void initMembers();
    void initServices();
    void initRequests();
    void initSkills();
    // When Member and Skill are initialized, add skill to member's skill list
    void linkSkillToMember();

    // Run when updateData() run, update each object to each data file
    void updateMemberFile();
    void updateServiceFile();
    void updateSkillsFile();

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
    bool validateUsername(string& str);
    bool validatePassword(string& str);
    bool validateFullName(string& str);
    bool validatePhoneNumber(string& str);
    bool validateEmail(string& str);
    bool validateHomeAddress(string& str);
};

#endif