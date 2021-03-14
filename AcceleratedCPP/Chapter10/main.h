#ifndef METHOD_H
#define METHOD_H

#include <vector>

int next(int s) {
	return (s + 1);
};

template <class In, class Pred>
In find_iff(In begin, In end, Pred f) {
	while (begin != end && !f(*begin))
	{
		++begin;
	}
	return begin;
}
bool is_negative(int n) {
	return (n < 0);
}
int Chapter10Example1() {
	int x = 5;
	int* p, q; 
	// 이렇게 쓸 땐 주의해야한다
	// int *p 와 int q를 선언한 것으로 간주함

	p = &x;
	q = x;	
	std::cout << "Chapter10.1.1 Pointer" << std::endl;
	std::cout << "x: " << x << " | " << p << " | " << (*p) << std::endl;
	std::cout << "q: " << q << " | " << (&q) << std::endl;
	// 값만 들어간 것이지 p와 &q는 서로 다르다

	// 포인터로 원래 변수의 값을 변경하면?
	(*p) = 6;
	std::cout << "x: " << x << " | " << p << " | " << (*p) << std::endl;
	// x 값 역시 변경된다

	int (*fp) (int);
	int (*qp) (int);
	fp = next;
	qp = &next;

	std::cout << std::endl;
	std::cout << "Chapter10.1.2 Function Pointer" << std::endl;
	std::cout << fp << " | " << qp << std::endl;
	std::cout << (*fp)(5) << " | " << fp(5) << std::endl;

	std::vector<int> vec;
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(-3);
	vec.push_back(-4);
	std::vector<int>::iterator i = find_iff(vec.begin(), vec.end(), is_negative);
	std::cout << (*i) << std::endl;	

	return 0;
}

int Chapter10Example1_Array() {
	std::cout << "Chapter10.1.3 Array" << std::endl;
	const size_t NDim = 3;
	double coordinate[NDim];
	coordinate[0] = 1.5;
	coordinate[1] = 2.3;
	coordinate[2] = 1.1;

	// coordinate 자체는 0번째의 주소를 가리킴
	// coordinate[0]은 0번째 값을 가리킴
	std::cout << coordinate[0] << " | " << (*coordinate) << std::endl;

	std::cout << std::endl;
	std::cout << "Chapter10.1.4 Pointer Arithmetic Operator" << std::endl;
	std::cout << (coordinate + 1) << " | "
		<< (coordinate + 2) << " | "
		<< (coordinate + 3) << std::endl;
	std::cout << *(coordinate + 1) << " | "
		<< *(coordinate + 2) << " | "
		<< *(coordinate + 3) << std::endl;
	// 3번은 없으니까~ 

	std::cout << std::endl;
	std::cout << "Chapter10.1.5 Indexing" << std::endl;
	// index 값으로 접근이 가능함
	std::cout << coordinate[0] << " | "
		<< coordinate[1] << " | "
		<< coordinate[2] << std::endl;
	// coordinate[1]과 *(coordinate + 1)은 같음

	std::cout << std::endl;
	std::cout << "Chapter10.1.6 Array Initialization" << std::endl;
	const int month_lengths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return 0;
}



#endif