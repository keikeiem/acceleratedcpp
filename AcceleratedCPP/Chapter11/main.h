#ifndef METHOD_H
#define METHOD_H

#include <vector>
#include <string>
#include <fstream>

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

void copy_file(const std::string& input, const std::string& output) {
	// in.txt 의 파일을 읽어와서
	// out.txt 에 저장하기
	std::ifstream infile(input);
	std::ofstream outfile(output);

	std::string s;

	while (std::getline(infile, s))
	{
		outfile << s << std::endl;
	}
}

int Chapter10Example5(int argc, char** argv) {
	int fail_count = 0;
	for (int i = 1; i < argc; ++i)
	{
		std::ifstream in(argv[i]);

		if (in)
		{
			// 파일을 잘 읽어온 경우
			std::string s;
			while (std::getline(in, s))
			{
				std::cout << s << std::endl;
			}
		}
		else
		{
			// 파일을 읽어오는데 실패한 경우
			std::cerr << "cannot open file: " << argv[i] << std::endl;
			++fail_count;
		}
	}
	return fail_count;
}

int* invalid_pointer() {
	// 이 함수 scope가 끝날 때 x가 사라지므로
	// 이 함수가 리턴하는 포인터는 invalid하다
	int x;
	return (&x);
}

int* pointer_to_static() {
	// 변수 x를 정적 할당하면
	// 프로그램이 끝날 때까지 값이 유지되므로
	// 포인터도 invalid하지 않게 된다
	static int x;
	// 단, 이 함수를 호출할 때마다
	// 동일한 포인터를 가리키게 된다
	return (&x);
}

int* pointer_to_dynamic() {
	return new int(0);
}

char* duplicate_chars(const char* p)
{
	size_t length = strlen(p) + 1;
	char* result = new char[length];

	std::copy(p, p + length, result);
	return result;
}

int Chapter10Example6() {
	// 메모리 관리의 세 종류
	int* invalid = invalid_pointer();
	std::cout << invalid << " | " << (*invalid) << std::endl;
	int* p1 = pointer_to_static();
	int* p2 = pointer_to_static();
	(*p2) = 5;
	// p1, p2가 동일하게 5를 가리킴
	std::cout << "p1: " << p1 << " | " << (*p1) << std::endl;
	std::cout << "p2: " << p2 << " | " << (*p2) << std::endl;

	// 동적 할당?
	int* q1 = pointer_to_dynamic();
	int* q2 = pointer_to_dynamic();
	(*q1) = 5;
	(*q2) = 10;
	// q1, q2가 각각 다른 값을 가리킴
	std::cout << "q1: " << q1 << " | " << (*q1) << std::endl;
	std::cout << "q2: " << q2 << " | " << (*q2) << std::endl;


	int* p = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		*(p + i) = (i + 1);
	}

	std::vector<int> vec(p, p + 5);

	for (std::vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		std::cout << (*iter) << std::endl;
	}

	delete[] p;
	// delete를 했기때문에 오류 발생!
	/*for (int i = 0; i < 10; ++i)
	{
		std::cout << (p + i) << " | " << *(p + i) << std::endl;
	}*/

	char test[6] = { 'H','e','l','l','o','\0' };
	char* result = duplicate_chars(test);

	std::cout << "duplicate: " << result << std::endl;

	return 0;
}
#endif