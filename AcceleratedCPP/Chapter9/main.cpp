#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <list>
#include <numeric>

#include "student_info.h"
#include "main.h"
#include "problem.h"

int main() {
	 //return Chapter9Example1();
	 //return Chapter9Example2();
	 return Chapter9Problem1();
}

bool space(char c) {
	return (isspace(c));
}

bool not_space(char c) {
	return !(isspace(c));
}