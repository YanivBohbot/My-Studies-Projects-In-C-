/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#pragma once
#ifndef Worker_H
#define Worker_H
#include <iostream>
#include "Person.h"
using namespace std;
#define Basis 5000

class Worker :public Person
{
private: int seniority;
		 int salary;
		
public:
	Worker();
	double return_salary_worker();
	int get_seniority_worker(){ return seniority; };
	void Print_details_Person();
	Worker(string firstName, string lastname, int id, int num);

	//void set_seniority_worker(int Seniority){ seniority = Seniority; 
	~Worker();
};
#endif

