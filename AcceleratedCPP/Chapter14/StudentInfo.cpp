#include "StudentInfo.h"

StudentInfo::StudentInfo(const StudentInfo& s) : cp(0)
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
	//delete cp;
	// new Core(in)이 실행되면서 Core*를 객체를 얻고
	// Handle(T*) 생성자를 통해 Hadle(Core)로 변환된다
	// Handle의 대입 연산자를 통해 cp에 대입되므로
	// 별도로 delete를 할 필요가 없다

	char ch;
	in >> ch;

	if (ch == 'U')
		cp = new Core(in);
	else
		cp = new Grad(in);

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