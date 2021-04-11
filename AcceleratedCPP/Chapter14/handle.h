#ifndef HANDLE_H
#define HANDLE_H

#include <stdexcept>

// 제네릭 핸들 클래스
// Handle은 객체를 참조하는 값
// Handle 객체를 복사할 수 있음
// Handle 객체가 다른 객체에 바인딩되어있는지 확인 가능
// Handle 객체가 가리키는 객체가 상속구조에 속해 있다면
//        다형성에 근거한 행동을 수행할 수 있음
//        즉, virtual 함수를 호출하면,
//        구현시스템이ㅣ 동적으로 실행시킬 적당한 함수를 선택함

template <class T> class Handle {
public:
	Handle() : p(0) { }
	Handle(const Handle& s) : p(0) { if (s.p) p = s.p->clone(); }
	Handle& operator=(const Handle&);
	~Handle() { delete p; }

	Handle(T* t) : p(t) { }
	
	operator bool() const { return p; }
	T& operator*() const;
	T* operator->() const;

private:
	T* p;
};

template <class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
	if (&rhs != this) {
		delete p;
		p = rhs.p ? rhs.p->clone() : 0;
	}
	return (*this);
}

template <class T>
T& Handle<T>::operator*() const {
	if (p)
		return (*p);
	throw std::runtime_error("unbound Handle");
}

template <class T>
T* Handle<T>::operator->() const {
	if (p)
		return p;
	throw std::runtime_error("unbound Handle");
}

#endif // !HANDLE_H
