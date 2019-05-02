/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#include "Teacher.h"


Teacher::Teacher()
{
	int  number_of_courses_learn = 0;
	names_of_courses_learn_teacher = NULL;
	/*number_of_courses_learn = 0;*/

}


Teacher::~Teacher()
{
}

void Teacher::Print_details_Person()
{
	
	cout << "Teacher:" << endl;
	Person::Print_details_Person(); // function for print details's Person 
	//cout << "Study in LAYER:" << name_of_chihva << endl << "In CLass:" << number_class << endl;

	cout << "The Salary:" << return_salary_worker()<< endl;
	
	cout << "The Courses Name:";
	Teacher::print_all_courses_of_teacher();
	
}

Teacher::Teacher(string firstName, string lastname, int id, int size, int seniority) : Worker(firstName, lastname, id, seniority)// Ctor
{
	string name_of_Course;

	names_of_courses_learn_teacher = new string[size];

	number_of_courses_learn = size;
	cout <<endl<<"Enter your courses names:"<<endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Course" << i + 1<<":"; //input student grades
		cin >> name_of_Course;
		names_of_courses_learn_teacher[i] = name_of_Course;
	}
}


void Teacher::print_all_courses_of_teacher()
{
	
	for (int i = 0; i <number_of_courses_learn; i++)
	{
		cout<<names_of_courses_learn_teacher[i] <<"/";
	}
	cout << endl;
}

double Teacher::return_salary_worker()
{
	int x, y;
	double salary_teacher;
	x = number_of_courses_learn;
	y = get_seniority_worker();
	salary_teacher = Basis*(1 + x / 10) + 300 * y;

	return salary_teacher;
}

bool Teacher::Verification_mitstayenne()
{
	int numb_course;
	numb_course = get_number_of_courses_learn();
	if (numb_course > 5)
	{
		cout << "Secretary is Mistayennete" << endl;
		return true;
	}
	else{
		cout << "Secretary is NOOOT  Mistayennete" << endl;
		return false;
	}
}




