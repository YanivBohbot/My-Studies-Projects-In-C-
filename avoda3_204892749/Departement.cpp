/*Full Name:Yaniv Bohbot
ID :204892749
Campus :Ashdod
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Departement.h"
#include "Student.h"
#include "Course.h"
#include "College.h"
#include <string>

Departement::Departement()
{	 name_of_departement= "  ";  
	 code_of_departement=0;
     array_of_course_in_departmnt=NULL;
     array_of_student_in_department=NULL;
	 array_of_grade_below=NULL;
	 code_of_departement = 0;
	 size_course_dept = 0;
	 size_of_grade_below = 0;
}


Departement::~Departement()
{

}

// ostream& operator<<(ostream &os, Departement &dep)
//{
//	os << "Department Name:" << dep.name_of_departement << endl << "code of Departement:" << dep.code_of_departement << endl;
//	for (int i = 0; i < dep.size_course_dept; i++)//print name of courses provided by The department
//		os << "The Department's courses:" << dep.get_array_of_course_in_departmnt()[i]->get_name_of_course() << endl;
//	for (int i = 0; i < dep.size_of_student_in_dept; i++)//print list of students at the department
//		os << "The Department's students:" << dep.get_array_of_student_in_department()[i]->get_student_name() << " " << dep.get_array_of_student_in_department()[i]->get_student_id() << endl;
//	return os;
//};

//ostream & operator<<(ostream & os, Departement & dep) //Output of information department - print department code and name, name of courses provided by The department, the list of students at the department and the list of students with academic status improperly (if already calculated).
//{
//	os << "name Department: " << dep.name_of_departement << "code Department: " << dep.code_of_departement << endl; //print department code and name
//	for (int i = 0; i < dep.amount_courseDepartment; i++)//print name of courses provided by The department
//	{
//		os << "The Department's courses:" << dep.getlistCourse()[i]->getNameC() << endl;
//	}
//	for (int i = 0; i < dep.amount_listStudent; i++)//print list of students at the department
//	{
//		os << "The Department's students:" << dep.getlistStudent()[i]->getstudentName() << " " << d.getlistStudent()[i]->getstudentId() << endl;
//	}
//	/*for (int i = 0; i < d.amount_courseDepartment; i++)
//	{
//	os << "list" << d.getlistCourse()[i]->getNameC() << " " << d.getlistCourse()[i]->getCodeC() << endl;
//	}*/
//
//	return os;
//}

void  Departement ::operator+=(Course &c) // operator adding course to departeemtn
{
	Course** pointeur_course= NULL;
	pointeur_course = new Course*[size_course_dept];
	for (int i = 0; i <size_course_dept; i++)
	{
		pointeur_course[i] = new Course;//Memory allocation
		pointeur_course[i] = array_of_course_in_departmnt[i];
	}

	array_of_course_in_departmnt = new Course*[size_course_dept];//assign the new memory to the object
	for (int i = 0; i <= size_course_dept; i++)
	{
		array_of_course_in_departmnt[i] = new Course;
		if (i == size_course_dept)//set last cell
		{
			array_of_course_in_departmnt[i]->set_name_course(c.get_name_of_course());//set name
			array_of_course_in_departmnt[i]->set_code_course(c.get_numb_of_course());//set number Course
		}
		else//set all cell
		{
			array_of_course_in_departmnt[i] = pointeur_course[i];
		}
	}
	size_course_dept += 1;
		

	//	array_of_course_in_departmnt = new Course*; // the first cell is type course 
	//	array_of_course_in_departmnt[0] = new Course;
	//	array_of_course_in_departmnt[0]->set_code_course(c.get_numb_of_course()); // we do the setting of the code of the course 
	//	array_of_course_in_departmnt[0]->set_name_course(c.get_name_of_course());// we do the setting of the name of the course 
	//	size_course_dept += 1; // increment the size of coure 
	//	
	//}
	//else{
	//	              
	//	for (int i = 0; i < size_course_dept; i++) // loop until the arrive to the size of course in the departement 
	//   	{ 
	//			pointeur_course = new Course*[size_course_dept]; // create a temporary dynamic array 
	//			for (int i = 0; i < size_course_dept; i++) // loop until we arrive to the size of array in the ddepartement  
	//			{
	//				pointeur_course[i] = new Course; // now the temporary array is set with the element of the course departement 
	//				pointeur_course[i] = array_of_course_in_departmnt[i];
	//			}

	//	//	;// incrementing the size of course 

	//			array_of_course_in_departmnt = new Course*[size_course_dept+1]; // we reacreate the array dynamic 

	//			for (int i = 0; i <= size_course_dept; i++)
	//			{
	//				array_of_course_in_departmnt[i] = new Course;
	//				if (i == size_course_dept)
	//				{
	//					array_of_course_in_departmnt[i]->set_name_course(c.get_name_of_course());
	//					array_of_course_in_departmnt[i]->set_code_course(c.get_numb_of_course());
	//				}
	//				else{

	//					array_of_course_in_departmnt[i] = pointeur_course[i];
	//				}
	//			}
	//			size_course_dept += 1;
	//			
	//			for (int i = 0; i < size_course_dept; i++) // we delete each cell of the array of course 
	//			{
	//				delete[]pointeur_course[i];// // we delete the array
	//			}
	//			delete[]pointeur_course; 

	//			for (int i = 0; i < size_course_dept; i++)
	//			{
	//				
	//				cout << array_of_course_in_departmnt[i]->get_name_of_course() << endl;
	//				cout << array_of_course_in_departmnt[i]->get_numb_of_course() << endl;
	//			}	
	//			
	//		
	//		}
	//			
	//	}
	
}

void  Departement ::operator+=(Student &stu)
{
	Student** pointeur_student = NULL;


	if (size_of_student_in_dept == 0) //if the amount of course is zero we create an array with one cell 
	{
		array_of_student_in_department = new Student*; // the first cell is type course 
		array_of_student_in_department[0] = new Student;
		array_of_student_in_department[0]->set_student_name(stu.get_student_name());// we do the setting of the name of the course  
		array_of_student_in_department[0]->set_student_id(stu.get_student_id());// we do the setting of the code of the course 
		array_of_student_in_department[0]->set_student_gender(stu.get_student_gender());	
	    array_of_student_in_department[0]->set_student_age(stu.get_student_age());
		size_course_dept += 1; // increment the size of coure 

	}
	else{

		for (int i = 0; i < size_of_student_in_dept; i++) // loop until the arrive to the size of course in the departement 
		{
			pointeur_student = new Student*[size_of_student_in_dept]; // create a temporary dynamic array 
			for (int i = 0; i < size_of_student_in_dept; i++) // loop until we arrive to the size of array in the ddepartement  
			{
				pointeur_student[i] = new  Student; // now the temporary array is set with the element of the course departement 
				pointeur_student[i] = array_of_student_in_department[i];
			}

			for (int i = 0; i < size_of_student_in_dept; i++) // we delete each cell of the array of course 
			{
				delete[]array_of_student_in_department[i];// 
			}
			delete[]array_of_student_in_department; // we delete the array

			array_of_student_in_department = new Student*[size_of_student_in_dept]; // we reacreate the array dynamic 

			for (int i = 0; i <= size_of_student_in_dept; i++)
			{
				array_of_student_in_department[i] = new Student;
				if (i == size_of_student_in_dept)
				{
					array_of_student_in_department[0]->set_student_name(stu.get_student_name());// we do the setting of the name of the course  
					array_of_student_in_department[0]->set_student_id(stu.get_student_id());// we do the setting of the code of the course 
					array_of_student_in_department[0]->set_student_gender(stu.get_student_gender());
					array_of_student_in_department[0]->set_student_age(stu.get_student_age());

				}
				else{

					array_of_student_in_department[i] = pointeur_student[i];
				}
			}
			size_of_student_in_dept += 1;// incrementing the size of course 

			for (int i = 0; i < size_of_student_in_dept; i++)
			{

				cout << array_of_student_in_department[i]->get_student_name() << endl;
				cout << array_of_student_in_department[i]->get_student_id() << endl;
				cout<< array_of_student_in_department[i]->get_student_age()<<endl;
				cout<< array_of_student_in_department[i]->get_student_gender()<<endl;
			}

		}

	}
}

 ostream& operator<<(ostream &os,  Departement &dep)
{
	os << "Department Name:" << dep.name_of_departement << endl << "code Department:" << dep.code_of_departement << endl;
	for (int i = 0; i < dep.get_AmountCourse(); i++)//print name of courses provided by The department
		os << "The Department's courses:" << dep.get_array_of_course_in_departmnt()[i]->get_name_of_course() << endl;

	for (int i = 0; i < dep.size_of_student_in_dept; i++)//print list of students at the department
		os << "The Department's students:" << dep.get_array_of_student_in_department()[i]->get_student_name() << " " << dep.get_array_of_student_in_department()[i]->get_student_id() << endl;
	return os;
};