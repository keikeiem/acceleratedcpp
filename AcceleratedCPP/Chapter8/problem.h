#ifndef PROBLEM_H
#define PROBLEM_H

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

template <class _mFunc>
double analysis(const Students& s, _mFunc m) {
	vector<double> grades;
	std::transform(s.begin(), s.end(), back_inserter(grades), m);
	return get_median_value(grades);
}

double average(const vector<double>& v);
double average_grade(const Student_info& s);
double optimistic_median(const Student_info& s);

double average(const vector<double>& v) {
	// accumulate�� numeric ���̺귯���� �ִ� �޼���
	// Q. 0.0�� �����ΰ�?
	// A. double Ÿ������ �Ϸ���.. 0���� �ϸ� int�� �����Ѵٰ���
	return (std::accumulate(v.begin(), v.end(), 0.0) / v.size());
}

double average_grade(const Student_info& s) {
	return grade(s.midterm, s.final, average(s.homework));
}

double optimistic_median(const Student_info& s) {
	vector<double> nonzero;
	// remove_copy�� �����ΰ�?
	// iterator�� ���鼭 0�� �׸��� ����� 
	// �������� ���� ������ nonzero�� ����Ǵ°� ����
	std::remove_copy(s.homework.begin(), s.homework.end(), std::back_inserter(nonzero), 0);
	if (nonzero.size()) {
		return grade(s.midterm, s.final, 0);
	}
	else {
		return grade(s.midterm, s.final, get_median_value(nonzero));
	}
}

void read_test(Student_info& s, const string name
	, const double midterm, const double final
	, const vector<double>& homework);

int Chapter8Problem1() {
	Students students;

	Student_info record;

	string::size_type max_length = 0;

	vector<double> hw1;
	hw1.push_back(10);
	hw1.push_back(0);
	hw1.push_back(0);
	hw1.push_back(30);
	cout << "kyungmin: " << get_median_value(hw1) << endl;
	read_test(record, "kimkm", 50, 50, hw1);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	vector<double> hw2;
	hw2.push_back(50);
	hw2.push_back(0);
	hw2.push_back(0);
	hw2.push_back(30);
	cout << "kyungmin: " << get_median_value(hw2) << endl;
	read_test(record, "kyungmin", 50, 50, hw2);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	cout << "median    : " << analysis(students, grade_aux) << endl;
	cout << "average   : " << analysis(students, average_grade) << endl;
	cout << "optimistic: " << analysis(students, optimistic_median) << endl;
	return 0;
}

#endif