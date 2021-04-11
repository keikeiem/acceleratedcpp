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

void Grad::show(void) {
	std::cout << "==== Grad::show(void) for " << name() << " ====" << std::endl;
	std::cout << "final   : " << final << std::endl;
	std::cout << "midterm : " << midterm << std::endl;
	std::cout << "homework: ";
	for (std::vector<double>::const_iterator iter = homework.begin();
		iter != homework.end(); ++iter)
	{
		if (iter != homework.begin())
			std::cout << " | ";
		std::cout << (*iter);
	}
	std::cout << std::endl;
	std::cout << "thesis  : " << thesis << std::endl;
	std::cout << "===============================" << std::endl;
}