
/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#pragma once
#ifndef Tutor_H
#define Tutor_H
#include <iostream>
#include "Teacher.h"
#include "Class.h"
class Class;
using namespace std;

class Tutor :public Teacher
{
private: 
	Class* Pointer_of_tutor_for_class;

public:
	Tutor();
	double return_salary_worker();
	bool Verification_mitstayenne();
	//Pupil print_all_details_pupil_in_classe_tutor();
	void Print_details_Person();
	Tutor(string firstName, string lastname, int id, int size, int seniority, char layer, int classNumber);
	~Tutor();
};
#endif

