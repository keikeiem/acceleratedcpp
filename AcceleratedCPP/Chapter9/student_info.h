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
	double grade() const;
	double grade(double midterm, double final, const vector<double>& homework) const;
	double grade(double midterm, double final, double median) const;
	double get_median_value(const vector<double>& homework) const;
	
	std::istream& read(std::istream& in);
	std::istream& read_homework(std::istream& in);
	std::string name() const { return (name_); }
	bool valid() const { return (!homework.empty()); }

	void show();

private:
	std::string name_;
	double midterm;
	double final;
	std::vector<double> homework;
};

typedef std::vector<Student_info> Students;
//typedef std::list<Student_info> Students;

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_homework(std::istream&, std::vector<double>&);
#endif
