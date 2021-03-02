#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <list>
#include <numeric>

#include "median.h"
#include "student_info.h"
#include "grade.h"
#include "main.h"
#include "problem.h"

int main() {
	// return Chapter8Example1();
	// return Chapter8Example2();
	// return Chapter8Example2_list();
	// return Chapter8Example3();
	// return Chapter8Example4();

	return Chapter8Problem1();
}

bool space(char c) {
	return (isspace(c));
}

bool not_space(char c) {
	return !(isspace(c));
}

void read_test(Student_info& s, const string name, const double midterm, const double final, const vector<double>& homework) {
	s.name = name;
	s.midterm = midterm;
	s.final = final;
	s.homework = homework;
}