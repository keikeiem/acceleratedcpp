#ifndef MAIN_H
#define MAIN_H

//#include <memory>
//#include "student_info.h"
#include "vec.h"
#include "vec_student_info.h"


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



//// Chapter11
//// Example3 Copy ó���ϱ�
//template <class T> class Vec {
//public:
//	typedef T* iterator;
//	typedef const T* const_iterator;
//	typedef size_t size_type;
//	typedef T value_type;
//
//	// �⺻ ������
//	Vec() { create(); }
//	// n�� ���� �ʱ� �����͸� �ִ� ������
//	// explicit�� � Ű�����ΰ�????
//	// >> ������ �����ڸ� ���� ȣ���� ������ �����Ϸ���
//	// �� �����ڸ� ����ϰ� �ȴ�
//	explicit Vec(size_type n, const T& val = T()) { create(n, val); }
//	// 11.3.1 ���� ������
//	// ��Ұ� �������̱⶧���� �Ϲ����� ����δ�
//	// �����͸� ���簡 �Ǵϱ�... ���� ���� �ٲ��
//	// �� �� �ٲ�� �ȴ�....
//	Vec(const Vec& v) {
//		create(v.begin(), v.end());
//	};
//	// create �Լ��� v.begin ���� v.end�� ����(?)�ϴ� �����ε�
//
//	// 11.3.2 ���� ������
//	Vec<T>& Vec<T>::operator=(const Vec& rhs) {
//		// ��ȣ�� ������ ���� �ڱ� �ڽ����� üũ�ؾ���.
//		if (&rhs != this) {
//			// ���� �������� (*this)�� �Ҵ�� �����͸� ��ȯ�ؾ���.
//			uncreate();
//
//			create(rhs.begin(), rhs.end());
//		}
//		// �ڱ� �ڽ��� ���� ������ ���� ���� �ٷ� �����ϸ� �ȴ�.
//		return (*this);
//	};
//
//	// 11.3.3 ���԰� �ʱ�ȭ�� �ٸ���
//	// �ϴ� Chapter11Example3()�� �ڼ��� ���
//
//	// 11.3.4 �Ҹ���(Destructor)
//	// local scope�� ��� �� Ŭ������ �Ҹ��ڸ� �����ϰ� �Ǵµ�
//	// �� �� ������ �����ؾ� �ϴ� �۾����� �޼���� ������ִ°� ����
//	~Vec(void) { uncreate(); }
//
//	// 11.3.5 Default ����
//	// ����Ʈ ������ ���� ��� ������ �� �� �� ���� ������
//	// �پ��� ������(��Ÿ�� ����, �޸� ����)�� �߻��� �� ����
//	// 11.3.6 rule of three?
//	// ���� ������, �Ҹ��� �׸��� ���� �����ڴ� ���α׷����� ��
//	// �� ������ �����δ�. ���� ��� �Ҹ��ڰ� �ʿ��ϴٸ�
//	// ���� �����ڿ� ���� �����ڵ� �ʿ��� ���̴�.
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
//	void create() {}
//	void uncreate() {}
//
//
//private:
//	//T* data; // ù ��° �������� ptr
//	//T* limit; // ������ ������ ������ ptr
//	// typedef�� �����Ƿ� iterator�� �ٲ���
//	iterator data;
//	iterator limit;
//};

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

//// Chapter11
//// Example4 ������ Vec
//template <class T> class Vec {
//public:
//	typedef T* iterator;
//	typedef const T* const_iterator;
//	typedef size_t size_type;
//	typedef T value_type;
//
//	// �⺻ ������
//	Vec() { create(); }
//	// n�� ���� �ʱ� �����͸� �ִ� ������
//	// explicit�� � Ű�����ΰ�????
//	// >> ������ �����ڸ� ���� ȣ���� ������ �����Ϸ���
//	// �� �����ڸ� ����ϰ� �ȴ�
//	explicit Vec(size_type n, const T& val = T()) { create(n, val); }
//	// 11.3.1 ���� ������
//	// ��Ұ� �������̱⶧���� �Ϲ����� ����δ�
//	// �����͸� ���簡 �Ǵϱ�... ���� ���� �ٲ��
//	// �� �� �ٲ�� �ȴ�....
//	Vec(const Vec& v) {
//		create(v.begin(), v.end());
//	};
//	// create �Լ��� v.begin ���� v.end�� ����(?)�ϴ� �����ε�
//
//	// 11.3.2 ���� ������
//	Vec<T>& operator=(const Vec<T>& rhs) {
//		// ��ȣ�� ������ ���� �ڱ� �ڽ����� üũ�ؾ���.
//		if (&rhs != this) {
//			// ���� �������� (*this)�� �Ҵ�� �����͸� ��ȯ�ؾ���.
//			uncreate();
//
//			create(rhs.begin(), rhs.end());
//		}
//		// �ڱ� �ڽ��� ���� ������ ���� ���� �ٷ� �����ϸ� �ȴ�.
//		return (*this);
//	};
//
//	// 11.3.3 ���԰� �ʱ�ȭ�� �ٸ���
//	// �ϴ� Chapter11Example3()�� �ڼ��� ���
//
//	// 11.3.4 �Ҹ���(Destructor)
//	// local scope�� ��� �� Ŭ������ �Ҹ��ڸ� �����ϰ� �Ǵµ�
//	// �� �� ������ �����ؾ� �ϴ� �۾����� �޼���� ������ִ°� ����
//	~Vec(void) { uncreate(); }
//
//	// 11.3.5 Default ����
//	// ����Ʈ ������ ���� ��� ������ �� �� �� ���� ������
//	// �پ��� ������(��Ÿ�� ����, �޸� ����)�� �߻��� �� ����
//	// 11.3.6 rule of three?
//	// ���� ������, �Ҹ��� �׸��� ���� �����ڴ� ���α׷����� ��
//	// �� ������ �����δ�. ���� ��� �Ҹ��ڰ� �ʿ��ϴٸ�
//	// ���� �����ڿ� ���� �����ڵ� �ʿ��� ���̴�.
//
//	size_type size() { return (avail - data); }
//	T& operator[](size_type i) { return data[i]; }
//	const T& operator[] (size_type i) const { return data[i]; }
//
//	void push_back(const T& val) {
//		// ���̻� ���� ������ ���� ���
//		if (avail == limit)
//		{
//			grow();
//		}
//		unchecked_append(val);
//	}
//
//	iterator erase(iterator pos);
//
//	void clear();
//
//	iterator begin() { return data; }
//	iterator end() { return avail; }
//	const_iterator begin() const { return data; }
//	const_iterator end() const { return avail; }
//
//	iterator end_limit() { return limit; }
//
//	// 11.5 �޸� ����
//	// ���� new �Ǵ� delete�� ����ϴ� �ͺ���
//	// ǥ�� ���̺귯�� <memory>�� �ִ� allocator<T> Ŭ������
//	// ����ϴ� ���� ����ȴ�
//
//private:
//	//T* data; // ù ��° �������� ptr
//	//T* limit; // ������ ������ ������ ptr
//	// typedef�� �����Ƿ� iterator�� �ٲ���
//	iterator data;
//	iterator avail; // (�ϳ� ����) �������� ������ ��ҿ� ���� ������
//	iterator limit; // ������ ������ ��ҿ� ���� ������
//
//	//      �ʱ�ȭ�� ���      |      �ʱ�ȭ���� ���� ����
//	//    data               avail                     limit
//
//	// �޸� �Ҵ��� ����
//	std::allocator<T> alloc; 
//
//	// �迭�� �Ҵ��ϴ� �޼���
//	void create();
//	void create(size_type, const T&);
//	void create(const_iterator, const_iterator);
//
//	// �迭�� ��Ҹ� �����ϰ�, �޸� ����
//	void uncreate();
//
//	// push_back�� ó���� �� ����ϴ� �Լ���
//	void grow(); // Vec�� ũ�⸦ �� ��� �÷��ִ� �޼���
//	void unchecked_append(const T& t); // Vec���ٰ� append �Ͽ� push_back�� �ϰ���..
//};

int Chapter11Example5() {
	// Vec ��ü�� ��ȿ�� ��� �Ʒ��� 4������ �׻� ��
	// �̷��� ���ǵ��� Ŭ���� �Һ���(class invariant)�̶� �θ���
	// 1. data�� Vec�� ù ��° ��Ҹ� ����Ų��. ������ 0 == nullptr
	// 2. data <= avail <= limit
	// 3. ������ ��Ҵ� [data, avail) ������ �ִ�
	// 4. �������� ���� ��Ҵ� [avail, limit) ������ �ִ�.

	Vec<int> vec;
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(3);
	// 3��°�� ���鼭 2 * 2 �� �Ǿ�
	// �� ũ��� 4�̰�, size�� 3�� �����Ѵ�.
	std::cout << vec.size() << " | "
		<< (vec.end_limit() - vec.begin());

	return 0;
}

#endif