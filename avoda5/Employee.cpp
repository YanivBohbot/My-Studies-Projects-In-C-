/*assignement 5
Name: yaniv bohbot
ID:204892749
CAmpus:Ashdod */
#include "Employee.h"

int Employee::totalEmployee = 0;//Static variable initialization
Employee::Employee()//defult ctor
{
	/*strcpy(fullName_, " ");
	strcpy(EmployerName_, " ");*/
	/*salary = 0.0;
	seniority = 0;*/
}
Employee::Employee(char name[], char name_boss[], int seniority, float salary)//ctor with parameters
{
	for (int i = 0; i < MAX_TAV; i++)
	{
		this->name[i] = name[i];
		this->name_BOSS[i] = name_boss[i];

	}
	this->seniority = seniority;
	this->salary = salary;
	totalEmployee++;
}
Employee::~Employee()//dtor
{
}
