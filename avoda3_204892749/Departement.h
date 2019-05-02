/*Full Name:Yaniv Bohbot
ID :204892749
Campus :Ashdod
*/
#pragma once
#ifndef Departement_H
#define Departement_H
#include <iostream>
#include <string>
using namespace std;
#include "Student.h"
#include "Course.h"
#define SIZE_NAME 30

class Student;
class Course;
class Departement
{
private:
	string name_of_departement;
	int code_of_departement;
	Course** array_of_course_in_departmnt;
	int size_course_dept;
	Student** array_of_student_in_department;
	int size_of_student_in_dept;
	Student** array_of_grade_below;
	int size_of_grade_below;
public:

	 Departement();
	~Departement();
	void set_id_department(int numb){ code_of_departement = numb; };
	void set_name_departement(string name){name_of_departement = name; };
	string get_name_departement(){ return name_of_departement; };
	int get_code_departement(){ return code_of_departement; };
	Student** get_array_of_student_in_department(){ return array_of_student_in_department; }
	void operator+=(Course& s);
	void operator+=(Student& s);
	Course** get_array_of_course_in_departmnt(){ return array_of_course_in_departmnt; };
	Departement&  Departement::operator=(const Departement &s);
	friend ostream& operator<<(ostream &os, const Departement &dep);
	//{os << "Department Name:" << dep.name_of_departement << endl << "code Department:" << dep.code_of_departement << endl;
	//for (int i = 0; i < dep.get_AmountCourse(); i++)//print name of courses provided by The department
	//	os << "The Department's courses:" << dep.get_array_of_course_in_departmnt()[i]->get_name_of_course() << endl;

	//for (int i = 0; i < dep.size_of_student_in_dept; i++)//print list of students at the department
	//	os << "The Department's students:" << dep.get_array_of_student_in_department()[i]->get_student_name() << " " << dep.get_array_of_student_in_department()[i]->get_student_id() << endl;
	// return os;
	//};
	friend istream& operator>>(istream &is, Departement &dep){ is >> dep.name_of_departement >> dep.code_of_departement; return is; };//print name of courses provided by The department
	//Course** get_array_of_course_in_departmnt(){ return array_of_course_in_departmnt; };
	int get_AmountCourse(){ return size_course_dept; };//Get amount of course in Department
	int get_size_of_student_in_dept(){ return size_of_student_in_dept; };
	friend ostream& operator<<(ostream &os,  Departement &dep);
}; 
#endif

