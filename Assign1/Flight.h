//Hady Hassan El Fadaly 20236113
//Khaled Mohamed 20235010

#include <bits/stdc++.h>
#include "Passenger.h"

using namespace std;

class Flight
{

private:

    //writing our member variables we need in the private part so they cant be accessed by users
    int flightNum, seatCapacity, numOfBooked;
    string flightDest, departureTime;
    string *passengersName;
    bool **seatingPlan;
    Passenger *passengers;
    map <string, string> seatNum;

    //needed functions for another required functions (remove passenger, add passenger,...etc.) made by me
    void DisplaySeatPlan();
    void deleteElement(Passenger*& arr, int& size, int index);

public:

    //3 arguments constructor for member variables initialisation
    Flight(int capacity, string dest, int num)
    {

        seatCapacity = capacity;
        flightNum = num;
        flightDest = dest;

        numOfBooked = 0;
        departureTime = "";
        passengersName = new string[seatCapacity];
        passengers = new Passenger[seatCapacity]; //already initialised with default constructor

        for(int i = 0; i < seatCapacity; i++) passengersName[i] = "";

        seatingPlan = new bool *[seatCapacity/6];

        for(int i = 0; i < seatCapacity/6; i++) seatingPlan[i] = new bool[seatCapacity/10];

        for (int i = 0; i < seatCapacity/6; i++) for(int j = 0; j < seatCapacity/10; j++) seatingPlan[i][j] = false;

    }
    //copy constructor
    Flight(Flight &obj)
    {

        seatCapacity = obj.seatCapacity;
        flightNum = obj.flightNum;
        flightDest = obj.flightDest;
        numOfBooked = obj.numOfBooked;
        departureTime = obj.departureTime;
        passengersName = new string[seatCapacity];
        passengers = new Passenger[seatCapacity]; //already initialised with default constructor

        for(int i = 0; i < seatCapacity; i++) passengersName[i] = obj.passengersName[i];

        seatingPlan = new bool *[seatCapacity/6];

        for(int i = 0; i < seatCapacity/6; i++) seatingPlan[i] = new bool[seatCapacity/10];

        for (int i = 0; i < seatCapacity/6; i++) for(int j = 0; j < seatCapacity/10; j++) seatingPlan[i][j] = obj.seatingPlan[i][j];

    }

    bool SearchName(string n); //function prototype, implementation in .cpp file
    bool SearchNum(int r, int c); //function prototype, implementation in .cpp file
    void display(); //function prototype, implementation in .cpp file
    void addPassengers(int num, Passenger *p); //function prototype, implementation in .cpp file
    void removePassenger(Passenger &obj); //function prototype, implementation in .cpp file
    int getNumBooked(); //function prototype, implementation in .cpp file
    string *getPassengersName(); //function prototype, implementation in .cpp file
    Passenger getPassenger(string n); //function prototype, implementation in .cpp file
    void setDeprture(string t); //function prototype, implementation in .cpp file

    friend ostream &operator<<(ostream &os, const Flight &f); //operator overloading prototype, implementation in .cpp file

    Flight operator++(); //operator overloading prototype, implementation in .cpp file
    void operator+=(Passenger &obj); //operator overloading prototype, implementation in .cpp file
    void operator--(int); //operator overloading prototype, implementation in .cpp file
    void operator-=(int n); //operator overloading prototype, implementation in .cpp file

    //destructor for cleaning up all dynamically allocated memory upon flight destruction
    ~Flight()
    {

        delete[] passengers;
        delete[] passengersName;

        for(int i = 0; i < seatCapacity/6; i++) delete seatingPlan[i];

        delete[] seatingPlan;

    }

};



