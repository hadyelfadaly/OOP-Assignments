//Hady Hassan Sayed Hassan El Fadaly 20236113
//Ziad Tarek El Marsafawy 20236043

#include <bits/stdc++.h>
#include "Surgeon.h"
#include "Specialist.h"

using namespace std;

int main()
{

    //asking user for number of doctors
    cout<<"Enter Number of Doctors\n";

    int num;

    cin>>num;

    Doctor *doctors[num];//dynamically allocated array of doctors to help better with polymorphism

    for(int i = 0; i < num; i++)
    {

        //asking user wheather the dr is specialist or surgeon
        cout<<"The Doctor is Specialist or Surgeon?\n";

        string answer;

        cin>>answer;

        //take doctor details based on users answer
        if(answer == "surgeon" || answer == "Surgeon")//to deal with different answers
        {

            cout<<"Surgeon's Name: ";

            string name;

            cin>>name;

            cout<<"Surgeon's ID: ";

            string id;

            cin>>id;

            cout<<"Surgeon's Duration (Enter in Minutes): ";

            int durt;

            cin>>durt;

            cout<<"Surgeon's Rate: ";

            int rt;

            cin>>rt;

            cout<<"Surgeon's Number of Surgeries: ";

            int numOfSurg;

            cin>>numOfSurg;

            doctors[i] = new Surgeon(id, name, durt, rt, numOfSurg);

            //for loop to set surgeries details
            for(int j = 0; j < numOfSurg; j++)
            {

                cout<<"Patient's Name: ";

                string n;

                cin>>n;

                cout<<"Date of Surgery: ";

                string date;

                cin>>date;

                surgerySchedule s(n, date);

                doctors[i]->setSurgery(j, s);

            }

        }
        else if(answer == "specialist" || answer == "Specialist")//to deal with different answers
        {

            cout<<"Specialist's Name: ";

            string name;

            cin>>name;

            cout<<"Specialist's ID: ";

            string id;

            cin>>id;

            cout<<"Specialist's Duration (Enter in Minutes): ";

            int durt;

            cin>>durt;

            cout<<"Specialist's Rate: ";

            int rt;

            cin>>rt;

            cout<<"Specialist's speciality: ";

            string spc;

            cin>>spc;

            doctors[i] = new Specialist(id, name, durt, rt, spc);

        }

    }

    fstream File;

    File.open("doctors.txt",ios::out);//opening doctors.txt file in output mode

    for(int i = 0; i < num; i++)
    {

        cout<<doctors[i]->PrettyPrint()<<endl;//print doctors details to console
        File<<doctors[i]->PrettyPrint()<<endl;//print doctors details to file
        doctors[i]->printSurgeries(cout); //print surgeon details to console
        doctors[i]->printSurgeries(File); //print surgeon details to file

    }

    File.close();

    return 0;

}
