#include "Date.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;
// Default constructor
Date::Date() : day(1), month(1), year(2000), hour(0), minute(0) {}

// Parameterized constructor
Date::Date(int year, int month, int day, int hour, int minute)
    : year(year), month(month), day(day), hour(hour), minute(minute) {}

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

    char slash1, slash2, colon;
    cout << "START" << endl;
    if (!(ss >> year >> slash1 >> month >> slash2 >> day >> hour >> colon >> minute) ||
        (slash1 != '/' || slash2 != '/' || colon != ':'))
    {
        std::cout << "Invalid date format or delimiters: "
                  << "slash1: " << slash1 << ", slash2: " << slash2
                  << ", colon: " << colon << std::endl;
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
    char slash1, slash2, colon;

    ss >> year >> slash1 >> month >> slash2 >> day >> hour >> colon >> minute;

    return Date(year, month, day, hour, minute);
}

// Comparing two Date objects
int Date::compare(const Date &date1, const Date &date2)
{
    if (date1.getYear() != date2.getYear())
    {
        return date1.getYear() - date2.getYear();
    }
    if (date1.getMonth() != date2.getMonth())
    {
        return date1.getMonth() - date2.getMonth();
    }
    if (date1.getDay() != date2.getDay())
    {
        return date1.getDay() - date2.getDay();
    }
    if (date1.getHour() != date2.getHour())
    {
        return date1.getHour() - date2.getHour();
    }
    return date1.getMinute() - date2.getMinute();
}

// Calculating the duration between two dates in minutes
int Date::getDurationInMinutes(const Date &date1, const Date &date2)
{
    int minutes = 0;

    int year1 = date1.getYear();
    int month1 = date1.getMonth();
    int day1 = date1.getDay();
    int hour1 = date1.getHour();
    int minute1 = date1.getMinute();

    int year2 = date2.getYear();
    int month2 = date2.getMonth();
    int day2 = date2.getDay();
    int hour2 = date2.getHour();
    int minute2 = date2.getMinute();

    // If the first date is after the second date, swap them
    if (Date::compare(date1, date2) > 0)
    {
        std::swap(year1, year2);
        std::swap(month1, month2);
        std::swap(day1, day2);
        std::swap(hour1, hour2);
        std::swap(minute1, minute2);
    }

    // Calculate the number of minutes between the two dates
    if (year1 == year2)
    {
        if (month1 == month2)
        {
            if (day1 == day2)
            {
                // Calculate minutes between hours and minutes only
                minutes += (hour2 - hour1) * 60;
                minutes += (minute2 - minute1);
            }
            else
            {
                // Calculate minutes between days, hours, and minutes
                minutes += (day2 - day1) * 24 * 60;
                minutes += (hour2 - hour1) * 60;
                minutes += (minute2 - minute1);
            }
        }
        else
        {
            // Calculate minutes between months, days, hours, and minutes
            for (int month = month1; month <= month2; ++month)
            {
                minutes += (daysInMonth(month, year1) - (month == month1 ? day1 - 1 : 0)) * 24 * 60;
            }
            minutes += (hour2 - hour1) * 60;
            minutes += (minute2 - minute1);
        }
    }
    else
    {
        // Calculate minutes for complete years between year1 and year2
        for (int year = year1; year < year2; ++year)
        {
            minutes += (isLeapYear(year) ? 366 * 24 * 60 : 365 * 24 * 60);
        }

        // Calculate minutes for the remaining months, days, hours, and minutes in year1
        for (int month = month1; month <= 12; ++month)
        {
            minutes += (daysInMonth(month, year1) - (month == month1 ? day1 - 1 : 0)) * 24 * 60;
        }
        minutes += (hour2 - hour1) * 60;
        minutes += (minute2 - minute1);

        // Calculate minutes for the remaining months, days, hours, and minutes in year2
        for (int month = 1; month < month2; ++month)
        {
            minutes += (daysInMonth(month, year2) - (month == month2 ? daysInMonth(month2, year2) - day2 : 0)) * 24 * 60;
        }
    }

    cout << "minutes: " << minutes << endl;

    return minutes;
}

// Helper function to check if a year is a leap year
bool Date::isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Helper function to get the number of days in a month for a given year
int Date::daysInMonth(int month, int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return -1; // Invalid month
    }
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
std::string Date::getMonthStr(int month) const
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
    cout << "validDateObj: " << validDateObj.toString() << endl;
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
    Date endDate(2023, 02, 16, 14, 45);

    int duration = Date::getDurationInMinutes(startDate, endDate);

    // Test 4: String representation
    std::string dateString = startDate.toString();
    assert(dateString == "2023/01/15 12:30");

    // Test 5: Month string representation
    std::string monthString = startDate.getMonthStr(1);
    assert(monthString == "January");

    std::cout << "All tests passed!" << std::endl;
}

// int main()
// {
//     runDateTests();
//     return 0;
// }