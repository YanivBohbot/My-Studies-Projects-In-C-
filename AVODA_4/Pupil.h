
/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#pragma once
#ifndef Pupil_H
#define Pupil_H
#include <iostream>
#include "Person.h"
using namespace std;

class Pupil :public Person
{

private: int *array_of_grades;   // array of grades for all the courses the pupil is learning
		 int amount_of_grades;   //amount of grades's pupil
		 char name_of_chihva;   //the layer is start from 'a'-'f'
		 int number_class;  //the number is  the class 1-3

public:
	Pupil();
	
	float return_average_grades();  // function return the average of grades's pupil
	bool Verification_mitstayenne();  // function check if the pupil is excellent
	int amount_grades_pupil(char);   // function set the grade
	int get_amount_grades_pupil(){ return amount_of_grades; };  //function return the number of courses's student
	
	char get_name_of_chihva(){ return name_of_chihva; };   // function to get name's layer
	void set_numb_class(int numb){ number_class = numb; };  //function for set the number of the class

	void Print_details_Person();  // funciton for print the specific details's pupil
	~Pupil();
	int *get_array_grades(){return array_of_grades;};   
	void set_amountgrades(int amount){ amount_of_grades = amount; };  // function for set the grade 
   int get_grades();  // funciton for get grades 
 
   Pupil(string firstName, string lastname, int id, char Level, int ClassNumber);
};
#endif

