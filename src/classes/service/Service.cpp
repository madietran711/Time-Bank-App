//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#include "Service.h"

#include <utility>

#include <string>
#include <vector>
using namespace std;

Service::Service(string serviceId, Member *serviceOwner, string startTime, string endTime, string availableTime,
                 int consumingCD, double scoreRequired, vector<Skill> skillList) : serviceOwner(serviceOwner), startTime(std::move(startTime)), endTime(std::move(endTime)), consumingCD(consumingCD), score_required(scoreRequired), skillList(std::move(skillList)){};
