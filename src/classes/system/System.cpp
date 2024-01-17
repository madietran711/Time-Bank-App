

#include "System.h"
#include <vector>
#include <iostream>
using namespace std;

void System::run()
{
    std::string groupNumber = "Group No.";
    std::string instructorName = "Mr. Tran Duc Linh";

    // Student information
    std::string student1ID = "sXXXXXXX";
    std::string student1Name = "Nguyen Ba Khoi";

    std::string student2ID = "s4022878";
    std::string student2Name = "Dang Minh Triet";

    std::string student3ID = "s3979462";
    std::string student3Name = "Nguyen Quoc Binh";

    std::string student4ID = "s3979638";
    std::string student4Name = "Tran Ha Phuong";

    // Print the assignment header
    std::cout << Colors::GREEN << "--------------------------------------------------\n";
    std::cout << "EEET2482/COSC2082 ASSIGNMENT\n";
    std::cout << "\"TIME BANK\" APPLICATION\n";
    std::cout << "Instructor: " << instructorName << "\n";
    std::cout << "Group: " << groupNumber << "\n";
    std::cout << "--------------------------------------------------\n"
              << Colors::RESET;

    // Print student information

    std::cout << Colors::YELLOW << student1ID << ", " << student1Name << "\n";
    std::cout << student2ID << ", " << student2Name << "\n";
    std::cout << student3ID << ", " << student3Name << "\n";
    std::cout << student4ID << ", " << student4Name << Colors::RESET << "\n";

    // Print the main menu
    displayWelcomeMenu();
};

void System::displayWelcomeMenu()
{
    initData();
    loadAllData();
    // Print the main menu
    std::cout << Colors::GREEN << "--------------------------------------------------\n";
    std::cout << "Welcome to Time Bank Application\n";
    std::cout << "--------------------------------------------------\n"
              << Colors::RESET;
    std::cout << "1. Guest\n";
    std::cout << "2. Member\n";
    std::cout << "3. Admin\n";
    std::cout << "Please enter your choice: ";

    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        displayGuestMenu();
        break;
    case 2:
        displayMemberMenu();
        break;
    case 3:
        displayAdminMenu();
        break;

    default:
        std::cout << "Invalid choice. Please try again.\n";

        break;
    }
};

void System::displayGuestMenu()
{
}

void System::displayMemberMenu()
{
}

void System::displayAdminMenu()
{
}

void System::initData()
{
    std::cout << "\n"
              << "\n"
              << "\n";
    std::cout << Colors::MAGENTA << "Initializing data...\n"
              << Colors::RESET;
    initMembers();
    initSkills();
    initServices();
    initRequests();
    saveAllMembers();
    saveAllSkills();
}

void System::initMembers()
{
    // Initialize some members
    Member newMember1("1", "newUsername1", "newPassword1", "New Full Name 1", "123456789", "newemail1@example.com", "New Address 1", 4.5, 3.2, 15);
    Member newMember2("2", "newUsername2", "newPassword2", "New Full Name 2", "987654321", "newemail2@example.com", "New Address 2", 3.8, 4.1, 10);

    // Add the new members to the existing member_list
    member_list.push_back(newMember1);
    member_list.push_back(newMember2);
}

void System::initSkills()
{
    // Initialize some skills
    Skill skill1("1", &member_list[0], "Programming", 4.8);
    Skill skill2("2", &member_list[1], "Graphic Design", 3.5);

    // Add the new skills to the existing skill_list
    skill_list.push_back(skill1);
    skill_list.push_back(skill2);

    // Link skills to members
    member_list[0].addSkill(&skill1);
    member_list[1].addSkill(&skill2);
}

void System::initServices()
{
    // Initialize some services
    Date date1 = Date::parse("2024/01/20 10:00");
    Date date2 = Date::parse("2024/01/20 15:00");
    Date date3 = Date::parse("2024/01/25 14:00");
    Date date4 = Date::parse("2024/01/25 18:00");
    Service service1("1", &member_list[0], date1, date2, 2, 4.5);
    Service service2("2", &member_list[1], date3, date4, 3, 3.8);

    // Add the new services to the existing service_list
    service_list.push_back(service1);
    service_list.push_back(service2);

    // Link services to members
    member_list[0].addService(&service1);
    member_list[1].addService(&service2);
}

void System::initRequests()
{
    // Initialize some requests
    Date date1 = Date::parse("2024/01/20 12:00");
    Date date2 = Date::parse("2024/01/20 14:00");
    Date date3 = Date::parse("2024/01/25 15:00");
    Date date4 = Date::parse("2024/01/25 17:00");
    Request request1("1", &service_list[0], &member_list[1], date1, date2, 1);
    Request request2("2", &service_list[1], &member_list[0], date3, date4, 1);

    // Add the new requests to the existing request_list
    request_list.push_back(request1);
    request_list.push_back(request2);

    // Link requests to members and services
    member_list[1].acceptRequest(&request1);
    member_list[0].acceptRequest(&request2);
    service_list[0].addRequest(&request1);
    service_list[1].addRequest(&request2);
}

bool System::saveAllMembers()
{
    std::ofstream memberFile(MEMBER_FILE, std::ios::out);

    if (!memberFile.is_open())
    {
        std::cout << "Failed to create/open member file\n";
        return false;
    }

    for (const Member &member : member_list)
    {                                                                                                                                                                                                                                                                                                                                                   // Use const reference to avoid unnecessary copy
        memberFile << member.getMemberId() << "," << member.getUsername() << "," << member.getPassword() << "," << member.getFullName() << "," << member.getPhoneNumber() << "," << member.getEmail() << "," << member.getHomeAddress() << "," << member.getHostScore() << "," << member.getSupporterScore() << "," << member.getCreditPoint() << "\n"; // Use '\n' for a newline character
        // Use '\n' for a newline character
    }

    memberFile.close();

    cout << "Saved " << Colors::YELLOW << member_list.size() << Colors::GREEN << " members." << Colors::RESET << endl;

    return true;
}

bool System::saveAllSkills()
{
    std::ofstream skillFile(SKILL_FILE, std::ios::out);

    if (!skillFile.is_open())
    {
        std::cout << "Failed to create/open skill file\n";
        return false;
    }

    for (const Skill &skill : skill_list)
    {                                                                                                                                                      // Use const reference to avoid unnecessary copy
        skillFile << skill.getSkillId() << "," << skill.getOwner()->getMemberId() << "," << skill.getSkillName() << "," << skill.getRatingScore() << "\n"; // Use '\n' for a newline character
    }

    skillFile.close();

    cout << "Saved " << Colors::YELLOW << skill_list.size() << Colors::GREEN << " skills." << Colors::RESET << endl;

    return true;
}
bool System::loadAllData()
{

    std::cout << Colors::MAGENTA << "Loading data...\n"
              << Colors::RESET;
    loadAllMembers();
    loadAllSkills();
    loadAllServices();
    loadAllRequests();
    std::cout << "\n"
              << "\n"
              << "\n";
}

bool System::loadAllMembers()
{
    member_list.clear();
    std::ifstream memberFile(MEMBER_FILE, std::ios::in);

    if (!memberFile.is_open())
    {
        std::cout << "Failed to open member file\n";
        return false;
    }

    std::string line;
    while (std::getline(memberFile, line))
    {
        std::vector<std::string> tokens = splitStr(line, ",");
        if (tokens.size() != 10)
        {
            std::cout << "Invalid member data\n";
            continue;
        }

        Member member(
            tokens[0],
            tokens[1],
            tokens[2],
            tokens[3],
            tokens[4],
            tokens[5],
            tokens[6],
            std::stod(tokens[7]),
            std::stod(tokens[8]),
            std::stoi(tokens[9]));

        member_list.push_back(member);
    }

    memberFile.close();

    cout << "Loaded " << Colors::YELLOW << member_list.size() << Colors::GREEN << " members." << Colors::RESET << endl;
    return true;
}

bool System::loadAllSkills()
{
    skill_list.clear();
    std::ifstream skillFile(SKILL_FILE, std::ios::in);

    if (!skillFile.is_open())
    {
        std::cout << "Failed to open skill file\n";
        return false;
    }

    std::string line;
    while (std::getline(skillFile, line))
    {
        std::vector<std::string> tokens = splitStr(line, ",");
        if (tokens.size() != 4)
        {
            std::cout << "Invalid skill data\n";
            continue;
        }

        Skill skill;
        skill.setSkillId(tokens[0]);
        skill.setOwner(getMemberByID(tokens[1]));
        skill.setSkillName(tokens[2]);
        skill.setRatingScore(std::stod(tokens[3]));
        skill_list.push_back(skill);
    }

    skillFile.close();

    cout << "Loaded " << Colors::YELLOW << skill_list.size() << Colors::GREEN << " skills." << Colors::RESET << endl;
    return true;
}

bool System::loadAllServices()
{
    return true;
}
bool System::loadAllRequests()
{
    return true;
}
// get BY ID
Member *System::getMemberByID(std::string memberId)
{
    for (Member &member : member_list)
    {
        if (member.getMemberId() == memberId)
        {
            return &member;
        }
    }

    return nullptr;
}
Skill *System::getSkillByID(std::string skillId)
{
    for (Skill &skill : skill_list)
    {
        if (skill.getSkillId() == skillId)
        {
            return &skill;
        }
    }

    return nullptr;
}
Service *System::getServiceByID(std::string serviceId)
{
    for (Service &service : service_list)
    {
        if (service.getServiceId() == serviceId)
        {
            return &service;
        }
    }

    return nullptr;
}
Request *System::getRequestByID(std::string requestId)
{
    for (Request &request : request_list)
    {
        if (request.getRequestId() == requestId)
        {
            return &request;
        }
    }

    return nullptr;
}
Review *System::getReviewByID(std::string reviewId)
{
    for (Review &review : review_list)
    {
        if (review.getReviewId() == reviewId)
        {
            return &review;
        }
    }

    return nullptr;
}

std::vector<std::string> System::splitStr(std::string &str, std::string delimiter)
{
    std::vector<std::string> tokens;
    size_t pos = 0;
    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        tokens.push_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.length());
    }
    tokens.push_back(str);
    return tokens;
}