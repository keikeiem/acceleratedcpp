#ifndef STUDENT_INFO_PTR_H
#define STUDENT_INFO_PTR_H

#include "Grad.h"
#include "Ptr.h"

class StudentInfoPtr {
public:
	StudentInfoPtr() : cp(0) {}
	StudentInfoPtr(std::istream& in) : cp(0) { read(in); };

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

	static bool compare(const StudentInfoPtr& s1, const StudentInfoPtr& s2) {
		return (s1.name() < s2.name());
	}

	void regrade(double d1, double d2) {
		cp.make_unique();

		if (cp)
			cp->regrade(d1, d2);
		else throw std::runtime_error("regrade of unknown student");
	}

	bool valid() const {
		return cp->valid();
	}

	std::string letter_grade(void);

	void show(void) {
		if (cp)
			return cp->show();
		else
			throw std::runtime_error("uninitialized Student");
	}
private:
	Ptr<Core> cp;
};

#endif