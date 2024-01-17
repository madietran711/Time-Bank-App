

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
    std::string student1Name = "Student Name 1";

    std::string student2ID = "sXXXXXXX";
    std::string student2Name = "Student Name 2";

    std::string student3ID = "sXXXXXXX";
    std::string student3Name = "Student Name 3";

    std::string student4ID = "sXXXXXXX";
    std::string student4Name = "Student Name 4";

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
