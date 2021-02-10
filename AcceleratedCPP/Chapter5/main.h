#pragma once
#ifndef METHOD_H
#define METHOD_H

#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::string;
using std::streamsize;
using std::vector;
using std::domain_error;

void Greeting(const string name);
string InsertName(void);

void read_test(Student_info& s, const string name, const double midterm, const double final, const vector<double> & homework);
Student_info random_grade(const string name);
bool check_fail(const Student_info&);
int Chapter5Example1() {
	vector<Student_info> students;
	Student_info record;

	string::size_type max_length = 0;

	vector<double> hw1;
	hw1.push_back(10);
	hw1.push_back(20);
	hw1.push_back(30);
	hw1.push_back(40);
	read_test(record, "kimkm", 100, 100, hw1);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	vector<double> hw2;
	hw2.push_back(50);
	hw2.push_back(40);
	hw2.push_back(30);
	hw2.push_back(40);
	read_test(record, "kyungmin", 50, 50, hw2);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	students.push_back(random_grade("note"));
	students.push_back(random_grade("alpha"));
	students.push_back(random_grade("beta"));
	students.push_back(random_grade("gamma"));
	students.push_back(random_grade("delta"));
	students.push_back(random_grade("epsilon"));

	sort(students.begin(), students.end(), compare);

	typedef vector<Student_info>::size_type std_size;
	for (std_size i = 0; i != students.size(); ++i) {
		cout << students[i].name
			<< string(max_length + 1 - students[i].name.size(), ' ');

		try {
			students[i].grade = grade(students[i]);
			streamsize prec = cout.precision(3);
			cout << setprecision(3) << students[i].grade
				<< setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}

	

	return 0;
}

#endif