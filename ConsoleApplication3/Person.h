#pragma once
#include <string>
# include <iostream>
using namespace std;

class Person
{
private:
	string name;
	int ID;
	int Age;
public:
	Person(int age, int ID, string name) { //constructors
		this->Age = age;
		this->ID = ID;
		this->name = name;
	}
	void SetName(string name){
		this->name = name;
	}
	string GetName(){
		return name;
	}

	void SetAge(int age) {
		this->Age = age;
	}
	int GetAge() {
		return Age;
	}

	void SetID(int ID) {
		this->ID = ID;
	}
	int GetID() {
		return ID;

	}

	void printinfo() {
		cout << "Name: " << name << endl;
		cout << "Age: " << Age << endl;
		cout << "ID: " << ID << endl;

	}
	struct appointment
	{
		int hours;
		int mins;
	};

};

