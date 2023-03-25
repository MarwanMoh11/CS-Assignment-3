#include <iostream>
#include <string>
#include "Customer.h"
#include "Person.h"
#include "Mechanic.h"
#include "Queue.h"


using namespace std;

int main()
{
    int size;
    int age, id;
    string name;

    cout << "Enter Number of available Mechanics: ";
    cin >> size;

    Mechanic* mechanics = new Mechanic[size];  //creates an array of mechanics

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Mechanic's Name: ";
        cin >> name;
        cout << "Enter Mechanic's ID: ";
        cin >> id;
        cout << "Enter Mechanic's Age: ";
        cin >> age;

        mechanics[i].SetName(name);
        mechanics[i].SetID(id);
        mechanics[i].SetAge(age);
    } //user input for mechanic data

    int customerNo;
    Person:: appointment y;

    cout << "Enter Number of Customers: ";
    cin >> customerNo;

    customer* customers = new customer[customerNo]; //creates array of customers

    for (int i = 0; i < customerNo; i++)
    {
        cout << "Enter Customer's Name: ";
        cin >> name;
        cout << "Enter Customer's ID: ";
        cin >> id;
        cout << "Enter Customer's Age: ";
        cin >> age;
        cout << "Enter the hour of appointment: ";
        cin >> y.hours;
        cout << "Enter the minutes of appointment: ";
        cin >> y.mins;

        customers[i].SetName(name);
        customers[i].SetAge(age);
        customers[i].SetID(id);
        customers[i].setAppointment(y);
    } //user input for customer data
    int size2 = size;
    for (int i = 0; i < customerNo; i++)
    {
        bool temp = false;
        while (size2 > 0)
        {
            if (mechanics[size - size2].isAvailable(customers[i].GetAppointment())) //checks availibility 
            {
                mechanics[size - size2].setAppointments(customers[i].GetAppointment());
                customers[i].setMechanicID(mechanics[size - size2].GetID());
                size2--;
                temp = true;  break;
            }
            size2--;
        }
        if (size2 == 0)
            size2 = size;
        if (!temp)
        {
            cout << "Appointment Cancelled: No Mechanic is Available at that time" << endl;
            Person:: appointment q; q.hours = -1; q.mins = -1;
            customers[i].setAppointment(q);
        }

    }
    for (int i = 0; i < customerNo; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (customers[i].GetMechanicID() == mechanics[j].GetID()) //Validation to check IDS are matching
            {

                cout << customers[i].GetName() << " should be appointed to "
                    << mechanics[j].GetName() << " at "
                    << customers[i].GetAppointment().hours << ":";
                if (customers[i].GetAppointment().mins < 10)
                    cout << "0" << customers[i].GetAppointment().mins << endl;
                else
                    cout << customers[i].GetAppointment().mins << endl;
                break;
            } //prints info about customer's appointment
        }
    }


    customer temp;

    for (int i = 0; i < customerNo - 1; i++)
    {
        for (int j = i + 1; j < customerNo; j++)
        {
            if (customers[i] > customers[j]) //sorts customers in ascending order of appointments
            {

                temp = customers[i];
                customers[i] = customers[j];
                customers[j] = temp;
            }
        }
    }

    Queue<customer> queue(customerNo); //defines a template Queue of type Customer

    for (int i = 0; i < customerNo; i++)
    {
        queue.Enqueue(customers[i]); //inserts customers in queue in ascending order
    }
    cout << "----------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < customerNo; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (customers[i].GetMechanicID() == mechanics[j].GetID()) //checks that the mechanic's IDs are matching 
            {

                cout << customers[i].GetName() << " has an appointment "
                    << "at "
                    << customers[i].GetAppointment().hours << ":";
                if (customers[i].GetAppointment().mins < 10)
                    cout << "0" << customers[i].GetAppointment().mins;
                else
                    cout << customers[i].GetAppointment().mins;
                cout << " with " << mechanics[j].GetName() << endl;
                break;
            }
        }
    } 
    return 0;
}