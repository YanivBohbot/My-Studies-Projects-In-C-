/*Full Name:Yaniv Bohbot
ID :204892749
Campus :Ashdod
*/
#pragma once
#ifndef College_H
#define College_H
#include "Student.h"
#include "Departement.h"
#include <iostream>
#include <string>
using namespace std;
#define SIZE_NAME 30

class Departement;
class Student;
class College
{
	Departement** array_of_departement_in_college;
	Student** array_of_total_student_college;
	int amount_departement;
	int amount_of_total_student;

public:
	College();
	~College();
	void menu();
	void  add_department_to_college(Departement& dept);
	void add_student_to_departemnt(Departement& dept, Student& student);
	void register_student_to_course();
	void Add_course_to_department(Departement& dept, Course& c);
	void Register_student_to_course(Departement& dept, Student& student, Course &course);
	void Grading_student_in_course(Departement& dept, Course &course);
	//void grading_student_to_course();
	//void print_course_information();
	void print_student_information(Student &student);
	//void print_departemnt_information();
	//void set_id_department(int);
	//void name_departement(string);
	//void find_student_with_ba_academic_staus();
	//void remove_student_from_course();
	bool verify_code_departement(const int code);
	bool exit(Departement dept, Student student, Course course);
	bool verify_code_student(const int code);
	void print_department_information(Departement &dept, Student &student);
	void print_student_information(Departement &dept, Student &student);
	void print_course_information(Departement &dept, Course& c);
	void Remove_student_from_course(Departement& dept, Student& student, Course& course);
	void find_students_with_bad_academic_status(Departement &dept,Student& student,Course& course);
	 int exit(int finish);
};
#endif

