/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#include "Class.h"


Class::Class()
{
	name_layer_for_class = NULL;

	number_of_class = 0;
	
	amount_pupils_class = 0;
    tutor_for_class = NULL;
}


Class::~Class()
{
}

//Pupil* Class::find_pupils_in_array_learning_class_in_index(int index)
//{
//
//	//do
//	//{
//	//	cout << array_pupils_learning_class[i];
//	//	if (get_name_of_chihva() == name_layer_for_class)
//	//	{
//	//		if (p->get_numb_class() == number_of_class)
//	//		{
//	//			array_pupils_learning_class[i] = p->set_family_name_person();
//	//		}
//	//		array_pupils_learning_class++;
//	//	} while (array_pupils_learning_class != NULL);
//	//	//array_pupils_learning_class[i] = p->get_amount_grades_pupil();
//
//	//}
//
//}
//bool Class::add_pupils_to_array_learning_class(Pupil* p)
//{
//	//int i = 0 ,  amount_pupils_class = 1 ;
//	string x = p->get_name_person();
//	int y = p->get_number_id_person();
//	string z = p->get_family_person();
//	int* arr = p->get_array_grades();
//
//	amount_pupils_class += 1;
//	array_pupils_learning_class = new Pupil*[amount_pupils_class];
//
//
//	for (int i = 0; i < amount_pupils_class; i++)
//	{
//		array_pupils_learning_class[i] = new Pupil;
//		array_pupils_learning_class[i]->set_name_person(x);
//		array_pupils_learning_class[i]->set_number_id_person(y);
//		array_pupils_learning_class[i]->set_family_name_person(z);
//
//	}
//
//	cout << "PUPIL in CLASS " << p->get_numb_class() << ":";
//	for (int i = 0; i < amount_pupils_class; i++)
//	{
//		cout << "Family Name:" << array_pupils_learning_class[i]->get_family_person() << endl << "Name:" << array_pupils_learning_class[i]->get_name_person() << "ID:" << array_pupils_learning_class[i]->get_number_id_person() << endl;
//		
//	}
//
//
//
//	if (array_pupils_learning_class == NULL)
//	{
//		return false;
//	}
//	else {
//		return true;
//	}
//}
void Class::settingCLass(char name_layer, int numb_clas)
{
	name_layer_for_class = name_layer;
	number_of_class = numb_clas;
}


void Class::add_pupils_to_array_learning_class(Pupil* p)
{
	
	Pupil** TEMp_array_pupils_learning_class = new Pupil*[amount_pupils_class];    // allocate new memory and copy the elements to temp array
	
	for (int i = 0; i <amount_pupils_class; i++)      //copy listpupil to temp array
	{
		TEMp_array_pupils_learning_class[i] = new Pupil;
		TEMp_array_pupils_learning_class[i] = array_pupils_learning_class[i];

	}
	array_pupils_learning_class = new Pupil*[amount_pupils_class];     //assign new memory to the object listCourses
	for (int i = 0; i <= amount_pupils_class; i++)
	{
		array_pupils_learning_class[i] = new Pupil;
		if (i == amount_pupils_class)      //set last cell
		{
			
			array_pupils_learning_class[i] = p;
			
		}
		else//set all cell
		{
			array_pupils_learning_class[i] = TEMp_array_pupils_learning_class[i];//Update the original list course 
		}
	}
	amount_pupils_class += 1;//Increases the size of department
}










