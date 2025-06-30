//Hady Hassan El Fadaly 20236113
//Khaled Mohamed 20235010

#include <bits/stdc++.h>

using namespace std;

class Passenger
{

//writing our member variables need int the private part so they cant be accessed by users
private:

    string name;
    int ID;
    static int passengerCount;

public:

    //2 arguments constructor that can also be default constructor when needed
    Passenger(string n = "", int id = 0)
    {

        name = n;
        ID = id;

        passengerCount++;

    }

    void Display(); //function prototype, implementation in .cpp file
    static int getCount(); //function prototype, implementation in .cpp file
    string getName(); //function prototype, implementation in .cpp file

    friend istream &operator>>(istream &is, Passenger &p);
    bool operator==(Passenger &obj);

    ~Passenger()
    {

        passengerCount--;

        if(name != "") cout<<"Passenger Removed or Arrived Safely"<<endl;

    }

};