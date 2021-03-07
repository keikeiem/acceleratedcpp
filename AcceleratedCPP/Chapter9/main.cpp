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

int main() {
	 return Chapter9Example1();
}

bool space(char c) {
	return (isspace(c));
}

bool not_space(char c) {
	return !(isspace(c));
}