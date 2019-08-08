
/*assignement 5
Name: yaniv bohbot
ID:204892749
CAmpus:Ashdod */
#include "Student.h"
int Student::totalStudent = 0;//Static variable initialization
Student::Student()//defult Ctor
{
	/*strcpy(fullName_, " ");
	strcpy(id_, " ");*/
	date = new Date();
	average = 0.0;
}
Student::Student(char name[], char name_id[], Date &d, float avg)//Ctor with parameters
{
	//strcpy(fullName_, a);
	//strcpy(id_, b);
	//DateOfBirth_ = new Date(d);
	//average = x;
	//totalStudent++;//Static variable
	for (int i = 0; i < MAX_TAV; i++)
	{
		name_student[i] = name[i];

	}

	for (int i = 0; i < MAX_TAV_ID; i++)
	{
		number_id[i] = name_id[i];
	}
	date = new Date(d);
	average = avg;
}
