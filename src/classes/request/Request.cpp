//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#include "Request.h"
using namespace std;
#include <string>

Request::Request(string requestId, Service *service, Member *requester, string startTime,
                 string endTime, int status, int score) : requestId(requestId), service(service), requester(requester), startTime(startTime), endTime(endTime), status(status), score(score)
{
}

// Getter functions
std::string Request::getRequestId() const
{
    return requestId;
}

Service *Request::getService() const
{
    return service;
}

Member *Request::getRequester() const
{
    return requester;
}

std::string Request::getStartTime() const
{
    return startTime;
}

std::string Request::getEndTime() const
{
    return endTime;
}

int Request::getStatus() const
{
    return status;
}

int Request::getScore() const
{
    return score;
}

// Setter functions
void Request::setRequestId(const std::string &requestId)
{
    this->requestId = requestId;
}

void Request::setService(Service *service)
{
    this->service = service;
}

void Request::setRequester(Member *requester)
{
    this->requester = requester;
}

void Request::setStartTime(const std::string &startTime)
{
    this->startTime = startTime;
}

void Request::setEndTime(const std::string &endTime)
{
    this->endTime = endTime;
}

void Request::setStatus(int status)
{
    this->status = status;
}

void Request::setScore(int score)
{
    this->score = score;
}
