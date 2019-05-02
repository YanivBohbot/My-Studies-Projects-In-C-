/* Assignment: 1
Campus: Ashdod
Author: Yaniv Bohbot, ID: 204892749
*/
#include "MyMatrix.h"


MyMatrix::MyMatrix() // default constructor 
{
	
	a11 = 0;  // the variables are all initialized to 0
	a12 = 0;
	a21 = 0;
	a22 = 0;
	}


MyMatrix::MyMatrix(float a11, float a12, float a21, float a22)  // constructor receive 4 parameters
{
	this->a11 = a11; // the first place receive the first number
 this->a12= a12;// the second place receive the second number
	this->a21 = a21;// the third place receive the third number
	 this->a22= a22;// the fourth place receive the fourth number

}
 MyMatrix::MyMatrix(const MyMatrix &m) // copy constructor
{
	 a11 = m.a11; // we copy the fields in the private in the object to value that is in the object that we send  
	 a12 = m.a12;
	 a21 = m.a21;
	 a22 = m.a22;

}

void MyMatrix::set(const MyMatrix &m)//function set ,function that change all the values in the matrix to the values that we send a argument 
{
	a11= m.a11;// we copy the fields in the private in the object to value that is in the object that we send 
	a12 = m.a12;
	a21 = m.a21;
    a22 = m.a22;

}
bool MyMatrix::boolean_set(int i, int j, float num)
{
	if (i == 1 && j == 1) // condition to check if the index 0<i<3 && 0<j<3
	{
		a11 =num ; // if its ok then the variable is now egal to the varaible num
		return true; // return true to the function in the main
	}
	if (i == 1 && j == 2)  // condition to check if the index 0<i<3 && 0<j<3 
	{
		 a12=num ;// if its ok then the variable is now egal to the varaible num
		 return true; // return true to the function in the main
		 
	}
	if (i == 2 && j == 1)  // condition to check if the index 0<i<3 && 0<j<3
	{
		a21 =num ;// if its ok then the variable is now egal to the varaible num
		return true; // return true to the function in the main
		
	}
	if (i == 2 && j == 2)  // condition to check if the index 0<i<3 && 0<j<3
	{
		a22 = num;// if its ok then the variable is now egal to the varaible num
		return true; // return true to the function in the main
		
	}		
	else  // if is not in the range there is message erro and return false , the user will change the index
	{
		cout << "YOUR INDEX IS NoT IN THE RANGE!!! (0<i<3 && 0<j<3)" << endl << "TRY AGAIN:" << endl;
		return false;		
	}

}
bool MyMatrix::bool_get(int i, int j, float &num)const //
{
	if (i == 1 && j == 1) // condition to check if the index 0<i<3 && 0<j<3
	{
		num = a11;;// if its ok then the variable num is now egale to the value in the matrix
		 // return true to the function in the main
		cout << endl << "Now after the fonction get -> the value that you entered is now:" << num<< endl;
		return true;
	}
	if (i == 1 && j == 2)// condition to check if the index 0<i<3 && 0<j<3
	{
		num = a12;;// if its ok then the variable num is now egale to the value in the matrix
		// return true to the function in the main
		 cout << endl << "Now after the fonction get -> the value that you entered is now:" << num << endl;
		return true;
	}
	if (i == 2 && j == 1) // condition to check if the index 0<i<3 && 0<j<3
	{
		num = a21;;// if its ok then the variable num is now egale to the value in the matrix 
		// return true to the function in the main
		 cout << endl << "Now after the fonction get -> the value that you entered is now:" << num << endl;
		return true;
	}
	if (i == 2 && j == 2) // condition to check if the index 0<i<3 && 0<j<3
	{
		num = a22;;// if its ok then the variable num is now egale to the value in the matrix
		// return true to the function in the main
		 cout << endl << "Now after the fonction get -> the value that you entered is now:" << num << endl;
		return true;
	}
	else
	{  // if the indexs are not in the range there is a meassage error ,we return false , the user have to change the index until we have true
		cout << "YOUR INDEX IS NoT IN THE RANGE!!! (0<i<3 && 0<j<3)" << endl << "TRY AGAIN:" << endl;
		return false;
	}

}



bool MyMatrix::bool_is_equal(const MyMatrix &m)const // function that check if the value in the matrix are equal to the value that are in the second matrix from the second object that we send 
{  
	return ( (a11 == m.a11) && (a12 == m.a12) && (a21 == m.a21) && (a22 == m.a22) ) ? true : false;// we check each one  if all the value are equal we return true , else false 

}

void MyMatrix::print()const // function print , print the matrix 
{

	cout << a11 << "  " << a12 << "  " << endl << a21 << "  " << a22 << endl; // the matrix look like   a11   a12
	                                                                          //                        a21   a22
	}

float MyMatrix::det()const // function determinant 
{
	float determinant=0;

	determinant=( (a11* a22) - (a12 * a21)); // we calculate the determinant 

	return determinant; // return the result 
}
bool MyMatrix::invertible()const // function invertible , return true if the matrix is invertible 
{
	float determinant_invert;

	determinant_invert=det(); // we call the function determinant 

	if (determinant_invert != 0) // if the determinant is not equal to 0 
	{
		
		return true; // we return true if the condtion is true 
	}
	else{
		 // else we return false  to the main 
		return false;
	}
}
bool MyMatrix::bool_is_inverse(const MyMatrix &m ) // function bool is inverse check  if the matrix that we send as argument is the inverse of the matrix that we have 
{
	//float chev;
	//chev = (1 / ((m.a11 * m.a22) - (m.a12 *m.a21))); // we calculate the 1/determinant 
	//if (((a11*chev) == m.a11) && ((a12*-(chev)) == m.a12) && ((a21*-(chev)) == m.a21) && ((a22*(chev)) == m.a22)) // we check with this calcul if the matrix that we receive is the inverse of our matrix 
	//	return true; // return true if it ok 
	//else{ 
	//	return false; // else retur nfalse to the main
	//}
	if (( ( (a11* m.a11) + (a12*m.a21) ) == 1) &&( ( (a11* m.a12) + (a12*m.a22) ) == 0) && (((a21* m.a11) + (a22*m.a21)) == 0) &&( ( (a21* m.a12) + (a22*m.a22) ) == 1) )
	{
		return true;
	}
	else{
		return false;
	}

}
MyMatrix::~MyMatrix() // destructor 
{
}
