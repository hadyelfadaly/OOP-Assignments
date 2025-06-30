//Hady Hassan Sayed Hassan El Fadaly 20236113
//Ziad Tarek El Marsafawy 20236043

#include <bits/stdc++.h>
#include "Doctor.h"
#include "surgerySchedule.h"
#pragma once //to ensure that the header file contents are included only once during compilation

using namespace std;

//surgeon class inherits from doctor class as surgeon is a doctor
class Specialist : public Doctor
{

private:

    string speciality;

public:

    //default constructor to initialise variables
    Specialist() : Doctor()
    {

        speciality = "";
        //inherited attributes
        id = "";
        name = "";
        duration = 0;
        rate = 0.0;

    }
    //parameterized constructor to initialise variables with given parameters
    Specialist(string docId, string docName, int totalDuration, double ratePerMinute, string spc)
    : Doctor(docId, docName, totalDuration, ratePerMinute)//pass the doctor related parameters
    {

        speciality = spc;

    }

    //override function prototypes of inherited functions to be implemented in .cpp file
    double calculateTotalFee() const override;
    string PrettyPrint() const override;
    void setSurgery(int index, const surgerySchedule& surgery) override;//just function prototype as we dont need it in this class
    void printSurgeries(ostream &strm) const override;//just function prototype as we dont need it in this class
};

