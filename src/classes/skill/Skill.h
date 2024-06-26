#ifndef TIME_BANK_APP_SKILL_H
#define TIME_BANK_APP_SKILL_H

#include <string>
#include "../member/Member.h"
class Member;
class Skill
{
private:
    std::string skillId;
    Member *owner;
    std::string skillName;
    double ratingScore;

public:
    // Constructor
    Skill() = default; // default constructor
    Skill(
        std::string skillId,
        Member *owner,
        std::string skillName,
        double ratingScore);

    // Getter functions
    std::string getSkillId() const;
    Member *getOwner() const;
    std::string getSkillName() const;
    double getRatingScore() const;

    // Setter functions
    void setSkillId(std::string id);
    void setOwner(Member *owner);
    void setSkillName(std::string skillName);
    void setRatingScore(double ratingScore);
};

#endif // TIME_BANK_APP_SKILL_H
     // TIME_BANK_APP_SKILL_H
