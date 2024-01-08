#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

#define STRSIZE 100

class Member
{
private:
    bool is_admin;
    string username;
    string password;
    string full_name;
    string phone_num;
    string email;
    string home_address;
    double host_score;
    double supporter_score;

    vector<string> listed_service;

public:
    void viewInfo()
    {
        cout << "User Information:" << endl;
        cout << "Username: " << username << endl;
        cout << "Full Name: " << full_name << endl;
        cout << "Phone Number: " << phone_num << endl;
        cout << "Email: " << email << endl;
        cout << "Home Address: " << home_address << endl;
        cout << "Host Score: " << host_score << endl;
        cout << "Supporter Score: " << supporter_score << endl;
    }
};
