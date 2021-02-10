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
	return Chapter5Example1();
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

Student_info random_grade(const string name) {
	Student_info record;

	int random_value = (1 + std::rand() % 10);
	bool statement = (random_value % 2 == 0 ? true : false);

	double homework = random_value * 10;
	double mid = homework + (statement ? 5 : -5);
	double final = homework + (statement ? -5 : 5);

	vector<double> hw;
	hw.push_back(random_value * 10);

	read_test(record, name, mid, final, hw);
	return (record);
}

bool check_fail(const Student_info& s) {
	return (s.grade < 50);
}