//Hady Hassan Sayed Hassan El Fadaly 20236113
//Ziad Tarek El Marsafawy 20236043

#include <bits/stdc++.h>
#pragma once //to ensure that the header file contents are included only once during compilation

using namespace std;

class surgerySchedule
{

private:

    string patientName, Date;

public:

    //default constructor to initialise variables
    surgerySchedule()
    {

        patientName = "";
        Date = "";

    }
    //parameterized constructor to initialise variables with given parameters
    surgerySchedule(string pName, string date)
    {

        patientName = pName;
        Date = date;

    }

    //setters prototypes to be implemented in .cpp file
    void setPatientName(string pName);
    void setDate(string date);

    //getters prototypes to be implemented in .cpp file
    string getPatientName() const;
    string getDate() const;

};