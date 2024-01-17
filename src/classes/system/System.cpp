#include "System.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istringstream;
using std::stoi;
using std::string;
using std::vector;

System::System(vector<Member *> member_list,
               vector<Service *> service_list,
               vector<Request *> request_list,
               vector<Skill *> skill_list)
    : member_list(member_list),
      service_list(service_list),
      request_list(request_list),
      skill_list(skill_list){};

Member *System::getMember(string memID)
{
    for (Member *member : member_list)
    {
        if (member->memberId == memID)
        {
            return member;
        }
    }
};

Service *System::getService(string servID)
{
    for (Service *service : service_list)
    {
        if (service->serviceId == servID)
        {
            return service;
        }
    }
}

// Delete function
// void System::linkSkillToMember(Skill *skill)
// {
//     for (auto &member : member_list)
//     {
//         if (member->getID() == skill->getOwnerID())
//         {
//             member->addSkill(skill);
//         }
//     }
// }

void System::initData()
{
    initMembers();
    initRequests();
    initSkills();
    initServices;
}
vector<string> System::splitStr(string &input, string delimiter)
{
    vector<string> tokens;
    istringstream stream(input);
    string token;

    while (getline(stream, token, delimiter[0]))
    {
        tokens.push_back(token);
    }

    return tokens;
}
void System::initMembers()
{
    member_list.clear();

    std::ifstream file(MEMBER_FILE);

    if (!file.is_open())
    {
        std::cerr << "Error opening the file" << endl;
        return;
    }

    string str;
    while (getline(file, str))
    {
        vector<string> infos;
        infos = splitStr(str, ";");
        Member *member = new Member(
            infos.at(0),
            infos.at(1),
            infos.at(2),
            infos.at(3),
            infos.at(4),
            infos.at(5),
            infos.at(6),
            std::stod(infos.at(7)),
            std::stod(infos.at(8)),
            {},
            {});
        member_list.push_back(member);
    };
    file.close();
}

void System::initSkills()
{
    skill_list.clear();
    std::ifstream file(SKILL_FILE);

    if (!file.is_open())
    {
        std::cerr << "Error opening the file" << endl;
        return;
    }

    string str;
    while (getline(file, str))
    {
        vector<string> infos;
        infos = splitStr(str, ";");
        Member *currentMember = getMember(infos.at(1));
        Skill *skill = new Skill(
            infos.at(0),
            currentMember,
            infos.at(2),
            std::stod(infos.at(3)));
        skill_list.push_back(skill);
        currentMember->addSkill(skill);
    };
    file.close();
}

void System::initServices()
{
    service_list.clear();

    std::ifstream file(SERVICE_FILE);
    if (!file.is_open())
    {
        std::cerr << "Error opening the file" << endl;
        return;
    }

    string str;
    while (getline(file, str))
    {
        vector<string> infos;
        infos = splitStr(str, ";");
        Member *currentMember = getMember(infos.at(1));
        Service *service = new Service(
            infos.at(0),
            currentMember,
            infos.at(2),
            infos.at(3),
            infos.at(4),
            stoi(infos.at(5)),
            stod(infos.at(6)),
            currentMember,
            {});
        service_list.push_back(service);
        currentMember->addService(service);
    };
    file.close();
};

void System::initRequests()
{
    service_list.clear();

    std::ifstream file(REQUEST_FILE);
    if (!file.is_open())
    {
        std::cerr << "Error opening the file" << endl;
        return;
    }

    string str;
    while (getline(file, str))
    {
        vector<string> infos;
        infos = splitStr(str, ";");
        Service *currentService = getService(infos.at(1));
        Member *currentMember = getMember(infos.at(2));
        Request *request = new Request(
            infos.at(0),
            currentService,
            currentMember,
            infos.at(3),
            infos.at(4),
            stoi(infos.at(6)),
            stoi(infos.at(7)));
        request_list.push_back(request);
    };
    file.close();
};

void System::updateMemberFile()
{
    std::ofstream file(MEMBER_FILE, std::ios::app);

    if (!file.is_open())
    {
        std::cerr << "Error opening file for appending!" << std::endl;
        return;
    }
    for (Member *member : member_list)
    {
        file << member->memberId << ";"
             << member->username << ";"
             << member->password << ";"
             << member->fullName << ";"
             << member->phoneNumber << ";"
             << member->email << ";"
             << member->homeAddress << ";"
             << member->hostScore << ";"
             << member->supporterScore << endl;
    }

    file.close();
}

void System::updateServiceFile()
{
    std::ofstream file(SERVICE_FILE);
    if (!file.is_open())
    {
        std::cerr << "Error opening file for appending!" << std::endl;
        return;
    }

    for (Service *service : service_list)
    {
        file << service->serviceId << ";"
             << service->service_owner->memberId << ";"
             << service->startTime << ";"
             << service->endTime << ";"
             << service->availableTime << ";"
             << service->consumingCD << ";"
             << service->score_required << ";"
             << service->supporter->memberId << endl;
    }
    file.close();
}

void System::updateSkillsFile()
{
    std::ofstream file(SKILL_FILE);
    if (!file.is_open())
    {
        std::cerr << "Error opening file for appending!" << std::endl;
        return;
    }

    for (Skill *skill : skill_list)
    {
        file << skill->skillId << ";"
             << skill->owner->memberId << ";"
             << skill->skillName << ";"
             << skill->ratingScore << endl;
    }
    file.close();
}

void System::updateRequestFile()
{
    std::ofstream file(REQUEST_FILE);
    if (!file.is_open())
    {
        std::cerr << "Error opening file for appending!" << std::endl;
        return;
    }

    for (Request *request : request_list)
    {
        file << request->requestId << ";"
             << request->service->serviceId << ";"
             << request->requester->memberId << ";"
             << request->startTime << ";"
             << request->endTime << ";"
             << request->status << ";"
             << request->score << endl;
    }
    file.close();
}

