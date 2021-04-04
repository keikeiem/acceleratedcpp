#include "Core.h"

Core::Core() : midterm(0), final(0)
{
	std::cerr << "[Generator] Core::Core()" << std::endl;
}

Core::Core(std::string s) : midterm(0), final(0)
{
	n = s;
}

Core::Core(std::istream& in) : midterm(0), final(0)
{
	std::cerr << "[Generator] Core::Core(std::istream&)" << std::endl;
	read(in);
}

std::string Core::name(void) const {
	std::cout << "Core::grade()" << std::endl;
	return n;
}

std::istream& Core::read(std::istream& in) {
	read_common(in);
	read_homework(in, homework);
	return in;
}

double Core::grade(void) const {
	std::cout << "Core::grade()" << std::endl;
	if (valid())
		return ::grade(midterm, final, homework);
	
	return 0;
}

std::istream& Core::read_common(std::istream& in) {
	in >> n >> midterm >> final;
	return in;
}

std::istream& Core::read_homework(std::istream& in, std::vector<double>& hw) {
	if (in) {
		// 초기화
		hw.clear();

		double x;
		while (in >> x) {
			hw.push_back(x);
		}
		// istream 객체의 초기화
		in.clear();
	}
	return in;
}