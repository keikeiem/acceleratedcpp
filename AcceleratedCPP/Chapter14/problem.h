#ifndef PROBLEM_H
#define PROBLEM_H

#include "Ptr.h"
#include "Core.h"
#include "StudentInfo.h"

bool compare_Core_Ptr(const Ptr<Core>& a, const Ptr<Core>& b)
{
	return (a->name() < b->name());
}

int Chapter14Problem1() {
	// Ptr<Core>에 대해 동작하는 비교 연산을 구현하기

	std::vector<Ptr<Core>> testVec;
	Ptr<Core> record1 = new Core;
	Ptr<Core> record2 = new Core;

	record1->read(std::cin);
	testVec.push_back(record1);
	record2->read(std::cin);
	testVec.push_back(record2);

	std::sort(testVec.begin(), testVec.end(), compare_Core_Ptr);

	for (std::vector<Ptr<Core>>::const_iterator iter = testVec.begin();
		iter != testVec.end(); ++iter)
	{
		std::cout << (*iter)->name() << std::endl;
	}

	return 0;
}

#endif