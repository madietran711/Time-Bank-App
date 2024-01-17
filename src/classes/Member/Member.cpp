//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#include "Member.h"
#include <string>
using namespace std;

Member::Member(std::string memberId, std::string username, std::string password, std::string fullName,
               std::string phoneNumber, std::string email, std::string homeAddress, double hostScore,
               double supporterScore, std::vector<Skill> skills, vector<Member> blockedList, std::vector<Service> listedService)
    : memberId(memberId), username(username), password(password), fullName(fullName),
      phoneNumber(phoneNumber), email(email), homeAddress(homeAddress), hostScore(hostScore),
      supporterScore(supporterScore), skills(move(skills)), blockedList(move(blockedList)), listedService(move(listedService))
{
}

bool Member::addSkill(Skill *skill)
{
  this->skills.push_back(*skill);
  return true;
}