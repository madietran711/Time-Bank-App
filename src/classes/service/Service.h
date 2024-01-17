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
    std::string startTime;
    std::string endTime;

    std::vector<Skill> skillList;
    int consumingCD;
    double score_required;

public:
    Service(
        std::string serviceId,
        Member *serviceOwner,
        std::string startTime,
        std::string endTime,
        std::string availableTime,
        int consumingCD,
        double scoreRequired,

        std::vector<Skill> skillList = {});

    // Return address of the array of info to display
    int *returnServiceInfo();
};

#endif // TIME_BANK_APP_SERVICE_H
