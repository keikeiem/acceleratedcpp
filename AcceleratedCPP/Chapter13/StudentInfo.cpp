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

	if (ch == 'U')
		cp = new Core(in);
	else
		cp = new Grad(in);

	return in;
}