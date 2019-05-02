/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#include "Layer.h"

//#define size_class 2
Layer::Layer()
{
	name_layer = NULL;
	array_of_class_in_layer = NULL;
	amount_of_class_in_layer = 3;

}

void Layer::Class_constructor_in_Layer(char name_chihva)// constructor of class for each layer at  school 
{

	int numb = 1;

	array_of_class_in_layer = new Class*[amount_of_class_in_layer]; //create dynamic array of 3 CLass for each LAyer 

	for (int i = 0; i <amount_of_class_in_layer; i++)  // for each CLass we give name from a until f to know where the class belong to, and a number 1-3
	{
		array_of_class_in_layer[i] = new Class; // new class is created  in the  dynamic array 
		array_of_class_in_layer[i]->set_name_layer_for_class(name_chihva); // set the naame of the layer for each class
		array_of_class_in_layer[i]->set_number_of_the_class(numb);// we set for each class a number
		numb += 1;//we incrementing the number 
	}

	
}


Layer::~Layer()
{
}






