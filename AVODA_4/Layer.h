
/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/#pragma once
#ifndef Layer_H
#define Layer_H
#include <iostream>
#include "Class.h"
using namespace std;
class Layer
{
private: char name_layer;  // 'a'-'f'
		 Class** array_of_class_in_layer;   // 3 class
		 int amount_of_class_in_layer;   // 3 classer in one layer 
public:
	Layer();  //constructor 
	Layer(char name_chichva);  //create 3classe in the layer 
	Class* return_Class_in_array_chichva(int index1){ return array_of_class_in_layer[index1]; } // index between 1-3 function to find class in the array 
	~Layer(); //destructor
	void Class_constructor_in_Layer(char name_chihva);
	void set_name_chihva(char name){ name_layer = name; };
	char get_name_chihva(){ return name_layer; };
	int get_amount_of_class(){ return amount_of_class_in_layer; };
	
};
#endif

