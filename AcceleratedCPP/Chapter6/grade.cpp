#include "median.h"
#include "grade.h"

using std::vector;
using std::domain_error;

double grade(double midterm, double final, double homework) {
	return (0.2 * midterm) + (0.4 * final) + (0.4 * homework);
}

double grade(double midterm, double final, const vector<double> & hw) {
	if (hw.size() == 0)
		throw domain_error("student has done no homework");

	return grade(midterm, final, get_median_value(hw));
}

double grade(Student_info & s) {
	s.grade = grade(s.midterm, s.final, s.homework);
	return (s.grade);
}

void grade(Students & s) {
	for (Students::iterator iter = s.begin(); iter != s.end(); ++iter) {
		try {
			grade(*iter);
		}
		catch (domain_error e) {
			std::cout << e.what();
		}
	}
}