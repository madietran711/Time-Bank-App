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
    int creditPoint)
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
      skills({}),
      blockedList({}),
      acceptedRequest({}),
      listedService({}){};

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

const std::vector<Skill *> &Member::getSkills() const
{
  return skills;
}

const std::vector<Member *> &Member::getBlockedList() const
{
  return blockedList;
}

const std::vector<Service *> &Member::getListedService() const
{
  return listedService;
}

const std::vector<Request *> &Member::getAcceptedRequest() const
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

void Member::setSkills(const std::vector<Skill *> &skills)
{
  this->skills = skills;
}

void Member::setBlockedList(const std::vector<Member *> &blockedList)
{
  this->blockedList = blockedList;
}

void Member::setListedService(const std::vector<Service *> &listedService)
{
  this->listedService = listedService;
}

void Member::setAcceptedRequest(const std::vector<Request *> &acceptedRequest)
{
  this->acceptedRequest = acceptedRequest;
}

// Member functions
bool Member::acceptRequest(Request *request)
{
  request->setStatus(1);
  this->acceptedRequest.push_back(request);
  return true;
}
bool Member::addService(Service *service)
{
  this->listedService.push_back(service);
  return true;
}

bool Member::addSkill(Skill *skill)
{
  this->skills.push_back(skill);
  return true;
}

void Member::viewProfile()
{
  std::cout << Colors::YELLOW
            << std::left << std::setw(10) << this->getMemberId()
            << std::left << std::setw(20) << this->getUsername()
            << std::left << std::setw(20) << this->getFullName()
            << std::left << std::setw(20) << this->getPhoneNumber()
            << std::left << std::setw(20) << this->getEmail()
            << std::left << std::setw(20) << this->getHomeAddress()
            << std::left << std::setw(20) << this->getHostScore()
            << std::left << std::setw(20) << this->getSupporterScore()
            << std::left << std::setw(20) << this->getCreditPoint()

            << Colors::RESET << std::endl;
}

void Member::showSkills()
{
  std::cout << Colors::MAGENTA
            << std::left << std::setw(10) << "Skill ID"
            << std::left << std::setw(20) << "Skill Name"
            << std::left << std::setw(20) << "Skill Point"
            << Colors::RESET << std::endl;
  for (Skill *skill : this->skills)
  {
    std::cout << Colors::YELLOW
              << std::left << std::setw(10) << skill->getSkillId()
              << std::left << std::setw(20) << skill->getSkillName()
              << std::left << std::setw(20) << skill->getRatingScore()
              << Colors::RESET << std::endl;
  }
}