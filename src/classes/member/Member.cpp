#include <iostream>
#include <vector>
#include "Member.h"

#define STRSIZE 100

Member::Member(std::string memberId,
               std::string username,
               std::string password,
               std::string fullName,
               std::string phoneNumber,
               std::string email,
               std::string homeAddress,
               double hostScore,
               double supporterScore,
               std::vector<Skill> skills = {},
               std::vector<Service> listedService = {})
    : memberId(memberId),
      username(username),
      password(password),
      fullName(fullName),
      phoneNumber(phoneNumber),
      email(email),
      homeAddress(homeAddress),
      hostScore(hostScore),
      supporterScore(supporterScore),
      skills(skills),
      listedService(listedService){};
void Member::addSkill(Skill *skill)
{
  this->skills.push_back(*skill);
};

void Member::addService(Service *service)
{
  this->listedService.push_back(*service);
};
