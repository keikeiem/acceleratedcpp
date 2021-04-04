
#include "main.h"

int main() {
	//return 0;
	return Chapter13Example1();
}

Grad::Grad() {

}

Grad::Grad(std::istream&) {

}

double Grad::grade(void) const {
	return 0.0;
}

std::istream& Grad::read(std::istream& in) {
	return in;
}