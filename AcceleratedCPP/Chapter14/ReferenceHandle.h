#ifndef REFERENCE_HANDLE_H
#define REFERENCE_HANDLE_H

#include <stdexcept>

template <class T> class ReferenceHandle {
public:
	// �����ͻӸ� �ƴ϶� ���۷��� ī��Ʈ�� ������.
	// ���۷��� ī��Ʈ�� ������ �� �� �̷�������� ��Ÿ���� ��
	// �� ���� 0�� �� ��ü�� �Ҹ��ų ������ ����

	ReferenceHandle() : refptr(new size_t(1)), p(0) {}
	ReferenceHandle(T* t) : refptr(new size_t(1)), p(t) {}
	ReferenceHandle(const ReferenceHandle& h) : refptr(h.refptr), p(h.p)
	{
		++(*refptr);
	}

	ReferenceHandle& operator=(const ReferenceHandle&);
	~ReferenceHandle();

	operator bool() const { return p; }
	T& operator*() const {
		if (p) return (*p);
		throw std::runtime_error("unbound ReferenceHandle");
	}

	T* operator->() const {
		if (p) return (p);
		throw std::runtime_error("unbound ReferenceHandle");
	}

private:
	T* p;
	size_t* refptr;
};

template <class T>
ReferenceHandle<T>& ReferenceHandle<T>::operator=(const ReferenceHandle& rhs)
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
ReferenceHandle<T>::~ReferenceHandle() {
	if (--(*refptr) == 0)
	{
		delete refptr;
		delete p;
	}
}

#endif
