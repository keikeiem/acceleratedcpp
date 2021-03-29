#ifndef PROBLEM_H
#define PROBLEM_H

#include "my_string_ext.h"

int Chapter12Question1() {
	std::string test;
	std::cin >> test;
	std::cout << test << std::endl;
	// std::cin.unget(); �޼��忡 ���ؼ�..
	// ���ۿ� �ٽ� �ִ´ٴ°� � �ǹ��ϱ�??
	std::cin.unget();
	std::cout << test << std::endl;

	return 0;
}

int Chapter12Problem1() {

	// MyStringExt Ŭ���� ����
	// ���� ��������� �����ϴ� ���� �������
	MyStringExt string = "abcd1234";
	std::cout << (string + "value") << std::endl;

	// Vec�� ������ ����� ���� ������ �ø� �� ó���ϴ� ����̶�
	// ���� ������ �����ϴ� �Ϳ� ���� �޸� ���� ���� �� �ִ�.
	return 0;
}

int Chapter12Problem2() {
	// c_str(), data(), copy(char*, size_t) �Լ� �ۼ��ϱ�
	return 0;
}

int Chapter12Problem3() {
	// ������ �����ڸ� �����غ���
	// <cstring>�� �ִ� strcmp�� ����ؾ��Ѵ�.
	// strcmp��?
	// �տ������� ���ڿ��� �ƽ�Ű�ڵ�� ���Ѵ�.
	// �ٸ� ���ڰ� �������� -1 �Ǵ� 1�� ���� �����ǰ�
	// �� ���ڿ��� �����ϸ� 0�� �����Ѵ�.
	// strcmp('ABCD', 'ABDC') = 1
	// strcmp('ABDD', 'ABDC') = -1
	// strcmp('ABCD', 'ABCD') = 0

	return 0;
}

int Chapter12Problem4() {
	// ��ȣ�� �ε�ȣ �����ڸ� �����غ���.

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
	// �� ������ ���ڿ��� ��� get_line �Լ� �����
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

