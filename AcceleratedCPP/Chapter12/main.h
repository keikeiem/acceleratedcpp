#ifndef MAIN_H
#define MAIN_H

#include "my_string.h"
#include "my_string_ext.h"

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

std::string::size_type width(const Vec<std::string>& v)
{
	std::string::size_type max_length = 0;
	for (Vec<std::string>::size_type i = 0; i != v.size(); ++i) {
		max_length = std::max(max_length, v[i].size());
	}
	return (max_length);
}
Vec<std::string> frame(const Vec<std::string>& v)
{
	Vec<std::string> ret;
	std::string::size_type max_length = width(v);
	std::string border(max_length + 4, ' *');

	ret.push_back(border);
	// draw boundary using asterisk and empty space ...
	for (Vec<std::string>::size_type i = 0; i != v.size(); ++i) {
		ret.push_back("* " + v[i] +
			std::string(max_length - v[i].size(), ' ') + " *");
	}
	ret.push_back(border);

	return ret;
}

int Chapter12Example4() {
	// Vec 클래스의 생성자 중
	// explicit Vec(size_type n, const T& val = T()) { create(n, val); }
	// 이 explicit이 아니라면 어떻게 될까?

	// Case1) 우리가 기대하는 결과
	Vec<std::string> test;
	test.push_back("42");
	 Vec<std::string> p = frame(test);

	// Case2) 우리가 기대하지 않을 결과..
	// 42개의 빈 행과 그를 둘러싸고 있는 테두리
	//Vec<std::string> p = frame(42);

	for (Vec<std::string>::size_type i = 0; i != p.size(); ++i)
	{
		std::cout << p[i] << std::endl;
	}

	return 0;
}

int Chapter12Example5() {
	// bool 과 void*의 차이 ?
	// void* 는 유니버셜 포인터, 객체의 어떤 타입에든 쓸 수 있는 함수
	// istream 클래스에서
	// operator bool 아 이나리 operaor void * 로 쓴 이유가 있을것
	return 0;
}

int Chapter12Example6() {
	// 변환 및 메모리 관리
	// MyString 클래스에서 NULL-종료 문자배열로의 변환을 제공하면 좋겠는데
	// 이러한 방식은 메모리 관리 면에서 문제가 발생할 수 있다.
	
	// data()를 통해 리턴한 값은 Vec<char> 형식인데
	// 우리가 필요한 것은 char의 배열 타입이다

	// 타입이 맞다 해도 MyString 클래스는 캡슐화를 위반하게 되며
	// 게다가 사용자는 이 포인터를 통해 원래의 string 값을 변경할 수 있다.

	// 객체가 소멸되었을 때 유효하지 않는 메모리를 가리킬 것이다

	// Q)
	// data의 문자열 복사본을 새로운 공간에 할당하고
	// 이 공간에 대한 포인터를 리턴하여 사용자가 직접 관리한다면??
	// 필요하지 않은 시점에 메모리를 직접 해제하면 안될까?
	
	// A)
	// ifstream 생성자에 string 값 s를 전달했을 때
	// const char*로 MyString을 변환시키는데
	// 이러한 변환으로 s의 복사본을 담을 새로운 공간을 할당하지만
	// 이 공간에 대한 포인터를 사용자는 알 수가 없기 때문에
	// 소멸시 메모리를 해제시킬 수가 없다.
	// 이런 식의 메모리 누수 가능성이 있는 설계는 좋지 않다.

	// 표준 라이브러리의 string은 다른 접근 방식을 사용한다.
	// string에서 char를 얻을 수 있는 세 가지 멤버 함수를 제공하는데
	// 1) c_str() 
	//    string의 내용을 null종료 char 배열에 복사한다.
	//    string 클래스가 소유하고 있어서 사용자는 그 포인터를 delete할 수 없다
	// 2) data()
	//    c_str()과 비슷하나 null종료가 아닌 char 배열을 리턴한다.
	// 3) copy()

	std::string test = "test is best";

	//test.c_str();
	//test.data();
	size_t copy_size = 3;
	char test_c[10];

	test.copy(test_c, copy_size);
	std::cout << std::strlen(test_c) << std::endl;;
	for (size_t i = 0; i != copy_size; ++i)
	{
		std::cout << test_c[i];
	}
	std::cout << std::endl;	

	return 0;
}

#endif