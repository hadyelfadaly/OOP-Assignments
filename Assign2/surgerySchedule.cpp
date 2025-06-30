//Hady Hassan Sayed Hassan El Fadaly 20236113
//Ziad Tarek El Marsafawy 20236043

#include "surgerySchedule.h"
#include <bits/stdc++.h>

using namespace std;

//setter or mutator for patient name
void surgerySchedule::setPatientName(string pName)
{patientName = pName;}

//setter or mutator for date
void surgerySchedule::setDate(string date)
{Date = date;}

//getter or accessor to patients name
string surgerySchedule::getPatientName() const
{return patientName;}

//getter or accessor to date
string surgerySchedule::getDate() const
{return Date;}