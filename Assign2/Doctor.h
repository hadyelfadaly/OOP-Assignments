//Hady Hassan Sayed Hassan El Fadaly 20236113
//Ziad Tarek El Marsafawy 20236043

#include <bits/stdc++.h>
#include "surgerySchedule.h"
#pragma once //to ensure that the header file contents are included only once during compilation

using namespace std;

class Doctor
{

protected:

    string id, name;
    int duration;
    double rate;

public:

    //default constructor to initialise variables
    Doctor()
    {

        id = "";
        name = "";
        duration = 0;
        rate = 0.0;

    }
    //parameterized constructor to initialise variables with given parameters
    Doctor(string docId, string docName, int totalDuration, double ratePerMinute)
    {

        id = docId;
        name = docName;
        duration = totalDuration;
        rate = ratePerMinute;

    }

    //function prototypes to be implemented in .cpp file
    virtual double calculateTotalFee() const;
    virtual string PrettyPrint() const;
    virtual void setSurgery(int index, const surgerySchedule& surgery) = 0;//pure virtual function
    virtual void printSurgeries(ostream &strm) const = 0;//pure virtual function

};

