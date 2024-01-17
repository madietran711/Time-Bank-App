#include "Service.h"

// Default constructor
Service::Service(
    std::string serviceId,
    Member *serviceOwner,
    std::string startTime,
    std::string endTime,
    int consumingCD,
    double scoreRequired,
    std::vector<Skill> skillList)
    : serviceId(serviceId), serviceOwner(serviceOwner), consumingCD(consumingCD),
      score_required(scoreRequired), skillList(std::move(skillList))
{

    // Assuming you have a Date constructor that takes a string for initialization.
    this->startTime = new Date(startTime);
    this->endTime = new Date(endTime);
}

// Getter functions
std::string Service::getServiceId() const
{
    return serviceId;
}

Member *Service::getServiceOwner() const
{
    return serviceOwner;
}

Date *Service::getStartTime() const
{
    return startTime;
}

Date *Service::getEndTime() const
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

// Setter functions
void Service::setServiceId(const std::string &id)
{
    serviceId = id;
}

void Service::setServiceOwner(Member *owner)
{
    serviceOwner = owner;
}

void Service::setStartTime(const std::string &start)
{
    // Assuming you have a Date setter function that takes a string.
    startTime->setDateTimeFromString(start);
}

void Service::setEndTime(const std::string &end)
{
    // Assuming you have a Date setter function that takes a string.
    endTime->setDateTimeFromString(end);
}

void Service::setConsumingCD(int cd)
{
    consumingCD = cd;
}

void Service::setScoreRequired(double score)
{
    score_required = score;
}

void Service::setSkillList(const std::vector<Skill> &skills)
{
    skillList = skills;
}

// Destructor
Service::~Service()
{
    // Add cleanup code for dynamic memory if needed.
    delete startTime;
    delete endTime;
}
