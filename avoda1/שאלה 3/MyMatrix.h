/* Assignment: 1
Campus: Ashdod
Author: Yaniv Bohbot, ID: 204892749
*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef MyMatrix_H
#define MyMatrix_H
#include <iostream>
//#include <cstdlib>
using namespace std;
#define SIZE 2

class MyMatrix
{ private :
	
	float a11, a12,a21, a22; // four variables of float types

public:
	MyMatrix();//constructor 
	~MyMatrix();//deconstructor 
	MyMatrix::MyMatrix(float a, float b, float c, float d);//constructor with 4 arguments to initialize the four variables in the privates 
	MyMatrix::MyMatrix(const MyMatrix &m);// function copy constructor who receive an object to copy 
	void set(const MyMatrix &m);//set function ,set an object with the object that we send 
	bool boolean_set(int i, int j, float num); // the function change the value in the matrix (i,j) ,it return true if the coordinates are correct  
	bool bool_get(int i, int j, float &num)const;//the function change the num that we send before to the value in the index in the matrix ,it return true if the index are correct 
	bool bool_is_equal(const MyMatrix &m)const; // the function return true if matrix are equal to the matrix of the second object that we send as argument 
	void print()const;// function for print the matrix 
	float det()const;// fuunction that calculate the determinant of the matrix 
	bool invertible()const; // the function check if the matrix is invertible 
	bool bool_is_inverse(const MyMatrix &m); // the function check if the matrix in the second object is the inverse of the matrix of the first object 
	
};
#endif

