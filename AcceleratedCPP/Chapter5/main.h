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

using std::list;

void Greeting(const string name);
string InsertName(void);

void read_test(Student_info& s, const string name, const double midterm, const double final, const vector<double> & homework);
Student_info random_grade(const string name);
Student_infoL random_grade_list(const string name);
bool check_fail(const Student_info&);
void classify_index(vector<Student_info>&, vector<Student_info>&);
void classify_iter(vector<Student_info>&, vector<Student_info>&);

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

	vector<Student_info> failed_students;
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

	// Chapter5 Example 1.1
	// 인덱스를 사용한 vector 접근 방식
	//classify_index(students, failed_students);
	// Chapter5 Example 1.2
	// iterator를 사용한 vector 접근 방식
	//classify_iter(students, failed_students);


	cout << "passed:" << endl;
	PrintStudentsData(students);
	cout << "failed:" << endl;
	PrintStudentsData(failed_students);

	return 0;
}

void read_test_list(Student_infoL& s, const string name, const double midterm, const double final, const list<double> & homework);
bool check_fail_list(const Student_infoL&);
list<Student_infoL> classify_iter(list<Student_infoL>&);
// list 타입
int Chapter5Example5() {
	list<Student_infoL> students;

	Student_infoL record;

	string::size_type max_length = 0;

	list<double> hw1;
	hw1.push_back(10);
	hw1.push_back(20);
	hw1.push_back(30);
	hw1.push_back(40);
	read_test_list(record, "kimkm", 100, 100, hw1);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	list<double> hw2;
	hw2.push_back(50);
	hw2.push_back(40);
	hw2.push_back(30);
	hw2.push_back(40);
	read_test_list(record, "kyungmin", 50, 50, hw2);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	students.push_back(random_grade_list("note"));
	students.push_back(random_grade_list("alpha"));
	students.push_back(random_grade_list("beta"));
	students.push_back(random_grade_list("gamma"));
	students.push_back(random_grade_list("delta"));
	students.push_back(random_grade_list("epsilon"));

	students.sort(compare_list);

	list<Student_infoL> failed_students = classify_iter(students);
	// Chapter5 Example 1.1
	// 인덱스를 사용한 vector 접근 방식
	//classify_index(students, failed_students);
	// Chapter5 Example 1.2
	// iterator를 사용한 vector 접근 방식
	//classify_iter(students, failed_students);


	cout << "passed:" << endl;
	PrintStudentsData(students);
	cout << "failed:" << endl;
	PrintStudentsData(failed_students);

	return 0;
}

#endif