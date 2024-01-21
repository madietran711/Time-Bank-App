
#include <algorithm>
#include "System.h"
#include <random>
#include <vector>
#include <iostream>
std::regex usernameRegex("^[A-Za-z0-9_]{5,30}$"); // Alphanumeric and underscores, 5-30 characters
std::regex passwordRegex("^[A-Za-z0-9]{8,}$");    // Alphanumeric, minimum 8 characters
std::regex nameRegex("^[A-Za-z'\\- ]{1,50}$");
// Letters, hyphen, ap    ostrophe, up to 50 characters
std::regex phoneNumRegex("^[0-9]{8,15}$");                    // Only numbers, 8-15 digits
std::regex emailRegex("^[\\w.-]+@[\\w.-]+\\.[A-Za-z]{2,6}$"); // Simple email pattern
std::regex addressRegex("^[\\w\\s.,'-]{1,}$");                // Alphanumeric with space, comma, period, apostrophes, hyphen, minimum 10 characters
std::regex cityRegex("^(HANOI|SAIGON)$");

void System::run()

{
    // initData();
    loadAllData();
    printAllData();
    saveAllData();
    loadAllData();
    std::string groupNumber = "Group No.";
    std::string instructorName = "Mr. Tran Duc Linh";

    // Student information
    std::string student1ID = "s3926984";
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
    std::string username, password;
    bool exit = false;
    char confirm;
    int choice;
    do
    {
        // Print the main menu
        std::cout << Colors::GREEN << "--------------------------------------------------\n";
        std::cout << "Welcome to Time Bank Application\n";
        std::cout << "--------------------------------------------------\n"
                  << Colors::RESET;
        std::cout << Colors::YELLOW
                  << std::left << std::setw(20) << "[1] GUEST"
                  << std::left << std::setw(20) << "[2] MEMBER"
                  << std::left << std::setw(20) << "[3] ADMIN"
                  << std::left << std::setw(20) << "[4] EXIT"
                  << Colors::RESET << std::endl;
        std::cout << endl;
        std::cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;

        std::cin >> choice;
        switch (choice)
        {
        case 1:
            displayGuestMenu();
            break;
        case 2:
            // currentMember = getMemberByID("1");
            do
            {
                std::cout << Colors::CYAN << "Enter username: " << Colors::RESET;
                std::cin >> username;
                std::cout << Colors::CYAN << "Enter password: " << Colors::RESET;
                std::cin >> password;

                if (checkLogIn(username, password, "member"))
                {
                    isUserLoggedIn = true;
                    std::cout << Colors::GREEN << "Login as MEMBER successfully\n"
                              << Colors::RESET;
                    // assign member
                    currentMember = getMemberByUsername(username);
                    displayMemberMenu();
                }
                else
                {
                    std::cout << Colors::RED << "Login failed\n"
                              << Colors::RESET;
                    std::cout << Colors::CYAN << "Do you want to try again? (Y/N): " << Colors::RESET;

                    cin >> confirm;
                    if (confirm == 'Y' || confirm == 'y')
                    {
                        continue;
                    }
                    else
                    {

                        break;
                    }
                }
            } while (!isUserLoggedIn);

            break;
        case 3:
            do
            {
                std::cout << Colors::CYAN << "Enter username: " << Colors::RESET;
                std::cin >> username;
                std::cout << Colors::CYAN << "Enter password: " << Colors::RESET;
                std::cin >> password;

                if (checkLogIn(username, password, "admin"))
                {
                    isUserAdmin = true;
                    std::cout << Colors::GREEN << "Login as ADMIN successfully\n"
                              << Colors::RESET;
                    displayAdminMenu();
                }
                else
                {
                    std::cout << Colors::RED << "Login failed\n"
                              << Colors::RESET;
                    std::cout << Colors::CYAN << "Do you want to try again? (Y/N): " << Colors::RESET;

                    cin >> confirm;
                    if (confirm == 'Y' || confirm == 'y')
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            } while (!isUserAdmin);

            break;
        case 4:
            char choice;
            cout << "Do you want to exit? (Y/N): ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {
                saveAllData();
                exit = true;
            }
            else
            {
                break;
            }
        default:
            std::cout << "Invalid choice. Please try again.\n";

            break;
        }
    } while (!exit);
};

void System::displayGuestMenu()
{
    int choice;
    bool exit = false;
    do
    {
        std::cout << Colors::GREEN << "--------------------------------------------------\n";
        std::cout << "Time Bank Application - Welcome Guest\n";
        std::cout << "--------------------------------------------------\n"
                  << Colors::RESET;
        std::cout << Colors::YELLOW << std::setw(5) << "[1]"
                  << "View Available Services\n";
        std::cout << std::setw(5) << "[2]"
                  << "Register\n";

        std::cout << std::setw(5) << "[3]"
                  << "Exit\n";
        std::cout << endl;
        std::cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;

        std::cin >> choice;
        char viewSupporterChoice;
        int serviceChoice;
        Service *service;
        switch (choice)
        {
        case 1:
            std::cout << Colors::GREEN << "--------------1. View Available Services----------------\n"
                      << Colors::RESET;
            displayAllService();

            // choose to view supporter detail
            cout << Colors::CYAN << "Do you want to view supporter detail? (Y/N): " << Colors::RESET;
            cin >> viewSupporterChoice;
            if (viewSupporterChoice == 'Y' || viewSupporterChoice == 'y')
            {
                cout << Colors::CYAN << "Please enter the number of service you want to view the supporter detail: " << Colors::RESET;
                cin >> serviceChoice;
                while (serviceChoice < 1 || serviceChoice > service_list.size())
                {
                    cout << Colors::RED << "Invalid choice. Please try again: " << Colors::RESET;
                    cin >> serviceChoice;
                }
                service = service_list[serviceChoice - 1];
                displaySupporterDetail(service);
            }
            else
            {
                break;
            }
            break;

        case 2:
            std::cout << Colors::GREEN << "--------------2. Register----------------\n"
                      << Colors::RESET;
            registerNewAcc();
            std::cout << Colors::GREEN << "Account Registered, back to welcome menu to login as MEMBER\n"
                      << Colors::RESET;
            saveAllMembers();
            exit = true;
            break;

        case 3:
            std::cout << Colors::GREEN << "--------------3. Exit----------------\n"
                      << Colors::RESET;
            char choice;
            cout << Colors::CYAN << "Do you want to exit? (Y/N): " << Colors::RESET;
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {
                saveAllData();
                cout << Colors::MAGENTA << "Exiting...\n"
                     << Colors::RESET;
                exit = true;
            }
            else
            {
                break;
            }
        }
    } while (!exit);
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
        std::cout << Colors::YELLOW << std::setw(5) << "[1]"
                  << "Manage Profile (View, Edit)\n";
        std::cout << std::setw(5) << "[2]"
                  << "Manage Skills (View, Add, Delete)\n";
        std::cout << std::setw(5) << "[3]"
                  << "View Available Services\n";
        std::cout << std::setw(5) << "[4]"
                  << "Manage Service Listing (Add Service, Delete Service, View & Accept Request)\n";

        std::cout << std::setw(5) << "[5]"
                  << "Manage Request (View, Add)\n";
        std::cout << std::setw(5) << "[6]"
                  << "View Reviews For Your Service\n";
        std::cout << std::setw(5) << "[7]"
                  << "Manage Reviews For Supporters (View, Add)\n";
        std::cout << std::setw(5) << "[8]"
                  << "Rate Host\n";
        std::cout << std::setw(5) << "[9]"
                  << "Top up Credit Point\n";
        std::cout << std::setw(5) << "[10]"
                  << "Blocking (View, Block, Unblock)\n";

        std::cout << "[11] Logout\n";
        std::cout << endl;
        std::cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;

        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << Colors::GREEN << "----------------1. Manage Profile (View, Edit)----------------\n"
                      << Colors::RESET;
            manageProfile(currentMember);
            break;
        case 2:
            std::cout << Colors::GREEN << "----------------2. Manage Skills (View, Add, Delete)----------------\n"
                      << Colors::RESET;
            displayMemberSkillList(currentMember);
            manageSkills(currentMember);
            break;
        case 3:
            std::cout << Colors::GREEN << "----------------3. View Available Services----------------\n"
                      << Colors::RESET;
            // displayAvailableServices(currentMember);
            break;
        case 4:
            std::cout << Colors::GREEN << "----------------4. Manage Service Listing (Add Service, Delete Service, View & Accept Request)\n----------------\n"
                      << Colors::RESET;
            displayServiceListing(currentMember);
            manageServiceListing();
            break;

        case 5:
            // displayMemberMenu();
            std::cout << Colors::GREEN << "--------------5. Manage Request (View, Add, Delete)----------------\n"
                      << Colors::RESET;
            manageRequest();
            break;
        case 6:
            std::cout << Colors::GREEN << "--------------6. View Reviews For My Service----------------\n"
                      << Colors::RESET;
            viewReviews();
            break;
        case 7:
            std::cout << Colors::GREEN << "--------------7. Manage Reviews (View, Add)----------------\n"
                      << Colors::RESET;
            manageReviews();
            break;
        case 8:
            std::cout << Colors::GREEN << "--------------8. Rate Host----------------\n"
                      << Colors::RESET;
            hostRatingFunction();
            break;
        case 9:
            std::cout << Colors::GREEN << "--------------9. Top up Credit Point----------------\n"
                      << Colors::RESET;
            topUp();
            break;
        case 10:
            std::cout << Colors::GREEN << "--------------10. Blocking (View, Block, Unblock)----------------\n"
                      << Colors::RESET;
            manageBlockList();
            break;
        case 12:
            // displayMemberMenu();
            break;
        case 13:
            // displayMemberMenu();
            break;
        case 11:
            // displayMemberMenu();
            char choice;
            cout << "Do you want to log out? (Y/N): ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {

                saveAllData();
                currentMember = nullptr;
                exit = true;
            }
            else
            {
                break;
            }
        }
    } while (!exit);
}

void System::displayAdminMenu()
{

    int choice;
    string newPassword;
    bool exit = false;
    bool validPassword = false;
    do
    {
        std::cout << Colors::GREEN << "--------------------------------------------------\n";
        std::cout << "Time Bank Application - Welcome " << adminUsername << "\n";
        std::cout << "--------------------------------------------------\n"
                  << Colors::RESET;
        std::cout << Colors::YELLOW << std::setw(5) << "[1]"
                  << "View all Members\n";
        std::cout << std::setw(5) << "[2]"
                  << "Change Member Password\n";
        std::cout << std::setw(5) << "[3]"
                  << "Log Out";

        std::cout << endl;
        std::cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;

        std::cin >> choice;
        int count = 1;
        switch (choice)
        {
        case 1:
            std::cout << Colors::GREEN << "--------------1. View all Members----------------\n"
                      << Colors::RESET;

            displayAllMember();
            break;
        case 2:
            std::cout << Colors::GREEN << "--------------2. Change member password----------------\n"
                      << Colors::RESET;
            displayAllMember();
            int memberNo;
            cout << Colors::CYAN << "Please enter the number of member you want to change password: ";
            cin >> memberNo;
            while (memberNo < 1 || memberNo > member_list.size())
            {
                cout << Colors::RED << "Invalid choice. Please try again: " << Colors::RESET;
                cin >> memberNo;
            }

            do
            {
                cout << "Please enter new password: ";
                cin >> newPassword;
                if (Utilities::validatePassword(newPassword))
                {
                    validPassword = true;
                    cout << Colors::GREEN << "Password is valid.\n"
                         << Colors::RESET;
                    char confirm;
                    cout << Colors::CYAN << "Are you sure you want to change password? (Y/N): " << Colors::RESET;
                    cin >> confirm;
                    if (confirm == 'Y' || confirm == 'y')
                    {
                        member_list[choice - 1]->setPassword(newPassword);
                        cout << Colors::GREEN << "Password changed successfully for "
                             << Colors::BOLD << member_list[choice - 1]->getFullName() << Colors::RESET << endl;
                    }
                    else
                    {
                        cout << "Password not changed!\n";
                    }
                }
                else
                {
                    validPassword = false;
                    cout << Colors::RED << "Password is invalid.\n"
                         << Colors::RESET;
                }
            } while (!validPassword);

            break;

        case 3:
            // displayMemberMenu();
            char choice;
            cout << Colors::CYAN << "Do you want to log out? (Y/N): " << Colors::RESET;
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {
                saveAllData();
                isUserAdmin = false;
                exit = true;
            }
            else
            {
                break;
            }
        }
    } while (!exit);
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
        cout << "member id: " << member->getMemberId() << endl;
        cout << "username: " << member->getUsername() << endl;
        memberFile << member->getMemberId() << ","
                   << member->getUsername() << ","
                   << member->getPassword() << ","
                   << member->getFullName() << ","
                   << member->getPhoneNumber() << ","
                   << member->getEmail() << ","
                   << member->getHomeAddress() << ","
                   << member->getCity() << ","
                   << member->getHostScore() << ","
                   << member->getSupporterScore() << ","
                   << member->getCreditPoint();
        // Save blocked member IDs separated by dashes
        const std::vector<Member *> &blockedList = member->getBlockedList();
        // check if blocked list is empty
        if (blockedList.size() == 0)
        {
            memberFile << " ,";
        }
        for (size_t i = 0; i < blockedList.size(); ++i)
        {
            memberFile << blockedList[i]->getMemberId();
            if (i < blockedList.size() - 1)
            {
                memberFile << "-";
            }
        }

        memberFile << "\n";
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
    {
        skillFile << skill->getSkillId() << ","
                  << skill->getOwner()->getMemberId() << ","
                  << skill->getSkillName() << ","
                  << skill->getRatingScore() << "\n";
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
    {
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
        if (tokens.size() != 12)
        {
            std::cout << "Invalid member data\n";
            continue;
        }

        Member *member = new Member();
        member->setMemberId(tokens[0]);
        member->setUsername(tokens[1]);
        member->setPassword(tokens[2]);
        member->setFullName(tokens[3]);
        member->setPhoneNumber(tokens[4]);
        member->setEmail(tokens[5]);
        member->setHomeAddress(tokens[6]);
        member->setCity(tokens[7]);
        member->setHostScore(std::stoi(tokens[8]));
        member->setSupporterScore(std::stoi(tokens[9]));
        member->setCreditPoint(std::stoi(tokens[10]));

        member_list.push_back(member);
    }
    memberFile.close();
    std::ifstream memberFile2(MEMBER_FILE, std::ios::in);
    while (std::getline(memberFile2, line))
    {
        std::vector<std::string> tokens = splitStr(line, ",");
        if (tokens.size() != 12)
        {
            std::cout << "Invalid member data\n";
            continue;
        }

        Member *member = getMemberByID(tokens[0]);

        // Load skill IDs from the string separated by dashes
        std::vector<std::string> blockedList = splitStr(tokens[11], "-");
        for (const std::string &blockedId : blockedList)
        {
            Member *blockedMember = getMemberByID(blockedId);
            if (blockedMember)
            {
                // Linking
                member->blockMember(blockedMember);
                cout << "Blocked " << blockedMember->getFullName() << endl;
            }
            else
            {
                std::cout << "Invalid member ID in block list data\n";
            }
        }
    }
    memberFile2.close();

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

// ID generation
string generateUUIDV4()
{
    static std::random_device dev;
    static std::mt19937 rng(dev());

    std::uniform_int_distribution<int> dist(0, 15);

    const char *hexaDigits = "0123456789abcdef";

    std::stringstream id;
    for (int i = 0; i < 32; i++)
    {
        id << hexaDigits[dist(rng)];
    }
    return id.str();
}
string System::generateId()
{
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
              << std::left << std::setw(10) << "PHONE"
              << std::left << std::setw(25) << "EMAIL"
              << std::left << std::setw(20) << "HOME ADDRESS"
              << std::left << std::setw(10) << "CITY"
              << std::left << std::setw(10) << "HOST SCR"
              << std::left << std::setw(10) << "SUPPORTER SCR"
              << std::left << std::setw(10) << "CREDIT POINT"

              << Colors::RESET << endl;
    member->viewProfile();
}

void System::displayMemberSkillList(Member *member)
{

    member->showSkills();
}

// -----------------------6. Manage Request (View, Add, Delete)---------------------
void System::manageRequest()
{
    int choice;
    bool exit = false;
    do
    {

        std::cout << Colors::YELLOW << "[1]  View Request\n";
        std::cout << "[2] Add Request\n";
        std::cout << "[3] Back\n";
        std::cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;

        std::cin >> choice;
        int serviceNumber;
        Request *newRequest;
        string startTime, endTime;
        int count = 1;
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
            //             cout << Colors::GREEN << "List of available services: " << endl;

            //             cout << Colors::CYAN << "Enter service number to add request: " << Colors::RESET;
            //             cin >> serviceNumber;

            //             while (serviceNumber < 1 || serviceNumber > service_list.size())
            //             {
            //                 cout << Colors::RED << "Invalid number. Please enter service number to add request: " << Colors::RESET;
            //                 cin >> serviceNumber;
            //             }

            //             Service *service = service_list[serviceNumber - 1];
            //             user Input

            //                     cout
            //                 << "Enter start time (yyyy/mm/dd hh:mm): ";
            //             cin.ignore();
            //             getline(cin, startTime);
            //             cout << "Enter end time (yyyy/mm/dd hh:mm): ";
            //             cin.ignore();
            //             getline(cin, endTime);
            //  ___________REMEMBER TO APPLY LOGIC TO CALCULATE CREDIT POINTS TO SEE IF USER HAS ENOUGH CREDIT POINTS TO REQUEST SERVICE_____________________
            //             cout << "Enter skill number to request: ";

            //             for (Skill *skill : service->getSkillList())
            //             {
            //                 cout << count << ". " skill->getSkillName() << "\n ";
            //                 count++
            //             }
            //             cin >> skillNumber;
            //             while (skillNumber < 1 || skillNumber > service->getSkillList().size())
            //             {
            //                 cout << Colors::RED << "Invalid number. Please enter skill number to request: " << Colors::RESET;
            //                 cin >> skillNumber;
            //             }
            //             Skill *skill = service->getSkillList()[skillNumber - 1];
            //             newRequest = new Request(generateId(), service, currentMember, Date::parse(startTime), Date::parse(endTime), skill, 0);
            //             request_list.push_back(newRequest);
            //             currentMember->addRequest(newRequest);
            //             service->addRequest(newRequest);
            //             cout << Colors::GREEN << "Request added successfully.\n"
            //                  << Colors::RESET;
            // cout<<endl;
            //                currentMember->viewMyRequest();
            break;

        case 3:
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
// -------------------------8.  Manage Review For Supporter Service--------------------------------
void System::manageReviews()
{
    int choice;
    bool exit = false;
    do
    {
        std::cout << endl;
        std::cout << Colors::YELLOW << "[1] View Reviews\n";
        std::cout << Colors::YELLOW << "[2] Add Reviews\n";
        std::cout << Colors::YELLOW << "[3] Back\n";

        std::cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;

        // variable declartion
        std::vector<Request *> acceptedSupporterRequest;

        int count = 1;
        bool isNewReview;
        int requestNumber, hostRating;
        Review *newReview;
        Review *editReview;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            cout << Colors::GREEN << "--------------1. View Reviews----------------\n"
                 << Colors::RESET;
            // show list of reviews that user have made
            cout << "List of reviews that you have made: " << endl;
            for (Review *review : review_list)
            {
                if (review->getRequest()->getRequester() == currentMember)
                {
                    cout << Colors::MAGENTA << "Review ID: " << Colors::YELLOW << review->getReviewId() << endl;
                    cout << Colors::MAGENTA << "Skill Rating: " << Colors::YELLOW << review->getSkillRating() << endl;
                    cout << Colors::MAGENTA << "Supporter Rating: " << Colors::YELLOW << review->getSupporterRating() << endl;
                    cout << Colors::MAGENTA << "Host Rating: " << Colors::YELLOW << review->getHostRating() << endl;
                    cout << Colors::MAGENTA << "Service: " << Colors::YELLOW << review->getRequest()->getSkill()->getSkillName() << endl;
                    cout << Colors::MAGENTA << "Comment: " << Colors::YELLOW << review->getComment() << endl;
                    cout << "-----------------------------------------" << endl;
                }
            }
            break;
        case 2:
            cout << Colors::GREEN << "--------------2. Add Reviews----------------\n"
                 << Colors::RESET;
            // show list of supporter service
            cout << "List of services that you have been supported: " << endl;

            for (Request *request : currentMember->getMyRequest())
            {
                if (request->getStatus() == 1)
                {
                    acceptedSupporterRequest.push_back(request);
                }
            }
            // check empty
            if (acceptedSupporterRequest.size() == 0)
            {
                cout << Colors::RED << "You have not been supported any service yet.\n"
                     << Colors::RESET;
                break;
            }
            count = 1;
            for (Request *request : acceptedSupporterRequest)
            {
                cout << Colors::MAGENTA << "Service No.: " << Colors::YELLOW << count << endl;
                cout << Colors::MAGENTA << "Service Name: " << Colors::YELLOW << request->getSkill()->getSkillName() << endl;
                cout << Colors::MAGENTA << "Supporter Name: " << Colors::YELLOW << request->getService()->getServiceOwner()->getFullName() << endl;
                cout << Colors::MAGENTA << "Start Time: " << Colors::YELLOW << request->getStartTime().toString() << endl;
                cout << Colors::MAGENTA << "End Time: " << Colors::YELLOW << request->getEndTime().toString() << endl;
                cout << Colors::MAGENTA << "Status: " << Colors::YELLOW << request->getStatus() << endl;
                count++;
            }
            // user choice

            cout << Colors::CYAN << "Please enter service number to add review: " << Colors::RESET;
            cin >> requestNumber;
            while (requestNumber < 1 || requestNumber > acceptedSupporterRequest.size())
            {
                cout << Colors::MAGENTA << "Invalid number. Please enter service number to add review: " << Colors::RESET;
                cin >> requestNumber;
            }
            Request *request;
            request = acceptedSupporterRequest[requestNumber - 1];

            // find if the review already exist
            isNewReview = true;
            for (Review *review : review_list)
            {
                // if review exist
                if (review->getRequest() == request && review->getSkillRating() != 0 && review->getSupporterRating() != 0)
                {
                    isNewReview = false;
                    cout << Colors::RED << "You have already reviewed this service.\n"
                         << Colors::RESET;
                    cout << Colors::CYAN << "Do you want to edit your review? (Y/N): " << Colors::RESET;
                    char confirm;
                    cin >> confirm;
                    if (confirm == 'Y' || confirm == 'y')
                    {
                        editReview = inputReview(request, review->getReviewId());
                        review->setComment(editReview->getComment());
                        review->setSkillRating(editReview->getSkillRating());
                        review->setSupporterRating(editReview->getSupporterRating());
                        cout << "Edited review for " << Colors::YELLOW << request->getService()->getServiceOwner()->getFullName() << Colors::GREEN << " successfully." << Colors::RESET << endl;
                        break;
                    }
                    else
                    {
                        break;
                    }
                    break;
                }

                // if review exist but only the supporter has reviewed not the host
                else if (review->getRequest() == request && review->getHostRating() != 0)
                {
                    isNewReview = false;
                    hostRating = review->getHostRating();
                    newReview = inputReview(request, review->getReviewId());
                    review->setComment(newReview->getComment());
                    review->setSkillRating(newReview->getSkillRating());
                    review->setSupporterRating(newReview->getSupporterRating());
                    cout << "Added review for " << Colors::YELLOW << request->getService()->getServiceOwner()->getFullName() << Colors::GREEN << " successfully." << Colors::RESET << endl;
                    break;
                }
            }
            // if review not exist
            if (isNewReview)
            {
                newReview = inputReview(request, System::generateId());

                review_list.push_back(newReview);

                Member *serviceOwner;
                serviceOwner = request->getService()->getServiceOwner();

                cout << "Added review for " << Colors::YELLOW << serviceOwner->getFullName() << Colors::GREEN << " successfully." << Colors::RESET << endl;
                break;
            }

        case 3:

            exit = true;
            break;
        }
    } while (!exit);
}

Review *System::inputReview(Request *request, string reviewID)
{

    int hostRating, supporterRating, skillRating;
    string comment;

    cout << Colors::CYAN << "Enter your comment for service: ";
    cin.ignore();
    getline(cin, comment);
    bool isValidRating = false;
    do
    {
        cout << Colors::CYAN << "Enter your rating for skill: ";
        int skillRating;
        cin >> skillRating;
        isValidRating = Utilities::validateUserRating(skillRating);
    } while (!isValidRating);

    isValidRating = false;
    do
    {
        cout << Colors::CYAN << "Enter your rating for supporter: ";
        cin >> supporterRating;
        isValidRating = Utilities::validateUserRating(supporterRating);
    } while (!isValidRating);

    return new Review(reviewID, skillRating, supporterRating, request, comment);
}
void System::rateSupporter(Member *supporter, double score, Request *request, bool isNewReview, double skillScore)
{
    Review *existedReview;
    int numberOfSupporterReview = 0;
    int currentSupporterScore = supporter->getSupporterScore();
    Skill *skill = request->getSkill();
    int currentSkillScore = skill->getRatingScore();
    // find number of review related to the supporter
    bool isExistedReviewButOnlySupporterRate = false;
    for (Review *review : review_list)
    {
        if (review->getRequest()->getService()->getServiceOwner() == supporter && review->getSupporterRating() != 0)
        {
            numberOfSupporterReview++;
        }
        // get the exsisted review
        if (review->getRequest() == request && review->getSupporterRating() != 0)
        {
            existedReview = review;
        }
        else if (review->getRequest() == request && review->getSupporterRating() == 0 && review->getHostRating() != 0)
        {
            isExistedReviewButOnlySupporterRate = true;
            existedReview = review;
        }
    }

    // calculate new score for supporter or update score
    if (isNewReview)
    {
        double newSkillScore = (currentSkillScore * numberOfSupporterReview + skillScore) / (numberOfSupporterReview + 1);
        double newSupporterScore = (currentSupporterScore * numberOfSupporterReview + score) / (numberOfSupporterReview + 1);
        supporter->setSupporterScore(newSupporterScore);
        skill->setRatingScore(newSkillScore);
        Review *newReview = new Review(generateId(), skillScore, score, 0, request, "");
        review_list.push_back(newReview);
    }
    else
    { // if review exist but only the host has reviewed not the supporter
        if (isExistedReviewButOnlySupporterRate)
        {
            double newSupporterScore = (currentSupporterScore * numberOfSupporterReview + score) / (numberOfSupporterReview + 1);
            supporter->setSupporterScore(newSupporterScore);
            existedReview->setSupporterRating(score);
        }
        else
        {
            // exclude the existed score
            currentSkillScore = currentSkillScore - existedReview->getSkillRating();
            currentSupporterScore = currentSupporterScore - existedReview->getSupporterRating();

            // recalculate the score
            double newSkillScore = (currentSkillScore * numberOfSupporterReview + skillScore) / (numberOfSupporterReview);
            double newSupporterScore = (currentSupporterScore * numberOfSupporterReview + score) / (numberOfSupporterReview);
            supporter->setSupporterScore(newSupporterScore);
            skill->setRatingScore(newSkillScore);
            existedReview->setSupporterRating(score);
            existedReview->setSkillRating(skillScore);
        }
    }
}

// -------------------------------------9. Rate Host----------------------------------
void System::hostRatingFunction()
{
    // show list of accepted request and let user choose
    int count = 1;
    double score;
    cout << "List of accepted request for your service: " << endl;
    for (Request *request : currentMember->getAcceptedRequest())
    {
        cout << Colors::CYAN << "Request No.: " << Colors::YELLOW << count << endl;
        cout << Colors::CYAN << "Request ID: " << Colors::YELLOW << request->getRequestId() << endl;
        cout << Colors::CYAN << "Service Name: " << Colors::YELLOW << request->getSkill()->getSkillName() << endl;
        cout << Colors::CYAN << "Host Name: " << Colors::YELLOW << request->getRequester()->getFullName() << endl;
        cout << Colors::CYAN << "Start Time: " << Colors::YELLOW << request->getStartTime().toString() << endl;
        cout << Colors::CYAN << "End Time: " << Colors::YELLOW << request->getEndTime().toString() << endl;
        cout << Colors::CYAN << "Status: " << Colors::YELLOW << request->getStatus() << endl;
        count++;
    }
    // user choice
    int requestNumber;
    cout << Colors::MAGENTA << "Please enter request number to rate host: " << Colors::RESET;
    cin >> requestNumber;
    while (requestNumber < 1 || requestNumber > currentMember->getAcceptedRequest().size())
    {
        cout << Colors::MAGENTA << "Invalid number. Please enter request number to rate host: " << Colors::RESET;
        cin >> requestNumber;
    }

    Request *request = currentMember->getAcceptedRequest()[requestNumber - 1];

    // check if review exist
    bool isNewReview = true;
    for (Review *review : review_list)
    {
        if (review->getRequest() == request && review->getHostRating() != 0)
        {
            isNewReview = false;
            cout << Colors::RED << "You have already reviewed this host.\n"
                 << Colors::RESET;
            cout << Colors::CYAN << "Do you want to edit your review? (Y/N): " << Colors::RESET;
            char confirm;
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y')
            {
                cout << endl;
                cout << Colors::MAGENTA << "Please enter score to rate host: " << Colors::RESET;
                cin >> score;
                rateHost(request->getRequester(), score, request, false);
                cout << "Edited host score for " << Colors::YELLOW << request->getRequester()->getFullName() << Colors::GREEN << " successfully." << Colors::RESET << endl;
                break;
            }
            else
            {
                break;
            }
        }
        // review exist but only the host has reviewed not the supporter
        else if (review->getRequest() == request && review->getSupporterRating() != 0 && review->getSkillRating() != 0)
        {
            isNewReview = false;
            cout << Colors::MAGENTA << "Please enter score to rate host: " << Colors::RESET;
            cin >> score;
            rateHost(request->getRequester(), score, request, false);
        }
    }

    if (isNewReview)
    {
        // rate host
        cout << endl;
        cout << Colors::MAGENTA << "Please enter score to rate host: " << Colors::RESET;
        cin >> score;
        rateHost(request->getRequester(), score, request, true);
        cout << "Rated host " << Colors::YELLOW << request->getRequester()->getFullName() << Colors::GREEN << " with score " << Colors::YELLOW << score << Colors::RESET << endl;
    }
}
void System::rateHost(Member *host, double score, Request *request, bool isNewReview)
{
    Review *existedReview;
    int numberOfHostReview = 0;
    int currentHostScore = host->getHostScore();
    bool isExistedReviewButOnlySupporterRate = false;
    // find number of review related to the host
    for (Review *review : review_list)
    {
        if (review->getRequest()->getRequester() == host && review->getHostRating() != 0)
        {
            numberOfHostReview++;
        }
        // get the exsisted review
        if (review->getRequest() == request && review->getHostRating() != 0)
        {
            existedReview = review;
        }
        else if (review->getRequest() == request && review->getHostRating() == 0)
        {
            isExistedReviewButOnlySupporterRate = true;
            existedReview = review;
        }
    }

    // calculate new score for Host or update score
    if (isNewReview)
    {
        double newHostScore = (currentHostScore * numberOfHostReview + score) / (numberOfHostReview + 1);
        host->setHostScore(newHostScore, request);
        Review *newReview = new Review(generateId(), 0, 0, score, request, "");
        review_list.push_back(newReview);
    }
    else
    {
        // if review exist but only the supporter has reviewed not the host
        if (isExistedReviewButOnlySupporterRate)
        {
            double newHostScore = (currentHostScore * numberOfHostReview + score) / (numberOfHostReview + 1);
            host->setHostScore(newHostScore, request);
            existedReview->setHostRating(score);
        }
        else
        {
            // exclude the existed score
            currentHostScore = currentHostScore - existedReview->getHostRating();
            double newHostScore = (currentHostScore * numberOfHostReview + score) / (numberOfHostReview);
            host->setHostScore(newHostScore, request);
            existedReview->setHostRating(score);
        }
    }
}
// --------------------------10. Top up Credit Point-----------------------------------
void System::topUp()
{

    int creditPoint, choice;
    cout << "Please enter credit point to top up: ";
    cin >> creditPoint;
    cout << Colors::CYAN << " Your bill is " << Colors::BOLD << "$" << creditPoint << Colors::MAGENTA << ". Please choose a payment method to complete the transaction: " << Colors::RESET << endl;
    cout << "1. Credit Card" << endl;
    cout << "2. Cash" << endl;
    cout << "3. Internet Banking" << endl;
    cout << "4. Cancel Payment" << endl;
    cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;
    cin >> choice;

    switch (choice)
    {
    case 1:
    case 2:
    case 3:
        currentMember->addCD(100);
        cout << "Top up " << Colors::YELLOW << creditPoint << Colors::GREEN << " credit point to " << Colors::YELLOW << currentMember->getFullName() << Colors::RESET << endl;
        break;
    case 4:
        cout << Colors::CYAN << "Confirm cancel payment? (Y/N)" << Colors::RESET << endl;
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
    bool exit = false;
    do
    {
        cout << endl;
        cout << Colors::YELLOW << "[1] View Block List" << endl;
        cout << Colors::YELLOW << "[2] Unblock Member" << endl;
        cout << Colors::YELLOW << "[3] Block Member" << endl;
        cout << Colors::YELLOW << "[4] Back" << endl;
        cout << endl;
        cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;
        int choice;
        cin >> choice;
        Member *member = new Member();
        bool isAlreadyBlocked = false;
        int count = 1;
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
            cout << "Unblocked " << Colors::YELLOW << member->getFullName() << Colors::RESET << endl;
            break;
        case 3:
            // show list of member that have interacted with current member
            cout << "List of member that have interacted with you: " << endl;

            if (currentMember->getInteractedMembers().size() == 0)
            {
                cout << Colors::RED << "No member found" << Colors::RESET << endl;
                break;
            }
            cout << Colors::MAGENTA << std::left << std::setw(5) << "No."
                 << std::left << std::setw(20) << "USERNAME"
                 << std::left << std::setw(20) << "FULL NAME" << Colors::RESET << endl;

            count = 1;
            for (Member *member : currentMember->getInteractedMembers())
            {
                cout << Colors::YELLOW << setw(5) << count << setw(20) << member->getUsername() << setw(20) << member->getFullName() << Colors::RESET << endl;
                count++;
            }
            cout << Colors::CYAN << "Please enter the number of member you want to block: " << Colors::RESET;
            int blockMemberNo;
            cin >> blockMemberNo;
            while (blockMemberNo < 1 || blockMemberNo > currentMember->getInteractedMembers().size())
            {
                cout << Colors::MAGENTA << "Invalid number. Please enter the number of member you want to block: " << Colors::RESET;
                cin >> blockMemberNo;
            }
            member = currentMember->getInteractedMembers()[blockMemberNo - 1];

            // check if member is already blocked

            for (Member *blockedMember : currentMember->getBlockedList())
            {
                if (blockedMember == member)
                {
                    isAlreadyBlocked = true;
                    cout << Colors::RED << "Member " << Colors::YELLOW << member->getFullName() << Colors::RED << " is already blocked." << Colors::RESET << endl;
                    break;
                }
            }

            if (!isAlreadyBlocked)
            {
                currentMember->blockMember(member);
                cout << "Blocked " << Colors::YELLOW << member->getFullName() << Colors::RESET << endl;
            }

            break;
        case 4:
            cout << Colors::CYAN << "Do you want to go back? (Y/N)" << Colors::RESET << endl;
            char confirm;
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y')
            {
                exit = true;
            }
        }
    } while (!exit);
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
             << member->getCreditPoint() << ",";
        for (Member *blockedMember : member->getBlockedList())
        {
            cout << blockedMember->getMemberId() << "-";
        }

        cout << "\n"; // Use '\n' for a newline character
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

// ADMIN
void System::displayAllMember()
{
    int count = 1;
    std::cout << Colors::MAGENTA << "Member Profile\n"
              << std::left << std::setw(5) << "No."
              << std::left << std::setw(10) << "ID"
              << std::left << std::setw(20) << "USERNAME"
              << std::left << std::setw(20) << "FULL NAME"
              << std::left << std::setw(10) << "PHONE"
              << std::left << std::setw(25) << "EMAIL"
              << std::left << std::setw(20) << "HOME ADDRESS"
              << std::left << std::setw(10) << "CITY"
              << std::left << std::setw(1) << "HOST SCR"
              << std::left << std::setw(10) << "SUPPORTER SCR"
              << std::left << std::setw(10) << "CREDIT POINT"

              << Colors::RESET << endl;
    for (Member *member : member_list)
    {

        cout << Colors::YELLOW
             << std::left << std::setw(5) << count;
        member->viewProfile();
        count++;
    }
}
void System::manageProfile(Member *member)
{
    displayMemberProfile(currentMember);
    std::string inputPW;
    int subchoice;
    bool exit = false;
    do
    {
    std:
        cout << endl;
        std::cout << Colors::YELLOW << "[1] Edit Profile\n";
        std::cout << "[2] Change Password\n";
        std::cout << "[3] Back\n";
        std::cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;
        std::cin >> subchoice;
        switch (subchoice)
        {
        case 1:
            std::cout << Colors::GREEN << "----------------1. Edit Profile----------------\n"
                      << Colors::RESET;
            std::cout << "Enter current Password: ";
            cin.ignore();
            std::getline(std::cin, inputPW);

            if (inputPW == currentMember->getPassword())
            {
                std::cout << "Enter new Username: ";
                std::string newUsername;
                std::cin.ignore();
                std::getline(std::cin, newUsername);

                std::cout << "Enter new Full Name: ";
                std::string newFullName;
                std::cin.ignore();
                std::getline(std::cin, newFullName);

                std::cout << "Enter new Phone Number: ";
                std::string newPhoneNumber;
                std::cin.ignore();
                std::getline(std::cin, newPhoneNumber);

                std::cout << "Enter new Email Address: ";
                std::string newEmailAddress;
                std::cin.ignore();
                std::getline(std::cin, newEmailAddress);

                std::cout << "Enter new Home Address: ";
                std::string newHomeAddress;
                std::cin.ignore();
                std::getline(std::cin, newHomeAddress);

                std::cout << "Enter new City (HANOI/SAIGON): ";
                std::string newCity;
                std::cin.ignore();
                std::getline(std::cin, newCity);

                currentMember->setUsername(newUsername);
                currentMember->setFullName(newFullName);
                currentMember->setPhoneNumber(newPhoneNumber);
                currentMember->setEmail(newEmailAddress);
                currentMember->setHomeAddress(newHomeAddress);
                currentMember->setCity(newCity);
                displayMemberProfile(currentMember);
            }
            else
            {
                std::cout << "Incorrect Password!\n";
            }
            break;
        case 2:
            std::cout << "----------------2. Change Password----------------\n";
            std::cout << "Enter current Password: ";
            std::getline(std::cin, inputPW);
            std::cin.ignore();
            if (inputPW == currentMember->getPassword())
            {
                std::cout << "Enter new Password: ";
                std::string newPassword;
                std::getline(std::cin, newPassword);
                std::cin.ignore();
                currentMember->setPassword(newPassword);
            }
            else
            {
                std::cout << "Incorrect Password!\n";
            }
            break;
        case 3:
            // displayMemberMenu();
            exit = true;
            break;
        }
    } while (!exit);
}

void System::manageSkills(Member *member)
{
    int subchoice;
    bool exit = false;
    std::string newSkillID;
    std::string newSkillName;
    Skill *newSkill;
    std::string deletingSkillName;
    do
    {
        std::cout << endl;
        std::cout << Colors::YELLOW << "[1] Add a new skill\n";
        std::cout << "[2] Delete an existing skill\n";
        std::cout << "[3] Back\n";

        std::cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;

        int subchoice;
        auto it = currentMember->getSkills().end();

        std::cin >> subchoice;

        switch (subchoice)
        {
        case 1:
            std::cout << Colors::GREEN << "----------------1. Add a new skill----------------\n";

            std::cout << Colors::CYAN << "Enter new Skill Name: " << Colors::RESET;
            std::cin.ignore();
            std::getline(std::cin, newSkillName);

            newSkill = new Skill(generateId(), currentMember, newSkillName, 0);
            currentMember->addSkill(newSkill);
            skill_list.push_back(newSkill);
            displayMemberSkillList(member);
            break;
        case 2:
            std::cout << Colors::GREEN << "----------------2. Delete an existing skill----------------\n";
            std::cout << Colors::CYAN << "Enter the Skill Name of the skill to be deleted: " << Colors::RESET;
            cin.ignore();
            std::getline(std::cin, deletingSkillName);
            it = std::find_if(
                currentMember->getSkills().begin(),
                currentMember->getSkills().end(),
                [&deletingSkillName](const Skill *deletingSkillPtr)
                {
                    return deletingSkillPtr->getSkillName() == deletingSkillName;
                });
            if (it != currentMember->getSkills().end())
            {
                std::cout << Colors::GREEN << "Skill to be deleted found.\n"
                          << Colors::RESET;
                currentMember->removeSkill(*it);
                // delete skill from system vector
                skill_list.erase(std::remove(skill_list.begin(), skill_list.end(), *it), skill_list.end());

                std::cout << "Skill successfully deleted.\n";
            }
            else
            {
                std::cout << Colors::RED << "Cannot find specified Skill.\n"
                          << Colors::RESET;
            }
            displayMemberSkillList(currentMember);
            break;
        case 3:
            // displayMemberMenu();
            exit = true;
            break;
        }
    } while (!exit);
}

void System::displayServiceListing(Member *member)
{
    member->showListedService();
}

void System::manageServiceListing()
{
    bool exit = false;
    do
    {
        std::cout << Colors::YELLOW << "[1] Add a new service\n";
        std::cout << "[2] Delete an existing service\n";
        std::cout << "[3] View available requests\n";
        std::cout << "[4] Return to Main Menu\n";

        std::cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;
        int subchoice;
        std::cin >> subchoice;
        Service *newService, *serviceToViewRequest;
        int requestNumber;
        Request *toBeAcceptRequest;
        bool deletingResult;
        std::string deletingServiceID, selectedSkillName, newServiceID;
        std::vector<Skill *> newServiceSkillList;
        auto it = currentMember->getSkills().end();
        auto itService = currentMember->getListedService().end();
        auto itt = newServiceSkillList.end();

        Date endDate, startDate;
        switch (subchoice)
        {
        case 1:
            std::cout << Colors::GREEN << "----------------1. Add a new service----------------\n"
                      << Colors::RESET;
            newServiceID = generateId();
            std::cout << "Enter new Service Start Time:\n";
            int startYear, startMonth, startDay, startHour, startMinute;
            std::cout << "Enter the Year: ";
            cin >> startYear;
            std::cin.ignore();
            std::cout << "Enter the Month: ";
            cin >> startMonth;
            std::cin.ignore();
            std::cout << "Enter the Day: ";
            cin >> startDay;
            std::cin.ignore();
            std::cout << "Enter the Hour: ";
            cin >> startHour;
            std::cin.ignore();
            std::cout << "Enter the Minute: ";
            cin >> startMinute;
            std::cin.ignore();
            startDate = Date(startYear, startMonth, startDay, startHour, startMinute);
            std::cout << "Enter new Service End Time: ";
            int endYear, endMonth, endDay, endHour, endMinute;
            std::cout << "Enter the Year: ";
            cin >> endYear;
            std::cin.ignore();
            std::cout << "Enter the Month: ";
            cin >> endMonth;
            std::cin.ignore();
            std::cout << "Enter the Day: ";
            cin >> endDay;
            std::cin.ignore();
            std::cout << "Enter the Hour: ";
            cin >> endHour;
            std::cin.ignore();
            std::cout << "Enter the Minute: ";
            cin >> endMinute;
            std::cin.ignore();
            endDate = Date(endYear, endMonth, endDay, endHour, endMinute);
            std::cout << "Enter new Service Consuming Credit Points: ";
            int newServiceCCD;
            std::cin >> newServiceCCD;
            std::cin.ignore();

        std:
            cout << "Enter new Service Minimum Host Score Required: ";
            double newSericeMinHostScore;
            std::cin >> newSericeMinHostScore;
            std::cin.ignore();
            displayMemberSkillList(currentMember);

            int count;
            std::cout << "Enter the number of Skills available for the new Service: ";
            std::cin >> count;
            std::cin.ignore();

            for (int i = 0; i < count; i++)
            {
                std::cout << "Enter the Skill Name: ";
                std::getline(std::cin, selectedSkillName);
                it = std::find_if(
                    currentMember->getSkills().begin(),
                    currentMember->getSkills().end(),
                    [&selectedSkillName](const Skill *selectedSkillPtr)
                    {
                        // Assuming Skill has a method getSkillName() to get the skill name
                        return selectedSkillPtr->getSkillName() == selectedSkillName;
                    });
                if (it != currentMember->getSkills().end())
                {
                    itt = std::find(newServiceSkillList.begin(), newServiceSkillList.end(), *it);
                    // Checking if the Skill has already been added to the NEW Service lisitng
                    if (itt != newServiceSkillList.end())
                    {
                        std::cout << "The Skill has already been listed.\n";
                        i--;
                    }
                    else
                    {
                        newServiceSkillList.push_back(*it);
                    }
                }
                else
                {
                    std::cout << "Cannot find specified Skill.\n";
                }
            }
            newService = new Service(newServiceID, currentMember, startDate, endDate, newServiceCCD, newSericeMinHostScore, newServiceSkillList, {});
            currentMember->addService(newService);
            service_list.push_back(newService);
            std::cout << "New Service listing has been successfully added!\n";
            displayServiceListing(currentMember);
            break;
        case 2:
            std::cout << Colors::GREEN << "----------------2. Delete an existing service----------------\n";
            displayServiceListing(currentMember);
            std::cout << Colors::CYAN << "Enter the Service ID of the skill to be deleted: " << Colors::RESET;

            std::getline(std::cin, deletingServiceID);
            itService = std::find_if(
                currentMember->getListedService().begin(),
                currentMember->getListedService().end(),
                [&deletingServiceID](const Service *deletingServicePtr)
                {
                    return deletingServicePtr->getServiceId() == deletingServiceID;
                });
            if (itService != currentMember->getListedService().end())
            {
                std::cout << "Service to be deleted found.\n";
                deletingResult = currentMember->removeService(*itService);
                if (deletingResult)
                {
                    std::cout << "Service successfully deleted.\n";
                }
                else
                {
                    std::cout << "Service cannot be deleted.\n";
                }
            }
            else
            {
                std::cout << "Cannot find specified Service.\n";
            }
            displayServiceListing(currentMember);
            break;
        case 3:
            std::cout << Colors::GREEN << "----------------3. View available requests----------------\n";
            displayServiceListing(currentMember);
            std::cout << Colors::CYAN << "Enter the  Number of the service to view requests: " << Colors::RESET;
            int serviceNumber;
            std::cin >> serviceNumber;
            if (serviceNumber < 1 || serviceNumber > currentMember->getListedService().size())
            {
                std::cout << Colors::RED << "Invalid number. Please enter the number of service to view requests: " << Colors::RESET;
                std::cin >> serviceNumber;
            }

            serviceToViewRequest = currentMember->getListedService()[serviceNumber - 1];

            // display all request of a service
            displayMemberRequestList(serviceToViewRequest);

            // user choice

            std::cout << Colors::CYAN << "Please enter request number to accept: " << Colors::RESET;
            std::cin >> requestNumber;
            while (requestNumber < 1 || requestNumber > getRequestByService(serviceToViewRequest).size())
            {
                std::cout << "Invalid number. Please enter request number to accept: ";
                std::cin >> requestNumber;
            }

            // accept request
            toBeAcceptRequest = getRequestByService(serviceToViewRequest)[requestNumber - 1];
            if (acceptRequest(toBeAcceptRequest))
            {
                cout << Colors::GREEN << "Accepted request successfully" << endl
                     << Colors::RESET;
            }
            else
            {
                cout << Colors::RED << "Accepted request failed" << endl
                     << Colors::RESET;
            }
            break;

            std::cout << Colors::GREEN << "Request List Updated!" << Colors::RESET << endl;
            displayMemberRequestList(serviceToViewRequest);

        case 4:
            std::cout << "----------------4. Return to Main Menu----------------\n";
            exit = true;
            break;
        }
    } while (!exit);
}

void System::displayMemberRequestList(Service *service)
{
    // display all request of a service
    int count = 1;
    cout << "List of request for your service: " << endl;
    std::cout << Colors::MAGENTA
              << std::left << std::setw(10) << "No."
              << std::left << std::setw(20) << "Skill Request"
              << std::left << std::setw(20) << "Requester"
              << std::left << std::setw(20) << "Start Time"
              << std::left << std::setw(20) << "End Time"
              << std::left << std::setw(20) << "Status"
              << Colors::RESET << std::endl;

    // get request by service
    std::vector<Request *> requestList = getRequestByService(service);

    for (Request *request : requestList)
    {
        std::cout << Colors::YELLOW
                  << std::left << std::setw(10) << count

                  << std::left << std::setw(20) << request->getSkill()->getSkillName()
                  << std::left << std::setw(20) << request->getRequester()->getFullName()
                  << std::left << std::setw(20) << request->getStartTime().toString()
                  << std::left << std::setw(20) << request->getEndTime().toString()
                  << std::left << std::setw(20) << (request->getStatus() == 0 ? "PENDING" : (request->getStatus() == 1 ? "ACCEPTED" : "REJECTED"))
                  << Colors::RESET << std::endl;
        count++;
    }
}
std::vector<Request *> System::getRequestByService(Service *service)
{
    std::vector<Request *> requestList;
    for (Request *request : request_list)
    {
        if (request->getService() == service)
        {
            requestList.push_back(request);
        }
    }
    return requestList;
}

bool System::acceptRequest(Request *request)
{
    // check if request is accepted
    if (request->getStatus() == 1)
    {
        cout << Colors::RED << "Request is already accepted." << Colors::RESET << endl;
        return false;
    }
    // check if request is expired
    else if (Date::compare(request->getEndTime(), Date::getCurrentDate()) < 0)
    {
        cout << Colors::RED << "Request is expired." << Colors::RESET << endl;
        return false;
    }
    // accept request and reject other request
    else
    {
        // accept request

        currentMember->acceptRequest(request);

        // deduct credit point from requester and add to supporter
        // calculate request duration
        double requestDurationInHour = Date::getDurationInMinutes(request->getStartTime(), request->getEndTime()) / 60;
        double totalConsumingCD = requestDurationInHour * request->getService()->getConsumingCD();
        int totalConsumingCDInt = static_cast<int>(std::round(totalConsumingCD));
        currentMember->addCD(totalConsumingCDInt);
        request->getRequester()->deductCD(totalConsumingCDInt);

        // reject other time overlapped request

        std::vector<Request *> requestList = getRequestByService(request->getService());
        for (Request *otherRequest : requestList)
        {
            if (otherRequest == request)
            {
                continue;
            }
            Date currentRequestStartTime = request->getStartTime();
            Date currentRequestEndTime = request->getEndTime();
            Date otherRequestStartTime = otherRequest->getStartTime();
            Date otherRequestEndTime = otherRequest->getEndTime();

            // otherEndTime after currentStartTime
            // otherStartTime before currentEndTime
            // otherStartTime after/= currentStartTime and otherEndTime before/= currentEndTime
            // otherStartTime before currentStartTime and otherEndTime after currentEndTime
            if (Date::compare(otherRequestEndTime, currentRequestStartTime) > 0 || Date::compare(otherRequestStartTime, currentRequestEndTime) < 0)
            {
                otherRequest->setStatus(2);
            }
            else if (Date::compare(otherRequestStartTime, currentRequestStartTime) >= 0 && Date::compare(otherRequestEndTime, currentRequestEndTime) <= 0)
            {
                otherRequest->setStatus(2);
            }
            else if (Date::compare(otherRequestStartTime, currentRequestStartTime) <= 0 && Date::compare(otherRequestEndTime, currentRequestEndTime) >= 0)
            {
                otherRequest->setStatus(2);
            }
        }

        return true;
    }
}

// Login and Register

bool System::checkLogIn(std::string username, std::string password, std::string logInType)
{
    if (logInType == "admin")
    {
        cout << Colors::MAGENTA << "Processing Admin login data..." << Colors::RESET << endl;

        return (username == adminUsername && password == adminPassword) ? true : false;
    }
    else if (logInType == "member")
    {
        bool valid = false;
        cout << Colors::MAGENTA << "Processing Member login data..." << Colors::RESET << endl;

        for (Member *member : member_list)

        {

            if (username == member->getUsername() && password == member->getPassword())
            {
                valid = true;
                return true;
            }
        }
        if (!valid)
        {

            return false;
        }
    }
}

void System::registerNewAcc()
{
    std::string username = getRegUsername();
    std::string password = getRegPassword();
    std::string email = getRegEmail();
    std::string phone = getRegPhone();
    std::string name = getRegName();

    std::string address = getRegAddress();

    std::string city = getRegCity();
    int creditPoint = getFirstTopUp();

    std::cout << username << password << email << phone << name << address << city << creditPoint << endl;

    std::cout << "Registergin..." << endl;
    Member *member = new Member(generateId(), username, password, name, phone, email, address, city, 0, 0, creditPoint);
    member_list.push_back(member);
}
std::string System::getRegUsername()
{
    std::string input = "";
    do
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << Colors::MAGENTA << "Username must be unique and only contains alphanumeric and underscores (5-30 characters)" << std::endl;
        std::cout << Colors::CYAN << "Input Username: " << Colors::RESET;
        cin >> input;

        if (validateRegisterRegex(input, usernameRegex) and validateUniqueUsername(input, member_list))
        {
            return input;
        }
        std::cout << "Error" << std::endl;
        if (!validateRegisterRegex(input, usernameRegex))
        {
            std::cout << Colors::MAGENTA << "Username must only contains alphanumeric and underscores (5-30 characters)" << std::endl;
        };

        if (!validateUniqueUsername(input, member_list))
        {
            std::cout << Colors::MAGENTA << "Username must be unique" << std::endl;
        };
        if (!verifyContinueRegister())
        {
            std::cout << Colors::RED << "Cancelled registering, back to welcome menu\n"
                      << Colors::RESET;
            displayWelcomeMenu();
        }

    } while (!validateRegisterRegex(input, passwordRegex) and !validateUniqueUsername(input, member_list));
};

std::string System::getRegPassword()
{
    std::string input = "";
    do
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << Colors::MAGENTA << "Password cannot have space or special character (Minimum 8 characters)" << std::endl;
        std::cout << Colors::CYAN << "Input Password: " << Colors::RESET;
        cin >> input;
        if (validateRegisterRegex(input, passwordRegex))
        {
            return input;
        };
        std::cout << Colors::RED << "Error" << std::endl;
        std::cout << "Please check the requirement" << std::endl
                  << Colors::RESET;
        if (!verifyContinueRegister())
        {
            std::cout << Colors::RED << "Cancelled registering, back to welcome menu\n"
                      << Colors::RESET;
            break;
        }
    } while (!validateRegisterRegex(input, passwordRegex));
};

std::string System::getRegEmail()
{
    std::string input = "";
    do
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << Colors::MAGENTA << "Email must be unique and only includes characters, an @ symbol, domain name, and a domain suffix" << std::endl;
        std::cout << Colors::CYAN << "Input Email: " << Colors::RESET;

        cin >> input;

        if (validateRegisterRegex(input, emailRegex) && validateUniqueEmail(input, member_list))
        {
            return input;
        };
        std::cout << "Error" << std::endl;
        if (!validateRegisterRegex(input, emailRegex))
        {
            std::cout << Colors::MAGENTA << "Email must only includes characters, an @ symbol, domain name, and a domain suffix" << std::endl;
        };

        if (!validateUniqueUsername(input, member_list))
        {
            std::cout << Colors::MAGENTA << "Email must be unique" << std::endl;
        };

        if (!verifyContinueRegister())
        {
            std::cout << Colors::RED << "Cancelled registering, back to welcome menu\n"
                      << Colors::RESET;
            break;
        }

    } while (!validateRegisterRegex(input, emailRegex) && validateUniqueEmail(input, member_list));
};

std::string System::getRegPhone()
{
    std::string input = "";
    do
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << Colors::MAGENTA << "Phone Number must be unique and only includes numbers (8-15 digits)" << std::endl;
        std::cout << Colors::CYAN << "Input Phone Number: " << Colors::RESET;

        cin >> input;
        cout << input << endl;

        if (validateRegisterRegex(input, phoneNumRegex) && validateUniquePhone(input, member_list))
        {
            return input;
        };
        std::cout << "Error" << std::endl;
        if (!validateRegisterRegex(input, phoneNumRegex))
        {
            std::cout << Colors::MAGENTA << "Phone Number must only includes numbers" << std::endl;
        };
        if (!validateUniquePhone(input, member_list))
        {
            std::cout << Colors::MAGENTA << "Phone Number must be unique" << std::endl;
        }

        if (!verifyContinueRegister())
        {
            std::cout << Colors::RED << "Cancelled registering, back to welcome menu\n"
                      << Colors::RESET;
            break;
        }

    } while (!validateRegisterRegex(input, emailRegex) && validateUniquePhone(input, member_list));
};

std::string System::getRegName()
{
    std::string input = "";
    do
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << Colors::MAGENTA << "Name can only have letters, hyphen, apostrophe (maximun 50 characters)" << std::endl;
        std::cout << Colors::CYAN << "Input your full name: ";

        std::getline(std::cin, input);

        cout << input << endl;

        if (validateRegisterRegex(input, nameRegex))
        {
            return input;
        };
        std::cout << Colors::RED << "Error" << std::endl;
        std::cout << Colors::MAGENTA << "Please check the requirement" << std::endl;
        cin.ignore();
        if (!verifyContinueRegister())
        {
            std::cout << Colors::RED << "Cancelled registering, back to welcome menu\n"
                      << Colors::RESET;
            break;
        }
    } while (!validateRegisterRegex(input, nameRegex));
};
std::string System::getRegCity()
{
    std::string input = "";
    do
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << Colors::MAGENTA << "Input only HANOI or SAIGON" << std::endl;
        std::cout << Colors::CYAN << "Input your city (HANOI/SAIGON): ";

        cin >> input;

        if (validateRegisterRegex(input, cityRegex))
        {
            return input;
        };
        std::cout << Colors::RED << "Error" << std::endl;
        std::cout << Colors::MAGENTA << "Please check the requirement" << std::endl;

        if (!verifyContinueRegister())
        {
            std::cout << Colors::RED << "Cancelled registering, back to welcome menu\n"
                      << Colors::RESET;
            break;
        }
    } while (!validateRegisterRegex(input, cityRegex));
};

std::string System::getRegAddress()
{
    std::string input = "";
    do
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << Colors::MAGENTA << "Address can only have alphanumeric with space, comma, period, apostrophes, hyphen" << std::endl;
        std::cout << Colors::CYAN << "Input your address: ";

        std::getline(std::cin, input);

        if (validateRegisterRegex(input, addressRegex))
        {
            return input;
        };
        std::cout << Colors::RED << "Error" << std::endl;
        std::cout << Colors::MAGENTA << "Please check the requirement" << std::endl;
        cin.ignore();
        if (!verifyContinueRegister())
        {
            std::cout << Colors::RED << "Cancelled registering, back to welcome menu\n"
                      << Colors::RESET;
            break;
        }
    } while (!validateRegisterRegex(input, addressRegex));
};

int System::getFirstTopUp()
{
    do
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string choice;
        std::cout << Colors::CYAN << "You have to pay $20 for your first 20 credit points. Confirm? (Y/N): ";
        std::cin >> choice;
        if (choice == "y" or choice == "Y")
        {
            return 20;
        }
        else if (choice == "n" or choice == "N")
        {
            std::cout << Colors::GREEN << "Cancelled topup\n"
                      << Colors::RESET;
        }
        else
        {
            std::cout << Colors::RED << "ERROR! Wrong input\n"
                      << Colors::RESET;
        }

        if (!verifyContinueRegister())
        {
            std::cout << Colors::RED << "Cancelled registering, back to welcome menu\n"
                      << Colors::RESET;
            break;
        }
    } while (true);
}

bool System::verifyContinueRegister()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string choice;
    std::cout << Colors::CYAN << "Do you want to continue registering? (Y/N): " << Colors::RESET;
    std::cin >> choice;
    if (choice == "y" or choice == "Y")
    {
        return true;
    }
    displayWelcomeMenu();
    return false;
};

bool System::validateRegisterRegex(string input, std::regex pattern)
{
    return std::regex_match(input, pattern);
}

bool System::validateUniqueUsername(string input, vector<Member *> member_list)
{
    for (Member *member : member_list)
    {
        if (input == member->getUsername())
        {
            return false;
        };
        return true;
    }
}
bool System::validateUniqueEmail(string input, vector<Member *> member_list)
{
    for (Member *member : member_list)
    {
        if (input == member->getEmail())
        {
            return false;
        };
        return true;
    }
}

bool System::validateUniquePhone(string input, vector<Member *> member_list)
{
    for (Member *member : member_list)
    {
        if (input == member->getPhoneNumber())
        {
            return false;
        };
        return true;
    }
}

bool System::checkUniqueId(int i)
{
    for (Member *member : member_list)
    {
        if (i == std::stoi(member->getMemberId()))
        {
            return false;
        }
    }
    return true;
};

Member *System::getMemberByUsername(string username)
{
    for (Member *member : member_list)
    {
        if (username == member->getUsername())
        {
            return member;
        }
    }
    return NULL;
}

// GUEST
void System::displayAllService()
{
    int count = 1;
    std::cout << Colors::MAGENTA << "Service Listing\n"
              << std::left << std::setw(5) << "No."
              << std::left << std::setw(20) << "OWNER"
              << std::left << std::setw(20) << "START TIME"
              << std::left << std::setw(20) << "END TIME"
              << std::left << std::setw(10) << "CONSUMING CD"
              << std::left << std::setw(10) << "MIN HOST SCR"
              << std::left << std::setw(50) << "SKILL LIST"
              << Colors::RESET << endl;
    for (Service *service : service_list)
    {

        cout << Colors::YELLOW
             << std::left << std::setw(5) << count;
        service->viewService();
        count++;
    }
}

void System::displaySupporterDetail(Service *service)
{
    cout << endl;
    cout << Colors::MAGENTA << "Supporter Detail" << Colors::RESET << endl;
    cout << Colors::YELLOW << "Name: " << Colors::RESET << service->getServiceOwner()->getFullName() << endl;
    cout << Colors::YELLOW << "Phone: " << Colors::RESET << service->getServiceOwner()->getPhoneNumber() << endl;
    cout << Colors::YELLOW << "Email: " << Colors::RESET << service->getServiceOwner()->getEmail() << endl;
    cout << Colors::YELLOW << "Address: " << Colors::RESET << service->getServiceOwner()->getHomeAddress() << endl;
    cout << Colors::YELLOW << "City: " << Colors::RESET << service->getServiceOwner()->getCity() << endl;
    cout << Colors::YELLOW << "Skills: " << Colors::RESET;
    for (Skill *skill : service->getServiceOwner()->getSkills())
    {
        cout << skill->getSkillName() << ", ";
    }
    cout << Colors::RESET << endl;
}