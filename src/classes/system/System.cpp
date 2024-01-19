
#include <algorithm>
#include "System.h"
#include <random>
#include <vector>
#include <iostream>
using namespace std;

void System::run()
{
    std::string groupNumber = "Group No.19";
    std::string instructorName = "Mr. Tran Duc Linh";

    // Student information
    std::string student1ID = "ss3926984";
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
    // initData();
    loadAllData();
    printAllData();
    saveAllData();
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
        currentMember = getMemberByID("1");
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
    int choice;
    bool exit = false;
    do
    {
        std::cout << Colors::GREEN << "--------------------------------------------------\n";
        std::cout << "Time Bank Application - Welcome " << currentMember->getFullName() << "\n";
        std::cout << "--------------------------------------------------\n"
                  << Colors::RESET;
        std::cout << "1. Manage Profile (View, Edit)\n";
        std::cout << "2. Manage Skills (View, Add, Delete)\n";
        std::cout << "3. View Available Services\n";
        std::cout << "4. Manage Service Listing (Add Service, Delete Service, View & Accept Request)\n\n";
        std::cout << "5. View Available Supporter (By Time or Location)\n";
        std::cout << "6. Manage Request (View, Add, Delete)\n";
        std::cout << "7. View Reviews\n";
        std::cout << "8. Add Review For Service\n";
        std::cout << "9. Rate Host\n";
        std::cout << "10. Top up Credit Point\n";
        std::cout << "11. Blocking (View, Block, Unblock)\n";

        std::cout << "25. Logout\n";
        std::cout << "Please enter your choice: ";

        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "----------------1. Manage Profile (View, Edit)----------------\n";
            displayMemberProfile(currentMember);
            std::cout << "1. Edit Profile";
            std::cout << "2. Change Password";
            std::cout << "3. Return to Main Menu";

            int subchoice;
            std::cin >> subchoice;
            switch (subchoice)
            {
                case 1:
                    std::cout << Colors::GREEN << "----------------1. Edit Profile----------------\n"
                            << Colors::RESET;
                    std::cout << "Enter current Password: ";
                    std::string inputPW;
                    std::getline(std::cin, inputPW);
                    if (inputPW == currentMember->getPassword())
                    {
                        std::cout << "Enter new Username: ";
                        std::string newUsername;
                        std::getline(std::cin, newUsername);
                        std::cin.ignore();
                        std::cout << "Enter new Full Name: ";
                        std::string newFullName;
                        std::getline(std::cin, newFullName);
                        std::cin.ignore();
                        std::cout << "Enter new Phone Number: ";
                        std::string newPhoneNumber;
                        std::getline(std::cin, newPhoneNumber);
                        std::cin.ignore();
                        std::cout << "Enter new Email Address: ";
                        std::string newEmailAddress;
                        std::getline(std::cin, newEmailAddress);
                        std::cin.ignore();
                        std::cout << "Enter new Home Address: ";
                        std::string newHomeAddress;
                        std::getline(std::cin, newHomeAddress);
                        std::cin.ignore();
                        currentMember->setUsername(newUsername);
                        currentMember->setFullName(newFullName);
                        currentMember->setPhoneNumber(newPhoneNumber);
                        currentMember->setEmail(newEmailAddress);
                        currentMember->setHomeAddress(newHomeAddress);
                        displayMemberProfile(currentMember);
                    } else {
                        std::cout << "Incorrect Password!\n";
                    }
                    break;
                case 2:
                    std::cout << "----------------2. Change Password----------------\n";
                    std::cout << "Enter current Password: ";
                    std::string inputPW;
                    std::getline(std::cin, inputPW);
                    std::cin.ignore();
                    if (inputPW == currentMember->getPassword())
                    {
                        std::cout << "Enter new Password: ";
                        std::string newPassword;
                        std::getline(std::cin, newPassword);
                        std::cin.ignore();
                        currentMember->setPassword(newPassword);
                    } else {
                        std::cout << "Incorrect Password!\n";
                    }
                    break;
                case 3:
                    std::cout << "----------------3. Return to Main Menu----------------\n";
                    displayMemberMenu();
                    break;
            }
            displayMemberMenu();
            break;
        case 2:
            std::cout << Colors::GREEN << "----------------2. Manage Skills (View, Add, Delete)----------------\n"
                    << Colors::RESET;
            displayMemberSkillList(currentMember);
            std::cout << "1. Add a new skill";
            std::cout << "2. Delete an existing skill";
            std::cout << "3. Return to Main Menu";

            int subchoice;
            std::cin >> subchoice;
            if (subchoice == 1) 
            switch (subchoice)
            {
                case 1:
                    std::cout << "----------------1. Add a new skill----------------\n";
                    std::cout << "Enter new Skill Name: ";
                    std::string newSkillName;
                    std::getline(std::cin, newSkillName);
                    std::cin.ignore();
                    std::string newSkillID = generateId();
                    Skill newSkill(newSkillID, currentMember, newSkillName, 0.0);
                    currentMember->addSkill(&newSkill);
                    displayMemberSkillList(currentMember);
                    break;
                case 2:
                    std::cout << "----------------2. Delete an existing skill----------------\n";
                    std::cout << "Enter the Skill Name of the skill to be deleted: ";
                    std::string deletingSkillName;
                    std::getline(std::cin, deletingSkillName);
                    auto it = std::find_if(currentMember->getSkills().begin(), currentMember->getSkills().end(), [&deletingSkillName](const Skill& deletingSkill) 
                        { return deletingSkill.getSkillName() == deletingSkillName; });
                    if (it != currentMember->getSkills().end()) {
                        std::cout << "Skill to be deleted found.\n";
                        bool deletingResult = currentMember->removeSkill(*it);
                        if (deletingResult) {
                            std::cout << "Skill successfully deleted.\n";
                        } else {
                            std::cout << "Skill cannot be deleted.\n";
                        }
                    } else {
                        std::cout << "Cannot find specified Skill.\n";
                    }
                    displayMemberSkillList(currentMember);
                    break;
                case 3:
                    std::cout << "----------------3. Return to Main Menu----------------\n";
                    displayMemberMenu();
                    break;
            }
            displayMemberMenu();
            break;
        case 3:
            std::cout << Colors::GREEN << "----------------3. View Available Services----------------\n"
                    << Colors::RESET;
            // displayAvailableServices(currentMember);

            std::cout << std::endl;
            displayMemberMenu();
            break;
        case 4:
            std::cout << Colors::GREEN << "----------------4. Manage Service Listing (Add Service, Delete Service, View & Accept Request)\n----------------\n"
                    << Colors::RESET;
            displayServiceListing(currentMember);
            std::cout << "1. Add a new service";
            std::cout << "2. Delete an existing service";
            std::cout << "3. View available requests";
            std::cout << "4. Accept a request";
            std::cout << "5. Return to Main Menu";

            int subchoice;
            std::cin >> subchoice;
            switch (subchoice)
            {
                case 1:
                    std::cout << "----------------1. Add a new service----------------\n";
                    std::string newServiceID = generateId();
                    std::cout << "Enter new Service Start Time:\n";
                    int startYear, startMonth, startDay, startHour, startMinute;
                    std::cout<< "Enter the Year: ";
                    cin >> startYear;
                    std::cin.ignore();
                    std::cout<< "Enter the Month: ";
                    cin >> startMonth;
                    std::cin.ignore();
                    std::cout<< "Enter the Day: ";
                    cin >> startDay;
                    std::cin.ignore();
                    std::cout<< "Enter the Hour: ";
                    cin >> startHour;
                    std::cin.ignore();
                    std::cout<< "Enter the Minute: ";
                    cin >> startMinute;
                    std::cin.ignore();
                    Date startDate(startYear, startMonth, startDay, startHour, startMinute);
                    std::cout << "Enter new Service End Time: ";
                    int endYear, endMonth, endDay, endHour, endMinute;
                    std::cout<< "Enter the Year: ";
                    cin >> endYear;
                    std::cin.ignore();
                    std::cout<< "Enter the Month: ";
                    cin >> endMonth;
                    std::cin.ignore();
                    std::cout<< "Enter the Day: ";
                    cin >> endDay;
                    std::cin.ignore();
                    std::cout<< "Enter the Hour: ";
                    cin >> endHour;
                    std::cin.ignore();
                    std::cout<< "Enter the Minute: ";
                    cin >> endMinute;
                    std::cin.ignore();
                    Date endDate(endYear, endMonth, endDay, endHour, endMinute);
                    std::cout << "Enter new Service Consuming Credit Points: ";
                    int newServiceCCD;
                    std::cin >> newServiceCCD;
                    std::cin.ignore();
                    std:cout << "Enter new Service Minimum Host Score Required: ";
                    double newSericeMinHostScore; 
                    std::cin >> newSericeMinHostScore;
                    std::cin.ignore();
                    displayMemberSkillList(currentMember);
                    std::vector<Skill *> newServiceSkillList;
                    int count;
                    std::cout << "Enter the number of Skills available for the new Service: ";
                    std::cin >> count;
                    std::cin.ignore();
                    std::string selectedSkillName;
                    for (int i = 0; i < count; i++)
                    {
                        std::cout << "Enter the Skill Name: ";
                        std::getline(std::cin, selectedSkillName);
                        auto it = std::find_if(currentMember->getSkills().begin(), currentMember->getSkills().end(), [&selectedSkillName](const Skill& selectedSkill) 
                        { return selectedSkill.getSkillName() == selectedSkillName; });
                        if (it != currentMember->getSkills().end()) {
                            auto itt = std::find(newServiceSkillList.begin(), newServiceSkillList.end(), it);
                            // Checking if the Skill has already been added to the NEW Service lisitng
                            if (itt != newServiceSkillList.end()) {
                                std::cout << "The Skill has already been listed.\n";
                                i--;
                            } else {
                                newServiceSkillList.push_back(*it);
                            }
                        } else {
                            std::cout << "Cannot find specified Skill.\n";
                        }
                    }
                    Service newService(newServiceID, currentMember, startDate, endDate, newServiceCCD, newSericeMinHostScore, newServiceSkillList, {});
                    currentMember->addService(&newService);
                    std::cout << "New Service listing has been successfully added!\n";
                    displayServiceListing(currentMember);
                    break;
                case 2:
                    std::cout << "----------------2. Delete an existing service----------------\n";
                    displayServiceListing(currentMember);
                    std::cout << "Enter the Service ID of the skill to be deleted: ";
                    std::string deletingServiceID;
                    std::getline(std::cin, deletingServiceID);
                    auto it = std::find_if(currentMember->getListedService().begin(), currentMember->getListedService().end(), [&deletingServiceID](const Service& deletingService) 
                        { return deletingService.getServiceId() == deletingServiceID; });
                    if (it != currentMember->getListedService().end()) {
                        std::cout << "Service to be deleted found.\n";
                        bool deletingResult = currentMember->removeService(*it);
                        if (deletingResult) {
                            std::cout << "Service successfully deleted.\n";
                        } else {
                            std::cout << "Service cannot be deleted.\n";
                        }
                    } else {
                        std::cout << "Cannot find specified Service.\n";
                    }
                    displayServiceListing(currentMember);
                    break;
                case 3:
                    std::cout << "----------------3. View available requests----------------\n";
                    break;
                case 4:
                    std::cout << "----------------4. Accept a request----------------\n";
                    break;
                case 5:
                    std::cout << "----------------5. Return to Main Menu----------------\n";
                    displayMemberMenu();
                    break;
            }
            displayMemberMenu();
            break;
        case 5:
            // displayMemberMenu();
            break;
        case 6:
            // displayMemberMenu();
            cout << Colors::GREEN << "--------------6. Manage Request (View, Add, Delete)----------------\n"
                 << Colors::RESET;
            manageRequest();
            break;
        case 7:
            std::cout << Colors::GREEN << "--------------7. View Reviews----------------\n"
                 << Colors::RESET;
            viewReviews();
            break;
        case 8:
            // displayMemberMenu();
            break;
        case 9:
            std::cout << Colors::GREEN << "--------------9. Rate Host----------------\n"
                 << Colors::RESET;
            hostRatingFunction();
            break;
        case 10:
            std::cout << Colors::GREEN << "--------------10. Top up Credit Point----------------\n"
                 << Colors::RESET;
            topUp();
            break;
        case 11:
            std::cout << Colors::GREEN << "--------------11. Blocking (View, Block, Unblock)----------------\n"
                 << Colors::RESET;
            manageBlockList();
            break;
        case 12:
            // displayMemberMenu();
            break;
        case 13:
            // displayMemberMenu();
            break;
        case 25:
            // displayMemberMenu();
            exit = true;
            break;
        }
    } while (!exit);
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
}
bool System::saveAllData()
{
    cout << Colors::MAGENTA << "Saving data...\n"
         << Colors::RESET;
    try
    {
        saveAllMembers();
        saveAllSkills();
        saveAllServices();
        saveAllRequests();
        saveAllReviews();
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
void System::initMembers()
{
    // Initialize some members
    Member *newMember1 = new Member("1", "newUsername1", "newPassword1", "New Full Name 1", "123456789", "newemail1@example.com", "New Address 1", 4.5, 3.2, 15);
    Member *newMember2 = new Member("2", "newUsername2", "newPassword2", "New Full Name 2", "987654321", "newemail2@example.com", "New Address 2", 3.8, 4.1, 10);

    // Add the new members to the existing member_list
    member_list.push_back(newMember1);
    member_list.push_back(newMember2);
}

void System::initSkills()
{
    // Initialize some skills
    Skill *skill1 = new Skill("1", member_list[0], "Programming", 4.8);
    Skill *skill2 = new Skill("2", member_list[1], "Graphic Design", 3.5);

    // Add the new skills to the existing skill_list
    skill_list.push_back(skill1);
    skill_list.push_back(skill2);

    // Link skills to members
    member_list[0]->addSkill(skill1);
    member_list[1]->addSkill(skill2);
}

void System::initServices()
{
    // Initialize some services
    Date date1 = Date::parse("2024/01/20 10:00");
    Date date2 = Date::parse("2024/01/20 15:00");
    Date date3 = Date::parse("2024/01/25 14:00");
    Date date4 = Date::parse("2024/01/25 18:00");
    Service *service1 = new Service("1", member_list[0], date1, date2, 2, 4.5, {}, {});
    Service *service2 = new Service("2", member_list[1], date3, date4, 3, 3.8, {}, {});

    // Add the new services to the existing service_list
    service_list.push_back(service1);
    service_list.push_back(service2);

    // Link services to members
    member_list[0]->addService(service1);
    member_list[1]->addService(service2);
}

void System::initRequests()
{
    // Initialize some requests
    Date date1 = Date::parse("2024/01/20 12:00");
    Date date2 = Date::parse("2024/01/20 14:00");
    Date date3 = Date::parse("2024/01/25 15:00");
    Date date4 = Date::parse("2024/01/25 17:00");
    Request *request1 = new Request("1", service_list[0], member_list[1], date1, date2, skill_list[0], 1);
    Request *request2 = new Request("2", service_list[1], member_list[0], date3, date4, skill_list[0], 1);

    // Add the new requests to the existing request_list
    request_list.push_back(request1);
    request_list.push_back(request2);

    // Link requests to members and services
    member_list[1]->acceptRequest(request1);
    member_list[0]->acceptRequest(request2);
    service_list[0]->addRequest(request1);
    service_list[1]->addRequest(request2);
}

bool System::saveAllMembers()
{
    std::ofstream memberFile(MEMBER_FILE, std::ios::out);

    if (!memberFile.is_open())
    {
        std::cout << "Failed to create/open member file\n";
        return false;
    }

    for (const Member *member : member_list)
    {
        memberFile << member->getMemberId() << ","
                   << member->getUsername() << ","
                   << member->getPassword() << ","
                   << member->getFullName() << ","
                   << member->getPhoneNumber() << ","
                   << member->getEmail() << ","
                   << member->getHomeAddress() << ","
                   << member->getHostScore() << ","
                   << member->getSupporterScore() << ","
                   << member->getCreditPoint() << "\n"; // Use '\n' for a newline character
    }

    memberFile.close();

    std::cout << "Saved " << Colors::YELLOW << member_list.size() << Colors::GREEN << " members." << Colors::RESET << endl;

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

    for (const Skill *skill : skill_list)
    { // Use const reference to avoid unnecessary copy
        skillFile << skill->getSkillId() << ","
                  << skill->getOwner()->getMemberId() << ","
                  << skill->getSkillName() << ","
                  << skill->getRatingScore() << "\n"; // Use '\n' for a newline character
    }

    skillFile.close();

    std::cout << "Saved " << Colors::YELLOW << skill_list.size() << Colors::GREEN << " skills." << Colors::RESET << endl;

    return true;
}

bool System::saveAllRequests()
{
    std::ofstream requestFile(REQUEST_FILE, std::ios::out);

    if (!requestFile.is_open())
    {
        std::cout << "Failed to create/open request file\n";
        return false;
    }

    for (const Request *request : request_list)
    { // Use const reference to avoid unnecessary copy
        requestFile << request->getRequestId() << ","
                    << request->getService()->getServiceId() << ","
                    << request->getRequester()->getMemberId() << ","
                    << request->getStartTime().toString() << ","

                    << request->getEndTime().toString() << ","
                    << request->getSkill()->getSkillId() << ","
                    << request->getStatus() << ","
                    << "\n"; // Use '\n' for a newline character
    }

    requestFile.close();

    cout << "Saved " << Colors::YELLOW << request_list.size() << Colors::GREEN << " skills." << Colors::RESET << endl;

    return true;
}

bool System::saveAllServices()
{
    std::ofstream serviceFile(SERVICE_FILE, std::ios::out);

    if (!serviceFile.is_open())
    {
        std::cout << "Failed to create/open service file\n";
        return false;
    }

    for (const Service *service : service_list)
    { // Use const reference to avoid unnecessary copy
        serviceFile << service->getServiceId() << ","
                    << service->getServiceOwner()->getMemberId() << ","
                    << service->getStartTime().toString() << ","
                    << service->getEndTime().toString() << ","
                    << service->getConsumingCD() << ","
                    << service->getScoreRequired() << ",";

        // Save skill IDs separated by dashes
        const std::vector<Skill *> &skillList = service->getSkillList();
        for (size_t i = 0; i < skillList.size(); ++i)
        {
            serviceFile << skillList[i]->getSkillId();
            if (i < skillList.size() - 1)
            {
                serviceFile << "-";
            }
        }

        serviceFile << "\n"; // Use '\n' for a newline character
    }

    serviceFile.close();

    cout << "Saved " << Colors::YELLOW << service_list.size() << Colors::GREEN << " skills." << Colors::RESET << endl;

    return true;
}

bool System::saveAllReviews()
{
    std::ofstream reviewFile(REVIEW_FILE, std::ios::out);

    if (!reviewFile.is_open())
    {
        std::cout << "Failed to create/open review file\n";
        return false;
    }

    for (const Review *review : review_list)
    { // Use const reference to avoid unnecessary copy
        reviewFile << review->getReviewId() << ","
                   << review->getSkillRating() << ","
                   << review->getSupporterRating() << ","
                   << review->getHostRating() << ","
                   << review->getRequest()->getRequestId() << ","
                   << review->getComment() << ","
                   << "\n"; // Use '\n' for a newline character
    }

    reviewFile.close();

    cout << "Saved " << Colors::YELLOW << review_list.size() << Colors::GREEN << " reviews." << Colors::RESET << endl;
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
    loadAllReviews();
    std::cout << "\n"
              << "\n"
              << "\n";
    return true;
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

        Member *member = new Member(
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

    std::cout << "Loaded " << Colors::YELLOW << member_list.size() << Colors::GREEN << " members." << Colors::RESET << endl;
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
        Skill *skill = new Skill;
        Member *owner = getMemberByID(tokens[1]);
        skill->setSkillId(tokens[0]);
        skill->setOwner(owner);
        skill->setSkillName(tokens[2]);
        skill->setRatingScore(std::stod(tokens[3]));
        skill_list.push_back(skill);

        // Linking
        owner->addSkill(skill);
    }

    skillFile.close();

    std::cout << "Loaded " << Colors::YELLOW << skill_list.size() << Colors::GREEN << " skills." << Colors::RESET << endl;
    return true;
}

bool System::loadAllServices()
{
    service_list.clear();
    std::ifstream serviceFile(SERVICE_FILE, std::ios::in);

    if (!serviceFile.is_open())
    {
        std::cout << "Failed to open service file\n";
        return false;
    }

    std::string line;
    while (std::getline(serviceFile, line))
    {
        std::vector<std::string> tokens = splitStr(line, ",");

        if (tokens.size() != 7)
        {
            std::cout << "Invalid service data\n";
            continue;
        }

        Service *service = new Service();
        Member *owner = getMemberByID(tokens[1]);
        service->setServiceId(tokens[0]);
        service->setServiceOwner(owner);
        service->setStartTime(tokens[2]);
        service->setEndTime(tokens[3]);
        service->setConsumingCD(std::stoi(tokens[4]));
        service->setScoreRequired(std::stod(tokens[5]));

        // Load skill IDs from the string separated by dashes
        std::vector<std::string> skillIds = splitStr(tokens[6], "-");
        for (const std::string &skillId : skillIds)
        {
            Skill *skill = getSkillByID(skillId);
            if (skill)
            {
                // Linking
                service->addSkill(skill);
            }
            else
            {
                std::cout << "Invalid skill ID in service data\n";
            }
        }

        service_list.push_back(service);

        // Linking
        owner->addService(service);
    }

    serviceFile.close();

    cout << "Loaded " << Colors::YELLOW << service_list.size() << Colors::GREEN << " Service." << Colors::RESET << endl;
    return true;
}

bool System::loadAllRequests()
{
    request_list.clear();
    std::ifstream requestFile(REQUEST_FILE, std::ios::in);

    if (!requestFile.is_open())
    {
        std::cout << "Failed to open request file\n";
        return false;
    }

    std::string line;
    while (std::getline(requestFile, line))
    {
        std::vector<std::string> tokens = splitStr(line, ",");
        if (tokens.size() != 7)
        {
            std::cout << "Invalid request data\n";
            continue;
        }

        Request *request = new Request();
        Service *service = getServiceByID(tokens[1]);
        Member *requester = getMemberByID(tokens[2]);
        request->setRequestId(tokens[0]);
        request->setService(service);
        request->setRequester(requester);
        request->setStartTime(tokens[3]);
        request->setEndTime(tokens[4]);
        request->setSkill(getSkillByID(tokens[5]));
        request->setStatus(stoi(tokens[6]));

        request_list.push_back(request);

        // Linking
        service->addRequest(request);
        requester->addRequest(request);
        if (request->getStatus() == 1)
        {
            Member *serviceOwner = service->getServiceOwner();
            serviceOwner->acceptRequest(request);
        }
    }

    requestFile.close();

    cout << "Loaded " << Colors::YELLOW << request_list.size() << Colors::GREEN << " Requests." << Colors::RESET << endl;
    return true;
}

bool System::loadAllReviews()
{
    review_list.clear();
    std::ifstream reviewFile(REVIEW_FILE, std::ios::in);

    if (!reviewFile.is_open())
    {
        std::cout << "Failed to open review file\n";
        return false;
    }

    std::string line;
    while (std::getline(reviewFile, line))
    {
        std::vector<std::string> tokens = splitStr(line, ",");
        if (tokens.size() != 6)
        {
            std::cout << "Invalid review data\n";
            continue;
        }

        Review *review = new Review();
        Request *request = getRequestByID(tokens[4]);
        review->setReviewId(tokens[0]);
        review->setSkillRating(std::stoi(tokens[1]));
        review->setSupporterRating(std::stoi(tokens[2]));
        review->setHostRating(std::stoi(tokens[3]));
        review->setRequest(request);
        review->setComment(tokens[5]);

        review_list.push_back(review);
    };

    reviewFile.close();

    cout << "Loaded " << Colors::YELLOW << review_list.size() << Colors::GREEN << " Review." << Colors::RESET << endl;
    return true;
}

// get BY ID
string generateUUIDV4() {
    static std::random_device dev;
    static std::mt19937 rng(dev());

    std::uniform_int_distribution<int> dist(0, 15);

    const char* hexaDigits = "0123456789abcdef";
    const bool dashPostitions[] = {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0};

    string id;
    for (int i = 0; i < 16; i++) {
        if (dashPostitions[i]) id += "-";
        id += hexaDigits[dist(rng)];
        id += hexaDigits[dist(rng)];
    }
    return id;
}

string System::generateId() {
    return generateUUIDV4();
}

Member *System::getMemberByID(std::string memberId)
{
    for (Member *member : member_list)
    {
        if (member->getMemberId() == memberId)
        {
            return member;
        }
    }

    return nullptr;
}
Skill *System::getSkillByID(std::string skillId)
{
    for (Skill *skill : skill_list)
    {
        if (skill->getSkillId() == skillId)
        {
            return skill;
        }
    }

    return nullptr;
}
Service *System::getServiceByID(std::string serviceId)
{
    for (Service *service : service_list)
    {
        if (service->getServiceId() == serviceId)
        {
            return service;
        }
    }

    return nullptr;
}
Request *System::getRequestByID(std::string requestId)
{
    for (Request *request : request_list)
    {
        if (request->getRequestId() == requestId)
        {
            return request;
        }
    }

    return nullptr;
}
Review *System::getReviewByID(std::string reviewId)
{
    for (Review *review : review_list)
    {
        if (review->getReviewId() == reviewId)
        {
            return review;
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
        std::string token = str.substr(0, pos);
        if (!token.empty()) // Skip empty tokens
        {
            tokens.push_back(token);
        }
        str.erase(0, pos + delimiter.length());
    }

    // Add the last token (or the only token if there's no delimiter)
    if (!str.empty()) // Skip empty tokens
    {
        tokens.push_back(str);
    }

    return tokens;
}

void System::displayMemberProfile(Member *member)
{

    std::cout << Colors::MAGENTA << "Member Profile\n"
              << std::left << std::setw(10) << "ID"
              << std::left << std::setw(20) << "USERNAME"
              << std::left << std::setw(20) << "FULL NAME"
              << std::left << std::setw(20) << "PHONE NUMBER"
              << std::left << std::setw(20) << "EMAIL"
              << std::left << std::setw(20) << "HOME ADDRESS"
              << std::left << std::setw(20) << "HOST SCORE"
              << std::left << std::setw(20) << "SUPPORTER SCORE"
              << std::left << std::setw(20) << "CREDIT POINT"

              << Colors::RESET << endl;
    member->viewProfile();
}

void System::displayMemberSkillList(Member *member)
{

    member->showSkills();
}

// ---------------5. View Available Supporter (By Time or Location)----------------

// -----------------------6. Manage Request (View, Add, Delete)---------------------
void System::manageRequest()
{
    int choice;
    bool exit = false;
    do
    {

        std::cout << "1. View Request\n";
        std::cout << "2. Add Request\n";
        std::cout << "3. Delete Request\n";
        std::cout << "25. Back\n";
        std::cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;

        std::cin >> choice;
        switch (choice)
        {
        case 1:
            cout << Colors::GREEN << "--------------1. View Request----------------\n"
                 << Colors::RESET;
            currentMember->viewMyRequest();
            break;
        case 2:
            cout << Colors::GREEN << "--------------2. Add Request----------------\n"
                 << Colors::RESET;
            // show list of service
            break;
        case 3:
            cout << Colors::GREEN << "--------------3. Delete Request----------------\n"
                 << Colors::RESET;
            // show list of user request

            break;
        case 25:
            // displayMemberMenu();
            exit = true;
            break;
        }
    } while (!exit);
}
// --------------------------------------7. View Reviews-----------------------------
void System::viewReviews()
{
    cout << "List of my services' reviews: " << endl;
    for (Review *review : review_list)
    {
        if (review->getRequest()->getService()->getServiceOwner() == currentMember)
        {
            cout << Colors::CYAN << "Review ID: " << Colors::YELLOW << review->getReviewId() << endl;
            cout << Colors::CYAN << "Skill Rating: " << Colors::YELLOW << review->getSkillRating() << endl;
            cout << Colors::CYAN << "Supporter Rating: " << Colors::YELLOW << review->getSupporterRating() << endl;
            cout << Colors::CYAN << "Host Rating: " << Colors::YELLOW << review->getHostRating() << endl;
            cout << Colors::CYAN << "Service: " << Colors::YELLOW << review->getRequest()->getSkill()->getSkillName() << endl;
            cout << Colors::CYAN << "Comment: " << Colors::YELLOW << review->getComment() << endl;
            cout << "-----------------------------------------" << endl;
        }
    }
}
// -------------------------8. Add Review For Service--------------------------------
// -------------------------------------9. Rate Host----------------------------------
void System::hostRatingFunction()
{
    // show list of accepted request and let user choose
    int count = 1;
    cout << "List of accepted request: " << endl;
    for (Request *request : currentMember->getAcceptedRequest())
    {
        cout << Colors::CYAN << "Request No.: " << Colors::YELLOW << count << endl;
        cout << Colors::CYAN << "Request ID: " << Colors::YELLOW << request->getRequestId() << endl;
        cout << Colors::CYAN << "Service Name: " << Colors::YELLOW << request->getSkill()->getSkillName() << endl;
        cout << Colors::CYAN << "Host Name: " << Colors::YELLOW << request->getService()->getServiceOwner()->getFullName() << endl;
        cout << Colors::CYAN << "Start Time: " << Colors::YELLOW << request->getStartTime().toString() << endl;
        cout << Colors::CYAN << "End Time: " << Colors::YELLOW << request->getEndTime().toString() << endl;
        cout << Colors::CYAN << "Status: " << Colors::YELLOW << request->getStatus() << endl;
        count++;
    }
    // user choirce
    int requestNumber;
    cout << Colors::MAGENTA << "Please enter request number to rate host: " << Colors::RESET;
    cin >> requestNumber;
    while (requestNumber < 1 || requestNumber > currentMember->getAcceptedRequest().size())
    {
        cout << Colors::MAGENTA << "Invalid number. Please enter request number to rate host: " << Colors::RESET;
        cin >> requestNumber;
    }

    Request *request = currentMember->getAcceptedRequest()[requestNumber - 1];
    // rate host

    double score;
    cout << endl;
    cout << Colors::MAGENTA << "Please enter score to rate host: " << Colors::RESET;
    cin >> score;
    rateHost(request->getService()->getServiceOwner(), score, request);
}
void System::rateHost(Member *host, double score, Request *request)
{
    int numberOfHostReview = 0;
    int currentHostScore = host->getHostScore();
    // find review from review_list by request
    for (Review *review : review_list)
    {
        if (review->getRequest() == request)
        {

            numberOfHostReview++;
        }
    }
    // calculate new score
    double newHostScore = (currentHostScore * numberOfHostReview + score) / (numberOfHostReview + 1);
    host->setHostScore(newHostScore, request);
    cout << "Rated host " << Colors::YELLOW << host->getFullName() << Colors::GREEN << " with score " << Colors::YELLOW << score << Colors::RESET << endl;
}
// --------------------------10. Top up Credit Point-----------------------------------
void System::topUp()
{

    int creditPoint, choice;
    cout << "Please enter credit point to top up: ";
    cin >> creditPoint;
    cout << Colors::CYAN << " Your bill is " << Colors::BOLD << "$" << creditPoint << Colors::YELLOW << ". Please choose a payment method to complete the transaction: " << Colors::RESET << endl;
    cout << "1. Credit Card" << endl;
    cout << "2. Cash" << endl;
    cout << "3. Internet Banking" << endl;
    cout << "4. Cancel Payment" << endl;
    cout << Colors::GREEN << "Please enter your choice: " << Colors::RESET;

    switch (choice)
    {
    case 1:
    case 2:
    case 3:
        currentMember->addCD(100);
        cout << "Top up " << Colors::YELLOW << creditPoint << Colors::GREEN << " credit point to " << Colors::YELLOW << currentMember->getFullName() << Colors::RESET << endl;
        break;
    case 4:
        cout << "Confirm cancel paymen? (Y/N)" << endl;
        char confirm;
        cin >> confirm;
        if (confirm == 'Y' || confirm == 'y')
        {
            cout << "Cancel payment successfully" << endl;
            return;
        }
        else if (confirm == 'N' || confirm == 'n')
        {
            cout << "Cancel payment failed" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    default:
        cout << "Invalid choice. Please try again.\n";
        break;
    }
}
// -------------------------11. Blocking (View, Block, Unblock)------------------------
void System::manageBlockList()
{
    cout << Colors::GREEN << "1. View Block List" << endl;
    cout << Colors::GREEN << "2. Unblock Member" << endl;
    cout << Colors::GREEN << "3. Block Member" << endl;
    cout << Colors::GREEN << "4. Back" << endl;
    cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;
    int choice;
    cin >> choice;
    Member *member = new Member();
    switch (choice)
    {
    case 1:
        currentMember->showBlockedList();
        break;
    case 2:
        currentMember->showBlockedList();
        cout << Colors::CYAN << "Please enter the number of member you want to unblock: " << Colors::RESET;
        int number;
        cin >> number;
        while (number < 1 || number > currentMember->getBlockedList().size())
        {
            cout << Colors::MAGENTA << "Invalid number. Please enter the number of member you want to unblock: " << Colors::RESET;
            cin >> number;
        }

        member = currentMember->getBlockedList()[number - 1];
        currentMember->unblockMember(member);
        break;
    case 3:

        break;
    }
}

void System::printAllData()
{
    for (Member *member : member_list)
    {
        cout << member->getMemberId() << ","
             << member->getUsername() << ","
             << member->getPassword() << ","
             << member->getFullName() << ","
             << member->getPhoneNumber() << ","
             << member->getEmail() << ","
             << member->getHomeAddress() << ","
             << member->getHostScore() << ","
             << member->getSupporterScore() << ","
             << member->getCreditPoint() << "\n"; // Use '\n' for a newline character
        // Use '\n' for a newline character
    }
    for (Skill *skill : skill_list)
    { // Use const reference to avoid unnecessary copy
        cout << skill->getSkillId() << ","
             << skill->getOwner()->getMemberId() << ","
             << skill->getSkillName() << ","
             << skill->getRatingScore() << "\n"; // Use '\n' for a newline character
    }
    for (Service *service : service_list)
    { // Use const reference to avoid unnecessary copy
        cout << service->getServiceId() << ","
             << service->getServiceOwner()->getMemberId() << ","
             << service->getStartTime().toString() << ","
             << service->getEndTime().toString() << ","
             << service->getConsumingCD() << ","
             << service->getScoreRequired() << ",";
        for (Skill *skill : service->getSkillList())
        {
            cout << skill->getSkillId() << "-";
        }
        cout << "\n"; // Use '\n' for a newline character
    }
    for (Request *request : request_list)
    { // Use const reference to avoid unnecessary copy
        cout << request->getRequestId() << ","
             << request->getService()->getServiceId() << ","
             << request->getRequester()->getMemberId() << ","
             << request->getStartTime().toString() << ","
             << request->getEndTime().toString() << ","
             << request->getStatus() << ","
             << "\n"; // Use '\n' for a newline character
    }
    for (Review *review : review_list)
    { // Use const reference to avoid unnecessary copy
        cout << review->getReviewId() << ","
             << review->getSkillRating() << ","
             << review->getSupporterRating() << ","
             << review->getHostRating() << ","
             << review->getRequest()->getRequestId() << ","
             << review->getComment() << ","
             << "\n"; // Use '\n' for a newline character
    }
}

void System::displayServiceListing(Member *member)
{
    member->showListedService();
}