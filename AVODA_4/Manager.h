/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#pragma once
#ifndef Manager_H
#define Manager_H
#include <iostream>
#include "Worker.h"
using namespace std;

class Manager :public Worker
{
public:
	Manager();
	~Manager();
	double return_salary_worker();  //  function return salary 's manager
	bool Verification_mitstayenne();   //function to verify if the manager is exclent
	void  Print_details_Person();  // function for print the details manager
	Manager(string firstName, string lastname, int id, int seniority);
};
#endif

