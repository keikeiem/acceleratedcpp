#include <iostream>
#include "main.h"
#include "problem.h"

int main(int argc, char** argv) {
	//return Chapter11Example3();
	//return Chapter11Example5();

	//return Chapter11Problem3();
	//return Chapter11Problem4();
	return Chapter11Problem6();
}

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
