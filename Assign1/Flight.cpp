//Hady Hassan El Fadaly 20236113
//Khaled Mohamed 20235010

#include <bits/stdc++.h>
#include "Flight.h"

using namespace std;

//implementation file for flight class

int row1, column1;

bool Flight::SearchName(string n)
{

    bool flag = false; //initialise flag to false

    for(int i = 0; i < numOfBooked; i++)
    {

        if(passengersName[i] == n)
        {

            flag = true; //if we find the name in our list make flag = true
            break;

        }

    }

    return flag;

}
bool Flight::SearchNum(int r, int c)
{

    if(seatingPlan[r-1][c-1]) return true;
    else return false;

}
void Flight::display()
{

    cout<<"Flight Number: "<<flightNum<<endl;
    cout<<"Seating Capacity: "<<seatCapacity<<endl;
    cout<<"Flight Destination: "<<flightDest<<endl;
    cout<<"Departure: "<<departureTime<<endl;
    cout<<"Number of Booked Seats: "<<numOfBooked<<endl;
    cout<<"Passengers Names: "<<endl;

    for (int i = 0; i < seatCapacity; i++)
    {

        if(passengersName[i].empty()) break;
        else cout<<passengersName[i]<<endl;

    }

    cout<<"Seating Plan: "<<endl;

    DisplaySeatPlan();

}
void Flight::addPassengers(int num, Passenger *p)
{

    for(int i = 0; i < num; i++)
    {

        cout<<"Choose Your Seat: "<<endl;

        DisplaySeatPlan();//display seating plan to see available seats

        cout<<"Row: ";

        cin>>row1;

        cout<<"Column: ";

        cin>>column1;

        //while loop for unavailable seat
        while(SearchNum(row1, column1))
        {

            cout<<"Unavailable please choose another seat: ";

            cin>>row1>>column1;

        }

        seatingPlan[row1-1][column1-1] = true; //reserving the passenger seat on the plan
        passengersName[numOfBooked] = p[i].getName(); //adding passenger name to the list of names
        passengers[numOfBooked] = p[i]; //adding passenger to list of passengers
        seatNum[p[i].getName()] = to_string(row1-1) + to_string(column1-1); //map to hold every passenger with his seat number
        //out of this course content

        numOfBooked++; //increment number of booked seats

    }

}
//function i made for displaying seats that wasnt required in the assignment
void Flight::DisplaySeatPlan()
{

    for(int i = 0; i < seatCapacity/6; i++) //dividing seat capacity by 6 to get 10 the rows for 6 seats per row
    {

        for (int j = 0; j < seatCapacity/20; j++) //dividing by 20 to get the first 3 columns
        {

            if(seatingPlan[i][j]) cout<<"R ";
            else cout<<"A ";

            if(j != (seatCapacity/20)-1) cout<<" ";

        }

        cout<<"\t";

        for (int j = seatCapacity/20; j < seatCapacity/10; j++) //dividing by 20 to get the second 3 columns
        {

            if(seatingPlan[i][j]) cout<<"R ";
            else cout<<"A ";

            if(j != (seatCapacity/10)-1) cout<<" ";

        }

        cout<<endl;

    }

}
//function i made for deleting specific elements in an array that wasnt required in the assignment
void Flight::deleteElement(Passenger*& arr, int& size, int index)
{

    Passenger* newArr = new Passenger[size - 1]; //initialising array of smaller size

    //copy elements skipping the element at index that we want to delete
    for(int i = 0, j = 0; i < size; i++) if(i != index) newArr[j++] = arr[i];

    delete[] arr; //deallocate old array
    arr = newArr; //point to new array
    size--;

}
void Flight::removePassenger(Passenger &obj)
{

    for (int i = 0; i < numOfBooked; i++)
    {

        if(passengers[i] == obj)
        {

            deleteElement(passengers,numOfBooked, i);
            string n = obj.getName();
            int seat = stoi(seatNum[n]); //convert the seat number into int
            seatingPlan[seat/10][seat%10] = false; //get 1st num as the row 2nd num as the column and make his seat available
            seatNum.erase(passengersName[i]); //deleting passenger's seat number and name from the map
            passengersName[i] = "";
            break;

        }

    }

}
int Flight::getNumBooked()
{return numOfBooked;}
//function i made to get specific passenger by name
Passenger Flight::getPassenger(string n)
{

    for(int i = 0; i < numOfBooked; i++) if(n == passengers[i].getName()) return passengers[i];

}
void Flight::setDeprture(std::string t)
{departureTime = t;}

ostream &operator<<(ostream &os, const Flight &f)
{

    os<<"Flight Number: "<<f.flightNum<<endl;
    os<<"Seating Capacity: "<<f.seatCapacity<<endl;
    os<<"Flight Destination: "<<f.flightDest<<endl;
    os<<"Departure: "<<f.departureTime<<endl;
    os<<"Number of Booked Seats: "<<f.numOfBooked<<endl;
    os<<"Passengers Names: "<<endl;

    for (int i = 0; i < f.seatCapacity; i++)
    {

        if(f.passengersName[i].empty()) break;
        else os<<f.passengersName[i]<<endl;

    }

    cout<<"Seating Plan: "<<endl;

    for (int i = 0; i < f.seatCapacity/6; i++) //dividing seat capacity by 6 to get 10 the rows for 6 seats per row
    {

        for(int j = 0; j < f.seatCapacity/20; j++) //dividing by 20 to get the first 3 columns
        {

            if(f.seatingPlan[i][j]) cout<<"R ";
            else os<<"A ";

        }

        os<<'\t'; //space between every 3 columns

        for(int j = f.seatCapacity/20; j < f.seatCapacity/10; j++) //dividing by 20 to get the second 3 columns
        {

            if(f.seatingPlan[i][j]) cout<<"R ";
            else os<<"A ";

        }

        os<<endl;

    }

}
Flight Flight::operator++()
{

    int rows = seatCapacity / 6;
    ++rows;

    seatingPlan = new bool *[rows];

    for(int i = 0; i < seatCapacity/6; i++) seatingPlan[i] = new bool[seatCapacity/10];

    return *this;

}
void Flight::operator+=(Passenger &obj)
{

    addPassengers(1, &obj);

}
void Flight::operator--(int)
{

    passengersName[numOfBooked-1] = ""; //reinitialise the deleted passenger name to empty string

    seatingPlan[row1][column1] = false; //make his seat available

    deleteElement(passengers, numOfBooked, numOfBooked-1);

}
void Flight::operator-=(int n)
{

    for(int i = numOfBooked - 1; i >= numOfBooked - n; i--)
    {

        deleteElement(passengers,numOfBooked,i);
        int seat = stoi(seatNum[passengersName[i]]); //convert the seat number into int
        seatingPlan[seat/10][seat%10] = false; //get 1st num as the row 2nd num as the column and make his seat available
        seatNum.erase(passengersName[i]); //deleting passenger's seat number and name from the map
        passengersName[i] = ""; //reinitialise the deleted passenger name to empty string

    }

}