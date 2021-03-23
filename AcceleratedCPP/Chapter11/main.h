#ifndef MAIN_H
#define MAIN_H

//#include <memory>
//#include "student_info.h"
#include "vec.h"
#include "vec_student_info.h"


// Chapter11Example2
//template <class T> class Vec {
//public:
//	// 기본 생성자
//	Vec() { create(); }
//	// n개 값에 초기 데이터를 넣는 생성자
//	// explicit은 어떤 키워드인가????
//	// >> 지정된 생성자를 직접 호출할 때에만 컴파일러가
//	// 그 생성자를 사용하게 된다
//	explicit Vec(size_type n, const T& val = T()) { create(n, val); }
//
//	typedef T* iterator;
//	typedef const T* const_iterator;
//	typedef size_t size_type;
//	typedef T value_type;
//	// 예를 들어 Vec<int> 라 하면
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
//	//T* data; // 첫 번째 데이터의 ptr
//	//T* limit; // 마지막 데이터 다음의 ptr
//	// typedef를 했으므로 iterator로 바꾸자
//	iterator data;
//	iterator limit;
//};



//// Chapter11
//// Example3 Copy 처리하기
//template <class T> class Vec {
//public:
//	typedef T* iterator;
//	typedef const T* const_iterator;
//	typedef size_t size_type;
//	typedef T value_type;
//
//	// 기본 생성자
//	Vec() { create(); }
//	// n개 값에 초기 데이터를 넣는 생성자
//	// explicit은 어떤 키워드인가????
//	// >> 지정된 생성자를 직접 호출할 때에만 컴파일러가
//	// 그 생성자를 사용하게 된다
//	explicit Vec(size_type n, const T& val = T()) { create(n, val); }
//	// 11.3.1 복사 생성자
//	// 요소가 포인터이기때문에 일반적인 복사로는
//	// 포인터만 복사가 되니까... 실제 값이 바뀌면
//	// 둘 다 바뀌게 된다....
//	Vec(const Vec& v) {
//		create(v.begin(), v.end());
//	};
//	// create 함수는 v.begin 부터 v.end를 복사(?)하는 느낌인데
//
//	// 11.3.2 대입 연산자
//	Vec<T>& Vec<T>::operator=(const Vec& rhs) {
//		// 등호의 오른쪽 항이 자기 자신인지 체크해야함.
//		if (&rhs != this) {
//			// 먼저 왼쪽항인 (*this)에 할당된 데이터를 반환해야함.
//			uncreate();
//
//			create(rhs.begin(), rhs.end());
//		}
//		// 자기 자신일 때는 별도의 동작 없이 바로 리턴하면 된다.
//		return (*this);
//	};
//
//	// 11.3.3 대입과 초기화는 다르다
//	// 하단 Chapter11Example3()에 자세히 기술
//
//	// 11.3.4 소멸자(Destructor)
//	// local scope를 벗어날 때 클래스의 소멸자를 실행하게 되는데
//	// 그 때 별도로 수행해야 하는 작업들을 메서드로 명시해주는게 좋다
//	~Vec(void) { uncreate(); }
//
//	// 11.3.5 Default 연산
//	// 디폴트 생성자 등이 어떻게 동작할 지 알 수 없기 때문에
//	// 다양한 문제들(런타임 오류, 메모리 누수)이 발생할 수 있음
//	// 11.3.6 rule of three?
//	// 복사 생성자, 소멸자 그리고 대입 연산자는 프로그래밍할 때
//	// 한 쌍으로 움직인다. 예를 들어 소멸자가 필요하다면
//	// 복사 생성자와 대입 연산자도 필요할 것이다.
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
//	//T* data; // 첫 번째 데이터의 ptr
//	//T* limit; // 마지막 데이터 다음의 ptr
//	// typedef를 했으므로 iterator로 바꾸자
//	iterator data;
//	iterator limit;
//};

int Chapter11Example3() {
	// 11.3.3 대입과 초기화는 다르다
	// 등호(=) 연산자는 어떻게 동작하는가?
	// <초기화>
	// 변수 선언 시
	// 함수 진입 시, 함수 매개변수에 대해
	// 함수로부터 리턴 시, 함수의 리턴 값에 대해
	// 생성자 초기 설정자(? initializer)

	std::string strA = "abcd"; // 초기화
	std::string spaces(strA.size(), 'X'); // 초기화
	std::string test(10, 'A');
	std::string y; // 초기화
	y = strA; // 대입

	// 그러면 이건 뭐임?
	std::string x = y;

	std::cout << spaces << " | " << test << std::endl;
	std::cout << x << std::endl;

	return 0;
}

//// Chapter11
//// Example4 동적인 Vec
//template <class T> class Vec {
//public:
//	typedef T* iterator;
//	typedef const T* const_iterator;
//	typedef size_t size_type;
//	typedef T value_type;
//
//	// 기본 생성자
//	Vec() { create(); }
//	// n개 값에 초기 데이터를 넣는 생성자
//	// explicit은 어떤 키워드인가????
//	// >> 지정된 생성자를 직접 호출할 때에만 컴파일러가
//	// 그 생성자를 사용하게 된다
//	explicit Vec(size_type n, const T& val = T()) { create(n, val); }
//	// 11.3.1 복사 생성자
//	// 요소가 포인터이기때문에 일반적인 복사로는
//	// 포인터만 복사가 되니까... 실제 값이 바뀌면
//	// 둘 다 바뀌게 된다....
//	Vec(const Vec& v) {
//		create(v.begin(), v.end());
//	};
//	// create 함수는 v.begin 부터 v.end를 복사(?)하는 느낌인데
//
//	// 11.3.2 대입 연산자
//	Vec<T>& operator=(const Vec<T>& rhs) {
//		// 등호의 오른쪽 항이 자기 자신인지 체크해야함.
//		if (&rhs != this) {
//			// 먼저 왼쪽항인 (*this)에 할당된 데이터를 반환해야함.
//			uncreate();
//
//			create(rhs.begin(), rhs.end());
//		}
//		// 자기 자신일 때는 별도의 동작 없이 바로 리턴하면 된다.
//		return (*this);
//	};
//
//	// 11.3.3 대입과 초기화는 다르다
//	// 하단 Chapter11Example3()에 자세히 기술
//
//	// 11.3.4 소멸자(Destructor)
//	// local scope를 벗어날 때 클래스의 소멸자를 실행하게 되는데
//	// 그 때 별도로 수행해야 하는 작업들을 메서드로 명시해주는게 좋다
//	~Vec(void) { uncreate(); }
//
//	// 11.3.5 Default 연산
//	// 디폴트 생성자 등이 어떻게 동작할 지 알 수 없기 때문에
//	// 다양한 문제들(런타임 오류, 메모리 누수)이 발생할 수 있음
//	// 11.3.6 rule of three?
//	// 복사 생성자, 소멸자 그리고 대입 연산자는 프로그래밍할 때
//	// 한 쌍으로 움직인다. 예를 들어 소멸자가 필요하다면
//	// 복사 생성자와 대입 연산자도 필요할 것이다.
//
//	size_type size() { return (avail - data); }
//	T& operator[](size_type i) { return data[i]; }
//	const T& operator[] (size_type i) const { return data[i]; }
//
//	void push_back(const T& val) {
//		// 더이상 넣을 공간이 없는 경우
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
//	// 11.5 메모리 관리
//	// 직접 new 또는 delete를 사용하는 것보다
//	// 표준 라이브러리 <memory>에 있는 allocator<T> 클래스를
//	// 사용하는 것이 권장된다
//
//private:
//	//T* data; // 첫 번째 데이터의 ptr
//	//T* limit; // 마지막 데이터 다음의 ptr
//	// typedef를 했으므로 iterator로 바꾸자
//	iterator data;
//	iterator avail; // (하나 지난) 마지막에 생성된 요소에 대한 포인터
//	iterator limit; // 마지막 가용한 요소에 대한 포인터
//
//	//      초기화된 요소      |      초기화되지 않은 공간
//	//    data               avail                     limit
//
//	// 메모리 할당을 위해
//	std::allocator<T> alloc; 
//
//	// 배열을 할당하는 메서드
//	void create();
//	void create(size_type, const T&);
//	void create(const_iterator, const_iterator);
//
//	// 배열의 요소를 제거하고, 메모리 해제
//	void uncreate();
//
//	// push_back을 처리할 때 사용하는 함수들
//	void grow(); // Vec의 크기를 두 배로 늘려주는 메서드
//	void unchecked_append(const T& t); // Vec에다가 append 하여 push_back을 하겠지..
//};

int Chapter11Example5() {
	// Vec 객체가 유효할 경우 아래의 4가지는 항상 참
	// 이러한 조건들을 클래스 불변식(class invariant)이라 부른다
	// 1. data는 Vec의 첫 번째 요소를 가리킨다. 없으면 0 == nullptr
	// 2. data <= avail <= limit
	// 3. 생성된 요소는 [data, avail) 범위에 있다
	// 4. 생성되지 않은 요소는 [avail, limit) 범위에 있다.

	Vec<int> vec;
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(3);
	// 3개째가 들어가면서 2 * 2 가 되어
	// 총 크기는 4이고, size는 3을 리턴한다.
	std::cout << vec.size() << " | "
		<< (vec.end_limit() - vec.begin());

	return 0;
}

#endif