//Hady Hassan El Fadaly 20236113
//Khaled Mohamed 20235010

#include <bits/stdc++.h>
#include "Passenger.h"

using namespace std;

void Passenger::Display()
{

    cout<<"Name: "<<name<<" ID: "<<ID<<endl;

}
int Passenger::getCount()
{return passengerCount;}
string Passenger::getName()
{return name;}

istream &operator>>(istream &is, Passenger &p)
{

    cout<<"Passenger's Name: ";

    is>>p.name;

    cout<<"Passenger's ID: ";

    is>>p.ID;

    return is;

}
//overloading == i made not required in the assignment
bool Passenger::operator==(Passenger &obj)
{

    if(name == obj.name && ID == obj.ID) return true;
    else return false;

}

int Passenger::passengerCount = 0;