#pragma once
/* Assignment: 1
Campus: Ashdod
Author: Yaniv Bohbot, ID: 204892749
*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef MyString_h
#define MyString_h
#include <iostream>
using namespace std;
#define N 80  
class MyString
{
private:
	char *str; /*A pointer containing the starting address of an array of characters.*/
	int length; /*length of string str*/
public:
	MyString();/* defualt Constructors*/
	MyString(char*);/*Constructors with parameter*/
	~MyString();/*Destructors*/
	void Print()const;/*print to screen*/
	MyString(const MyString &m);/*Copy constructor allocating ptr*/
	void Change_tableaux_str(char*);/*fanction to change str*/
	int getLength();// function to get the size of the table 
	int Counter_Char(char);//function that cont the number of the charactere 
	int CountWord();// function that count the number of word 
	void LItlle_to_Upper();// function that convert the letter to biiger 
	void Bigger_ToLower();// function that convert to lower 
	void by_reference(int &count_upper, int &count_lower, int &count_num);// function that update by reference the number big ,lower letter and number 
	void Concetanation(const MyString &m); // function that concatanete the new string with the old one 
	char* Find_Word(int n);// function to find the word with number send by user 
};

#endif;