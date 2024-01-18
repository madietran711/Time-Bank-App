//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#ifndef TIME_BANK_APP_SERVICE_H
#define TIME_BANK_APP_SERVICE_H
#include <string>
#include "../skill/Skill.h"
#include <vector>
#include "../member/Member.h"
#include "../date/Date.h"
#include "../request/Request.h"
class Member;
class Skill;
class Date;
class Service;
class Request;
class Service
{

private:
    std::string serviceId;
    Member *serviceOwner;
    Date startTime;
    Date endTime;

    std::vector<Skill> skillList;
    int consumingCD;
    double score_required;
    std::vector<Request> requestList;

public:
    Service() = default;
    Service(
        std::string serviceId,
        Member *serviceOwner,
        Date startTime,
        Date endTime,
        int consumingCD,
        double scoreRequired,
        std::vector<Skill> skillList = {},
        std::vector<Request> requestList = {}

    );

    // Getter functions
    std::string getServiceId() const;
    Member *getServiceOwner() const;
    Date getStartTime() const;
    Date getEndTime() const;
    int getConsumingCD() const;
    double getScoreRequired() const;
    const std::vector<Skill> &getSkillList() const;
    const std::vector<Request> &getRequestList() const;

    // Setter functions
    void setServiceId(const std::string &id);
    void setServiceOwner(Member *owner);
    void setStartTime(std::string startTime);
    void setEndTime(std::string endTime);
    void setConsumingCD(int consumingCD);
    void setScoreRequired(double scoreRequired);
    void setSkillList(const std::vector<Skill> &skillList);
    void setRequestList(const std::vector<Request> &requestList);

    // Return address of the array of info to display
    int *returnServiceInfo();
    void addRequest(Request *request);
};

#endif // TIME_BANK_APP_SERVICE_H
