#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include "Vec.h"
#include "Ptr.h"

// 표준 라이브러리 스트링이 char의 포인터 형태인 것을 생각하며
// Vec 클래스와 char를 조합하여 MyString 클래스를 만들자
class MyString {
	// friend는 해당 메서드 안에서
	// private 변수의 접근이 가능하도록 한다 (쓰기권한 포함)
	friend std::istream& operator>>(std::istream& is, MyString& str);
	// 이런 식으로 클래스 맨 앞에서 선언함
public:

	typedef Vec<char>::size_type size_type;
	size_type size(void) const { return data->size(); }

	// 디폴트 생성자
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

	// 이런 식으로 
	// 읽기 권한만 가능한 접근으로는 istream operator로
	// 기능할 수 없다.
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

// 입출력 연산자를 추가해야한다.
// cin >> s는
// cin.operator>>(s) 를 의미한다

//비멤버함수로서 정의한다
// 여기서는 입력 연산자를 단순한 버전으로 구현한다
// 클래스 내에 friend 로 다시 정의
std::istream& operator>>(std::istream& is, MyString& str)
{
	// 기존의 값을 삭제한다.
	str.data->clear();

	// 맨 앞의 공백문자를 읽고 그 후는 무시한다.
	char c;
	while (is.get(c) && isspace(c));
	// istream.get이 다음번 character를 리턴하기때문에
	// while문이 무한루프에 빠지지 않는다

	if (is) {
		do str.data->push_back(c);
		while (is.get(c) && !isspace(c));

		// 공백문자를 읽으면, 스트림의 뒤에 집어넣는다
		if (is)
			is.unget();
	}

	return (is);
}

// 출력 연산자는 단순하다. ostream에 str 값을 넣어주고
// 해당 ostream을 리턴하면 된다.
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