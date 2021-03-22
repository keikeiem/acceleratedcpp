#ifndef PROBLEM_H
#define PROBLEM_H

#include "student_info.h"

void show_vector(const vector<double> v) {
	for (vector<double>::const_iterator it = v.begin();
		it != v.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
}

int Chapter11Problem3() {
	vector<double> hw;
	hw.push_back(30);
	hw.push_back(20);

	vector<double> hw2(hw.begin(), hw.end());
	show_vector(hw2);

	vector<double> hw3(hw);
	show_vector(hw3);

	vector<double> hw4 = hw;
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
	vector<double> hw;
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
	vector<double> vec;
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

#endif
