#include "student_info.h"

using std::istream;
using std::vector;
using std::cout;
using std::endl;

using std::list;

bool compare(const Student_info& x, const Student_info& y) {
	return (x.name < y.name);
}

bool compare_list(const Student_infoL& x, const Student_infoL& y) {
	return (x.name < y.name);
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

void PrintStudentsData(list<Student_infoL> & students) {
	for (auto iter = students.begin(); iter != students.end(); iter++) {
		cout << (*iter).name << " | "
			<< (*iter).midterm << " | "
			<< (*iter).final << endl;
		cout << "Homework: ";
		list<double> & hw = (*iter).homework;
		for (auto iter_hw = hw.begin(); iter_hw != hw.end(); iter_hw++) {
			cout << (*iter_hw) << " ";
		}
		cout << endl;
	}
}