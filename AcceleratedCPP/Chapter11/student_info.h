#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::domain_error;

class Student_info {
public:
	Student_info();
	Student_info(std::istream& in);

	double grade() const;
	double grade(double midterm, double final, const vector<double>& homework) const;
	double grade(double midterm, double final, double median) const;
	double get_median_value(const vector<double>& homework) const;
	void compute_grade(void);

	std::istream& read(std::istream& in);
	std::istream& read_homework(std::istream& in);
	std::istream& read_and_compute(std::istream& in);
	std::string name() { return (name_); }
	bool valid() const { return (!homework_.empty()); }
	double get_grade() const { return (grade_); }

	void show();

private:
	std::string name_;
	double midterm_;
	double final_;
	std::vector<double> homework_;
	double grade_;
};

typedef std::vector<Student_info> Students;
//typedef std::list<Student_info> Students;

bool compare(Student_info&, Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_homework(std::istream&, std::vector<double>&);
#endif
