#ifndef PROBLEM_H
#define PROBLEM_H

#include "Grad.h"

int Chapter13Problem1() {
	// �������� �̸��� ���� ����� ����ϵ���
	// ������ �����ϱ�
	return 0;
}

int Chapter13Problem2() {
	Core* p1 = new Core;
	Core* p2 = new Core;
	Core s1;
	Grad s2;

	p1->grade(); // Core::grade
	p1->name();  // Core::name

	p2->grade(); // Core::grade
	p2->name();  // Core::name

	s1.grade();  // Core::grade
	s1.name();   // Core::name

	s2.name();   // Core::name
	s2.grade();  // Grad::grade -> Core::grade
	return 0;
}

int Chapter13Problem3() {
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
		// �Ҹ��ڸ� virtual�� �߰��ؼ�
		// Core* �� delete�� �� Grad ��ü����
		// ��� �Ҹ��Ű���� �����Ұ�
		//delete students[i];
		students[i].regrade(10, 20);
	}
	return 0;
}

int Chapter13Problem4() {
	// ������ �������� ǥ���ϴ� �Լ� �߰��ϱ�
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
			std::string letter_grade = students[i].letter_grade();
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade
				<< std::setprecision(prec) << std::endl;
			std::cout << "result: " << letter_grade << std::endl;
		}
		catch (std::domain_error e) {
			std::cout << e.what() << std::endl;
		}
		// �Ҹ��ڸ� virtual�� �߰��ؼ�
		// Core* �� delete�� �� Grad ��ü����
		// ��� �Ҹ��Ű���� �����Ұ�
		//delete students[i];
		students[i].regrade(10, 20);
	}
	return 0;
}

int Chapter13Problem7() {
	// û���� Auditor Ŭ���� �ۼ��ϱ�
	
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
		students[i].show();
		std::cout << students[i].name()
			<< std::string(max_length + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();
			std::string letter_grade = students[i].letter_grade();
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade
				<< std::setprecision(prec) << std::endl;
			std::cout << "result: " << letter_grade << std::endl;
		}
		catch (std::domain_error e) {
			std::cout << e.what() << std::endl;
		}
		// �Ҹ��ڸ� virtual�� �߰��ؼ�
		// Core* �� delete�� �� Grad ��ü����
		// ��� �Ҹ��Ű���� �����Ұ�
		//delete students[i];
		students[i].regrade(10, 20);
	}
	return 0;
}

#endif
