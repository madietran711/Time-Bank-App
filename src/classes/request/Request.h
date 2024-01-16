//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#ifndef TIME_BANK_APP_REQUEST_H
#define TIME_BANK_APP_REQUEST_H
#include<string>
#include "Service.h"
#include "Member.h"
class Request {
private:
    std::string requestId;
    Service *service;
    Member *requester;
    std::string startTime;
    std::string endTime;
    int status;
    int score;



public:
    Request(
            std::string requestId,
            Service *service,
            Member *requester,
            std::string startTime,
            std::string endTime,
            int status,
            int score);

    // Return address of the array of info to display
    int *returnRequestInfo();

};

#endif //TIME_BANK_APP_REQUEST_H