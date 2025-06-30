//Hady Hassan Sayed Hassan El Fadaly 20236113
//Ziad Tarek El Marsafawy 20236043

#include "Doctor.h"
#include <bits/stdc++.h>

using namespace std;

//get total fee and put as const because its a getter we want to make sure it wont change anything
double Doctor::calculateTotalFee() const
{return duration * rate;}

//print doctor details and put as const because its a getter we want to make sure it wont change anything
string Doctor::PrettyPrint() const
{return "Doctor ID is " + id + ", and name is " + name;}