#ifndef PROBLEM_H
#define PROBLEM_H

#include "my_string_ext.h"

int Chapter12Question1() {
	std::string test;
	std::cin >> test;
	std::cout << test << std::endl;
	// std::cin.unget(); 메서드에 대해서..
	// 버퍼에 다시 넣는다는게 어떤 의미일까??
	std::cin.unget();
	std::cout << test << std::endl;

	return 0;
}

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

int Chapter12Problem3() {
	// 관계형 연산자를 정의해보자
	// <cstring>에 있는 strcmp를 사용해야한다.
	// strcmp란?
	// 앞에서부터 문자열을 아스키코드로 비교한다.
	// 다른 문자가 나왔을때 -1 또는 1의 값이 결정되고
	// 두 문자열이 동일하면 0을 리턴한다.
	// strcmp('ABCD', 'ABDC') = 1
	// strcmp('ABDD', 'ABDC') = -1
	// strcmp('ABCD', 'ABCD') = 0

	return 0;
}

int Chapter12Problem4() {
	// 등호와 부등호 연산자를 정의해보자.

	return 0;
}

int Chapter12Problem6() {
	MyStringExt str1 = "test";
	MyStringExt str2 = "";

	if (str1.empty())
		std::cout << "str1 is_empty" << std::endl;
	else
		std::cout << "str1 non-empty" << std::endl;

	if (str2.empty())
		std::cout << "str2 is_empty" << std::endl;
	else
		std::cout << "str2 non-empty" << std::endl;

	return 0;
}

int Chapter12Problem7() {
	MyStringExt str1;
	std::cin >> str1;

	for (MyStringExt::const_iterator iter = str1.begin(); iter != str1.end(); ++iter)
	{
		std::cout << (*iter) << " ";
	}
	std::cout << std::endl;

	return 0;
}

int Chapter12Problem8() {
	// 줄 단위로 문자열을 얻는 get_line 함수 만들기
	Vec<MyStringExt> vec;
	MyStringExt input;
	while (get_line(std::cin, input))
	{
		vec.push_back(input);
	}

	for (Vec<MyStringExt>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		std::cout << (*iter) << std::endl;
	}
	
	return 0;
}


#endif // !

