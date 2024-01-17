

#include "Request.h"

// Constructor
Request::Request(
    std::string requestId,
    Service *service,
    Member *requester,
    Date startTime,
    Date endTime,
    int status)
    : requestId(requestId), service(service), requester(requester),
      startTime(startTime), endTime(endTime), status(status) {}

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

Date Request::getStartTime() const
{
    return startTime;
}

Date Request::getEndTime() const
{
    return endTime;
}

int Request::getStatus() const
{
    return status;
}

// setter functions
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
void Request::setStartTime(std::string startTime)
{
    this->startTime = Date::parse(startTime);
}
void Request::setEndTime(std::string endTime)
{
    this->endTime = Date::parse(endTime);
}
void Request::setStatus(int status)
{
    this->status = status;
}
