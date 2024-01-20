//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#include "Utilities.h"
bool Utilities::validateUsername(string &str)
{
    if (str.empty())
    {
        cout << "ERROR: Username is blank.\n";
        return false;
    }

    if (str.length() < 6 || str.length() > 30)
    { // Check length (6-30 characters)
        cout << "ERROR: Username must contain 6-30 characters.\n";
        return false;
    }

    for (char c : str)
    { // Check allowed characters
        if (!isalnum(c) || c == '@')
        {
            cout << "ERROR: Username can only contain letters, digits, and no blank space.\n";
            return false;
        }
    }

    return true;
}

bool Utilities::validatePassword(string &str)
{
    if (str.empty())
    {
        cout << "ERROR: Password is blank.\n";
        return false;
    }

    if (str.length() < 8 || str.length() > 20)
    { // Check length (8-20 characters)
        cout << "ERROR: Username must contain 8-20 characters.\n";
        return false;
    }

    if (str.find(" ") != std::string::npos)
    { // Check blank space
        cout << "ERROR: Password must contains no blank space.\n";
        return false;
    }

    return true;
}

bool Utilities::validateFullName(string &str)
{
    if (str.empty())
    {
        cout << "ERROR: Full name is blank.\n";
        return false;
    }

    // Trim heading and ending whitespaces
    str.erase(str.begin(), find_if_not(str.begin(), str.end(), ::isspace));
    str.erase(find_if_not(str.rbegin(), str.rend(), ::isspace).base(), str.end());

    if (str.length() < 3 || str.length() > 30)
    { // Check length (3-30 characters)
        cout << "ERROR: Full name must contain 3-30 characters.\n";
        return false;
    }

    for (char c : str)
    { // Check allowed characters
        if (!isalpha(c) && c != ' ')
        {
            cout << "ERROR: Full name must contain letters and spaces only.\n";
            return false;
        }
    }

    if (str.find(" ") == std::string::npos)
    { // Check for at least one space
        cout << "ERROR: Full name must contain at least one space.\n";
        return false;
    }

    return true;
}

bool Utilities::validatePhoneNumber(string &str)
{ // validate phone number
    if (str.empty())
    {
        cout << "ERROR: Phone number is blank.\n";
        return false;
    }

    // Trim heading and ending whitespaces
    str.erase(str.begin(), find_if_not(str.begin(), str.end(), ::isspace));
    str.erase(find_if_not(str.rbegin(), str.rend(), ::isspace).base(), str.end());

    for (char c : str)
    { // Check digits
        if (!isdigit(c))
        {
            cout << "ERROR: Phone number must only contain digits.\n";
            return false;
        }
    }

    if (str[0] != '0' && str.compare(0, 2, "84") != 0)
    { // Check header number (0 or 84)
        cout << "ERROR: Phone number must start with 0 or 84.\n";
        return false;
    }

    int validLength = (str[0] == '0') ? 10 : 11; // 10 if starting with 0, 11 if starting with 84

    if (str.length() != validLength)
    { // Check length
        if (validLength == 10)
        {
            cout << "ERROR: Phone number starting with 0 must be 10 digits long.\n";
            return false;
        }
        else
        {
            cout << "ERROR: Phone number starting with 84 must be 11 digits long.\n";
            return false;
        }
    }

    return true;
}

bool Utilities::validateEmail(string &str)
{
    if (str.empty())
    {
        cout << "ERROR: Email is blank.\n";
        return false;
    }

    int atIndex = str.find('@');               // Search for @ position
    int dotIndex = str.find('.', atIndex + 1); // Search for . after @

    if (str[0] == '.' || str[atIndex - 1] == '.')
    {
        cout << "ERROR: Email's local part cannot begin or end with a dot.\n";
        return false;
    }

    for (int i = 0; i < atIndex; i++)
    { // Loop through the local part
        if (str[i] == '.' && str[i + 1] == '.')
        {
            cout << "ERROR: Email's local part cannot contain two dots in a row.\n";
            return false;
        }
    }

    if (!(atIndex != std::string::npos && isalnum(str[atIndex + 1]) && dotIndex != std::string::npos && isalnum(str[dotIndex + 1])))
    {
        // Check email address does not contains @, followed by character (domain name), a dot after @, followed by character (top-level domain)
        std::cout << "ERROR: Wrong email domain format." << std::endl;
        return false;
    }

    return true;
}
bool Utilities::validateUserRating(int &rating)
{
    if (rating < 0 || rating > 5)
    {
        cout << Colors::RED << "ERROR: Rating must be between 0 and 5.\n"
             << Colors::RESET;
        return false;
    }

    return true;
}
std::string Utilities::generateId()
{
    std::string id = "";
    srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        id += std::to_string(rand() % 10);
    }
    return id;
}