#ifndef PROBLEM_H
#define PROBLEM_H

#include "vec.h"
#include "vec_student_info.h"
#include "list.h"

void show_vector(const Vec<double> v) {
	for (Vec<double>::const_iterator it = v.begin();
		it != v.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
}

int Chapter11Problem3() {
	Vec<double> hw;
	hw.push_back(30);
	hw.push_back(20);

	Vec<double> hw2(hw.begin(), hw.end());
	show_vector(hw2);

	Vec<double> hw3(hw);
	show_vector(hw3);

	Vec<double> hw4 = hw;
	show_vector(hw4);

	Student_info info_;
	info_.set_name("kimkm");
	info_.set_test_score(45, 32);
	info_.set_homework(hw);

	info_.show();

	Student_info test = info_;
	// string, double�� �׳� �����Ұ� ����
	// hw�� ?? vector copy�� �ϴ°� ������

	test.set_name("nono");
	test.show();

	return 0;
}

Student_info* get_new_item() {
	Vec<double> hw;
	hw.push_back(30);
	hw.push_back(20);

	Student_info info_;
	info_.set_name("kimkm");
	info_.set_test_score(45, 32);
	info_.set_homework(hw);

	info_.show();

	return (&info_);
}

int Chapter11Problem4() {
	Student_info* info = get_new_item();
	// ��� ����� �� �ʱ�ȭ��Ű�µ�?
	// name = "";
	//
	double a = 100;
	std::cout << &a << std::endl;
	info->show();

	return 0;
}

int Chapter11Problem6() {
	// Vec���� ��Ҹ� �����ϴ� �Լ��� ������
	Vec<double> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.erase(vec.end() - 1);
	show_vector(vec);

	Vec<double> test;
	test.push_back(100);
	test.push_back(50);
	test.push_back(30);
	test.push_back(40);
	
	for (Vec<double>::const_iterator iter = test.begin();
		iter != test.end(); ++iter)
	{
		std::cout << (*iter) << std::endl;
	}

	test.clear();
	std::cout << (test.end_limit() - test.begin()) << std::endl;

	return 0;
}

int Chapter11Problem7() {
	// Vec�� ����Ͽ� Student_info ���α׷� �����
	return 0;
}

void show_list(List<double> list)
{
	for (List<double>::const_iterator iter = list.begin();
		iter != list.end(); ++iter)
	{
		std::cout << (*iter) << std::endl;
	}
}

int Chapter11Problem8() {
	List<double> test;
	test.push_back(100);
	test.push_back(50);
	test.push_back(30);
	// 3���� push���� �� ��ü ������ 4������ Ȯ��
	std::cout << test.end_limit() << " | " << test.begin() << std::endl;

	// bool üũ true
	std::cout << "empty: " << test.empty() << std::endl;

	// ��� ���� ��������
	test.erase(test.begin() + 1);
	
	// i��° ��Ҹ� �������� �޼���
	std::cout << test[1] << std::endl;

	test.clear();
	std::cout << test.end_limit() << " | " << test.begin() << std::endl;
	std::cout << test.end() << " | " << test.begin() << std::endl;

	// bool üũ true
	std::cout << "empty: " << test.empty() << std::endl;

	return 0;
}

#endif
