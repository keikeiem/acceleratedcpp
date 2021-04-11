#include "StudentInfo.h"

StudentInfo::StudentInfo(const StudentInfo& s)
{
	if (s.cp)
		cp = s.cp->clone();
}
StudentInfo& StudentInfo::operator=(const StudentInfo& s) {
	if (&s != this)
	{
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	}
	return (*this);
}

std::istream& StudentInfo::read(std::istream& in) {
	delete cp;

	char ch;
	in >> ch;

	if (ch == 'A')
		cp = new Auditor(in);
	else if (ch == 'G')
		cp = new Grad(in);
	else
		cp = new Core(in);

	return in;
}

std::string StudentInfo::letter_grade(void) {
	double final_grade;
	if (cp)
	{
		final_grade = grade();
		return cp->letter_grade(final_grade);
	}
	else
		throw std::runtime_error("uninitialized Student");
}