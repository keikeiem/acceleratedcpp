#include "main.h"
#include "problem.h"

int main() {
	//return Chapter12Example1();
	//return Chapter12Example3();
	//return Chapter12Example4();
	//return Chapter12Example6();

	std::string test;
	std::cin >> test;
	std::cout << test << std::endl;
	// ���ۿ� �ٽ� �ִ´ٴ°� � �ǹ��ϱ�??
	std::cin.unget();
	std::cout << test << std::endl;
	
	// Problem
	return Chapter12Problem1();
}

