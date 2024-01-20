

#include "System.h"
#include <vector>
#include <iostream>
std::regex usernameRegex("^[A-Za-z0-9_]{5,30}$");             // Alphanumeric and underscores, 5-30 characters
std::regex passwordRegex("^[A-Za-z0-9]{8,}$");                // Alphanumeric, minimum 8 characters
std::regex nameRegex("^[A-Za-z'-]{1,50}$");                   // Letters, hyphen, apostrophe, up to 50 characters
std::regex phoneNumRegex("^[0-9]{8,15}$");                    // Only numbers, 8-15 digits
std::regex emailRegex("^[\\w.-]+@[\\w.-]+\\.[A-Za-z]{2,6}$"); // Simple email pattern
std::regex addressRegex("^[\\w\\s.,'-]{1,}$");                // Alphanumeric with space, comma, period, apostrophes, hyphen, minimum 10 characters
std::regex cityRegex("^(HANOI|SAIGON)$");

void System::run()
{
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
    // initData();
    loadAllData();
    printAllData();
    saveAllData();
    loadAllData();
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
            registerNewAcc();
            std::cout << Colors::GREEN << "Account Registered, back to welcome menu\n"
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
                  << "Manage Request (View, Add, Delete)\n";
        std::cout << std::setw(5) << "[6]"
                  << "View Reviews For Your Service\n";
        std::cout << std::setw(5) << "[7]"
                  << "Manage Reviews (View, Add, Delete)\n";
        std::cout << std::setw(5) << "[8]"
                  << "Rate Host\n";
        std::cout << std::setw(5) << "[9]"
                  << "Top up Credit Point\n";
        std::cout << std::setw(5) << "[10]"
                  << "Blocking (View, Block, Unblock)\n";

        std::cout << "[25] Logout\n";
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
            std::cout << Colors::GREEN << "--------------6. Manage Request (View, Add, Delete)----------------\n"
                      << Colors::RESET;
            manageRequest();
            break;
        case 6:
            std::cout << Colors::GREEN << "--------------7. View Reviews For My Service----------------\n"
                      << Colors::RESET;
            viewReviews();
            break;
        case 7:
            std::cout << Colors::GREEN << "--------------8. Manage Reviews (View, Add, Delete)----------------\n"
                      << Colors::RESET;
            break;
        case 8:
            std::cout << Colors::GREEN << "--------------9. Rate Host----------------\n"
                      << Colors::RESET;
            hostRatingFunction();
            break;
        case 9:
            std::cout << Colors::GREEN << "--------------10. Top up Credit Point----------------\n"
                      << Colors::RESET;
            topUp();
            break;
        case 10:
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
                   << member->getCreditPoint() << "\n"; // Use '\n' for a newline character
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
        if (tokens.size() != 11)
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
            tokens[7],
            std::stod(tokens[8]),
            std::stod(tokens[9]),
            std::stoi(tokens[10]));

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
              << std::left << std::setw(20) << "PHONE NUMBER"
              << std::left << std::setw(20) << "EMAIL"
              << std::left << std::setw(20) << "HOME ADDRESS"
              << std::left << std::setw(10) << "HOST SCORE"
              << std::left << std::setw(10) << "SUPPORTER SCORE"
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
// -------------------------8. Add Review For Service--------------------------------
// -------------------------------------9. Rate Host----------------------------------
void System::hostRatingFunction()
{
    // show list of accepted request and let user choose
    int count = 1;
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
    rateHost(request->getRequester(), score, request);
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

// Login and Register

bool System::checkLogIn(std::string username, std::string password, std::string logInType)
{
    if (logInType == "admin")
    {
        return (username == adminUsername && password == adminPassword) ? true : false;
    }
    else if (logInType == "member")
    {
        for (Member *member : member_list)
        {
            if (username == member->getUsername() && password == member->getUsername())
            {
                currentMember = member;
                return true;
            }
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
    std::string id = createNewAccId();

    std::cout << username << password << email << phone << name << address << city << creditPoint << id;

    std::cout << "Registergin..." << endl;
    Member *member = new Member(id, username, password, name, phone, address, city, 0, 0, getFirstTopUp());
    member_list.push_back(member);
}
std::string System::getRegUsername()
{
    std::string input = "";
    do
    {
        std::cout << "Username must be unique and only contains alphanumeric and underscores (5-30 characters)" << std::endl;
        std::cout << "Input Username: ";
        cin >> input;

        if (validateRegisterRegex(input, usernameRegex) and validateUniqueUsername(input, member_list))
        {
            return input;
        }
        std::cout << "Error" << std::endl;
        if (!validateRegisterRegex(input, usernameRegex))
        {
            std::cout << "Username must only contains alphanumeric and underscores (5-30 characters)" << std::endl;
        };

        if (!validateUniqueUsername(input, member_list))
        {
            std::cout << "Username must be unique" << std::endl;
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
        std::cout << "Password cannot have space or special character (Minimum 8 characters)" << std::endl;
        std::cout << "Input Password: ";
        cin >> input;
        if (validateRegisterRegex(input, passwordRegex))
        {
            return input;
        };
        std::cout << "Error" << std::endl;
        std::cout << "Please check the requirement" << std::endl;
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
        cout << "Email must be unique and only includes characters, an @ symbol, domain name, and a domain suffix" << std::endl;
        std::cout << "Input Email: " << std::endl;
        cin >> input;
        if (validateRegisterRegex(input, emailRegex) && validateUniqueEmail(input, member_list))
        {
            return input;
        };
        std::cout << "Error" << std::endl;
        if (!validateRegisterRegex(input, emailRegex))
        {
            std::cout << "Email must only includes characters, an @ symbol, domain name, and a domain suffix" << std::endl;
        };

        if (!validateUniqueUsername(input, member_list))
        {
            std::cout << "Email must be unique" << std::endl;
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
        std::cout << "Phone Number must be unique and only includes numbers (8-15 digits)" << std::endl;
        std::cout << "Input Phone Number: ";
        cin >> input;
        if (validateRegisterRegex(input, phoneNumRegex) && validateUniquePhone(input, member_list))
        {
            return input;
        };
        std::cout << "Error" << std::endl;
        if (!validateRegisterRegex(input, phoneNumRegex))
        {
            std::cout << "Phone Number must only includes numbers" << std::endl;
        };
        if (!validateUniquePhone(input, member_list))
        {
            std::cout << "Phone Number must be unique" << std::endl;
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
        std::cout << "Name can only have letters, hyphen, apostrophe (maximun 50 characters)" << std::endl;
        std::cout << "Input your full name: ";
        cin >> input;
        if (validateRegisterRegex(input, nameRegex))
        {
            return input;
        };
        std::cout << "Error" << std::endl;
        std::cout << "Please check the requirement" << std::endl;
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
        std::cout << "Input only HANOI or SAIGON" << std::endl;
        std::cout << "Input your city (HANOI/SAIGON): ";
        cin >> input;
        if (validateRegisterRegex(input, cityRegex))
        {
            return input;
        };
        std::cout << "Error" << std::endl;
        std::cout << "Please check the requirement" << std::endl;
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
        std::cout << "Address can only have alphanumeric with space, comma, period, apostrophes, hyphen" << std::endl;
        std::cout << "Input your address: ";
        cin >> input;
        if (validateRegisterRegex(input, addressRegex))
        {
            return input;
        };
        std::cout << "Error" << std::endl;
        std::cout << "Please check the requirement" << std::endl;
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
        std::string choice;
        std::cout << "You have to pay $20 for your first 20 credit points. Confirm? (Y/N): ";
        std::cin >> choice;
        if (choice == "y" or choice == "Y")
        {
            return 20;
        }
        std::cout << "Cancelled topup";
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
    std::string choice;
    std::cout << "Do you want to continue registering? (Y/N): ";
    std::cin >> choice;
    return (choice == "y" or choice == "Y") ? true : false;
    displayWelcomeMenu();
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

std::string System::createNewAccId()
{
    for (int i = 1; i < member_list.size(); i++)
    {
        if (checkUniqueId(i))
        {
            std::cout << "That";

            return std::to_string(i);
        }
    }
    std::string id = std::to_string(member_list.size() + 1);
    return id;
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
