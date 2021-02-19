#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>
#include <list>


struct Student_info {
	std::string name;
	double midterm;
	double final;
	std::vector<double> homework;
	double grade;
 };

typedef std::vector<Student_info> Students;
//typedef std::list<Student_info> Students;

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_homework(std::istream&, std::vector<double>&);

void PrintStudentsData(Students & students);

#endif
