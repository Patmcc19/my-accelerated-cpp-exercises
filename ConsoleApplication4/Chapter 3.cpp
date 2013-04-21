// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;		using std::setprecision;
using std::cout;	using std::string;
using std::endl;	using std::streamsize;
using std::vector;	using std::sort;

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

	/*For average grades.
	//the number and sum of grades so far.
	int count = 0;
	double sum = 0;
	*/

	//varible to read into 
	double x;
	vector<double> homework;

	// invariant:
	// we have read count grades so far, and
	// sum is the sum of the first count grades
	while (cin>>x)
	{
		homework.push_back(x);

		/*For average grades
		++count;
		sum += x;
		*/
	}

	//get the size of the vector homework
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();

	//check for data 
	if (size == 0)
	{
		cout<<endl<<"You must enter your grades." 
			"Please try again."<<endl;
		system("PAUSE");
		return 1;
	}

	//sort homework vector
	sort(homework.begin(),homework.end());

	//find the middle elements 
	vec_sz mid = size/2;
	double median;
	median = size % 2 == 0 ? (homework[mid]+homework[mid-1])/2:homework[mid];


	//write the result
	streamsize prec = cout.precision();
	cout<<"your final grade is "<<setprecision(3)
		<<.2*midterm+.4*final+.4*median<<setprecision(prec)<<endl;


	/*output for average grades
	cout<<"Your final grade is "<< setprecision(3)
			<<.2*midterm+.4*final+.4*sum/count
			<<setprecision(prec)<<endl;
			*/
	system("PAUSE");

	return 0;
}

