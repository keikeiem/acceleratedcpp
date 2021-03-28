#ifndef MY_STRING_EXT_H
#define MY_STRING_EXT_H

#include <iostream>
#include <memory>

// ǥ�� ���̺귯�� ��Ʈ���� char�� ������ ������ ���� �����ϸ�
// Vec Ŭ������ char�� �����Ͽ� MyStringExt Ŭ������ ������
class MyStringExt {
	// friend�� �ش� �޼��� �ȿ���
	// private ������ ������ �����ϵ��� �Ѵ� (������� ����)
	friend std::istream& operator>>(std::istream& is, MyStringExt& val);
	friend MyStringExt operator+(const char*, const MyStringExt&);

	// �̷� ������ Ŭ���� �� �տ��� ������
public:
	typedef size_t size_type;
	typedef char* iterator;
	typedef const char* const_iterator;

	// ����Ʈ ������
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

	// �� ������ char �迭�� ����
	const char* c_str(void) const { return data_; }

	// �� ���ᰡ �ƴ� char �迭�� ����
	const char * data(void) const { return data_; };

	// MyString �����͸� size_t ��ŭ char* �� �����Ѵ�
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

	// iterator �ΰ�
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

// ����� �����ڸ� �߰��ؾ��Ѵ�.
// cin >> s��
// cin.operator>>(s) �� �ǹ��Ѵ�

//�����Լ��μ� �����Ѵ�
// ���⼭�� �Է� �����ڸ� �ܼ��� �������� �����Ѵ�
// Ŭ���� ���� friend �� �ٽ� ����

//std::istream& operator>>(std::istream& is, MyStringExt& str)
//{
//	// ������ ���� �����Ѵ�.
//	str.data_.clear();
//
//	// �� ���� ���鹮�ڸ� �а� �� �Ĵ� �����Ѵ�.
//	char c;
//	while (is.get(c) && isspace(c));
//	// istream.get�� ������ character�� �����ϱ⶧����
//	// while���� ���ѷ����� ������ �ʴ´�
//
//	if (is) {
//		do str.data_.push_back(c);
//		while (is.get(c) && !isspace(c));
//
//		// ���鹮�ڸ� ������, ��Ʈ���� �ڿ� ����ִ´�
//		if (is)
//			is.unget();
//	}
//
//	return (is);
//}
#endif