#ifndef TIME_BANK_APP_GUEST_H
#define TIME_BANK_APP_GUEST_H

#include <string>
#include <vector>
#include "../system/System.h"
#include "../date/Date.h"
#include "../skill/Skill.h"
#include "../service/Service.h"
#include "../../utils/colors.h"

class System;
class Date;
class Service;
class Skill;

class Guest
{
private:
public:
    Guest() = default;

    void showAllService(std::vector<Service *> serviceList);

    std::string getSkillsString(std::vector<Skill *> skillList);
};

#endif