#ifndef PTR_HANDLE_H
#define PTR_HANDLE_H

#include <stdexcept>

template <class T> class Ptr {
public:
	// 포인터뿐만 아니라 레퍼런스 카운트도 관리함.
	// 레퍼런스 카운트란 참조가 몇 번 이루어졌는지 나타내는 수
	// 이 값이 0일 때 객체를 소멸시킬 안전한 시점

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
	// 왼쪽 항의 메모리를 해제하기 위해, 해당 포인터를 소멸시킨다.
	if (--(*refptr) == 0) {
		delete refptr;
		delete p;
	}
	// rhs로부터 값을 복사한다.
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
