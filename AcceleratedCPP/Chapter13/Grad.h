#ifndef GRAD_H
#define GRAD_H

#include "Core.h"

class Grad : public Core {
public:
	Grad();
	Grad(std::string s);
	Grad(std::istream&);

	// grade, read는 Core로부터 virutal로 상속받음
	double grade() const;
	std::istream& read(std::istream&);
	virtual void regrade(double d1, double d2) {
		final = d1;
		thesis = d2;
	}
protected:
	Grad* clone() const { return new Grad(*this); }

private:
	double thesis;
};

#endif