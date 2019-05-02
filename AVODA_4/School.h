
/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#pragma once
#ifndef School_H
#define School_H
#include <iostream>
#include "Layer.h"
#include "Person.h"
#include "Worker.h"
#include "Manager.h"
#include "Secretary.h"
class Layer;
class Person;

using namespace std;

class School
{

private: Layer** array_of_layers_in_school;
		 int amount_of_layers; // 6 layers at school  'a'-'f'
		 Person** array_of_all_the_person_in_school;
		 int amount_of_all_the_person_in_school;
		 bool check_if_exist_manager;

public:
	School();
	void Menu();
	~School();
	//void add_pupil_in_class(Pupil &c);
	void ADD_PUPIL();
	bool exist_code(char code);
	bool exist_code_class(int code);
	void ADD_TUTOR();
	void add_teacher_in_school();
	void PRint_workers_and_pupils_details();
	void ADD_Manager();	
	void ADD_SEcretary();	
	void Print_worker_details_with_biggest_salray();
	void Print_oustanding_people();
	bool Check_number_id(int id);
    void Print_tutor_class();
};
#endif

