#include <iostream>
#include <vector>
#include "Skill.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

Skill::Skill(string skillId,
             Member *owner,
             string skillName,
             double ratingScore)
    : skillId(skillId),
      owner(owner),
      skillName(skillName),
      ratingScore(ratingScore){};