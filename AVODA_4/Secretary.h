
/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#pragma once
#ifndef Secretary_H
#define Secretary_H
#include <iostream>
#include "Worker.h"
using namespace std;

class Secretary :public Worker
{
private: int  amount_of_pupil_secretary;

public:
	Secretary();
	double return_salary_worker();
	bool Verification_mitstayenne();
	void set_amount_of_pupil_secretary(int amount){ amount_of_pupil_secretary = amount; };
	int get_amount_of_pupil_secretary(){ return amount_of_pupil_secretary; };
	void Print_details_Person();
	Secretary(string firstName, string lastname, int id, int num, int Quantity_Of_Children);
	~Secretary();
};
#endif

