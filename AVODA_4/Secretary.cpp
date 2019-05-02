
/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#include "Secretary.h"


Secretary::Secretary()
{
	amount_of_pupil_secretary=0;
}

Secretary::Secretary(string firstName, string lastname, int id, int num, int Quantity_Of_Children) :Worker(firstName, lastname, id, num)
{
	amount_of_pupil_secretary = Quantity_Of_Children;
}
Secretary::~Secretary()
{
}
double Secretary::return_salary_worker()
{
	int x,salary_secretary;

	x = get_amount_of_pupil_secretary();

	salary_secretary = Basis + x * 200;

	return salary_secretary;
}
bool Secretary::Verification_mitstayenne()
{
	int senior_mazcira, mazcira_excelent=10;

	senior_mazcira = get_seniority_worker();

	if (senior_mazcira >mazcira_excelent)
	{
		cout << "Secretary is Mistayennete" << endl;
		return true;
	}
	else{
		cout << "Secretary is NOOOT  Mistayennete" << endl;
		return false;
	}
}

void Secretary::Print_details_Person()
{
	cout << "Secretary:" << endl;

	Person::Print_details_Person();
	cout <<endl<<"Secretary's salary:"<<return_salary_worker()<<endl;
	cout <<"Seniority:"<<get_seniority_worker()<<endl;
	cout <<"Amount of pupil in school for secretary:" << get_amount_of_pupil_secretary()<<endl;
}


