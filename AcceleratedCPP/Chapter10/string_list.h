#ifndef STRING_LIST_H
#define STRING_LIST_H

#include <iostream>
#include <string>

class StringList {
public:
	typedef std::string* iterator;
private:
	std::string* m_array;
	int m_size;
	int m_used;
	iterator iter;
public:
	StringList(void);
	StringList(int size);
	~StringList(void);

	void PopBack(void);
	void PushBack(const std::string& set);
	void Print(void);
	iterator begin(void);
	iterator end(void);
	std::string& operator[](int index);
};

#endif
