#include "StudentInfoPtr.h"

std::istream& StudentInfoPtr::read(std::istream& in) {
	//delete cp;
	// new Core(in)�� ����Ǹ鼭 Core*�� ��ü�� ���
	// Handle(T*) �����ڸ� ���� Hadle(Core)�� ��ȯ�ȴ�
	// Handle�� ���� �����ڸ� ���� cp�� ���ԵǹǷ�
	// ������ delete�� �� �ʿ䰡 ����

	char ch;
	in >> ch;

	if (ch == 'U')
		cp = new Core(in);
	else
		cp = new Grad(in);

	return in;
}

std::string StudentInfoPtr::letter_grade(void) {
	double final_grade;
	if (cp)
	{
		final_grade = grade();
		return cp->letter_grade(final_grade);
	}
	else
		throw std::runtime_error("uninitialized Student");
}