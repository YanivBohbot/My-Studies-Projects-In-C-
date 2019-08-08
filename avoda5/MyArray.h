/*assignement 5
Name: yaniv bohbot
ID:204892749
CAmpus:Ashdod */

#pragma once
#ifndef MyArray_h
#define MyArray_h
using namespace std;
#include "Student.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

template<class T>
class MyArray {
protected:
	T*  array_object;//Template array 
	int size;
	static int lengthStudentArr;
	static int lengthEmployeeArr;
public:
	MyArray() : size(1), array_object(new T[1]){};//Defult Ctor
	MyArray(int size);//Ctor with parameter
	void enter_object(int i, T &val);//Set class
	~MyArray() { delete[] array_object; }//Dtor
	T& operator[](int index) { return array_object[index]; }//1: Implicit inline: Returns that array indexed member
	void swap(T& a, T& b);//2:implemented externally
	void print_element(int index);//3:Prints this indexed member
	void print_all(int);//4:implemented externally, print all array
	void print_max();// 5: Prints all the element with maximum value,implemented externally
	int find_total();//6:Return The amount of type objects
	int find_total_length(){ return  array_object[0]->getTotalLength(); }//7:Returns the sum of the lengths of objects type
	int getLength(){ return  size; }
	T getArray(){ return *array_object; }
};
#endif
//-------------------------template Function---------------------------------------------------
template<class T>
int MyArray<T>::lengthStudentArr = 0;//Static variable initialization
template<class T>
int MyArray<T>::lengthEmployeeArr = 0;//Static variable initialization


template<class T>
MyArray<T>::MyArray(int size)//Ctor with parameter
{
	size = size;
	array_object = new T[size];
	if (typeid(Student**) == typeid(array_object))
		lengthStudentArr++; //Static variable
	if (typeid(Employee**) == typeid(array_object))
		lengthEmployeeArr++;//Static variable 

}

template<class T>
void MyArray<T>::swap(T& a, T& b) //The function Exchange values of two objects ( a and b)
{
	T  temp = a;
	a = b;
	b = temp;
}
template<class T>
void MyArray<T>::print_element(int index)//The function prints all the element in template array
{
	array_object[index]->print();
}
template<class T>
void MyArray<T>::print_all(int size)//The function prints all the element in template array
{
	for (int i = 0; i < size; i++)
		array_object[i]->print();
}

template<class T>
void MyArray<T>::print_max()// Prints all the element with maximum value
{
	T *max = new T[1];
	for (int i = 0; i< size; i++)
	{
		if (i + 1< size)
			if (array_object[i]->getMax() > array_object[i + 1]->getMax())
			{
			*max = array_object[i];
			}
			else
				*max = array_object[i + 1];
	}
	max[0]->print();//print student with highest average and employee with highest paid
}

template<class T>
void MyArray<T>::enter_object(int i, T &val) //Set class
{
	array_object[i] = val;
}

template<class T>
int MyArray<T>::find_total()//Return The amount of type objects
{
	if (typeid(Student**) == typeid(array_object))
		return lengthStudentArr;
	if (typeid(Employee**) == typeid(array_object))
		return lengthEmployeeArr;

}