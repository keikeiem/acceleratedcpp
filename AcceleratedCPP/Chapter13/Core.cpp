#include "Core.h"

Core::Core() : midterm(0), final(0)
{

}

Core::Core(std::string s) 
: midterm(0)
, final(0)
{
	n = s;
}

Core::Core(std::istream& in)
: midterm(0)
, final(0)
{
	read(in);
}

std::string Core::name(void) const {
	return n;
}

std::istream& Core::read(std::istream& in) {
	read_common(in);
	read_homework(in, homework);
	return in;
}

double Core::grade(void) const {
	return ::grade(midterm, final, homework);
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