#ifndef SKILL_H
#define SKILL_H

#include "Member.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

class Skill
{
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

    string getOwnerID();

    friend class System;
};

#endif