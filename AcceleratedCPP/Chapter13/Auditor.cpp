#include "Auditor.h"

Auditor::Auditor() : attendence(0) {
	std::cerr << "[Generator] Auditor::Auditor()" << std::endl;
}

Auditor::Auditor(std::istream& in) {
	std::cerr << "[Generator] Auditor::Auditor(std::istream&)" << std::endl;
	read(in);
}

double Auditor::grade(void) const {
	std::cout << "Auditor::grade()" << std::endl;
	if (valid())
		return std::min(Core::grade(), attendence);
	return 0;
}

std::istream& Auditor::read(std::istream& in) {
	read_common(in);
	in >> attendence;
	read_homework(in, Core::homework);
	return in;
}

void Auditor::show(void) {
	std::cout << "==== Auditor::show(void) for " << name() << " ====" << std::endl;
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
	std::cout << "attendence: " << attendence << std::endl;
	std::cout << "===============================" << std::endl;
}