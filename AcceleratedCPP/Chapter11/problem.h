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
	// string, double은 그냥 복사할거 같고
	// hw는 ?? vector copy를 하는거 같은데

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
	// 모든 멤버를 다 초기화시키는데?
	// name = "";
	//
	double a = 100;
	std::cout << &a << std::endl;
	info->show();

	return 0;
}

int Chapter11Problem6() {
	// Vec에서 요소를 제거하는 함수를 만들자
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
	// Vec을 사용하여 Student_info 프로그램 만들기
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
	// 3개를 push했을 때 전체 영역이 4개인지 확인
	std::cout << test.end_limit() << " | " << test.begin() << std::endl;

	// bool 체크 true
	std::cout << "empty: " << test.empty() << std::endl;

	// 가운데 꺼를 지워보자
	test.erase(test.begin() + 1);
	
	// i번째 요소를 가져오는 메서드
	std::cout << test[1] << std::endl;

	test.clear();
	std::cout << test.end_limit() << " | " << test.begin() << std::endl;
	std::cout << test.end() << " | " << test.begin() << std::endl;

	// bool 체크 true
	std::cout << "empty: " << test.empty() << std::endl;

	return 0;
}

#endif
