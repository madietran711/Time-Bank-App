

#include "System.h"
#include <vector>
#include <iostream>

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

    bool exit = false;
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
            currentMember = getMemberByID("1");
            displayMemberMenu();
            break;
        case 3:

            displayAdminMenu();
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
                  << "Login\n";
        std::cout << std::setw(5) << "[4]"
                  << "Exit\n";
        std::cout << endl;
        std::cout << Colors::CYAN << "Please enter your choice: " << Colors::RESET;

        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << Colors::GREEN << "--------------1. View Available Services----------------\n"
                      << Colors::RESET;
            break;

        case 2:
            std::cout << Colors::GREEN << "--------------2. Register----------------\n"
                      << Colors::RESET;
            // registerMember();
            break;
        case 3:
            std::cout << Colors::GREEN << "--------------3. Login----------------\n"
                      << Colors::RESET;
            // login();
            break;
        case 4:
            std::cout << Colors::GREEN << "--------------4. Exit----------------\n"
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
                  << "Manage Skills (View, Add)\n";
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
            std::cout << Colors::GREEN << "--------------1. Manage Profile (View, Edit)----------------\n"
                      << Colors::RESET;
            displayMemberProfile(currentMember);
            break;
        case 2:
            std::cout << Colors::GREEN << "--------------2. Manage Skills (View, Add)----------------\n"
                      << Colors::RESET;
            displayMemberSkillList(currentMember);
            break;
        case 3:
            // displayMemberMenu();
            break;
        case 4:
            // displayMemberMenu();
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
                   << member->getCreditPoint() << ",";
        // Save blocked member IDs separated by dashes
        const std::vector<Member *> &blockedList = member->getBlockedList();
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

    for (const Skill *skill : skill_list)
    {
        skillFile << skill->getSkillId() << ","
                  << skill->getOwner()->getMemberId() << ","
                  << skill->getSkillName() << ","
                  << skill->getRatingScore() << "\n";
    }

    skillFile.close();

    cout << "Saved " << Colors::YELLOW << skill_list.size() << Colors::GREEN << " skills." << Colors::RESET << endl;

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

    cout << "Loaded " << Colors::YELLOW << skill_list.size() << Colors::GREEN << " skills." << Colors::RESET << endl;
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
                newReview = inputReview(request, Utilities::generateId());

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
        Review *newReview = new Review(Utilities::generateId(), skillScore, score, 0, request, "");
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
        Review *newReview = new Review(Utilities::generateId(), 0, 0, score, request, "");
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
            currentMember->blockMember(member);
            cout << "Blocked " << Colors::YELLOW << member->getFullName() << Colors::RESET << endl;
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
             << member->getCreditPoint();
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