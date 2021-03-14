#ifndef METHOD_H
#define METHOD_H

#include <vector>
#include <string>

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

int Chapter10Example2() {
	const char hello[] = { 'H','e','l','l','o','\0' };
	std::string s(hello);
	std::cout << "size: " << std::strlen(hello) << " | " << s.length() << std::endl;

	// string pointer로 선언하기
	std::string test(hello, hello + std::strlen(hello));
	std::cout << "test: " << test << std::endl;

	return 0;
}
std::string letter_grade(double grade);
int Chapter10Example3() {
	// 문자 포인터 배열 초기화하기
	double grade = 97.5;
	std::string result;

	// letter_grade 함수 (여기에 쓰느라 일부 수정함)
	static const double scores[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};

	static const char* const letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};

	static const size_t ngrades = sizeof(scores) / sizeof(*scores);
	std::cout << sizeof(scores) << " | "
		<< sizeof(*scores) << " | "
		<< ngrades << std::endl;
	for (size_t i = 0; i < ngrades; ++i)
	{
		if (grade >= scores[i])
		{
			result = letters[i];
			break;
		}
	}
	if (result.empty())
		result = "?\?\?";
	// letter_grade 함수 (여기에 쓰느라 일부 수정함)

	std::cout << result << std::endl;

	return 0;
}

int Chapter10Example4(int argc, char** argv) {
	// 원래는 main에서 체크하는 내용
	if (argc > 1) {
		int i;
		for (i = 1; i < (argc - 1); ++i)
		{
			std::cout << argv[i] << " ";
		}
		std::cout << argv[i] << std::endl;
	}
	// 명령인수에 써 넣은 문자열에 대한 처리를 할 수 있음


	return 0;
}

int Chapter10Example5() {

	return 0;
}

#endif