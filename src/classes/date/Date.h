#ifndef TIME_BANK_APP_DATE_H
#define TIME_BANK_APP_DATE_H

#include <string>

class Date
{
private:
    int day;
    int month;
    int year;
    int hour;
    int minute;

public:
    // Constructors
    Date();                                                   // Default constructor
    Date(int year, int month, int day, int hour, int minute); // Parameterized constructor
    ~Date();                                                  // Destructor
    Date(const Date &other);                                  // Copy constructor
    Date &operator=(const Date &other);                       // Assignment operator

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getHour() const;
    int getMinute() const;

    // Setters
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void setHour(int hour);
    void setMinute(int minute);

    // Other methods
    static bool isValid(const std::string &date);
    static Date parse(const std::string &date);
    static int compare(const Date &date1, const Date &date2);
    static int getDurationInMinutes(const Date &date1, const Date &date2);
    static bool isLeapYear(int year);
    static int daysInMonth(int month, int year);

    std::string toString() const;
    std::string getMonthStr(int month) const;

    void runDateTest();
};

#endif // TIME_BANK_APP_DATE_H
