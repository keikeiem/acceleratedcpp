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

	// compare_Core_handles 를 정의해야함
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

// 14.2 레퍼런스 카운트되는 핸들
int Chapter14Example2() {
	// Handle(Core) 대입연산자가 실행되면서
	// Core 객체의 추가적인 복사본을 생성하고 소멸시키는 과정이 포함되는데
	// 이러한 복사작업을 어떻게 피할 수 있을까?

	// 객체를 복사하거나 대입하면, 필요 이상으로 내부 데이터들을 복사한다.
	// Handle은 바인딩되는 객체를 매번 복사하게 된다.

	// 이러한 복사를 수행할지 말지를 직접 선택할 수 있으면 좋다.

	//std::vector<ReferenceHandle<Core>> students;

	return 0;
}

bool compare_Core_Ptr(const StudentInfoPtr& a, const StudentInfoPtr& b)
{
	return (a.name() < b.name());
}

// 14.3 데이터를 공유해야할 때가 언제인지 알려주는 핸들
int Chapter14Example3() {
	std::vector<StudentInfoPtr> students;
	StudentInfoPtr record;
	std::string::size_type max_length = 0;

	while (record.read(std::cin)) {
		max_length = std::max(max_length, record.name().size());
		students.push_back(record);
	}

	// compare_Core_handles 를 정의해야함
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

	// s2.read 가 실행되며 s2는 초기화된다. s1은 안 바뀜
	return 0;
}

int Chapter14Example4() {
	// MyStringExt 객체에 Ptr을 적용해보기

}

#endif // !MAIN_H

