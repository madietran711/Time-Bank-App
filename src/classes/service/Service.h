#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <vector>
#include "Skill.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

class Service
{
private:
    string service_owner;
    string start_time;
    string end_time;
    vector<Skill> skill_list;
    int consuming_CD;
    double score_required;
    string supporter_name;

public:
    Service(
        string service_owner,
        string start_time,
        string end_time,
        vector<Skill> skill_list,
        int consuming_CD,
        double score_required,
        string supporter_name);

    // Return address of the array of info to display
    int *returnServiceInfo();
};

#endif