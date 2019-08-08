/*assignement 5
Name: yaniv bohbot
ID:204892749
CAmpus:Ashdod */

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef Date_h
#define Date_h
#include <iostream>
using namespace std;
/*file Date*/
class Date
{
private:
	int day;//day
	int month;//month
	int year;//year
public:
	Date();//Defult ctor
	Date(int d, int m, int y);//Ctor with parameters
	~Date();//This class has no memory release
	void print(){ cout << day << " " << month << " " << year << endl; };//print to screen the date 
	int getday_(){ return day; };//return day
	int getmonth_(){ return month; };//return month
	int getyear_(){ return year; };//return year
};
#endif;