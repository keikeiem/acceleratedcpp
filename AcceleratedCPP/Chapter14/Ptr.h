#ifndef PTR_HANDLE_H
#define PTR_HANDLE_H

#include <stdexcept>

template <class T> class Ptr {
public:
	// �����ͻӸ� �ƴ϶� ���۷��� ī��Ʈ�� ������.
	// ���۷��� ī��Ʈ�� ������ �� �� �̷�������� ��Ÿ���� ��
	// �� ���� 0�� �� ��ü�� �Ҹ��ų ������ ����

	Ptr() : refptr(new size_t(1)), p(0) {}
	Ptr(T* t) : refptr(new size_t(1)), p(t) {}
	Ptr(const Ptr& h) : refptr(h.refptr), p(h.p)
	{
		++(*refptr);
	}

	Ptr& operator=(const Ptr&);
	~Ptr();

	operator bool() const { return p; }
	T& operator*() const {
		if (p) return (*p);
		throw std::runtime_error("unbound ReferenceHandle");
	}

	T* operator->() const {
		if (p) return (p);
		throw std::runtime_error("unbound ReferenceHandle");
	}

	void make_unique() {
		if ((*refptr) != 1) {
			--(*refptr);
			refptr = new size_t(1);
			p = p ? p->clone() : 0;
		}
	}

private:
	T* p;
	size_t* refptr;
};

template <class T>
Ptr <T>& Ptr<T>::operator=(const Ptr& rhs)
{
	++(*rhs.refptr);
	// ���� ���� �޸𸮸� �����ϱ� ����, �ش� �����͸� �Ҹ��Ų��.
	if (--(*refptr) == 0) {
		delete refptr;
		delete p;
	}
	// rhs�κ��� ���� �����Ѵ�.
	refptr = rhs.refptr;
	p = rhs.p;
	return (*this);
}
template <class T>
Ptr<T>::~Ptr() {
	if (--(*refptr) == 0)
	{
		delete refptr;
		delete p;
	}
}

#endif
