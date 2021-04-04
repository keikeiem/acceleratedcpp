#ifndef MAIN_H
#define MAIN_H

#include <algorithm>
#include <iomanip>
#include "StudentInfo.h"

int Chapter13Example1() {
	Grad grad(std::cin);
	std::cout << grad.name() << std::endl;

	return 0;
}

bool compare(const Core& c1, const Core& c2) {
	return (c1.name() < c2.name());
}

bool compare_grade(const Core& c1, const Core& c2) {
	return (c1.grade() < c2.grade());
}

int Chapter13Example2() {
	Grad g1("Kim");
	Grad g2("Kang");

	Core c1("Park");
	Core c2("Son");

	std::cout << g1.name() << " vs " << g2.name() << ": " << compare(g1, g2) << std::endl;
	std::cout << c1.name() << " vs " << c2.name() << ": " << compare(c1, c2) << std::endl;
	std::cout << c1.name() << " vs " << g2.name() << ": " << compare(c1, g2) << std::endl;

	return 0;
}

int Chapter13Example3() {
	std::vector<Core> students;
	Core record;
	std::string::size_type max_length = 0;

	while (record.read(std::cin))
	{
		max_length = std::max(max_length, record.name().size());
		students.push_back(record);
	}

	std::sort(students.begin(), students.end(), compare);

	for (std::vector<Core>::size_type i = 0; i != students.size(); ++i)
	{
		std::cout << students[i].name()
			<< std::string(max_length + 1 - students[i].name().size(), ' ');
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

bool compare_Core_ptrs(const Core* cp1, const Core* cp2) {
	return compare(*cp1, *cp2);
}

int Chapter13Example5() {
	std::vector<StudentInfo> students;
	StudentInfo record;
	std::string::size_type max_length = 0;

	while (record.read(std::cin))
	{
		max_length = std::max(max_length, record.name().size());
		students.push_back(record);
	}

	std::sort(students.begin(), students.end(), StudentInfo::compare);
	for (std::vector<StudentInfo*>::size_type i = 0; i != students.size(); ++i)
	{
		std::cout << students[i].name()
			<< std::string(max_length + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade
				<< std::setprecision(prec) << std::endl;
		}
		catch (std::domain_error e) {
			std::cout << e.what() << std::endl;
		}
		// 소멸자를 virtual로 추가해서
		// Core* 를 delete할 때 Grad 객체에서
		// 어떻게 소멸시키는지 이해할것
		//delete students[i];
		students[i].regrade(10, 20);
	}

	return 0;
}

#endif