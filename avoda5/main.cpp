/*assignement 5
Name: yaniv bohbot 
ID:204892749
CAmpus:Ashdod */
#pragma once
#define _CRT_SECURE_NO_WARNINGS
 
#define MAX_TAV 30
#define MAX_TAV_ID 10
#include "Employee.h"
#include "Student.h"
#include "MyArray.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Student **arr_stu1, **arr_stu2;
	Employee **arr_emp1, **arr_emp2, **arr_emp3;
	char filename[MAX_TAV], outfile[MAX_TAV];
	char name_stu[MAX_TAV], name_last[MAX_TAV], name_e[MAX_TAV], name_emp_last[MAX_TAV], name_boss[MAX_TAV], id_number[MAX_TAV_ID];
	float average, salary;
	Date *D;
	int day, month, year, seniority, i, size = 0, flag_capital, counter = 0, index,index1 = 0, index2 = 0, j = 0;
	string fullname = " ",ligne[MAX_TAV];
	//***************************************open file for read data **************************************************************/
	cout << "Enter a name for read file:" << endl;
	cin >> filename;

	ifstream file(filename, ios::in);//open file for Reading
	try//check if file open
	{
		if (file.fail())
			throw filename;

	}
	catch (char *file)
	{
		cout << "Error:can not open file" << file << endl;
		return 0;
	}

	/**********************************************************************************************************************************/
	/*According to the input file is dynamically allocates memory for 5 arrays and initiates them.Then create entry from MyArrayT type*/
	/**********************************************************************************************************************************/

	/***********************************************Student********************************************************/

	file >> size;
	MyArray<Student*> student1(size);
	arr_stu1 = new Student*[size];
	for (int i = 0; i < size; i++)    //2 student
	{
		file >> name_stu >> name_last >> id_number >> day >> month >> year >> average;
		strcat(name_stu, name_last);
		D = new Date(day, month, year);
		arr_stu1[i] = new Student(name_stu, id_number, *D, average);
		student1.enter_object(i, arr_stu1[i]);
		student1.print_element(i);

		delete D;
	}
		

	file >> size;//input size array from file
	MyArray<Student*>student2(size);//Creating an Student object
	arr_stu2 = new Student*[size];//Dynamically allocates memory for array
	for (int i = 0; i < size; i++)
	{

		//file >> name >> id_number >> day >> month >> year >> average;//input data from file

		file >> name_stu >> name_last >> id_number >> day >> month >> year >> average;
		strcat(name_stu, name_last);
		D = new Date(day, month, year);//initialize Student's date of birth
		arr_stu2[i] = new Student(name_stu, id_number, *D, average);//initiates array
		//arr_stu2[i]->print();
		student2.enter_object(i, arr_stu2[i]);//initiates object with array parameters
		student2.print_element(i);
		delete D;
	}

	/****************************************Employee***********************************************************************/

	file >> size;//input size array from file
	MyArray<Employee*>employe1(size);//Creating an Employee object
	arr_emp1 = new Employee*[size];//Dynamically allocates memory for array
	for (int i = 0; i < size; i++)
	{
		//file >> name >> nameEmployee >> seniority >> salary;//input data from file
		//arr_emp1[i] = new Employee(name, nameEmployee, salary, seniority);//initiates array
		//arr_emp1[i]->print();
		//employe1.enter_object(i, arr_emp1[i]);//initiates object with array parameters


		file >> name_e >> name_emp_last >> name_boss >> seniority >> salary;
		strcat(name_e, name_emp_last);
		arr_emp1[i] = new Employee(name_e, name_boss, seniority, salary);
		employe1.enter_object(i, arr_emp1[i]);
		employe1.print_element(i);

	}
	file >> size;//input size array from file
	MyArray<Employee*>employe2(size);//Creating an Employee object
	arr_emp2 = new Employee*[size];//Dynamically allocates memory for array
	for (int i = 0; i < size; i++)
	{
		//file >> name >> nameEmployee >> seniority >> salary;//input data from file
		//arr_emp2[i] = new Employee(name, nameEmployee, salary, seniority);//initiates array
		//arr_emp2[i]->print();
		//employe2.enter_object(i, arr_emp2[i]);//initiates object with array parameters



		file >> name_e >> name_emp_last >> name_boss >> seniority >> salary;
		strcat(name_e, name_emp_last);
		arr_emp2[i] = new Employee(name_e, name_boss, seniority, salary);
		employe2.enter_object(i, arr_emp2[i]);
		employe2.print_element(i);
	}
	file >> size;//input size array from file
	MyArray<Employee*>employe3(size);//Creating an Employee object
	arr_emp3 = new Employee*[size];//Dynamically allocates memory for array
	for (int i = 0; i < size; i++)
	{
		//file >> name >> nameEmployee >> seniority >> salary;//input data from file
		//arr_emp3[i] = new Employee(name, nameEmployee, salary, seniority);//initiates array
		//arr_emp3[i]->print();
		//employe3.enter_object(i, arr_emp3[i]);//initiates object with array parameters

		/*file >> name_e >> name_emp_last >> name_boss >> seniority >> salary;
		strcat(name_e, name_last);
		arr_emp3[i] = new Employee(name_e, name_boss, seniority, salary);
		employe3.enter_object(i, arr_emp3[i]);
		employe3.print_element(i);*/

		file >> name_stu >> name_last >> name_boss >> seniority >> salary;
		strcat(name_stu, name_last);
		arr_emp3[i] = new Employee(name_stu, name_boss, seniority, salary);
		employe3.enter_object(i, arr_emp3[i]);
		employe3.print_element(i);



	}

	file.close();
	/*****************************************************/
	/**Input from user To perform SWAP to student object**/
	/*****************************************************/

	//////////////////*************************SWAp Student *************************************//////////////////////////
	try{
		cout << endl << "Make swap with One persons : " << endl;
		
		cout << "NAme: "; cin >> name_stu;
		flag_capital = 0;
		i = 0;
		while (name_stu[i] != '\0')
		{
			if ((flag_capital == i) && (name_stu[flag_capital]<'A' || name_stu[flag_capital]>'Z'))//Checks if first charactersis is capital letter
				throw "Error:illegal name! first charactersis in every word is not capital letter";
			else
			{
				i++;
				if (name_stu[i] >= 'a' || name_stu[i] <= 'z')//Checks if charactersis is small letter
					counter++;
				else
				{
					if (name_stu[i] != '-' || name_stu[i] != ' ')//Checks if Between two words Separating space or hyphen
						throw "Error:illegal name! Between two words Separating space or hyphen";
					flag_capital = i + 1;
					if (name_stu[flag_capital]<'A' || name_stu[flag_capital]>'Z')//Checks if first letter in every word is capital letter
						throw "Error:illegal name! first letter in every word must be capital letter";
				}
			}
		}
		if (counter < 5 || counter>20)
			throw "Error the name must be at least 5 letter or maximum 20";
		//**************************id student************
		cout << "enter id : ";
		cin >> id_number;
		i = 0;
		counter = 0;
		while (id_number[i] != '\0')
		{
			if (id_number[i]<'0' || id_number[i]>'9')
				throw "EROOR your ID is not with DIGIT";
			counter++;
			i++;
		}
		if (counter != 9)
			throw "EROOR your NUmber id is not 9 digit";

		//**********************************bithday student***
		cout << "ENtER student birthday:";
		cout << "Day:";
		cin >> day;
		if ((day > 31) || (day < 1))
			throw"erroor the day have to be between (1-31)";
		cout << endl << "Month: ";
		cin >> month;
		if ((month>12) || (month < 1) || ((day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))) || (day == 30 && month == 2))
			throw "your month is incorrect ";
		cout << endl << "Year:";
		cin >> year;
		if (year < 0)
			throw "error your year cant not be 0";
		if (year < 200)
			if ((day == 29 && month == 2) && !((year - 1900) % 4 == 0))
				throw "error this is a leap year !";
		if (year>2000)
			if ((day == 29 && month == 2) && !((year - 2000) % 4 == 0))
				throw"error";
		//**********************************AVERAGE student***************************************
		cout << endl << "the AVerage: ";
		cin >> average;
		if (average > 100 || average < 0)
			throw "Eroor your average is not good";
	}
	catch (char * error)
	{
		cout << error;
		delete[]arr_stu1;//free array date of birth
		delete[]arr_stu2;//free array date of birth
		return 0;
	}

	//*****************************SWWAP STUDENT--*******************************

	///****************Swap stutent object*******************/
	//D = new Date(day, month, year);//initialize Student's date of birth
	//Student* Swap = new Student(name_stu, id_number, *D, average);
	//student.swap(student[0], Swap);
	//student2.swap(student2[0], Swap);
 //    student.print_all();
	//student2.print_all();


	//*****************************SWWAP STUDENT--*******************************
	D = new Date(day, month, year);
	Student *Swap = new Student(name_stu, id_number, *D, average);
	cout << endl << "Now choose the index of the 1st object that you want to swap:(index 0-1)";
	cin >> index;

	student1.swap(student1[index], Swap);
	//student1.print_element(index);
		/*student1.print_all(2);*/
	
	ifstream file2(filename, ios::in);//open file for Reading
	try//check if file open
	{
		if (file2)
		{
			// déclaration d'une chaîne qui contiendra la ligne lue

			//while (getline(filename, ligne))  // on met dans "contenu" la ligne
			//{
			//	cout << ligne;  // on affiche la ligne

			//}

			while (file2 >> name_stu >> name_last >> id_number >> day >> month >> year >> average)
			{
				cout << name_stu << " " << name_last << endl << id_number << day << " " << month << " " << year << endl << average;
			}
		}
		else{
throw filename;
		}
	}

	catch (char *file2)
	{
		cout << "Error:can not open file" << file2 << endl;
		return 0;
	}

	


		file.close();





	cout << endl << "Now choose the index of the 2nd object that you want to swap:(index 0)";
	cin >> index;
	student2.swap(student2[index], Swap);
	/*student2.print_all(1);*/
	







	/******************************************************/
	/**Input from user To perform SWAP to Employee object**/
	/******************************************************/

	//---------------Exception Handling for Employee---------------------------------------------------------------------------------------------
	try//This function will check the given name,id_number,date and average of student is valid or not.
	{
		//-----------Check Employee's name-------------------------------------------------------------------------------------------
		cout << "Please enter employee name" << endl;
		cin >> name_e;
	
		int i = 0,
			flag_capital = 0;
		while (name_e[i] != '\0')
		{
			if ((flag_capital == i) && (name_e[flag_capital]<'A' || name_e[flag_capital]>'Z'))//Checks if first charactersis is capital letter
				throw "Error:illegal name! first charactersis in every word is not capital letter";
			else
			{
				i++;
				if (name_e[i] >= 'a' || name_e[i] <= 'z')//Checks if charactersis is small letter
					counter++;
				else
				{
					if (name_e[i] != '-' || name_e[i] != ' ')//Checks if Between two words Separating space or hyphen
						throw "Error:illegal name! Between two words Separating space or hyphen";
					flag_capital = i + 1;
					if (name_e[flag_capital]<'A' || name_e[flag_capital]>'Z')//Checks if first letter in every word is capital letter
						throw "Error:illegal name! first letter in every word must be capital letter";
				}
			}
		}
		if (counter <5 || counter>20)//Check size student name less than five Or greater than 20
			throw "Error:illegal name! student name less than five Or greater than 20";
		//-----------Check Employee's name ---------------------------------------------------------------------------------------------
		cout << "Enter BOSS NAME:" << endl;
		cin >> name_boss;

		//------------Check Employee's Salary----------------------------------------------------------------------------------
		cout << "Enter employee's Salary" << endl;
		cin >> salary;
		if (salary <= 0)//Check day
			throw "Error:illegal employee's Salary ! must be positive number";

		//-------------Check Employee's Seniority----------------------------------------------------------------------------------------
		cout << "Enter employee's Seniority:(0-50)" << endl;
		cin >> seniority;
		if (seniority < 0 || seniority>50)//check if semployee's Seniority less than 0 Or greater than 50
			throw "Error:illegal Seniority! need to be between 0-50";
	}
	catch (char * error)
	{
		cout << error;
		delete[]arr_stu1;//free array date of birth
		delete[]arr_stu2;//free array date of birth
		delete[]arr_emp1;//free array date of birth
		delete[]arr_emp2;//free array date of birth
		delete[]arr_emp3;//free array date of birth
		return 0;
	}

	/*********************Swap Employee object*************************/
	Employee* eSwap = new Employee(name_e, name_boss, salary, seniority);
	employe1.swap(employe1[0], eSwap);	
	employe2.swap(employe2[0], eSwap);
	employe3.swap(employe3[0], eSwap);
	/*****************************************************************/
   /* employe1.print_element(1);
	employe2.print_element(3);
	employe3.print_element(1);*/
	//student1.print_element(1);//Prints this indexed member
	//student1.print_all();//print all object
	//student1.print_max(); //Prints all the element with maximum value, implemented externally
	for (int i = 0; i < 7; i++)
	{

	}

	//--------------open file for output----------------------------------------------------------------------------

	cout << "Enter a name for write file:" << endl;
	cin >> outfile;
	ofstream writeTOfile(outfile, ios::out);//open file for write
	try
	{
		if (writeTOfile.fail())
			throw  outfile;

	}
	catch (char *file)
	{
		cout << "Error:can not open file" << file << endl;
		return 0;
	}
	//-------------insert data into file--------------------------------------------------------------------------------
	if (dynamic_cast<Student*>(student1.getArray()))
	{
		for (int i = 0; i < student1.getLength(); i++)
		{
			writeTOfile << student1[i]->getfullName_() << endl;// Writing to the file fullName
			writeTOfile << student1[i]->getid_() << endl;// Writing to the file id_number
			writeTOfile << student1[i]->getDateOfBirthDay_() << " " << arr_stu1[i]->getDateOfBirthMonth() << " " << arr_stu1[i]->getDateOfBirthYear() << endl;//Writing to the file DateOfBirth
			writeTOfile << student1[i]->getaverage() << endl;// Writing to the file average
		}
	}
	if (dynamic_cast<Student*>(student2.getArray()))
	{
		for (int i = 0; i < student2.getLength(); i++)
		{
			writeTOfile << student2[i]->getfullName_() << endl;// Writing to the file fullName
			writeTOfile << student2[i]->getid_() << endl;// Writing to the file id_number
			writeTOfile << student2[i]->getDateOfBirthDay_() << " " << arr_stu1[i]->getDateOfBirthMonth() << " " << arr_stu1[i]->getDateOfBirthYear() << endl;//Writing to the file DateOfBirth
			writeTOfile << student2[i]->getaverage() << endl;// Writing to the file average
		}
	}
	if (dynamic_cast<Employee*>(employe1.getArray()))
	{
		for (int i = 0; i < employe1.getLength(); i++)
		{
			writeTOfile << employe1[i]->getfullName() << endl;// Writing to the file full Name
			writeTOfile << employe1[i]->getEmployerName() << endl;// Writing to the file Employer Name
			writeTOfile << employe1[i]->getSeniority() << endl;//Writing to the file Seniority
			writeTOfile << employe1[i]->getMax() << endl;// Writing to the file salary
		}
	}
	if (dynamic_cast<Employee*>(employe2.getArray()))
	{
		for (int i = 0; i < employe2.getLength(); i++)
		{
			writeTOfile << employe2[i]->getfullName() << endl;// Writing to the file full Name
			writeTOfile << employe2[i]->getEmployerName() << endl;// Writing to the file Employer Name
			writeTOfile << employe2[i]->getSeniority() << endl;//Writing to the file Seniority
			writeTOfile << employe2[i]->getMax() << endl;// Writing to the file salary
		}
	}
	if (dynamic_cast<Employee*>(employe3.getArray()))
	{
		for (int i = 0; i < employe3.getLength(); i++)
		{
			writeTOfile << employe3[i]->getfullName() << endl;// Writing to the file full Name
			writeTOfile << employe3[i]->getEmployerName() << endl;// Writing to the file Employer Name
			writeTOfile << employe3[i]->getSeniority() << endl;//Writing to the file Seniority
			writeTOfile << employe3[i]->getMax() << endl;// Writing to the file salary
		}
	}

	writeTOfile << "The length of objects type MyArray<Student>:" << student1.find_total_length() << endl;
	writeTOfile << "The length of objects type MyArray<Employee>:" << employe1.find_total_length() << endl;
	writeTOfile << "The number of objects type MyArray<Student>:" << student1.find_total() << endl;
	writeTOfile << "The number of objects type MyArray<Employee>:" << employe1.find_total() << endl;
	writeTOfile.close();//close file


	return 0;
}