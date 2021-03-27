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
	// ���ڿ� ���꿡 ���� ����
	MyString name = "kimkm";
	MyString greeting = "Hello, " + name + "!";
	// "Hello, " �� "!" �� ���ؼ�
	// MyString Ŭ�������� const char*�� �Ű������� ����
	// �����ڸ� ���� ������ ���ڿ��� MyString Ÿ������ ����ǰ�
	// ���Ŀ� + �����ڷ� �������� �ȴ�
	std::cout << greeting << std::endl;

	return 0;
}

#endif