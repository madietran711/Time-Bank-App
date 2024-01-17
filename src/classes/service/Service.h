//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#ifndef TIME_BANK_APP_SERVICE_H
#define TIME_BANK_APP_SERVICE_H
#include <string>
#include "Skill.h"
#include <vector>
#include "Member.h"

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

public:
    Service(
        std::string serviceId,
        Member *serviceOwner,
        Date startTime,
        Date endTime,
        int consumingCD,
        double scoreRequired,
        std::vector<Skill> skillList = {});

    // Getter functions
    std::string getServiceId() const;
    Member *getServiceOwner() const;
    Date getStartTime() const;
    Date getEndTime() const;
    int getConsumingCD() const;
    double getScoreRequired() const;
    const std::vector<Skill> &getSkillList() const;

    // Setter functions
    void setServiceId(const std::string &id);
    void setServiceOwner(Member *owner);
    void setStartTime(std::string startTime);
    void setEndTime(std::string endTime);
    void setConsumingCD(int consumingCD);
    void setScoreRequired(double scoreRequired);
    void setSkillList(const std::vector<Skill> &skillList);

    // Return address of the array of info to display
    int *returnServiceInfo();
};

#endif // TIME_BANK_APP_SERVICE_H
