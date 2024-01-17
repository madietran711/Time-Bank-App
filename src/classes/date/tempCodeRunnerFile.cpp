bool Date::isValid(const std::string &date)
{
    std::istringstream ss(date);
    int year, month, day, hour, minute;
    cout << "date: " << date << endl;

    char slash1, slash2, space, colon;

    if (!(ss >> year >> slash1 >> month >> slash2 >> day >> space >> hour >> colon >> minute) ||
        (slash1 != '/' || slash2 != '/' || space != ' '))
    {
        return false;
    }

    // Basic validation for month, day, and hour values
    return (month >= 1 && month <= 12 &&
            day >= 1 && day <= 31 &&
            hour >= 0 && hour <= 23 &&
   