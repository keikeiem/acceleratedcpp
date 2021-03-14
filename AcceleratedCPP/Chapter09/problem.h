#ifndef PROBLEM_H
#define PROBLEM_H

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

int Chapter9Problem1() {
	vector<Student_info> students;
	Student_info record;
	string::size_type max_length = 0;

	while (record.read_and_compute(cin))
	{
		max_length = std::max(max_length, record.name().size());
		students.push_back(record);
	}
	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::iterator iter = students.begin();
		iter != students.end(); ++iter)
	{
		cout << iter->name() << string(max_length + 1 - iter->name().size(), ' ');
		cout << iter->get_grade() << endl;
	}

	return 0;
}

int Chapter9Problem2() {
	// std::string name(void) const; ��
	// std::string name(void); �� �ٲٸ� � ���� �ٲ���ϴ°�
	// compare �Լ��� const �� ó��
	// const_iterator ��ſ� iterator�� ����ؾ���

	return 0;
}

#endif