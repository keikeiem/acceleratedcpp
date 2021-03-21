#include <iostream>
#include "main.h"

int main(int argc, char** argv) {
	//return Chapter11Example3();
	return Chapter11Example5();
}

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

	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	uncreate();

	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}
