/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#include "Worker.h"


Worker::Worker()
{
}


Worker::~Worker()
{
	seniority = 0;
	 salary=0;
}
Worker::Worker(string firstName, string lastname, int id, int num) :Person(firstName, lastname, id)
{
	seniority = num;
}
double Worker::return_salary_worker()
{
	return salary= Basis;

}
void Worker::Print_details_Person()
{
	/*cout << "Worker:" << endl;*/
	Person::Print_details_Person();
	cout<<"Seniority:"<< seniority<<endl;

}
