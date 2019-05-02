/*Full Name:Yaniv Bohbot
ID :204892749
Campus :Ashdod
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef Student_H
#define Student_H
#include <iostream>
#include <string>
#include "Course.h"
#include "Departement.h"
using namespace std;

#define SIZE_NAME 30 
class Course;
class Departement;
class Student
{
private:
	string name_student;
	int student_id;
	char gender;
	int age;
	int amount_of_course;
	Course** array_of_course;
	Departement* array_of_department;


public:
	Student();
	~Student();
	void set_student_departemnt(Departement *d){ array_of_department = d; };
	void set_student_id(int id){ student_id = id; };//set id student 
	void set_student_name(string name){ name_student = name; };//set name student 
//	void set_student(string n, int numb_id, char gen, int âge, int);
	void set_student_age(int age){ this->age = age; };
	int get_student_age(){ return age; };//get age student 
	void set_student_gender(int sex){ gender = sex; };
	int get_student_gender(){ return gender; };
	int get_student_id(){ return student_id; };// get id student 
	int get_amount_of_course(){ return amount_of_course; };
	char get_gender_student(){ return gender; };// get the gender student
	string get_student_name(){ return name_student; };// get name student 
	Student & operator=(const Student &s);// operator assama
	//bool operator==(const int &student_id){ return(this->student_id == student_id); };//operator equal 
	bool operator==(Departement& dept);
	bool operator>(const Student &stud)const;// operator bigger
	friend ostream& operator<<(ostream &os, Student &stud);// operator cout print the elemetn
	/*{
		os << "Name:" << stud.name_student << endl << "id:" << stud.student_id << endl << "gender:" << stud.gender << endl << "age:" << stud.age << endl;
		for (int i = 0; i < stud.get_amount_of_course(); i++)
		{
			os << "Courses:" << stud.array_of_course[i]->get_name_of_course() << " " << endl << "NUmber of course :" << stud.array_of_course[i]->get_numb_of_course() << endl;
		}
		return os;*/
	
	friend istream& operator>>(istream &is, Student &stud) // operator cin enter value 
	{is >> stud.name_student>> stud.student_id >> stud.gender >> stud.age ; return is;};
	void student_operator_assama(Student &s);
	int return_amount_course(int amount){ amount_of_course = amount; return amount; };
	void operator+=(Course& cours);// operator adding student 
	Course**get_array_of_course(){ return  array_of_course; };
	 Course* operator[](int index);
	 bool operator-=(Course& c);
	void print_course();

};
#endif

