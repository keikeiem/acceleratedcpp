#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "main.h"

int main() {
	//turn Chapter4Example1();
	return Chapter4Example2();
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

// call by value
double grade(double midterm, double final, double homework) {
	return (0.2 * midterm) + (0.4 * final) + (0.4 * homework);
}

double grade(double midterm, double final, const vector<double> & hw) {
	if (hw.size() == 0)
		throw domain_error("student has done no homework");

	return grade(midterm, final, get_median_value(hw));
}

double get_median_value(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("an empty vector");

	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;
	return (size % 2) == 0 ? (vec[mid] + vec[(mid - 1)]) / 2 : vec[mid];
}

std::istream & read_homework(std::istream& in, vector<double> & hw) {
	if (in) {
		// 초기화
		hw.clear();

		double x;
		while (in >> x) {
			hw.push_back(x);
		}
		// istream 객체의 초기화
		in.clear();
	}
	return in;
}

//Chapter4Example2

double grade(const Student_info & s) {
	return grade(s.midterm, s.final, s.homework);
}

std::istream & read(std::istream & is, Student_info& s) {
	cout << "Enter first name: ";
	is >> s.name;
	cout << "Enter your midterm grade: ";
	is >> s.midterm;
	cout << "Enter your final grade: ";
	is >> s.final;

	cout << "Enter your homework grades, followed by endoffile: ";
	read_homework(is, s.homework);
	return (is);
}

void read_test(Student_info& s, const string name, const double midterm, const double final, const vector<double> & homework) {
	s.name = name;
	s.midterm = midterm;
	s.final = final;
	s.homework = homework;
}