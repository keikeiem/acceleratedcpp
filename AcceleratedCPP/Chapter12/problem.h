#ifndef PROBLEM_H
#define PROBLEM_H

#include "my_string_ext.h"

int Chapter12Problem1() {

	// MyStringExt 클래스 설계
	// 직접 저장공간을 관리하는 구현 방식으로
	MyStringExt string = "abcd1234";
	std::cout << (string + "value") << std::endl;

	// Vec은 지정된 배수에 맞춰 공간을 늘린 후 처리하는 방식이라서
	// 직접 공간을 관리하는 것에 비해 메모리 낭비가 심할 수 있다.
	return 0;
}

int Chapter12Problem2() {
	// c_str(), data(), copy(char*, size_t) 함수 작성하기


	return 0;
}

int Chapter12Problem4() {
	// 등호와 부등호 연산자를 정의해보자.
	return 0;
}


#endif // !

