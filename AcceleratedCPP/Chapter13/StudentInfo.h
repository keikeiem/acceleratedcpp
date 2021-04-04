#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include "Grad.h"

class StudentInfo {
public:
	StudentInfo() : cp(0) {}
	StudentInfo(std::istream& in) : cp(0) { read(in); };
	StudentInfo(const StudentInfo&);
	StudentInfo& operator=(const StudentInfo&);
	~StudentInfo() { delete cp; }

	std::istream& read(std::istream&);

	std::string name(void) const {
		if (cp)
			return cp->name();
		else
			throw std::runtime_error("uninitialized Student");
	}

	double grade(void) const {
		if (cp)
			return cp->grade();
		else
			throw std::runtime_error("uninitialized Student");
	}

	static bool compare(const StudentInfo& s1, const StudentInfo& s2) {
		return (s1.name() < s2.name());
	}

	void regrade(double d1, double d2) {
		cp->regrade(d1, d2);
	}
private:
	Core* cp;
};

#endif