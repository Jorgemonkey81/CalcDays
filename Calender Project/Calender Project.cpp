// Calender Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>

using namespace std;

int userYear;
int userMonth;
int startMonth = 1;
int startYear = 1753;
int currentYear;
int numDays;
int noLeapDays;

/************************************
* Get the user inputted month & year
************************************/
int userInput()
{
	cout << "Pick a year after 1752: ";
	cin >> userYear;

	// Validate year
	while (userYear <= startYear)
	{
		cout << "Please enter in a year after Dec 31, 1752";
		cin >> userYear;
	}

	cout << "Pick a month.  Please enter in a number instead of the name. \n"
		<< "Example: for March, enter in 3: ";
	cin >> userMonth;

	// Validate month
	while (userMonth < 1 || userMonth > 13)
	{
		cout << "Please enter in a valid month {1,2,3,4,5,6,7,8,9,10,11,12}";
		cin >> userMonth;
	}

	return userMonth, userYear;
}

/****************************************************
* Calculate # of days that have passed between start
* year and user entered year
****************************************************/
int calcLeapYear(int userYear)
{
	numDays = (userYear - startYear) * 365; // Total days, not including leap years
	
	// Constant to check the math
	noLeapDays = (userYear - startYear) * 365;

	// This is supposed to add in the leap year days
	for (int currentYear = userYear; currentYear < userYear; startYear++)

		if ((currentYear % 4 == 0 && currentYear % 100 != 0) || (currentYear % 400 == 0))
		{
			numDays += 1;
		}
		else
			numDays += 0;

	return numDays, noLeapDays;
}



/**********************************************************
* Whole point of this to make sure calculations are right
***********************************************************/
void validateNumbersDisplay()
{
	cout << "Month: "<< userMonth << "\nYear: " << userYear << endl;
	cout << "Days passed: " << calcLeapYear << "\n";
	cout << "No leap days: " << noLeapDays << endl;
}

int main()
{
	userInput();
	calcLeapYear(userYear);

	validateNumbersDisplay();

    return 0;
}

