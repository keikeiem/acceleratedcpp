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

void read_test(Student_info& s, const string name, const double midterm, const double final, const vector<double> & homework);

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

int Chapter4Problem1(void) {
	int max_length;
	Student_info s;
	//std::max(s.name.size(), max_length);

	std::max((int)s.name.size(), max_length);
	std::max(s.name.size(), (size_t)max_length);

	return (0);
}

int Chapter4Problem2(const int value) {
	// 1부터 value까지의 정수와 그 제곱을 표시하는데
	// 정수 | 제곱수

	cout << "Integer" << " | " << "Square" << endl;
	for (int i = 1; i < value; i++) {
		cout << std::setw(7) << i << " | "
			<< std::setw(6) << std::pow(i, 2)
			<< endl;
	}	

	return 0;
}

int Chapter4Problem4(const double value) {
	// 1부터 value까지의 정수와 그 제곱을 표시하는데
	// 정수 | 제곱수

	cout << "Integer" << " | " << "Square" << endl;
	for (int i = 1; i < value; i++) {
		cout << std::setw(7) << i << " | "
			<< std::setw(6) << std::pow(i, 2)
			<< endl;
	}

	return 0;
}

int Chapter4Problem5() {
	// Chapter3 에서 문장에서 단어 추출하여
	// 개수 세는 작업을 한 것으로 갈음함.
}

int Chapter4Problem7() {
	double x;
	vector<double> datas;
	while (cin >> x) {
		datas.push_back(x);
	}

	if (datas.size() == 0) {
		cout << "No double value(s)" << endl;
		return (1);
	}

	double avg = 0;
	for (size_t i = 0; i < datas.size(); i++) {
		avg += datas[i];
	}
	//avg = (avg / ((double)datas.size()));
	avg = avg / datas.size();

	cout << "average is: " << avg << endl;
	return (0);
}

int Chapter4Problem8(void) {
	// double d = f() [n]
	// std::vector<double> 타입이겠지
	return (0);
}

#endif