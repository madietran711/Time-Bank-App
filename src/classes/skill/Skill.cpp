#include "Skill.h"

// Constructor
Skill::Skill(
    std::string skillId,
    Member *owner,
    std::string skillName,
    double ratingScore)
    : skillId(skillId), owner(owner), skillName(skillName), ratingScore(ratingScore)
{
}

// Getter functions
std::string Skill::getSkillId() const
{
    return skillId;
}

Member *Skill::getOwner() const
{
    return owner;
}

std::string Skill::getSkillName() const
{
    return skillName;
}

double Skill::getRatingScore() const
{
    return ratingScore;
}

// Setter functions
void Skill::setOwner(Member *owner)
{
    this->owner = owner;
}

void Skill::setSkillName(std::string skillName)
{
    this->skillName = skillName;
}

void Skill::setRatingScore(double ratingScore)
{
    this->ratingScore = ratingScore;
}

void Skill::setSkillId(const std::string id)
{
    this->skillId = id;
}