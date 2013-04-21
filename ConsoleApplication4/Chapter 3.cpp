// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;		using std::setprecision;
using std::cout;	using std::string;
using std::endl;	using std::streamsize;

int _tmain(int argc, _TCHAR* argv[])
{

	//ask for and read the students name.
	cout<<"Please enter your first name: ";
	string name;
	cin>>name;
	cout<<"Hello "<<name<<"!"<<endl;

	//ask for and read midterm and final grades
	cout<<"Please enter your midterm and final grades: ";
	double midterm, final;
	cin>>midterm>>final;

	//ask for homework grades
	cout<<"Please enter your homework grades " 
			"followed by end-of-file,: ";

	//the number and sum of grades so far.
	int count = 0;
	double sum = 0;

	//varible to read into 
	double x;

	// invariant:
	// we have read count grades so far, and
	// sum is the sum of the first count grades
	while (cin>>x)
	{
		++count;
		sum += x;
	}

	//write the result
	streamsize prec = cout.precision();
	cout<<"Your final grade is "<< setprecision(3)<<.2*midterm+.4*final+.4*sum/count<<setprecision(prec)<<endl;

	system("PAUSE");

	return 0;
}

