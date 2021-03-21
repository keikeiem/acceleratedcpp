#ifndef MAIN_H
#define MAIN_H

#include "student_info.h"


// Chapter11Example2
//template <class T> class Vec {
//public:
//	// �⺻ ������
//	Vec() { create(); }
//	// n�� ���� �ʱ� �����͸� �ִ� ������
//	// explicit�� � Ű�����ΰ�????
//	// >> ������ �����ڸ� ���� ȣ���� ������ �����Ϸ���
//	// �� �����ڸ� ����ϰ� �ȴ�
//	explicit Vec(size_type n, const T& val = T()) { create(n, val); }
//
//	typedef T* iterator;
//	typedef const T* const_iterator;
//	typedef size_t size_type;
//	typedef T value_type;
//	// ���� ��� Vec<int> �� �ϸ�
//
//	size_type size() { return (limit - data); }
//	T& operator[](size_type i) { return data[i]; }
//	const T& operator[] (size_type i) const { return data[i]; }
//
//	iterator begin() { return data; }
//	iterator end() { return limit; }
//	const_iterator begin() const { return data; }
//	const_iterator end() const { return limit; }
//
//private:
//	//T* data; // ù ��° �������� ptr
//	//T* limit; // ������ ������ ������ ptr
//	// typedef�� �����Ƿ� iterator�� �ٲ���
//	iterator data;
//	iterator limit;
//};



// Chapter11
// Example3 Copy ó���ϱ�
template <class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;

	// �⺻ ������
	Vec() { create(); }
	// n�� ���� �ʱ� �����͸� �ִ� ������
	// explicit�� � Ű�����ΰ�????
	// >> ������ �����ڸ� ���� ȣ���� ������ �����Ϸ���
	// �� �����ڸ� ����ϰ� �ȴ�
	explicit Vec(size_type n, const T& val = T()) { create(n, val); }
	// 11.3.1 ���� ������
	// ��Ұ� �������̱⶧���� �Ϲ����� ����δ�
	// �����͸� ���簡 �Ǵϱ�... ���� ���� �ٲ��
	// �� �� �ٲ�� �ȴ�....
	Vec(const Vec& v) {
		create(v.begin(), v.end());
	};
	// create �Լ��� v.begin ���� v.end�� ����(?)�ϴ� �����ε�


	// 11.3.2 ���� ������
	Vec<T>& Vec<T>::operator=(const Vec& rhs) {
		// ��ȣ�� ������ ���� �ڱ� �ڽ����� üũ�ؾ���.
		if (&rhs != this) {
			// ���� �������� (*this)�� �Ҵ�� �����͸� ��ȯ�ؾ���.
			uncreate();

			create(rhs.begin(), rhs.end());
		}
		// �ڱ� �ڽ��� ���� ������ ���� ���� �ٷ� �����ϸ� �ȴ�.
		return (*this);
	};

	// 11.3.3 ���԰� �ʱ�ȭ�� �ٸ���
	// �ϴ� Chapter11Example3()�� �ڼ��� ���

	size_type size() { return (limit - data); }
	T& operator[](size_type i) { return data[i]; }
	const T& operator[] (size_type i) const { return data[i]; }

	iterator begin() { return data; }
	iterator end() { return limit; }
	const_iterator begin() const { return data; }
	const_iterator end() const { return limit; }

	void create() {}
	void uncreate() {}


private:
	//T* data; // ù ��° �������� ptr
	//T* limit; // ������ ������ ������ ptr
	// typedef�� �����Ƿ� iterator�� �ٲ���
	iterator data;
	iterator limit;
};

int Chapter11Example3() {
	// 11.3.3 ���԰� �ʱ�ȭ�� �ٸ���
	// ��ȣ(=) �����ڴ� ��� �����ϴ°�?
	// <�ʱ�ȭ>
	// ���� ���� ��
	// �Լ� ���� ��, �Լ� �Ű������� ����
	// �Լ��κ��� ���� ��, �Լ��� ���� ���� ����
	// ������ �ʱ� ������(? initializer)

	std::string strA = "abcd"; // �ʱ�ȭ
	std::string spaces(strA.size(), 'X'); // �ʱ�ȭ
	std::string test(10, 'A');
	std::string y; // �ʱ�ȭ
	y = strA; // ����

	// �׷��� �̰� ����?
	std::string x = y;

	std::cout << spaces << " | " << test << std::endl;
	std::cout << x << std::endl;

	return 0;
}

#endif