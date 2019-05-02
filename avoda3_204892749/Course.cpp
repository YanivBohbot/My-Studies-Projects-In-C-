/*Full Name:Yaniv Bohbot
ID :204892749
Campus :Ashdod
*/
#define _CRT_SECURE_NO_WARNINGS
#include "College.h"
#include "Departement.h"
#include "Student.h"
#include "Course.h"
#include <string>


Course::Course()
{
	 name_of_course="  "; 
	 num_of_course = 0;
	 array_of_student=NULL;
	 amount_student=0;
	 array_of_grades=NULL;
	 departement=NULL;

}


Course::~Course()
{

}

////bool Course :: student_operator_equal(Course &c)
////{
////	if ( numb_of_course== c.)
////		
////		return true;
////	else
////		return false;
////}
//void Course::set_course(string name, int numb_course)
//{ 
//    name_of_course=name;
//	num_of_course = numb_course;
//}

float Course:: return_grade_average()
{    
	int add = 0;
	float average = 0;
	for (int i = 0; i <amount_student; i++)
	{
		add +=array_of_grades[i] ;
	}
	average=float(add / amount_student);

	return average;
}



void Course::operator+=(Student& s)//operator adding student to course to the array 
{
	Student** pointeur_student = NULL;//temp student list course
	int *pointeur_Grade = NULL;//temp student grade in the course
	pointeur_Grade = new int[amount_student];//Update size of list grade according to the number of students
	pointeur_student = new Student*[amount_student];// allocate new memory and copy the elements
	for (int i = 0; i < amount_student; i++)
	{
		pointeur_student[i] = new Student;
		pointeur_student[i] = array_of_student[i];//copy listCourses to temp array
		pointeur_Grade[i] = array_of_grades[i];//copy listGrade to temp array
	}
	array_of_student = new Student*[amount_student];//assign new memory to the object listCourses
	array_of_grades = new int[amount_student];//assign new memory to the object listGrade
	for (int i = 0; i <= amount_student; i++)
	{
		array_of_student[i] = new Student;
		if (i == amount_student)//set last cell
		{
			array_of_student[i]->set_student_name(departement->get_array_of_student_in_department()[i]->get_student_name());

			
			pointeur_Grade[i] = -1;//set student grade to -1
		}
		else//set all cell
		{
			array_of_student[i] = pointeur_student[i];//Update the original list course 
			array_of_grades[i] = pointeur_Grade[i];//Update the original list grade 
		}
	}
	amount_student += 1;//Increases the size of department
	for (int i = 0; i < amount_student; i++)
	{
		cout << array_of_student[i]->get_student_name();
	}
}



bool Course::operator==(Departement &dep) //operator for check if its already exist in the departement 
{
	for (int i = 0; i <dep.get_AmountCourse(); i++)
	{
		if (int(dep.get_array_of_course_in_departmnt()[i]->num_of_course) == num_of_course) //we check all the number of the departement that we have until we got it 
		{
			
			return false;
		}
	}
	return true;
}


ostream & operator<<(ostream & os, Course& course)//operator for print the course 
{
	os << "Name of course: " << course.name_of_course << " " << "Code of Course: " << course.num_of_course << endl;
	for (int i = 0; i < course.amount_student; i++)//print detail of Students registered for the course
	{
		os << "Students registered for the course: " << course.get_array_of_student()[i]->get_student_name() << "" << "Student id:" << course.get_array_of_student()[i]->get_student_id() << endl;
		if (course.get_array_of_grades(i) != -1)//if given grade to student then print the grade
			os << "grade:" << course.get_array_of_grades(i) << endl;
	}
	return os;
}



int Course::operator-=(Student& student)///delete Student from course
{
	Student** pointeur_temp_student = NULL;//temp student list course

	int *pointeur_temp_grade = NULL, check = 0;//temp student grade in the course

	pointeur_temp_grade = new int[amount_student];//Update size of list grade according to the number of students
	pointeur_temp_student = new Student*[amount_student];// allocate new memory and copy the elements
	cout << "The original list of  Student:" << " ";
	for (int i = 0; i < amount_student; i++)
	{
		cout << array_of_student[i]->get_student_name() << " " << array_of_student[i]->get_student_id() << " ";
	}
	cout << endl;
	for (int i = 0; i < amount_student; i++)
	{
		pointeur_temp_student[i] = new Student;
		if (student.get_student_id() != departement->get_array_of_student_in_department()[i]->get_student_id())//Copying except the student that want to delete
		{
			pointeur_temp_student[i] = array_of_student[i];//copy listCourses to temp array
			pointeur_temp_grade[i] = array_of_grades[i];//copy listGrade to temp array
		}
	}
	amount_student -= 1;//decrease the size of department
	array_of_student = new Student*[amount_student];//assign new memory to the object listCourses
	array_of_grades = new int[amount_student];//assign new memory to the object listGrade
	for (int i = 0; i < amount_student; i++)
	{
		array_of_student[i] = new Student;
		array_of_student[i] = pointeur_temp_student[i];//Update the original list course 
		array_of_grades[i] = pointeur_temp_grade[i];//Update the original list grade 
		check = 1;
	}
	cout << "The new list of  Student:" << " ";
	for (int i = 0; i <= amount_student; i++)
	{
		if (amount_student == 0)
			cout << "No student exist" << endl;
		else
			cout << array_of_student[i]->get_student_name() << " " << array_of_student[i]->get_student_id() << " ";
	}
	cout << endl;
	if ((check == 0 && amount_student == 0) || check == 1)
		return true;
	else
		return false;
}