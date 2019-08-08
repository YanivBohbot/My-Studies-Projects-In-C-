/*assignement 5
Name: yaniv bohbot
ID:204892749
CAmpus:Ashdod */
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef Employee_h
#define Employee_h
#include"string.h"
#define MAX_TAV 21
#include <iostream>
using namespace std;
class Employee
{
private:
	char name[MAX_TAV];//fullName
	char name_BOSS[MAX_TAV];//Empolyee fullName
	float salary;//salary
	int seniority;//seniority
	static int totalEmployee;//Static variable
public:
	Employee();// deflt ctor: fullName_({ '0' }), EmployerName_({ '0' }), salary_(0.0), seniority_(0){};//Defult ctor
	Employee(char name[], char name_boss[], int seniority, float salary);//ctor with parameters
	~Employee();//Dtor
	void print(){ cout << name << endl << name_BOSS << endl << seniority << endl << salary << endl; };//print to screen employee details 
	int getTotalLength(){ return totalEmployee; }//Static variable total objec Employee
	float getMax(){ return salary; }//return salary
	string getfullName(){ return name; }//return full Name
	string getEmployerName(){ return name_BOSS; }//return Employer Name
	int getSeniority(){ return seniority; }//return seniority
};
#endif;