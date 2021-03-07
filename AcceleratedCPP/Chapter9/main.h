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

	// 데이터 확인용 메서드
	student.show();

	return 0;
}

int Chapter9Example3() {
	// 드디어 class 등장!

	return 0;
}

#endif