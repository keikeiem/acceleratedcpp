#ifndef VEC_STUDENT_INFO_H
#define VEC_STUDENT_INFO_H

#include <iostream>
#include <string>
#include <algorithm>
#include "vec.h"

using std::domain_error;

class Student_info {
public:
	Student_info();
	Student_info(std::istream& in);

	double grade() const;
	double grade(double midterm, double final, const Vec<double>& homework) const;
	double grade(double midterm, double final, double median) const;
	double get_median_value(const Vec<double>& homework) const;
	void compute_grade(void);

	std::istream& read(std::istream& in);
	std::istream& read_homework(std::istream& in);
	std::istream& read_and_compute(std::istream& in);
	std::string name() { return (name_); }
	bool valid() const {
		return true;
		//return (!homework_.empty());
	}
	double get_grade() const { return (grade_); }

	void set_name(const std::string s) { name_ = s; }
	void set_test_score(const double mid, const double final) {
		midterm_ = mid;
		final_ = final;
	}
	void set_homework(const Vec<double> s) {
		for (Vec<double>::const_iterator iter = s.begin(); iter != s.end(); ++iter)
		{
			homework_.push_back(*iter);
		}
	}

	void show();

private:
	std::string name_;
	double midterm_;
	double final_;
	Vec<double> homework_;
	double grade_;
};

typedef Vec<Student_info> Students;
//typedef std::list<Student_info> Students;

bool compare(Student_info&, Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_homework(std::istream&, Vec<double>&);

#endif
