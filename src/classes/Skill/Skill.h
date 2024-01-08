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
    string owner;
    string skill_name;
    double rating_score;

public:
    Skill(
        string owner,
        string skill_name);

    Skill(
        string owner,
        string skill_name,
        double rating_score);

    // Return address of the array of info to display
    int *returnSkillInfo();
};

#endif