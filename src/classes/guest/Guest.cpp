// Guest.cpp

#include "Guest.h"

// Constructors

// Functions

void Guest::showAllService(std::vector<Service *> serviceList)
{
    int index = 1;
    std::cout << Colors::GREEN << "--------------View Listings----------------\n"
              << Colors::RESET;
    for (Service *service : serviceList)
    {
        std::cout << Colors::CYAN
                  << index << ". "
                  << "Service Id: " << service->getServiceId()
                  << Colors::RESET
                  << std::endl
                  << std::setw(5) << "Supporter: " << service->getServiceOwner()->getFullName()
                  << std::setw(5) << "Id: " << service->getServiceOwner()->getFullName()
                  << std::endl
                  << std::setw(5) << "Skill offered: " << getSkillsString(service->getSkillList())
                  << std::endl
                  << std::setw(5) << "Time Available: " << service->getStartTime().toString() << " - " << service->getEndTime().toString()
                  << std::setw(5) << "Location: " << service->getServiceOwner()->getCityLocation()
                  << std::endl;
        index++;
    }
}

std::string Guest::getSkillsString(std::vector<Skill *> skillList)
{
    std::string skillString = "";
    for (Skill *skill : skillList)
    {
        skillString += skill->getSkillName();
        if (skill != skillList.back())
        {
            skillString += ", ";
        }
    }
    return skillString;
}
