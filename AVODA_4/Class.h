
/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/#pragma once

#ifndef Class_H
#define Class_H

#include <iostream>
#include "Pupil.h"
#include "Tutor.h"

using namespace std;
class Tutor;
class Class
{
private: char name_layer_for_class;   // name of chihva 'a'-'f'
		 int number_of_class;  //number of class '1'-'3'
		 Pupil** array_pupils_learning_class;  // array of pupils in class 
		 int amount_pupils_class;   //the nuber of pupi lin class 
    	Tutor* tutor_for_class;   //pointer to the tutor of the class

public:
	Class();  // constructor 
    void add_pupils_to_array_learning_class(Pupil* p);  //funciton to add an pupil to the array of class
	Pupil* find_pupils_in_array_learning_class_in_index(int index){ return array_pupils_learning_class[index]; }; // funciton for find a pupil in the class 
	~Class();
	void settingCLass(char, int);
	void  set_name_layer_for_class(char name){ name_layer_for_class = name; };
	char get_name_layer_for_class(){ return name_layer_for_class; };
	void set_number_of_the_class(int numb){ number_of_class = numb; };
	int get_number_of_the_class(){ return number_of_class; };
	void Add_tutor_toclass(Tutor &tu);
	int get_amount_pupil_in_class(){ return amount_pupils_class; };
	
};
#endif

