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