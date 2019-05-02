
/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#pragma once
#ifndef Teacher_H
#define Teacher_H
#include <iostream>
#include <string.h>
#include "Worker.h"
using namespace std;
class Teacher :public Worker
{ private:
	string* names_of_courses_learn_teacher;
	int number_of_courses_learn;
public:
	Teacher();
	~Teacher();
//	void set_number_of_courses_learn(int amount_cours){  number_of_courses_learn = amount_cours; };
	int get_number_of_courses_learn(){ return number_of_courses_learn; };
	double return_salary_worker();
	bool Verification_mitstayenne();
	void print_all_courses_of_teacher();
	Teacher(string firstName, string lastname, int id, int size, int seniority);
	void Print_details_Person();
	//Secretary(string firstName, string lastname, int id, int num, int Quantity_Of_Children);
	//void constructor_array_of_name_of_course_learn_teach();


};
#endif

