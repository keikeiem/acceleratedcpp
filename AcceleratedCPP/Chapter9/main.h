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

int Chapter9Example2() {
	// 클래스의 생성자
	vector<Student_info> students;
	Student_info record;
	string::size_type max_length = 0;

	while (record.read(cin))
	{
		max_length = std::max(max_length, record.name().size());
		students.push_back(record);
	}

	// 이름순 정렬
	sort(students.begin(), students.end(), compare);
	for (vector<Student_info>::iterator iter = students.begin();
		iter != students.end(); ++iter)
	{
		cout << iter->name() << string(max_length + 1 - iter->name().size(), ' ');

		try {
			double final_grade = iter->grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}

#endif