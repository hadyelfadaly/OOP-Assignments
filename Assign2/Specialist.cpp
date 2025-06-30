//Hady Hassan Sayed Hassan El Fadaly 20236113
//Ziad Tarek El Marsafawy 20236043

#include "Specialist.h"
#include <bits/stdc++.h>

using namespace std;

//override of the inherited calculateTotalFee function to calculate per quarter hour
double Specialist::calculateTotalFee() const
{return (duration / 15.0) * rate;}

//override of the inherited PrettyPrint function
string Specialist::PrettyPrint() const
{return "Dr. " + name + " is a specialist whose total fee is " + to_string(calculateTotalFee()) + ".";}

//just function body as we dont need it in this class
void Specialist::setSurgery(int index, const surgerySchedule& surgery){}

//just function body as we dont need it in this class
void Specialist::printSurgeries(ostream &strm) const {}