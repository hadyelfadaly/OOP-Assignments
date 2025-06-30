//Hady Hassan El Fadaly 20236113
//Khaled Mohamed 20235010

#include <bits/stdc++.h>
#include "Flight.h"

using namespace std;

string name;
int ID, choice, row, column;
char answer = 'y';

int main()
{

    Flight f1(60,"cairo",12);//the flight object we gonna test our system on

    cout<<"First 2 Passengers entered the flight\n";

    Passenger p[2] {Passenger("ahmed", 6578), Passenger("khaled",7868)};//our first 2 passengers (passenger objects)

    f1.addPassengers(2, p);//adding passengers to the flight

    //main menu
    cout<<"Welcome to Flight System\n"
          "1. User\n"
          "2. Admin\n";

    cin>>choice;

    switch (choice)
    {

        case 1://1st menu for users

            cout<<"1. Trip details\n"
                  "2. Search for passengers by name\n"
                  "3. Search for available seat number\n";

            cin>>choice;

            switch(choice)
            {

                case 1:

                    f1.display(); //can use cout<<f1;

                break;

                case 2:

                    cout<<"Name: ";

                    cin>>name; //getting name that we will search for

                    if(f1.SearchName(name)) cout<<"Present\n";
                    else cout<<"Not Present\n";

                break;

                case 3:

                    cout<<"Row: ";

                    cin>>row; //getting row

                    cout<<"Column: ";

                    cin>>column; //getting column

                    int counter = 0;

                    if(f1.SearchNum(row, column))
                    {

                        cout<<"Not Available\n";

                        while(f1.SearchNum(row, column))
                        {

                            if(counter > 0) cout<<"Not Available\n";

                            cout<<"Search for another seat? (y/n)\n";

                            cin>>answer; //getting answer whether to continue or not

                            if(answer != 'y') break;
                            else
                            {

                                cout<<"Row: ";

                                cin>>row; //getting row

                                cout<<"Column: ";

                                cin>>column; //getting column

                                counter++;

                            }

                        }

                    }
                    if(!f1.SearchNum(row, column) || answer == 'y')
                    {

                        cout<<"It's Available, Do You Want to book? (y/n)\n";

                        cin>>answer; //getting answer whether to continue or not

                        if(answer == 'y')
                        {

                            Passenger p1;

                            cin>>p1; //inputting passenger information using input stream overload

                            f1.addPassengers(1,&p1); //calling function to add passengers

                            cout<<"Seat Booked.\n";

                        }
                        else cout<<"No Problem, See You Soon\n";

                    }

            }

        break;

        case 2: //2nd menu for admins

            cout<<"1. Add passengers\n"
                  "2. Remove passenger\n"
                  "3. Set departure time\n";

            cin>>choice;

            switch (choice)
            {

                case 1:

                    cout<<"Enter Number Of Passengers: ";

                    int size;

                    cin>>size; //getting number of passengers

                    Passenger *p2;
                    p2 = new Passenger[size]; //initialising dynamic array to carry passenger objects to be added

                    for(int i = 0; i < size; i++) cin>>p2[i]; //getting passengers information

                    f1.addPassengers(size,p2); //calling function to add passengers

                    cout<<"Passengers added successfully\n";

                    delete[] p2;

                break;

                case 2:

                    cout<<"Passenger Name: "; //getting passenger name we want to remove

                    cin>>name;

                    if(f1.SearchName(name))
                    {

                        Passenger p3 = f1.getPassenger(name); //getting passenger intended
                        f1.removePassenger(p3); //removes passenger we can also remove by -- and -=

                        cout<<"Flight Details after removal\n";
                        cout<<f1; //can be by f1.display() instead

                    }
                    else cout<<"Passenger is not present\n";

                break;

                case 3:

                    string time;

                    cout<<"Enter departure time: \n";

                    cin.ignore();//needed for the getline function
                    getline(cin,time); //getting departure time //using get line to get full line (Cairo 14:00 +2:00 GMT)

                    f1.setDeprture(time); //setting departure time

                    cout<<"Flight full details now: \n";

                    f1.display();

                break;

            }

        break;

    }

    return 0;

}