//Hady Hassan Sayed Hassan El Fadaly 20236113
//Ziad Tarek El Marsafawy 20236043

#include "Surgeon.h"
#include <bits/stdc++.h>

using namespace std;

//override of the inherited calculateTotalFee function to calculate per hour
double Surgeon::calculateTotalFee() const
{return (duration / 60.0) * rate;}

//override of the inherited PrettyPrint function
string Surgeon::PrettyPrint() const
{return "Dr. " + name + " is a surgeon whose total fee is " + to_string(calculateTotalFee()) + " and has "
+ to_string(numSurgeriesScheduled) + " surgeries scheduled.";}

//setter or mutator for surgeries
void Surgeon::setSurgery(int index, const surgerySchedule& surgery)
{

    if(index >= 0 && index < numSurgeriesScheduled) surgeries[index] = surgery;

}

//function to print all scheduled surgeries
void Surgeon::printSurgeries(ostream &strm) const
{

    for(int i = 0; i < numSurgeriesScheduled; i++)
    {

        strm<<"Surgery "<<i + 1<<": Patient Name: "<<surgeries[i].getPatientName()<<", Date: "<<surgeries[i].getDate()<< endl;

    }

}