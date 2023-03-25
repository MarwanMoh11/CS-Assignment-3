#include <string>
# include <iostream>
#include "Person.h"

class Mechanic: public Person
{
private :
	int counter;
	appointment* arr;
public:
    Mechanic() : Person(0, 0, ""), counter(0), arr(new appointment[100]) {} //default contructors
	void setCounter(int c) {
		counter = c;
	}
	int GetCounter() {
		return counter;

	}

	void setAppointments(appointment app) {
		arr[counter].hours = app.hours;
		arr[counter].mins = app.mins;
	}
	appointment* GetAppointments() {
		return arr;

	}
	
    bool isAvailable(appointment u)
    {
        const int min_duration = 40;  // minimum duration of an appointment

        int earliest_time, latest_time, start_time, end_time;
        if (u.mins < 20)
        {
            earliest_time = u.hours - 1;
            start_time = 60 - (20 - u.mins);
            latest_time = u.hours;
            end_time = u.mins + min_duration;
        }
        else if (u.mins >= 40)
        {
            earliest_time = u.hours;
            start_time = u.mins - 20;
            latest_time = u.hours + 1;
            end_time = u.mins + 20;
        }
        else 
        {
            earliest_time = u.hours;
            latest_time = u.hours;
            start_time = u.mins - 20;
            end_time = u.mins + min_duration;
        }

        for (int i = 0; i < counter; i++)
        {
            int current_time = arr[i].hours * 60 + arr[i].mins; // this is for converting to minutes

            if (current_time >= earliest_time * 60 && current_time < latest_time * 60)
            {
                int diff = abs(current_time - (u.hours * 60 + start_time));  

                if (diff < min_duration)
                {
                    return false;
                }
            }
        }

        return true;
    }


	
};

