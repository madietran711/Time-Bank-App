#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <vector>
#include "Skill.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

class Service
{
private:
    std::string serviceId;
    Member *service_owner;
    std::string startTime;
    std::string endTime;
    std::string availableTime;
    int consumingCD;
    double score_required;
    Member *supporter;
    std::vector<Skill> skillList;

public:
    Service(
        std::string serviceId,
        Member *service_owner,
        std::string startTime,
        std::string endTime,
        std::string availableTime,
        int consumingCD,
        double scoreRequired,
        Member *supporter,
        std::vector<Skill> skillList = {});

    // Return address of the array of info to display
    int *returnServiceInfo();

    friend class System;
};

#endif