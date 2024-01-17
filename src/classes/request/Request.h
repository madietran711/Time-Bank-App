

#ifndef TIME_BANK_APP_REQUEST_H
#define TIME_BANK_APP_REQUEST_H
#include <string>
#include "../service/Service.h"
#include "../member/Member.h"
#include "../date/Date.h"

class Request
{
private:
    std::string requestId;
    Service *service;
    Member *requester;
    Date startTime;
    Date endTime;
    int status;

public:
    Request(
        std::string requestId,
        Service *service,
        Member *requester,
        Date startTime,
        Date endTime,
        int status);

    // getter functions
    std::string getRequestId() const;
    Service *getService() const;
    Member *getRequester() const;
    Date getStartTime() const;
    Date getEndTime() const;
    int getStatus() const;

    // setter functions
    void setRequestId(const std::string &requestId);
    void setService(Service *service);
    void setRequester(Member *requester);
    void setStartTime(std::string startTime);
    void setEndTime(std::string endTime);
    void setStatus(int status);
};

#endif // TIME_BANK_APP_REQUEST_H