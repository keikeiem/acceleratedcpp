#ifndef GRADE_H
#define GRADE_H

#include <vector>
#include "student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double> &);
double grade(Student_info & s);
void grade(Students& students);

double grade_aux(const Student_info& s);

#endif
