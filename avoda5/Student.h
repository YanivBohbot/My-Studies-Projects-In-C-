/*assignement 5
Name: yaniv bohbot
ID:204892749
CAmpus:Ashdod */
#pragma once
#include "Date.h"
#define _CRT_SECURE_NO_WARNINGS
#ifndef Student_h
#define Student_h
#include"string.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define MAX_TAV 21
#define MAX_TAV_ID 10
using namespace std;

class Student
{
private:
	char name_student[MAX_TAV];
	char number_id[MAX_TAV_ID];
	Date *date;
	float average;
	static int totalStudent;
public:
	Student();//defult ctor
	Student(char a[], char b[], Date& d, float);//parameter ctor
	~Student(){ delete[]date ; }//dtor
	void print(){ cout << name_student << endl << number_id << endl; date->print(); cout << average << endl; }//print to screen student detail 
	float getaverage(){ return average; }//return average
	string getfullName_(){ return name_student; }//return fullName_
	string getid_(){ return number_id; }//return id_
	int getDateOfBirthDay_(){ return date->getday_(); }//return day DateOfBirth
	int getDateOfBirthMonth(){ return date->getmonth_(); }//return month DateOfBirth
	int getDateOfBirthYear(){ return date->getyear_(); }//return Year DateOfBirth
	int getTotalLength(){ return totalStudent; }//get static variable
	float getMax(){ return average; }//return average
};
#endif;
