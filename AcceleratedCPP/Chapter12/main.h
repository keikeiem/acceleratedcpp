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
	// Vec Ŭ������ ������ ��
	// explicit Vec(size_type n, const T& val = T()) { create(n, val); }
	// �� explicit�� �ƴ϶�� ��� �ɱ�?

	// Case1) �츮�� ����ϴ� ���
	Vec<std::string> test;
	test.push_back("42");
	 Vec<std::string> p = frame(test);

	// Case2) �츮�� ������� ���� ���..
	// 42���� �� ��� �׸� �ѷ��ΰ� �ִ� �׵θ�
	//Vec<std::string> p = frame(42);

	for (Vec<std::string>::size_type i = 0; i != p.size(); ++i)
	{
		std::cout << p[i] << std::endl;
	}

	return 0;
}

int Chapter12Example5() {
	// bool �� void*�� ���� ?
	// void* �� ���Ϲ��� ������, ��ü�� � Ÿ�Կ��� �� �� �ִ� �Լ�
	// istream Ŭ��������
	// operator bool �� �̳��� operaor void * �� �� ������ ������
	return 0;
}

int Chapter12Example6() {
	// ��ȯ �� �޸� ����
	// MyString Ŭ�������� NULL-���� ���ڹ迭���� ��ȯ�� �����ϸ� ���ڴµ�
	// �̷��� ����� �޸� ���� �鿡�� ������ �߻��� �� �ִ�.
	
	// data()�� ���� ������ ���� Vec<char> �����ε�
	// �츮�� �ʿ��� ���� char�� �迭 Ÿ���̴�

	// Ÿ���� �´� �ص� MyString Ŭ������ ĸ��ȭ�� �����ϰ� �Ǹ�
	// �Դٰ� ����ڴ� �� �����͸� ���� ������ string ���� ������ �� �ִ�.

	// ��ü�� �Ҹ�Ǿ��� �� ��ȿ���� �ʴ� �޸𸮸� ����ų ���̴�

	// Q)
	// data�� ���ڿ� ���纻�� ���ο� ������ �Ҵ��ϰ�
	// �� ������ ���� �����͸� �����Ͽ� ����ڰ� ���� �����Ѵٸ�??
	// �ʿ����� ���� ������ �޸𸮸� ���� �����ϸ� �ȵɱ�?
	
	// A)
	// ifstream �����ڿ� string �� s�� �������� ��
	// const char*�� MyString�� ��ȯ��Ű�µ�
	// �̷��� ��ȯ���� s�� ���纻�� ���� ���ο� ������ �Ҵ�������
	// �� ������ ���� �����͸� ����ڴ� �� ���� ���� ������
	// �Ҹ�� �޸𸮸� ������ų ���� ����.
	// �̷� ���� �޸� ���� ���ɼ��� �ִ� ����� ���� �ʴ�.

	// ǥ�� ���̺귯���� string�� �ٸ� ���� ����� ����Ѵ�.
	// string���� char�� ���� �� �ִ� �� ���� ��� �Լ��� �����ϴµ�
	// 1) c_str() 
	//    string�� ������ null���� char �迭�� �����Ѵ�.
	//    string Ŭ������ �����ϰ� �־ ����ڴ� �� �����͸� delete�� �� ����
	// 2) data()
	//    c_str()�� ����ϳ� null���ᰡ �ƴ� char �迭�� �����Ѵ�.
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