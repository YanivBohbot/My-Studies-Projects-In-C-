/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#include "Pupil.h"


Pupil::Pupil() :Person()
{

	amount_of_grades = 0;
	name_of_chihva = NULL;
	number_class = 0;
	array_of_grades = NULL; // creating a dynamic array of grades
}
	

//Pupil::Pupil(string name, string lastname, int id, int* array, int amount, char layer, int Class) :Person(name,lastname,id)
//{
//	amount_of_grades = amount;
//	name_of_chihva = layer;
//	number_class = Class;
//	array_of_grades = array; // creating a dynamic array of  6 layers at the school
//
//
//
//
//}

Pupil::~Pupil()
{
	
	delete array_of_grades;
	amount_of_grades=0;
	name_of_chihva=NULL;
	number_class = 0;
}

Pupil::Pupil(string firstname, string lastname, int  number_id, char layer, int class_numb): Person(firstname,lastname,number_id)
{
	
	number_class = class_numb;

	int grade;


	switch (layer)
	{
	case 'a': amount_of_grades = 5; break;
	case 'b': amount_of_grades = 6; break;
	case 'c': amount_of_grades = 7; break;
	case 'd': amount_of_grades = 8; break;
	case 'e': amount_of_grades = 9; break;
	case 'f': amount_of_grades = 10; break;

	default:cout << "Error";
		break;
	}

	array_of_grades = new int[amount_of_grades];

	for (int i = 0; i < amount_of_grades; i++)
	{
		cout << "grades" << i + 1 << ":";
		cin >> grade;
		array_of_grades[i] = grade;
	}
	cout << endl;

}

void Pupil::Print_details_Person() // fucntion to print all the detail about the pu
{
	float average = 0;

	cout << "Student:"<<endl;

	int * array_grade = get_array_grades();


	Person::Print_details_Person(); // function for print details's Person

	cout << "Study in LAYER:" << name_of_chihva<<endl<<"In CLass:"<<number_class<<endl;
	cout <<"Grades:"<< endl ;

	for (int i = 0; i <amount_of_grades; i++) // print all the grades in the array 
	{
		array_of_grades[i] = array_grade[i];
		cout <<array_of_grades[i]<<" "; // in the index i
	}
	
    average=return_average_grades();// the variable get the average of the pupil
	cout<<endl<<"Average:"<<average<<endl; // prin the average
}

float Pupil:: return_average_grades()
{

	float grade_calcul=0 ;
	float average=0;


	for (int i = 0; i < amount_of_grades; i++)
	{
		grade_calcul += array_of_grades[i];

	}

	average = float(grade_calcul / amount_of_grades);

	return average;

}

bool Pupil::Verification_mitstayenne()
{  
	bool mits = false;

	int grade_excelent = 65,counter = 0, average_excelent = 85;

	float average_pupil = return_average_grades(); 

	for (int i = 0; i < amount_of_grades; i++)
	{   
		if (array_of_grades[i]>grade_excelent)// if the grade of the course is higher than 65 
		{
			counter += 1;//count the courses with good grades for exclency
		}

	}


	if ( (counter == amount_of_grades) && (average_pupil > average_excelent) )
	{
		mits = true;
		return mits;
	}
	else{
		return mits;
	}
}

