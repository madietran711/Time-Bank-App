

#include "Request.h"

// Constructor
Request::Request(
    std::string requestId,
    Service *service,
    Member *requester,
    Date *startTime,
    Date *endTime,
    int status,
    int score)
    : requestId(requestId), service(service), requester(requester),
      startTime(startTime), endTime(endTime), status(status), score(score) {}

// Return array of info to display
int *Request::returnRequestInfo()
{
    /// format
    return requestInfo;
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

Date *Request::getStartTime() const
{
    return startTime;
}

Date *Request::getEndTime() const
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
