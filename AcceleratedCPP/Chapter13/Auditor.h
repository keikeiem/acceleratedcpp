#ifndef AUDITOR_H
#define AUDITOR_H

#include "Core.h"

class Auditor : public Core {
public:
	Auditor();
	Auditor(std::istream&);

	double grade() const;
	std::istream& read(std::istream&);
	void regrade(double d1, double d2) {
		final = d1;
		attendence = d2;
	}
	bool valid() const {
		return (attendence > 0);
	}

	void show(void);

protected:
	Auditor* clone() const { return new Auditor(*this); }

private:
	double attendence;
};

#endif