#ifndef VEC_H
#define VEC_H

#include <memory>

template <class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;

	// 기본 생성자
	Vec() { create(); }
	// n개 값에 초기 데이터를 넣는 생성자
	// explicit은 어떤 키워드인가????
	// >> 지정된 생성자를 직접 호출할 때에만 컴파일러가
	// 그 생성자를 사용하게 된다
	explicit Vec(size_type n, const T& val = T()) { create(n, val); }
	// 11.3.1 복사 생성자
	// 요소가 포인터이기때문에 일반적인 복사로는
	// 포인터만 복사가 되니까... 실제 값이 바뀌면
	// 둘 다 바뀌게 된다....
	Vec(const Vec& v) {
		create(v.begin(), v.end());
	}

	Vec(const iterator b, const iterator e) {
		create(b, e);
	}
	// create 함수는 v.begin 부터 v.end를 복사(?)하는 느낌인데

	// 11.3.2 대입 연산자
	Vec<T>& operator=(const Vec<T>& rhs) {
		// 등호의 오른쪽 항이 자기 자신인지 체크해야함.
		if (&rhs != this) {
			// 먼저 왼쪽항인 (*this)에 할당된 데이터를 반환해야함.
			uncreate();

			create(rhs.begin(), rhs.end());
		}
		// 자기 자신일 때는 별도의 동작 없이 바로 리턴하면 된다.
		return (*this);
	}

	// 11.3.3 대입과 초기화는 다르다
	// 하단 Chapter11Example3()에 자세히 기술

	// 11.3.4 소멸자(Destructor)
	// local scope를 벗어날 때 클래스의 소멸자를 실행하게 되는데
	// 그 때 별도로 수행해야 하는 작업들을 메서드로 명시해주는게 좋다
	~Vec(void) { uncreate(); }

	// 11.3.5 Default 연산
	// 디폴트 생성자 등이 어떻게 동작할 지 알 수 없기 때문에
	// 다양한 문제들(런타임 오류, 메모리 누수)이 발생할 수 있음
	// 11.3.6 rule of three?
	// 복사 생성자, 소멸자 그리고 대입 연산자는 프로그래밍할 때
	// 한 쌍으로 움직인다. 예를 들어 소멸자가 필요하다면
	// 복사 생성자와 대입 연산자도 필요할 것이다.

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
		// 더이상 넣을 공간이 없는 경우
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

	// 11.5 메모리 관리
	// 직접 new 또는 delete를 사용하는 것보다
	// 표준 라이브러리 <memory>에 있는 allocator<T> 클래스를
	// 사용하는 것이 권장된다

private:
	//T* data; // 첫 번째 데이터의 ptr
	//T* limit; // 마지막 데이터 다음의 ptr
	// typedef를 했으므로 iterator로 바꾸자
	iterator data;
	iterator avail; // (하나 지난) 마지막에 생성된 요소에 대한 포인터
	iterator limit; // 마지막 가용한 요소에 대한 포인터

	//      초기화된 요소      |      초기화되지 않은 공간
	//    data               avail                     limit

	// 메모리 할당을 위해
	std::allocator<T> alloc;

	// 배열을 할당하는 메서드
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// 배열의 요소를 제거하고, 메모리 해제
	void uncreate();

	// push_back을 처리할 때 사용하는 함수들
	void grow(); // Vec의 크기를 두 배로 늘려주는 메서드
	void unchecked_append(const T& t); // Vec에다가 append 하여 push_back을 하겠지..
};


// template 메서드 선언
template <class T>
void Vec<T>::create() {
	data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(Vec::size_type n, const T& val)
{
	// n개의 요소를 초기값 t로 넣는 것
	data = alloc.allocate(n);
	limit = avail = data + n;
	// 초기화되지 않은 것에다가 val을 채워넣는것
	std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(Vec::const_iterator i, Vec::const_iterator j)
{
	data = alloc.allocate((j - i));
	// 초기화되지 않은 것에다가 i부터 j까지를 data부터 시작하여 copy한다.
	limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T>
void Vec<T>::uncreate(void) {
	// create했던 작업을 되돌리는 메서드
	// 1. 각 요소에 대해 소멸자를 호출해서 제거하고
	// 2. Vec에 사용된 메모리 공간을 복구해야함.

	// 할당된 경우 :: data == 0 또는 nullptr가 아닌 경우
	if (data)
	{
		iterator it = avail;
		while (it != data)
		{
			// it 자체는 마지막 데이터의 다음 요소를 가리키므로
			// --it 로 해야 마지막 요소를 destroy 하게 됨
			alloc.destroy(--it);
		}

		// 할당된 모든 메모리 영역을 되돌린다.
		// 따라서 Vec의 사용하지 않은 공간의 다음 공간인 limit에서
		// 첫 요소인 data를 빼는 것
		alloc.deallocate(data, limit - data);
	}
	// 그리고나서 포인터를 리셋한다.
	// Vec(void) 생성자와 동일한 역할을 수행하면 됨
	data = avail = limit = 0; // nullptr을 가리킨다
}

template <class T>
void Vec<T>::grow(void) {

	size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
	// 최소 1개를 늘리거나 현재 크기의 2배로 늘린다

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
	// pos에 있는 요소를 지우는 메서드
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
	// 모든 요소를 비우는 메서드
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