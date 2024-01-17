// Member.cpp

#include "Member.h"

// Constructors
Member::Member(
    std::string memberId,
    std::string username,
    std::string password,
    std::string fullName,
    std::string phoneNumber,
    std::string email,
    std::string homeAddress,
    double hostScore,
    double supporterScore,
    int creditPoint,
    std::vector<Skill> skills,
    std::vector<Member> blockedList,
    std::vector<Service> listedService,
    std::vector<Request> acceptedRequest)
    : memberId(memberId),
      username(username),
      password(password),
      fullName(fullName),
      phoneNumber(phoneNumber),
      email(email),
      homeAddress(homeAddress),
      hostScore(hostScore),
      supporterScore(supporterScore),
      creditPoint(creditPoint),
      skills(skills),
      blockedList(blockedList),
      listedService(listedService),
      acceptedRequest(acceptedRequest)
{
}

Member::Member(std::string username, std::string password)
    : username(username),
      password(password)
{
  // Initialize other members with default values
  // ...
}

// Getter functions
std::string Member::getMemberId() const
{
  return memberId;
}

std::string Member::getUsername() const
{
  return username;
}

std::string Member::getPassword() const
{
  return password;
}

std::string Member::getFullName() const
{
  return fullName;
}

std::string Member::getPhoneNumber() const
{
  return phoneNumber;
}

std::string Member::getEmail() const
{
  return email;
}

std::string Member::getHomeAddress() const
{
  return homeAddress;
}

double Member::getHostScore() const
{
  return hostScore;
}

double Member::getSupporterScore() const
{
  return supporterScore;
}

int Member::getCreditPoint() const
{
  return creditPoint;
}

const std::vector<Skill> &Member::getSkills() const
{
  return skills;
}

const std::vector<Member> &Member::getBlockedList() const
{
  return blockedList;
}

const std::vector<Service> &Member::getListedService() const
{
  return listedService;
}

const std::vector<Request> &Member::getAcceptedRequest() const
{
  return acceptedRequest;
}

// Setter functions
void Member::setMemberId(std::string memberId)
{
  this->memberId = memberId;
}

void Member::setUsername(std::string username)
{
  this->username = username;
}

void Member::setPassword(std::string password)
{
  this->password = password;
}

void Member::setFullName(std::string fullName)
{
  this->fullName = fullName;
}

void Member::setPhoneNumber(std::string phoneNumber)
{
  this->phoneNumber = phoneNumber;
}

void Member::setEmail(std::string email)
{
  this->email = email;
}

void Member::setHomeAddress(std::string homeAddress)
{
  this->homeAddress = homeAddress;
}

void Member::setHostScore(double hostScore)
{
  this->hostScore = hostScore;
}

void Member::setSupporterScore(double supporterScore)
{
  this->supporterScore = supporterScore;
}

void Member::setCreditPoint(int creditPoint)
{
  this->creditPoint = creditPoint;
}

void Member::setSkills(const std::vector<Skill> &skills)
{
  this->skills = skills;
}

void Member::setBlockedList(const std::vector<Member> &blockedList)
{
  this->blockedList = blockedList;
}

void Member::setListedService(const std::vector<Service> &listedService)
{
  this->listedService = listedService;
}

void Member::setAcceptedRequest(const std::vector<Request> &acceptedRequest)
{
  this->acceptedRequest = acceptedRequest;
}

// Member functions
bool Member::acceptRequest(Request *request)
{
  request->setStatus(1);
  this->acceptedRequest.push_back(*request);
  return true;

}
bool Member::addService(Service *service)
{
  this->listedService.push_back(*service);
  return true;
}

bool Member::addSkill(Skill *skill)
{
  this->skills.push_back(*skill);
  return true;
}