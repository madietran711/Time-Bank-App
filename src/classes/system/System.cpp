#include "System.h"

void System::welcomeScreen() {
    for (int i = 0; i < 30; i++) {
        cout << "-";
    }

    cout << endl 
        << "EEET2482/COSC2082 ASSIGNMENT" << endl 
        << "“TIME BANK” APPLICATION" << endl
        << "Instructor: Mr. Tran Duc Linh" << endl
        << "Group: Group No. 19" << endl
        << "s3926984, Nguyen Ba Khoi" << endl
        << "s3979462, Nguyen Quoc Binh" << endl
        << "s3979638, Tran Ha Phuong" << endl
        << "s4022878, Dang Minh Triet" << endl;

    for (int i = 0; i < 30; i++) {
        cout << "-";
    }
    cout << endl;

    mainMenu();
}

void System::mainMenu() {
    cout << "Use the app as: " << endl
        << "1: Guest" << endl
        << "2: Member" << endl
        << "3: Admin" << endl;

    // not finish
}

bool System::validateUsername(string& str){ 
    if (str.empty()){
        cout << "ERROR: Username is blank.\n";
        return false;
    }

    std::regex reg1 { "^[a-zA-Z0-9@.]{6,30}$" };
    std::regex reg2 { "^([^@.]*[@.]?[^@.]*)$" };

    //a username can have either one . or one @
    if (!std::regex_match(str, reg1)){ 
        cout << "ERROR: `Username` must contain 4 - 18 characters. No special characters.\n"
             << "       `Username` is only available for . and @.\n";
        return false;
    } 

    if (!std::regex_match(str, reg2)){
        cout << "ERROR: `Username` contains more than 1 . or @.\n";
        return false;
    }

    for(auto mem : member_list){ //every username must be unique
        if(str == mem->username){ //Create getUserName()
            cout << "FAILED: `Username` is already taken.\n";
            return false;
        }
    }

    return true;
}

bool System::validatePassword(string& str){ 
    if (str.empty()){
        cout << "ERROR: Password is blank.\n";
        return false;
    }

    if ( str.length() < 4 || str.find(" ") != std::string::npos ){
        cout << "ERROR: `Password` must contains at least 4 characters. No `blank_space`.\n";
        return false;
    }

    return true;
}

bool System::validateFullName(string& str){ 
    if (str.empty()){
        cout << "ERROR: Full name is blank.\n";
        return false;
    }

    std::regex reg1("^\\s+|\\s+$"); // Matches leading or trailing whitespace
    std::string trimmedString = std::regex_replace(str, reg1, "");

    std::regex reg2 { "^[a-zA-Z0-9]{3,30}$" };

    if (!std::regex_match(trimmedString, reg2)){
        cout << "ERROR: Full name must contain 3 - 30 characters, blank space, and no digit characters.\n";
        return false;
    }
    return true;
}

bool System::validatePhoneNumber(string& str){ // validate phone number
    if (str.empty()){
        cout << "ERROR: Phone number is blank.\n";
        return false;
    }

    std::regex reg1("^\\s+|\\s+$"); // Matches leading or trailing whitespace
    std::string trimmedString = std::regex_replace(str, reg1, "");

    std::regex reg2 { "^(0|84)([0-9]{9}|[0-9]{8})$" }; // header number is 0 or 84 only with 10 digits
  
    if (!std::regex_match(trimmedString, reg2)){
        cout << "ERROR: Phone must contain 10 numbers starting with 0 or 84.\n";
        return false;
    }

    return true;
}

bool validateEmail(string& str) {
    if (str.empty()){
        cout << "ERROR: Email is blank.\n";
        return false;
    }

    int atIndex = str.find('@'); //Search for @ position
    int dotIndex = str.find('.', atIndex + 1);  // Search for . after @

    if (atIndex != std::string::npos && dotIndex != std::string::npos && dotIndex != atIndex + 1) {
        return true;  // "@" and "." found in valid positions
    } else {
        std::cout << "ERROR: Wrong email format." << std::endl;
        return false;
    }
}

bool validateHomeAddressString(string& str) {
    if (str.empty()){
        cout << "ERROR: Home address is blank.\n";
        return false;
    }

    std::string lowercaseAddress = str;
    std::transform(lowercaseAddress.begin(), lowercaseAddress.end(), lowercaseAddress.begin(), ::tolower);

    return (lowercaseAddress.find("hanoi") != std::string::npos) ||
           (lowercaseAddress.find("ha noi") != std::string::npos) ||
           (lowercaseAddress.find("ho chi minh city") != std::string::npos);
}