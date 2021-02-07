#pragma once
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

void foo(int & x);

void Greeting(const string name);
string InsertName(void);

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const vector<double> & hw);
double get_median_value(vector<double> vec);
std::istream & read_homework(std::istream& in, vector<double> & hw);

int Chapter4Example1() {
	cout << "Enter first name: ";
	string name = InsertName();
	Greeting(name);

	cout << "Enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Enter your homework grades, "
		<< "followed by endoffile: ";

	vector<double> homework;
	read_homework(cin, homework);

	try {
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3)
			<< final_grade << setprecision(prec) << endl;
	}
	catch (domain_error) {
		cout << endl << "You must enter your grades. "
			"Please try again";
		return 1;
	}
	return 0;
}

struct Student_info {
	string name;
	double midterm;
	double final;
	vector<double> homework;
};
double grade(const Student_info & s);
std::istream & read(std::istream & in, Student_info& s);
void read_test(Student_info& s, const string name, const double midterm, const double final, const vector<double> & homework);
bool compare(const Student_info & x, const Student_info & y) {
	return (x.name < y.name);
}

void PrintStudentsData(vector<Student_info> & students) {
	for (auto iter = students.begin(); iter != students.end(); iter++) {
		cout << (*iter).name << " | "
			<< (*iter).midterm << " | "
			<< (*iter).final << endl;
		cout << "Homework: ";
		vector<double> & hw = (*iter).homework;
		for (auto iter_hw = hw.begin(); iter_hw != hw.end(); iter_hw++) {
			cout << (*iter_hw) << " ";
		}
		cout << endl;
	}
}

int Chapter4Example2() {
	vector<Student_info> students;
	Student_info record;

	string::size_type max_length = 0;

	vector<double> hw1;
	hw1.push_back(10);
	hw1.push_back(20);
	hw1.push_back(30);
	hw1.push_back(40);
	read_test(record, "bkimkm", 100, 100, hw1);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	vector<double> hw2;
	hw2.push_back(50);
	hw2.push_back(40);
	hw2.push_back(30);
	hw2.push_back(40);
	read_test(record, "akyungmin", 50, 50, hw2);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	/*while (read(cin, record)) {
		max_length = std::max(max_length, record.name.size());
		students.push_back(record);
	}*/

	PrintStudentsData(students);
	sort(students.begin(), students.end(), compare);

	typedef vector<Student_info>::size_type std_size;
	for (std_size i = 0; i != students.size(); ++i) {
		cout << students[i].name
			<< string(max_length + 1 - students[i].name.size(), ' ');

		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision(3);
			cout << setprecision(3) << final_grade
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