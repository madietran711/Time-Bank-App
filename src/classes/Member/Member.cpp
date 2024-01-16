//
// Created by TRAN HA PHUONG on 12/01/2024.
//

#include "Member.h"


Member::Member(std::string username, std::string password):username(username), password(password) {

}

void Member::addSkill(Skill *skill) {
    this->skills.push_back(*skill);
}

Member::Member(std::string memberId, std::string username, std::string password, std::string fullName,
               std::string phoneNumber, std::string email, std::string homeAddress, double hostScore,
               double supporterScore, std::vector<Skill> skills={}, std::vector<Service> listedService):memberId(memberId), username(username), password(password), fullName(fullName), phoneNumber(phoneNumber), email(email), homeAddress(homeAddress), hostScore(hostScore), supporterScore(supporterScore), skills(skills), listedService(listedService) {

}
