

#ifndef TIME_BANK_APP_REQUEST_H
#define TIME_BANK_APP_REQUEST_H
#include <string>
#include "Service.h"
#include "Member.h"
#include "Date.h"

class Request
{
private:
    std::string requestId;
    Service *service;
    Member *requester;
    Date *startTime;
    Date *endTime;
    int status;
    int score;

public:
    Request(
        std::string requestId,
        Service *service,
        Member *requester,
        Date *startTime,
        Date *endTime,
        int status,
        int score);

    // Return address of the array of info to display
    int *returnRequestInfo();

    // getter functions
    std::string getRequestId() const;
    Service *getService() const;
    Member *getRequester() const;
    Date *getStartTime() const;
    Date *getEndTime() const;
    int getStatus() const;
    int getScore() const;
};

#endif // TIME_BANK_APP_REQUEST_H