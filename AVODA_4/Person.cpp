/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#include "Person.h"


Person::Person()
{
	name=" ";
	family_name = " ";
	number_id = 0;
}
Person::Person(string firstname,string lastname,int id)
{
	name = firstname;
	family_name = lastname;
	number_id = id;
}

Person::~Person()
{
}
