#include "Core.h"

Core::Core() {

}

Core::Core(std::istream& in) {

}

std::string Core::name(void) const {
	return n;
}

std::istream& Core::read(std::istream& in) {
	return in;
}

double Core::grade(void) const {
	return 0.0;
}

std::istream& Core::read_common(std::istream& in) {
	return in;
}