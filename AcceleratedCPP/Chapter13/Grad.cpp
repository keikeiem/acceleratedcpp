#include "Grad.h"

Grad::Grad() : thesis(0) {

}

Grad::Grad(std::string s) : Core(s), thesis(0) {
	
}

Grad::Grad(std::istream& in) {
	read(in);
}

double Grad::grade(void) const {
	return std::min(Core::grade(), thesis);
}

std::istream& Grad::read(std::istream& in) {
	read_common(in);
	in >> thesis;
	read_homework(in, Core::homework);
	return in;
}