//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#ifndef TIME_BANK_APP_SYSTEM_H
#define TIME_BANK_APP_SYSTEM_H
#include<vector>
#include "Member.h"
#include "Service.h"
#include "Request.h"

class System {

public:
    std::vector<Member> member_list;
    std::vector<Service> service_list;
    std::vector<Request> request_list;

    System(std::vector<Member> member_list={}, std::vector<Service> service_list={}, std::vector<Request> request_list={});
};


#endif //TIME_BANK_APP_SYSTEM_H
