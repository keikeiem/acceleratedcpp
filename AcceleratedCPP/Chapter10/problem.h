#ifndef PROBLEM_H
#define PROBLEM_H

#include <string>

int Chapter10Problem4() {
	StringList string_list;
	string_list.PushBack("S");
	string_list.PushBack("A");
	string_list.PushBack("D");
	/*string_list.PopBack();
	string_list.Print();*/

	// Problem5 :: iterator ó���ϱ�?
	// ������?
	for (StringList::iterator iter = string_list.begin(); iter != string_list.end(); ++iter)
	{
		std::cout << (iter) << " | " << (*iter) << std::endl;
	}
	// ������?
	for (StringList::iterator iter = (string_list.end() - 1); iter != (string_list.begin() - 1); --iter)
	{
		std::cout << (iter) << " | " << (*iter) << std::endl;
	}

	return 0;
}

bool space(char c) {
	return (isspace(c));
}

bool not_space(char c) {
	return !(isspace(c));
}

void split(StringList& ret, const std::string& s) {
	std::string::const_iterator prev = s.begin();
	
	while (prev != s.end()) {
		prev = std::find_if(prev, s.end(), not_space);
		std::string::const_iterator next = std::find_if(prev, s.end(), space);

		if (prev != s.end())
		{
			ret.PushBack(std::string(prev, next));
		}
		prev = next;
	}
}

StringList * split(const std::string& s) {
	StringList * ret = new StringList();
	std::string::const_iterator prev = s.begin();

	while (prev != s.end()) {
		prev = std::find_if(prev, s.end(), not_space);
		std::string::const_iterator next = std::find_if(prev, s.end(), space);

		if (prev != s.end())
		{
			ret->PushBack(std::string(prev, next));
		}
		prev = next;
	}
	return (ret);
}

int Chapter10Problem6() {
	std::string str = "Notorious Biggie Small";

	// result�� ���� split�� void �Լ����� Push�ϱ�
	StringList result;
	split(result, str);
	result.Print();

	// �����ͷ� ������ �޾Ƽ� Print
	std::string str2 = "Love Takes Time";
	StringList * ret = split(str2);
	ret->Print();

	return 0;
}

#endif