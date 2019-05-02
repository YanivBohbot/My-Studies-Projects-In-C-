
/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#include "Tutor.h"


Tutor::Tutor()
{

}


Tutor::~Tutor()
{
}

Tutor::Tutor(string firstName, string lastname, int id, int size, int seniority, char Layer, int classNumber) :Teacher(firstName, lastname, id, size, seniority)// Ctor
{
	Pointer_of_tutor_for_class = new Class();
}

double Tutor ::return_salary_worker()
{
	int x, y;
	double salary_teacher=0,salary_tutor=0;
	x = get_number_of_courses_learn();
	y = get_seniority_worker();
	
	salary_teacher = Basis*(1 + x / 10.) + 300 * y;
	salary_tutor += salary_teacher + 1000;


	return salary_tutor;
}

void Tutor::Print_details_Person()
{
cout << "Tutor:" << endl;
Person::Print_details_Person(); // function for print details's Person 
cout << "Study in LAYER:" << Pointer_of_tutor_for_class->get_name_layer_for_class()<< endl << "In CLass:" <<Pointer_of_tutor_for_class->get_number_of_the_class() << endl;

cout << "The Salary:" << return_salary_worker() << endl;

cout << "The Courses Name:";
 //print_all_courses_of_teacher();

for (int i = 0; i < Pointer_of_tutor_for_class->get_amount_pupil_in_class(); i++)//print pupil details
{
	Pointer_of_tutor_for_class->find_pupils_in_array_learning_class_in_index(i)->Print_details_Person();
	if (Pointer_of_tutor_for_class->find_pupils_in_array_learning_class_in_index(i)->Verification_mitstayenne())
	{
		cout << "Pupil is Excellent:)" << endl;
	}
}

}

bool Tutor::Verification_mitstayenne()
{
	int count = 0, countPupil = 0;
	
	countPupil = Pointer_of_tutor_for_class->get_amount_pupil_in_class();
	return(count > (countPupil / 2)) ? true : false;
}