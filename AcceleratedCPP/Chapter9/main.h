#ifndef METHOD_H
#define METHOD_H

#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::string;
using std::streamsize;
using std::vector;
using std::domain_error;

using std::list;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
//typedef list<string> Rule;
//typedef list<Rule> Rule_collection;

int Chapter9Example1() {

	Student_info student;
	student.read(cin);

	// ������ Ȯ�ο� �޼���
	student.show();

	return 0;
}

int Chapter9Example3() {
	// ���� class ����!

	return 0;
}

#endif