//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#ifndef TIME_BANK_APP_SKILL_H
#define TIME_BANK_APP_SKILL_H
#include <string>
#include "Member.h"


class Skill {
private:
    std::string skillId;
    Member *owner;
    std::string skillName;
    double ratingScore;

public:
    Skill(
            std::string skillId,
            Member *owner,
            std::string skillName,
            double ratingScore);


    // Return address of the array of info to display
    int *returnSkillInfo();
};


#endif //TIME_BANK_APP_SKILL_H
