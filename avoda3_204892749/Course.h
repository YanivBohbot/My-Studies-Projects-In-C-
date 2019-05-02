
/*Full Name:Yaniv Bohbot
ID :204892749
Campus :Ashdod
*/#pragma once
#include "Student.h"
#include "Departement.h"
#ifndef Course_H
#define Course_H
#include <iostream>
#include <string>
using namespace std;
#define SIZE_NAME 30

class Student;
class Departement;
class Course
{
	string name_of_course;
	int num_of_course;
	Student** array_of_student=NULL;
	int amount_student;
	int* array_of_grades=NULL;
	Departement* departement=NULL;

public:
	Course();
	~Course();

	/*void set_course(char n[SIZE_NAME], int code_course, char gen, int âge, int);
	int get_code_course(){ return numb_of_course; };
	int get_name_course(){ return name_of_course; };
	Student** get_student(){ return array_of_student; };
	int * get_student_badgrade(){ return array_of_grades; };*/
	//bool operator==(const  int &num_of_course){ return(this->num_of_course == num_of_course); }
	bool operator==(Departement &dep);
	//void student_operator_print(Student &s);
	//void student_opertor_insert();
	//void student_operator_assama(Student &s);
	//int return_amount_course(int amount);
	//void operator_add_course_to_student();
	void set_code_course(int c){ num_of_course = c ; };// set code course 
	void set_name_course(string name){ name_of_course = name; };// set name course 
	string get_name_of_course(){ return name_of_course; }// get name of course 
	int  get_numb_of_course(){ return num_of_course; }// get numb of course 
	friend istream& operator>>(istream &is, Course &course){is >> course.name_of_course >> course.num_of_course ; return is;};// operator cin for course 
	friend ostream & operator<<(ostream & os, Course& c);//output all the information of the course 
	float return_grade_average();//calculating the average 
	void set_array_of_grade(int index, int grade){ array_of_grades[index] = grade; };//set the array of graede
	int get_array_of_grade(int index2){ return array_of_grades[index2]; }//get the grade of one student
	int get_amount_student(){ return amount_student; };// get the amount of student in course 
	//void set_Depertment(Departement* d){ dep = d; };
	void setpointer_Depatment(Departement* d){ departement = d; };
	void operator+=(Student &stu);// operator for adding studenn to course 
	Student** get_array_of_student(){ return array_of_student; };// get all the array of student in the course 
	int get_array_of_grades(int index2){ return array_of_grades[index2]; };// get all the aarya of grade in de course 
	void set_array_of_grades(int index, int grade){ array_of_grades[index] = grade; }// set the list of the grade 
	//int get_amount_of_course(){return }
	int operator-=(Student& student/*, Departement &dept*/);
};
#endif

