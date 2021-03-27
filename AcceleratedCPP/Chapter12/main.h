#ifndef MAIN_H
#define MAIN_H

#include "my_string.h"

int Chapter12Example1() {
	MyString string1 = "string1";

	for (MyString::size_type i = 0; i < string1.size(); ++i)
	{
		std::cout << string1[i];
	}
	std::cout << std::endl;

	MyString string2("string2");

	std::cout << string2 << std::endl;

	MyString string3;
	std::cin >> string3;
	std::cout << string3 << std::endl;


	std::cout << "result: " << (string1 + string2 + string3) << std::endl;

	return 0;
}

int Chapter12Example3() {
	// 문자열 연산에 대한 이해
	MyString name = "kimkm";
	MyString greeting = "Hello, " + name + "!";
	// "Hello, " 와 "!" 에 대해서
	// MyString 클래스에서 const char*를 매개변수로 갖는
	// 생성자를 통해 각각의 문자열이 MyString 타입으로 선언되고
	// 이후에 + 연산자로 합쳐지게 된다
	std::cout << greeting << std::endl;

	return 0;
}

#endif