#ifndef MY_STRING_EXT_H
#define MY_STRING_EXT_H

#include <iostream>
#include <memory>

// 표준 라이브러리 스트링이 char의 포인터 형태인 것을 생각하며
// Vec 클래스와 char를 조합하여 MyStringExt 클래스를 만들자
class MyStringExt {
	// friend는 해당 메서드 안에서
	// private 변수의 접근이 가능하도록 한다 (쓰기권한 포함)
	friend std::istream& operator>>(std::istream& is, MyStringExt& val);
	friend MyStringExt operator+(const char*, const MyStringExt&);

	// 이런 식으로 클래스 맨 앞에서 선언함
public:
	typedef size_t size_type;
	typedef char* iterator;
	typedef const char* const_iterator;

	// 디폴트 생성자
	MyStringExt(void);

	MyStringExt(const MyStringExt&);

	MyStringExt(size_type, char);

	MyStringExt(const char* cp);

	template <class In>
	MyStringExt(In b, In e) { create(b, e); }

	~MyStringExt(void);

	MyStringExt& operator=(const MyStringExt& rhs);

	char& operator[](size_t i) { return data_[i]; }
	const char& operator[](size_t i) const { return data_[i]; }

	MyStringExt& operator+=(const char * cp)
	{
		append(cp, strlen(cp));
		return (*this);
	}

	MyStringExt& operator+=(const MyStringExt& val)
	{
		append(val);
		return (*this);
	}

	size_t size(void) const;

	// 널 종료인 char 배열을 리턴
	const char* c_str(void) const { return data_; }

	// 널 종료가 아닌 char 배열을 리턴
	const char * data(void) const { return data_; };

	// MyString 데이터를 size_t 만큼 char* 에 복사한다
	size_t copy(char*, size_t);

	iterator begin(void) { return data_; }
	iterator end(void) { return (data_ + size()); }
	const_iterator begin(void) const { return data_; }
	const_iterator end(void) const { return (data_ + size()); }

private:
	char* data_;
	size_t length_;

	void create(size_t, char);
	void uncreate(void);

	// iterator 인것
	template <class In>
	void create(const In& i, const In& j)
	{
		length_ = (j - i) + 1;
		data_ = new char[length_];
		memcpy(data_, i, (length_ - 1));
		data_[(length_ - 1)] = '\0';
	}

	void append(const MyStringExt&);
	void append(const char*, const size_t);
	void prepend(const char*, const size_t);
	void append(const char);

	size_t copy_characters(char*, size_t) const;

	void* is_not_empty() const {
		return (size() > 0) ? data_ : 0;
	}
};

//std::istream& operator>>(std::istream&, MyStringExt&);
std::ostream& operator<<(std::ostream&, const MyStringExt&);

std::istream& get_line(std::istream&, MyStringExt&);

MyStringExt operator+(const MyStringExt&, const MyStringExt&);
MyStringExt operator+(const MyStringExt&, const char *);
//MyStringExt operator+(const char *, const MyStringExt&);

inline bool operator==(const MyStringExt& lhs, const MyStringExt& rhs)
{
	return (strcmp(lhs.data(), rhs.data()) == 0);
}
inline bool operator!=(const MyStringExt& lhs, const MyStringExt& rhs)
{
	return (strcmp(lhs.data(), rhs.data()) != 0);
}
inline bool operator<(const MyStringExt& lhs, const MyStringExt& rhs)
{
	return (strcmp(lhs.data(), rhs.data()) < 0);
}

inline bool operator<=(const MyStringExt& lhs, const MyStringExt& rhs)
{
	return (strcmp(lhs.data(), rhs.data()) <= 0);
}

inline bool operator>(const MyStringExt& lhs, const MyStringExt& rhs)
{
	return (strcmp(lhs.data(), rhs.data()) > 0);
}

inline bool operator>=(const MyStringExt& lhs, const MyStringExt& rhs)
{
	return (strcmp(lhs.data(), rhs.data()) >= 0);
}

// 입출력 연산자를 추가해야한다.
// cin >> s는
// cin.operator>>(s) 를 의미한다

//비멤버함수로서 정의한다
// 여기서는 입력 연산자를 단순한 버전으로 구현한다
// 클래스 내에 friend 로 다시 정의

//std::istream& operator>>(std::istream& is, MyStringExt& str)
//{
//	// 기존의 값을 삭제한다.
//	str.data_.clear();
//
//	// 맨 앞의 공백문자를 읽고 그 후는 무시한다.
//	char c;
//	while (is.get(c) && isspace(c));
//	// istream.get이 다음번 character를 리턴하기때문에
//	// while문이 무한루프에 빠지지 않는다
//
//	if (is) {
//		do str.data_.push_back(c);
//		while (is.get(c) && !isspace(c));
//
//		// 공백문자를 읽으면, 스트림의 뒤에 집어넣는다
//		if (is)
//			is.unget();
//	}
//
//	return (is);
//}
#endif