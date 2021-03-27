#ifndef VEC_H
#define VEC_H

#include <memory>

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
	}

	Vec(const iterator b, const iterator e) {
		create(b, e);
	}
	// create �Լ��� v.begin ���� v.end�� ����(?)�ϴ� �����ε�

	// 11.3.2 ���� ������
	Vec<T>& operator=(const Vec<T>& rhs) {
		// ��ȣ�� ������ ���� �ڱ� �ڽ����� üũ�ؾ���.
		if (&rhs != this) {
			// ���� �������� (*this)�� �Ҵ�� �����͸� ��ȯ�ؾ���.
			uncreate();

			create(rhs.begin(), rhs.end());
		}
		// �ڱ� �ڽ��� ���� ������ ���� ���� �ٷ� �����ϸ� �ȴ�.
		return (*this);
	}

	// 11.3.3 ���԰� �ʱ�ȭ�� �ٸ���
	// �ϴ� Chapter11Example3()�� �ڼ��� ���

	// 11.3.4 �Ҹ���(Destructor)
	// local scope�� ��� �� Ŭ������ �Ҹ��ڸ� �����ϰ� �Ǵµ�
	// �� �� ������ �����ؾ� �ϴ� �۾����� �޼���� ������ִ°� ����
	~Vec(void) { uncreate(); }

	// 11.3.5 Default ����
	// ����Ʈ ������ ���� ��� ������ �� �� �� ���� ������
	// �پ��� ������(��Ÿ�� ����, �޸� ����)�� �߻��� �� ����
	// 11.3.6 rule of three?
	// ���� ������, �Ҹ��� �׸��� ���� �����ڴ� ���α׷����� ��
	// �� ������ �����δ�. ���� ��� �Ҹ��ڰ� �ʿ��ϴٸ�
	// ���� �����ڿ� ���� �����ڵ� �ʿ��� ���̴�.

	size_type size() const {
		return (avail - data);
	}
	T& operator[](size_type i) {
		return *(data + i);
	}
	const T& operator[] (size_type i) const {
		return *(data + i);
	}

	void push_back(const T& val) {
		// ���̻� ���� ������ ���� ���
		if (avail == limit)
		{
			grow();
		}
		unchecked_append(val);
	}

	iterator erase(iterator pos);

	void clear(void);
	bool empty(void) const;

	iterator begin() { return data; }
	iterator end() { return avail; }
	const_iterator begin() const { return data; }
	const_iterator end() const { return avail; }

	iterator end_limit() { return limit; }

	// 11.5 �޸� ����
	// ���� new �Ǵ� delete�� ����ϴ� �ͺ���
	// ǥ�� ���̺귯�� <memory>�� �ִ� allocator<T> Ŭ������
	// ����ϴ� ���� ����ȴ�

private:
	//T* data; // ù ��° �������� ptr
	//T* limit; // ������ ������ ������ ptr
	// typedef�� �����Ƿ� iterator�� �ٲ���
	iterator data;
	iterator avail; // (�ϳ� ����) �������� ������ ��ҿ� ���� ������
	iterator limit; // ������ ������ ��ҿ� ���� ������

	//      �ʱ�ȭ�� ���      |      �ʱ�ȭ���� ���� ����
	//    data               avail                     limit

	// �޸� �Ҵ��� ����
	std::allocator<T> alloc;

	// �迭�� �Ҵ��ϴ� �޼���
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// �迭�� ��Ҹ� �����ϰ�, �޸� ����
	void uncreate();

	// push_back�� ó���� �� ����ϴ� �Լ���
	void grow(); // Vec�� ũ�⸦ �� ��� �÷��ִ� �޼���
	void unchecked_append(const T& t); // Vec���ٰ� append �Ͽ� push_back�� �ϰ���..
};


// template �޼��� ����
template <class T>
void Vec<T>::create() {
	data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(Vec::size_type n, const T& val)
{
	// n���� ��Ҹ� �ʱⰪ t�� �ִ� ��
	data = alloc.allocate(n);
	limit = avail = data + n;
	// �ʱ�ȭ���� ���� �Ϳ��ٰ� val�� ä���ִ°�
	std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(Vec::const_iterator i, Vec::const_iterator j)
{
	data = alloc.allocate((j - i));
	// �ʱ�ȭ���� ���� �Ϳ��ٰ� i���� j������ data���� �����Ͽ� copy�Ѵ�.
	limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T>
void Vec<T>::uncreate(void) {
	// create�ߴ� �۾��� �ǵ����� �޼���
	// 1. �� ��ҿ� ���� �Ҹ��ڸ� ȣ���ؼ� �����ϰ�
	// 2. Vec�� ���� �޸� ������ �����ؾ���.

	// �Ҵ�� ��� :: data == 0 �Ǵ� nullptr�� �ƴ� ���
	if (data)
	{
		iterator it = avail;
		while (it != data)
		{
			// it ��ü�� ������ �������� ���� ��Ҹ� ����Ű�Ƿ�
			// --it �� �ؾ� ������ ��Ҹ� destroy �ϰ� ��
			alloc.destroy(--it);
		}

		// �Ҵ�� ��� �޸� ������ �ǵ�����.
		// ���� Vec�� ������� ���� ������ ���� ������ limit����
		// ù ����� data�� ���� ��
		alloc.deallocate(data, limit - data);
	}
	// �׸����� �����͸� �����Ѵ�.
	// Vec(void) �����ڿ� ������ ������ �����ϸ� ��
	data = avail = limit = 0; // nullptr�� ����Ų��
}

template <class T>
void Vec<T>::grow(void) {

	size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
	// �ּ� 1���� �ø��ų� ���� ũ���� 2��� �ø���

	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	uncreate();

	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val) {
	alloc.construct(avail++, val);
}

// Chapter11Problem6
template <class T>
typename Vec<T>::iterator Vec<T>::erase(Vec<T>::iterator pos) {
	// pos�� �ִ� ��Ҹ� ����� �޼���
	if (data && pos != avail)
	{
		alloc.destroy(pos);
		iterator it = (pos + 1);
		while (it != avail)
		{
			alloc.construct(pos++, *(it++));
			alloc.destroy(pos);
		}
		avail = pos;
	}
	return avail;
}

template <class T>
void Vec<T>::clear(void) {
	// ��� ��Ҹ� ���� �޼���
	if (data)
	{
		iterator it = avail;
		while (it != data)
		{
			alloc.destroy(--it);
		}
		avail = data;
	}
}

template <class T>
bool Vec<T>::empty(void) const {
	if (data)
	{
		return ((avail - data) == 0);
	}
	return (true);
}

#endif