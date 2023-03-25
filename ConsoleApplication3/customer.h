#include <string>
# include <iostream>
#include "Person.h"
class customer: public Person
{
private:
	int MechanicID;
	appointment x;

public:
	customer(int age = 0, int ID = 0, string name = "", int MID = 0, appointment app = { 0, 0 }) : Person(age, ID, name), MechanicID(MID), x(app) { // defualt constructors
		MechanicID = ID;
		x.hours = app.hours;
		x.mins = app.mins;
	};
	

	void setMechanicID(int MID) {
		MechanicID = MID;
	};
	int GetMechanicID() {
		return MechanicID;
	};

	void setAppointment(appointment app) {
		x.hours = app.hours;
		x.mins = app.mins;
	};
	appointment GetAppointment() {
		return x;
	};
	bool operator < (customer& c2) {
		if (c2.x.hours < x.hours)
		{
			return false;
		}
		if (c2.x.hours == x.hours)
			if (c2.x.mins < x.mins)
				return false;
		return true;

	};
	bool operator >(customer& c2)
	{
		if (c2.x.hours > x.hours)
		{
			return false;
		}
		if (c2.x.hours == x.hours)
			if (c2.x.mins > x.mins)
				return false;
		return true;
	};
	bool operator ==(customer& c2)
	{
		if (c2.x.hours == x.hours)
			if (c2.x.mins == x.mins)
				return true;
		return false;
	};

};

