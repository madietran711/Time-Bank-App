#ifndef TIME_BANK_APP_GUEST_H
#define TIME_BANK_APP_GUEST_H

#include <string>
#include <vector>
#include "../../utils/colors.h"
#include "../service/Service.h"
#include "../skill/Skill.h"
#include <iomanip>
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

#endif // TIME_BANK_APP_GUEST_H
