//Hady Hassan Sayed Hassan El Fadaly 20236113
//Ziad Tarek El Marsafawy 20236043

#include <bits/stdc++.h>
#include "Doctor.h"
#include "surgerySchedule.h"
#pragma once //to ensure that the header file contents are included only once during compilation

using namespace std;

//surgeon class inherits from doctor class as surgeon is a doctor
class Surgeon : public Doctor
{

private:

    int numSurgeriesScheduled;
    surgerySchedule* surgeries;//aggregation

public:

    //default constructor to initialise variables
    Surgeon() : Doctor()
    {

        numSurgeriesScheduled = 0;
        surgeries = new surgerySchedule();
        //inherited attributes
        id = "";
        name = "";
        duration = 0;
        rate = 0.0;

    }
    //parameterized constructor to initialise variables with given parameters
    Surgeon(string docId, string docName, int totalDuration, double ratePerMinute, int numSurgeries)
    : Doctor(docId, docName, totalDuration, ratePerMinute)//pass the doctor related parameters
    {

        numSurgeriesScheduled = numSurgeries;
        surgeries = new surgerySchedule[numSurgeriesScheduled];

    }
    //copy constructor for deep copying
    Surgeon(const Surgeon& other) : Doctor(other.id, other.name, other.duration, other.rate)
    {

        numSurgeriesScheduled = other.numSurgeriesScheduled;
        surgeries = new surgerySchedule[numSurgeriesScheduled];
        for(int i = 0; i < numSurgeriesScheduled; i++) surgeries[i] = other.surgeries[i];

    }

    //override function prototypes of inherited functions to be implemented in .cpp file
    double calculateTotalFee() const override;
    string PrettyPrint() const override;
    void setSurgery(int index, const surgerySchedule& surgery) override;
    void printSurgeries(ostream &strm) const override;//it takes ostream obj as a parameter so i can print it to file and to console

    //destructor to delete allocated memory of the dynamic allocated array
    ~Surgeon()
    {

        delete[] surgeries;

    }

};