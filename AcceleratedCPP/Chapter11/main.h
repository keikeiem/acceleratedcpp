#ifndef MAIN_H
#define MAIN_H

#include "student_info.h"


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



// Chapter11
// Example3 Copy 처리하기
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
	};
	// create 함수는 v.begin 부터 v.end를 복사(?)하는 느낌인데


	// 11.3.2 대입 연산자
	Vec<T>& Vec<T>::operator=(const Vec& rhs) {
		// 등호의 오른쪽 항이 자기 자신인지 체크해야함.
		if (&rhs != this) {
			// 먼저 왼쪽항인 (*this)에 할당된 데이터를 반환해야함.
			uncreate();

			create(rhs.begin(), rhs.end());
		}
		// 자기 자신일 때는 별도의 동작 없이 바로 리턴하면 된다.
		return (*this);
	};

	// 11.3.3 대입과 초기화는 다르다
	// 하단 Chapter11Example3()에 자세히 기술

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
	//T* data; // 첫 번째 데이터의 ptr
	//T* limit; // 마지막 데이터 다음의 ptr
	// typedef를 했으므로 iterator로 바꾸자
	iterator data;
	iterator limit;
};

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

#endif