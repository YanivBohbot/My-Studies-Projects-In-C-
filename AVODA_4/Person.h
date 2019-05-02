
/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#pragma once
#ifndef Person_H
#define Person_H
#include <iostream>
#include <string>
using namespace std;
class Person
{
private: string name;
		 string family_name;
		 int number_id;

public:

	Person();
	Person(string,string,int);

	string get_name_person(){return name; };

	string get_family_person(){ return family_name; };
	
	int get_number_id_person(){ return number_id; };
	
	virtual void Print_details_Person(){ cout <<"Name:"<<name<<endl<<"Family Name:"<<family_name<<endl<<"Number id:"<<number_id<<endl; };
	virtual bool Verification_mitstayenne()=0;
	virtual ~Person();
};
#endif

