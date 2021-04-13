#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include "Vec.h"
#include "Ptr.h"

// ǥ�� ���̺귯�� ��Ʈ���� char�� ������ ������ ���� �����ϸ�
// Vec Ŭ������ char�� �����Ͽ� MyString Ŭ������ ������
class MyString {
	// friend�� �ش� �޼��� �ȿ���
	// private ������ ������ �����ϵ��� �Ѵ� (������� ����)
	friend std::istream& operator>>(std::istream& is, MyString& str);
	// �̷� ������ Ŭ���� �� �տ��� ������
public:

	typedef Vec<char>::size_type size_type;
	size_type size(void) const { return data->size(); }

	// ����Ʈ ������
	MyString() {};

	MyString(size_type n, char c) : data(new Vec<char>(n, c)) { }

	MyString(const char* cp) {
		std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
	}

	template <class In>
	MyString(In b, In e) {
		std::copy(b, e, std::back_inserter(data));
	}

	char& operator[](size_type i) { return (*data)[i]; }
	const char& operator[](size_type i) const { return (*data)[i]; }

	// �̷� ������ 
	// �б� ���Ѹ� ������ �������δ� istream operator��
	// ����� �� ����.
	Vec<char> get_data(void) { return (*data); }

	MyString& operator+=(const MyString& s)
	{
		data.make_unique();

		std::copy(s.data->begin(), s.data->end(), std::back_inserter(data));
		return (*this);
	}

private:
	Ptr<Vec<char>> data;
};

// ����� �����ڸ� �߰��ؾ��Ѵ�.
// cin >> s��
// cin.operator>>(s) �� �ǹ��Ѵ�

//�����Լ��μ� �����Ѵ�
// ���⼭�� �Է� �����ڸ� �ܼ��� �������� �����Ѵ�
// Ŭ���� ���� friend �� �ٽ� ����
std::istream& operator>>(std::istream& is, MyString& str)
{
	// ������ ���� �����Ѵ�.
	str.data->clear();

	// �� ���� ���鹮�ڸ� �а� �� �Ĵ� �����Ѵ�.
	char c;
	while (is.get(c) && isspace(c));
	// istream.get�� ������ character�� �����ϱ⶧����
	// while���� ���ѷ����� ������ �ʴ´�

	if (is) {
		do str.data->push_back(c);
		while (is.get(c) && !isspace(c));

		// ���鹮�ڸ� ������, ��Ʈ���� �ڿ� ����ִ´�
		if (is)
			is.unget();
	}

	return (is);
}

// ��� �����ڴ� �ܼ��ϴ�. ostream�� str ���� �־��ְ�
// �ش� ostream�� �����ϸ� �ȴ�.
std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	for (MyString::size_type i = 0; i < str.size(); ++i)
		os << str[i];
	return os;
}

MyString operator+(const MyString& a, const MyString& b)
{
	MyString r = a;
	r += b;
	return (r);
}


#endif