#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
	std::string name;
	double midterm;
	double final;
	std::vector<double> homework;
	double grade;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_homework(std::istream&, std::vector<double>&);

void PrintStudentsData(std::vector<Student_info> & students);

#endif
