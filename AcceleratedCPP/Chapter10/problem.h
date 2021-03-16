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

	// Problem5 :: iterator 贸府窍扁?
	// 沥规氢?
	for (StringList::iterator iter = string_list.begin(); iter != string_list.end(); ++iter)
	{
		std::cout << (iter) << " | " << (*iter) << std::endl;
	}
	// 开规氢?
	for (StringList::iterator iter = (string_list.end() - 1); iter != (string_list.begin() - 1); --iter)
	{
		std::cout << (iter) << " | " << (*iter) << std::endl;
	}

	return 0;
}



#endif