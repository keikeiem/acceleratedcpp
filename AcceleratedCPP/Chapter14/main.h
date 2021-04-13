#ifndef MAIN_H
#define MAIN_H

#include <algorithm>
#include <iomanip>
#include <vector>
#include "handle.h"
#include "Grad.h"
#include "ReferenceHandle.h"
#include "Ptr.h"
#include "StudentInfo.h"
#include "StudentInfoPtr.h"

bool compare_Core_handles(const Handle<Core>& a, const Handle<Core>& b)
{
	return (a->name() < b->name());
}

int Chapter14Example1() {
	std::vector<Handle<Core>> students;
	Handle<Core> record;
	char ch;
	std::string::size_type max_length = 0;

	while (std::cin >> ch) {
		if (ch == 'U')
			record = new Core;
		else
			record = new Grad;

		record->read(std::cin);
		max_length = std::max(max_length, record->name().size());
		students.push_back(record);
	}

	// compare_Core_handles �� �����ؾ���
	std::sort(students.begin(), students.end(), compare_Core_handles);

	for (std::vector<Handle<Core>>::size_type i = 0;
		i != students.size(); ++i)
	{
		std::cout << students[i]->name()
			<< std::string(max_length + 1 - students[i]->name().size(), ' ');
		try {
			double final_grade = students[i]->grade();
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade
				<< std::setprecision(prec) << std::endl;
		}
		catch (std::domain_error e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}

bool compare_Core_ref_handles(const ReferenceHandle<Core>& a, const ReferenceHandle<Core>& b)
{
	return (a->name() < b->name());
}

// 14.2 ���۷��� ī��Ʈ�Ǵ� �ڵ�
int Chapter14Example2() {
	// Handle(Core) ���Կ����ڰ� ����Ǹ鼭
	// Core ��ü�� �߰����� ���纻�� �����ϰ� �Ҹ��Ű�� ������ ���ԵǴµ�
	// �̷��� �����۾��� ��� ���� �� ������?

	// ��ü�� �����ϰų� �����ϸ�, �ʿ� �̻����� ���� �����͵��� �����Ѵ�.
	// Handle�� ���ε��Ǵ� ��ü�� �Ź� �����ϰ� �ȴ�.

	// �̷��� ���縦 �������� ������ ���� ������ �� ������ ����.

	//std::vector<ReferenceHandle<Core>> students;

	return 0;
}

bool compare_Core_Ptr(const StudentInfoPtr& a, const StudentInfoPtr& b)
{
	return (a.name() < b.name());
}

// 14.3 �����͸� �����ؾ��� ���� �������� �˷��ִ� �ڵ�
int Chapter14Example3() {
	std::vector<StudentInfoPtr> students;
	StudentInfoPtr record;
	std::string::size_type max_length = 0;

	while (record.read(std::cin)) {
		max_length = std::max(max_length, record.name().size());
		students.push_back(record);
	}

	// compare_Core_handles �� �����ؾ���
	std::sort(students.begin(), students.end(), compare_Core_Ptr);

	for (std::vector<StudentInfoPtr>::size_type i = 0;
		i != students.size(); ++i)
	{
		std::cout << students[i].name()
			<< std::string(max_length + 1 - students[i].name().size(), ' ');

		students[i].regrade(80, 100);
		try {
			double final_grade = students[i].grade();
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade
				<< std::setprecision(prec) << std::endl;
		}
		catch (std::domain_error e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}

int Chapter14Example3_2() {
	StudentInfoPtr s1;
	s1.read(std::cin);
	StudentInfoPtr s2 = s1;
	s2.read(std::cin);

	// s2.read �� ����Ǹ� s2�� �ʱ�ȭ�ȴ�. s1�� �� �ٲ�
	return 0;
}

int Chapter14Example4() {
	// MyStringExt ��ü�� Ptr�� �����غ���

}

#endif // !MAIN_H

