

#ifndef TIME_BANK_APP_REQUEST_H
#define TIME_BANK_APP_REQUEST_H
#include <string>
#include "../service/Service.h"
#include "../member/Member.h"
#include "../date/Date.h"
#include "../skill/Skill.h"

class Service;
class Member;
class Date;
class Skill;
class Request
{
private:
    std::string requestId;
    Service *service;
    Member *requester;
    Date startTime;
    Date endTime;
    Skill *skill;
    int status;

public:
    // Constructor
    Request() = default;
    Request(
        std::string requestId,
        Service *service,
        Member *requester,
        Date startTime,
        Date endTime,
        Skill *skill,
        int status);

    // getter functions
    std::string getRequestId() const;
    Service *getService() const;
    Member *getRequester() const;
    Date getStartTime() const;
    Date getEndTime() const;
    int getStatus() const;
    Skill *getSkill() const;

    // setter functions
    void setRequestId(const std::string &requestId);
    void setService(Service *service);
    void setRequester(Member *requester);
    void setStartTime(std::string startTime);
    void setEndTime(std::string endTime);
    void setStatus(int status);
    void setSkill(Skill *skill);
};

#endif // TIME_BANK_APP_REQUEST_H