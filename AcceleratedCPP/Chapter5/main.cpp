#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <list>

#include "median.h"
#include "student_info.h"
#include "grade.h"
#include "main.h"

int main() {
	//return Chapter5Example1();
	return Chapter5Example5();
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

Student_infoL random_grade_list(const string name) {
	Student_infoL record;

	int random_value = (1 + std::rand() % 10);
	bool statement = (random_value % 2 == 0 ? true : false);

	double homework = random_value * 10;
	double mid = homework + (statement ? 5 : -5);
	double final = homework + (statement ? -5 : 5);

	list<double> hw;
	hw.push_back(random_value * 10);

	read_test_list(record, name, mid, final, hw);
	return (record);
}

bool check_fail(const Student_info& s) {
	return (s.grade < 50);
}

void classify_index(vector<Student_info>& s, vector<Student_info>& f) {
	vector<Student_info>::size_type index = 0;
	while (index < s.size()) {
		if (check_fail(s[index]))
		{
			f.push_back(s[index]);
			s.erase(s.begin() + index);
		}
		else
		{
			index++;
		}
	}
}

void classify_iter(vector<Student_info>& s, vector<Student_info>& f) {
	vector<Student_info>::const_iterator iter = s.begin();
	while (iter != s.end()) {
		if (check_fail(*iter))
		{
			f.push_back(*iter);
			iter = s.erase(iter);
		}
		else
		{
			++iter;
		}
	}
}

void read_test_list(Student_infoL& s, const string name, const double midterm, const double final, const list<double> & homework) {
	s.name = name;
	s.midterm = midterm;
	s.final = final;
	s.homework = homework;
}

bool check_fail_list(const Student_infoL& s) {
	return (s.grade < 50);
}

list<Student_infoL> classify_iter(list<Student_infoL>& s) {
	list<Student_infoL> failed;

	list<Student_infoL>::const_iterator iter = s.begin();
	while (iter != s.end()) {
		if (check_fail_list(*iter)) {
			failed.push_back(*iter);
			iter = s.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	return failed;
}