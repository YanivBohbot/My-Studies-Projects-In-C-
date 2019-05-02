/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#include "Manager.h"


Manager::Manager()
{

}


Manager::~Manager()
{
}
Manager::Manager(string firstName, string lastname, int id, int seniority) :Worker( firstName,lastname, id,seniority)
{

}
double Manager::return_salary_worker()   //function for return the salary's manager
{
	int y, salary_manager;
	y = get_seniority_worker(); // call the funciton to get the senioirty's worker 
	salary_manager = Basis * 2 + y * 500; // calculus the in the varaible salary manager
	return salary_manager; // return the salary's manager 
}

bool Manager::Verification_mitstayenne()//fucntion to check if the manager is excelent 
{
	int senior;
	senior = get_seniority_worker();  //call the function to get the seniority 's woker
	if (senior > 3) // if the seniority is more than 3 the maanger is excelent 
	{
		cout << "Manager is Mistayenne" << endl;
		return true; // returning true 
	}
	else{
		cout << "Manager is NOOOT  Mistayenne" << endl; // else print the following message to user  and return false 
		return false;
	}
}

void Manager::Print_details_Person()
{
	cout << "Manager:" << endl;
	Worker::Print_details_Person();
	cout << "Salary's Manager:" << return_salary_worker();
}