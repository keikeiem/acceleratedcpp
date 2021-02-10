#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "median.h"
#include "student_info.h"
#include "grade.h"
#include "main.h"

int main() {
	//turn Chapter4Example1();
	//return Chapter4Example2();
	
	//return Chapter4Problem2(1000);

	return Chapter4Problem7();
}

void foo(int & x) {
	x = 5;
}

void Greeting(const string name) {
	cout << "Hello, " << name << "!" << endl;
}

string InsertName(void) {
	string name;
	cin >> name;

	return (name); 
}

void read_test(Student_info& s, const string name, const double midterm, const double final, const vector<double> & homework) {
	s.name = name;
	s.midterm = midterm;
	s.final = final;
	s.homework = homework;
}