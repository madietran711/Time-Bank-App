#include "Service.h"

// Default constructor
Service::Service(
    std::string serviceId,
    Member *serviceOwner,
    Date startTime,
    Date endTime,
    int consumingCD,
    double scoreRequired,
    std::vector<Skill> skillList,
    std::vector<Request> requestList)
    : serviceId(serviceId),
      serviceOwner(serviceOwner),
      startTime(startTime),
      endTime(endTime),
      consumingCD(consumingCD),
      score_required(scoreRequired),
      skillList(std::move(skillList)),
      requestList(std::move(requestList)){};

// Getter functions
std::string Service::getServiceId() const
{
    return serviceId;
}

Member *Service::getServiceOwner() const
{
    return serviceOwner;
}

Date Service::getStartTime() const
{
    return startTime;
}

Date Service::getEndTime() const
{
    return endTime;
}

int Service::getConsumingCD() const
{
    return consumingCD;
}

double Service::getScoreRequired() const
{
    return score_required;
}

const std::vector<Skill> &Service::getSkillList() const
{
    return skillList;
}
const std::vector<Request> &Service::getRequestList() const
{
    return requestList;
}
// Setter functions
void Service::setServiceId(const std::string &id)
{
    this->serviceId = id;
}

void Service::setServiceOwner(Member *owner)
{
    this->serviceOwner = owner;
}

void Service::setStartTime(std::string startTime)
{
    // Assuming you have a Date setter function that takes a string.
    this->startTime = Date::parse(startTime);
}

void Service::setEndTime(std::string endTime)
{
    // Assuming you have a Date setter function that takes a string.
    this->endTime = Date::parse(endTime);
}

void Service::setConsumingCD(int cd)
{
    this->consumingCD = cd;
}

void Service::setScoreRequired(double score)
{
    this->score_required = score;
}

void Service::setSkillList(const std::vector<Skill> &skills)
{
    this->skillList = skills;
}
void Service::setRequestList(const std::vector<Request> &requests)
{
    this->requestList = requests;
}

// funtional
void Service::addRequest(Request *request)
{
    this->requestList.push_back(*request);
}