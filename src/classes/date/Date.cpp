#include "Date.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;
// Default constructor
Date::Date() : day(1), month(1), year(2000), hour(0), minute(0) {}

// Parameterized constructor
Date::Date(int day, int month, int year, int hour, int minute)
    : day(day), month(month), year(year), hour(hour), minute(minute) {}

// Destructor
Date::~Date()
{
    // Add any necessary cleanup code here
}

// Copy constructor
Date::Date(const Date &other)
    : day(other.day), month(other.month), year(other.year), hour(other.hour), minute(other.minute) {}

// Assignment operator
Date &Date::operator=(const Date &other)
{
    if (this != &other)
    {
        day = other.day;
        month = other.month;
        year = other.year;
        hour = other.hour;
        minute = other.minute;
    }
    return *this;
}

// Getters
int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

int Date::getHour() const
{
    return hour;
}

int Date::getMinute() const
{
    return minute;
}

// Setters
void Date::setDay(int day)
{
    this->day = day;
}

void Date::setMonth(int month)
{
    this->month = month;
}

void Date::setYear(int year)
{
    this->year = year;
}

void Date::setHour(int hour)
{
    this->hour = hour;
}

void Date::setMinute(int minute)
{
    this->minute = minute;
}

// Other methods

// Date validation based on the specified format
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
            minute >= 0 && minute <= 59);
}

// Parsing the date string into a Date object
Date Date::parse(const std::string &date)
{
    std::istringstream ss(date);
    int year, month, day, hour, minute;
    char slash1, slash2, space, colon;

    ss >> year >> slash1 >> month >> slash2 >> day >> space >> hour >> colon >> minute;

    return Date(day, month, year, hour, minute);
}

// Comparing two Date objects
int Date::compare(const Date &date1, const Date &date2)
{
    if (date1.year != date2.year)
    {
        return date1.year - date2.year;
    }
    if (date1.month != date2.month)
    {
        return date1.month - date2.month;
    }
    if (date1.day != date2.day)
    {
        return date1.day - date2.day;
    }
    if (date1.hour != date2.hour)
    {
        return date1.hour - date2.hour;
    }
    return date1.minute - date2.minute;
}

// Calculating the duration between two dates in minutes
int Date::getDurationInMinutes(const Date &date1, const Date &date2)
{
    // Assuming date1 is earlier than date2
    int minutes = (date2.year - date1.year) * 365 * 24 * 60 +
                  (date2.month - date1.month) * 30 * 24 * 60 +
                  (date2.day - date1.day) * 24 * 60 +
                  (date2.hour - date1.hour) * 60 +
                  (date2.minute - date1.minute);

    return minutes;
}

// Converting the Date object to a string with the specified format
std::string Date::toString() const
{
    std::ostringstream ss;
    ss << std::setfill('0') << std::setw(4) << year << "/"
       << std::setw(2) << month << "/" << std::setw(2) << day << " "
       << std::setw(2) << hour << ":" << std::setw(2) << minute;
    return ss.str();
}

// Getting the string representation of the month using switch case
std::string Date::getMonthStr() const
{
    switch (month)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        return "Invalid Month";
    }
}

// Converting the Date and time to a string with the specified format
std::string Date::toDateTimeString() const
{
    return toString();
}

void runDateTests()
{
    // Test 1: Date validation
    std::string validDate = "2023/01/15 12:30";
    std::string invalidDate = "2023/13/35 25:70";

    Date validDateObj;
    Date invalidDateObj;

    assert(Date::isValid(validDate));
    assert(!Date::isValid(invalidDate));

    validDateObj = Date::parse(validDate);
    invalidDateObj = Date::parse(invalidDate);

    assert(validDateObj.getYear() == 2023);
    assert(validDateObj.getMonth() == 1);
    assert(validDateObj.getDay() == 15);
    assert(validDateObj.getHour() == 12);
    assert(validDateObj.getMinute() == 30);

    // Test 2: Date comparison
    Date earlierDate(2022, 12, 01, 10, 0);
    Date laterDate(2023, 01, 15, 12, 30);

    assert(Date::compare(earlierDate, laterDate) < 0);

    // Test 3: Duration calculation
    Date startDate(2023, 01, 15, 12, 30);
    Date endDate(2023, 01, 16, 14, 45);

    int duration = Date::getDurationInMinutes(startDate, endDate);
    assert(duration == 30 * 24 * 60 + 2 * 60 + 15);

    // Test 4: String representation
    std::string dateString = startDate.toString();
    assert(dateString == "2023/01/15 12:30");

    // Test 5: Month string representation
    std::string monthString = startDate.getMonthStr();
    assert(monthString == "January");

    std::cout << "All tests passed!" << std::endl;
}

int main()
{
    runDateTests();
    return 0;
}