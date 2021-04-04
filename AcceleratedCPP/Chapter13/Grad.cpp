#include "Grad.h"

Grad::Grad() : thesis(0) {
	std::cerr << "[Generator] Grad::Grad()" << std::endl;
}

Grad::Grad(std::string s) : Core(s), thesis(0) {
	
}

Grad::Grad(std::istream& in) {
	std::cerr << "[Generator] Grad::Grad(std::istream&)" << std::endl;
	read(in);
}

double Grad::grade(void) const {
	std::cout << "Grad::grade()" << std::endl;
	if (valid())
		return std::min(Core::grade(), thesis);
	return 0;
}

std::istream& Grad::read(std::istream& in) {
	read_common(in);
	in >> thesis;
	read_homework(in, Core::homework);
	return in;
}