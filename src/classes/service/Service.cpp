//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#include "Service.h"

#include <utility>
#include "Member.h"
#include<string>
#include<vector>
using namespace std;


Service::Service(string serviceId, Member *service_owner, string startTime, string endTime, string availableTime,
                 int consumingCD, double scoreRequired, Member *supporter, vector<Skill> skillList): service_owner(service_owner), startTime(std::move(startTime)), endTime(std::move(endTime)), consumingCD(consumingCD), score_required(scoreRequired), supporter(supporter), skillList(std::move(skillList)) {

}
