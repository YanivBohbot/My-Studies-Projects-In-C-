/*assignement 5
Name: yaniv bohbot
ID:204892749
CAmpus:Ashdod */
#include "Date.h"


Date::Date()
{
	day = 0; month = 0; year = 0;
}


Date::~Date()
{
}

Date::Date(int d, int m, int y) 
{
	day = d; month = m; year = y;
}
