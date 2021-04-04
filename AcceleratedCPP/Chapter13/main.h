#ifndef MAIN_H
#define MAIN_H

#include "Core.h"

class Grad : public Core {
public:
	Grad();
	Grad(std::istream&);
	double grade() const;
	std::istream& read(std::istream&);
private:
	double thesis;
};

int Chapter13Example1() {
	Grad grad;
	std::cout << grad.name() << std::endl;
	return 0;
}

#endif