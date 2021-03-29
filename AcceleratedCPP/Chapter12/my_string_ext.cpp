#include "my_string_ext.h"

// 
MyStringExt::MyStringExt(void) {
	create(0, '\0');
}

MyStringExt::MyStringExt(const MyStringExt& val)
{
	create(val.data_, val.data_ + val.size());
}

MyStringExt::MyStringExt(size_type n, char val)
{
	create(n, val);
}

MyStringExt::MyStringExt(const char* cp)
{
	create(cp, (cp + strlen(cp)));
}

MyStringExt::~MyStringExt(void)
{
	uncreate();
}

MyStringExt& MyStringExt::operator=(const MyStringExt& rhs)
{
	if (&rhs != this)
	{
		uncreate();
		create(rhs.data_, rhs.data_ + rhs.size());
	}
	return (*this);
}

size_t MyStringExt::size(void) const
{
	return (length_ - 1);
}

// private method
void MyStringExt::create(size_t n, char val)
{
	data_ = new char[n + 1];
	length_ = (n + 1);
	memcpy(data_, &val, n);
	data_[n] = '\0';
}

void MyStringExt::uncreate(void)
{
	if (length_ != 0)
	{
		delete[] data_;
	}
	length_ = 0;
}

void MyStringExt::append(const MyStringExt& val)
{
	append(val.data(), val.size());
}

void MyStringExt::append(const char* cp, const size_t n)
{
	// 현재의 뒤에 cp를 붙이는 케이스
	size_t old_length = size();
	char* origin = new char[old_length];
	memcpy(origin, data_, old_length);
	// copy 에다가 자기 자신의 원본을 복사하자
	// 그리고 초기화
	uncreate();

	length_ = old_length + n + 1;
	data_ = new char[length_];
	memcpy(data_, origin, old_length);
	// data_[old_length] 가 cp를 붙이는 시작 위치
	memcpy(&data_[old_length], cp, n);
	data_[length_ - 1] = '\0';

	delete[] origin;
}

void MyStringExt::prepend(const char* cp, const size_t n)
{
	// 현재의 앞에 cp를 붙이는 케이스
	size_t old_length = size();
	char* origin = new char[old_length];
	memcpy(origin, data_, old_length);
	// copy 에다가 자기 자신의 원본을 복사하자
	// 그리고 초기화
	uncreate();

	length_ = old_length + n + 1;
	data_ = new char[length_];
	memcpy(data_, cp, n);
	// data[n]이 origin을 붙이는 시작 위치
	memcpy(&data_[n], origin, old_length);
	data_[length_ - 1] = '\0';

	delete[] origin;
}

void MyStringExt::append(const char val)
{
	// char 한 자이기 때문에
	// size_t 에 해당하는 매개변수를 1로 입력한다.
	append(&val, 1);
}

size_t MyStringExt::copy_characters(char* dest, size_t n) const
{
	size_t i;
	for (i = 0; i < n && i < size(); ++i)
	{
		dest[i] = data_[i];
	}
	return i;
}

MyStringExt operator+(const MyStringExt& lhs, const MyStringExt& rhs)
{
	MyStringExt result = lhs;
	result += rhs;
	return result;
}
MyStringExt operator+(const MyStringExt& lhs, const char* rhs)
{
	MyStringExt result = lhs;
	result += rhs;
	return result;
}
MyStringExt operator+(const char* lhs, const MyStringExt& rhs)
{
	MyStringExt result = rhs;
	result.prepend(lhs, strlen(lhs));
	return result;
}

std::istream& operator>>(std::istream& in, MyStringExt& val)
{
	val.uncreate();
	val.create(0, '\0'); // 0번 자리에 널 자리 \0을 넣는다.

	char c;
	while (in.get(c) && isspace(c));
	// 띄어쓰기가 나오기 전까지 읽어들인다
	
	if (in)
	{
		// 공백이 나오기 전까지 읽어들이고 append한다
		do val.append(c);
		while (in.get(c) && !isspace(c));

		if (in)
			in.unget();
	}
	return in;
}

std::ostream& operator<<(std::ostream& os, const MyStringExt& val)
{
	// 이게 뭐여 ???????????
	// std::ostream_iterator<char>(os)
	std::copy(val.begin(), val.end(), std::ostream_iterator<char>(os));
	return (os);
}

std::istream& get_line(std::istream& in, MyStringExt& val)
{
	val.uncreate();
	val.create(0, '\0'); // 0번 자리에 널 자리 \0을 넣는다.

	char c;
	// 띄어쓰기가 나오기 전까지 읽어들인다

	if (in)
	{
		// 공백이 나오기 전까지 읽어들이고 append한다
		while (in.get(c) && c != '\n')
			val.append(c);
	}
	return in;
}