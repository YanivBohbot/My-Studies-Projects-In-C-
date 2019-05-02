/* Assignment: 1
Campus: Ashdod
Author: Yaniv Bohbot, ID: 204892749
*/
#define _CRT_SECURE_NO_WARNINGS
#include "MyMatrix.h"



int main()
{
	MyMatrix M;
	float num1=0, num2=0, num3=0, num4=0,value,determinant; // create 4  float variables and one determinant 
	int index1=0, index2=0;// create index 
	
	
	cout << "The First object1 with the default constructor:" << endl;
	M.print();// we print the matrix with the default constructor 
	cout << "Enter 4 number float to insert in the matrix:" << endl;
	cin >> num1 >> num2 >> num3 >> num4; //the user insert 4 number in 4variables
	MyMatrix object1(num1, num2, num3, num4);/// we send the variables to the function constructor with the four variables
	cout << "THE Matrix of the object is :" << endl;// 
	object1.print();// we print now the matrix after the function,that change the matrix who was empty , now there is 4 numbers in it 
	cout << "WE print THE SET of THE OBJECT:"<<endl;
	M.set(object1);// we sent the object 1 to the function 
	M.print();
	object1.print();
	cout <<" WE print the Copy Constructor of he object:"<<endl;//message to the user
	MyMatrix object2(object1);// we call th copy constructor with the object2, we send object1
	object2.print();	//we print now the matrix of the object2

	do{	
		cout <<"Enter a Number to change the value in matrix:";//message to the user 
		cin >> value; //insert the variable value 
		cout << endl<<"enter coordinates:(0<i<3 && 0<j<3) " << endl; //mesage
		cout << "index i:";
		cin >> index1;// index i 
cout << "index j:";
		cin >>index2;	//index j 
	}while(!(object1.boolean_set(index1, index2, value)));	 // we check in the funtion boolean if the coordinates are correct , if there not we still in the loop ,until the user correct them  
	object1.print();// we print the matrix of the object 1 


 
	do{
		cout << "we change your number that you inserted:" << endl;
		cout << endl << "enter coordinates:(0<i<3 && 0<j<3):" << endl;		
		cout << "index i:";
		cin >> index1;// index i
		cout << "index j:";
		cin >> index2;// index j 
		cout << "the Number that you inserte before the fonction get ->:"<<value;// we print the value before 
		
	} while (!(object1.bool_get(index1,index2,value))); //the function check if the index are correct , if there not we still in the loop until the user correct them
	object1.print();// we print the matrix of the oject 
	

	if (M.bool_is_equal(object2) == true)  //we call the function boois esqual from the object M and we check if its equal with oobject 2 if its 
	{
		cout<<"Theyre Equaal !!"<<endl; // if the function is true its printing ''equal''
	}
	else
	{
		 cout<<"they are  NOT EQUAL"<<endl; // if not : ""not Equal""
	}	

	determinant=object1.det();// call the function determinant 
	cout << "THe Determinant of the Matrix is :"<<determinant << endl; // print the determinant 

	if (object1.invertible() == true) // we call the function invertible if its true 
	{
		cout <<"The Matrix is invertible !"<< endl; // its print the matrix is vertible 
	}
	else
	{
		cout <<"The Matrix is not invertible!-> the determinant==0" << endl; // if its not ,its not vertible 
	}
	num1 = 0, num2 = 0, num3 = 0, num4 = 0;
	cout << "Enter 4 number float to insert in the matrix:" << endl;
	cin >> num1 >> num2 >> num3 >> num4;
	MyMatrix object3(num1, num2, num3, num4);

	if (object1.bool_is_inverse(object3) == true) // call the function to check if the matrix in object 2 is the inverse matrix of the matrix object 1  
	{
		cout << "The Matrix is The INVERSE !" << endl; // if its true we print ok 
	}
	else
	{
		cout << "The Matrix is NOT THE INVERSE "<< endl; // if its not we print not ok 
	}

	return 0;
}