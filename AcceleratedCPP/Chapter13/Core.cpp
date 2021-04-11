#include "Core.h"

Core::Core() : midterm(0), final(0)
{
	std::cerr << "[Generator] Core::Core()" << std::endl;
}

Core::Core(std::string s) : midterm(0), final(0)
{
	n = s;
}

Core::Core(std::istream& in) : midterm(0), final(0)
{
	std::cerr << "[Generator] Core::Core(std::istream&)" << std::endl;
	read(in);
}

std::string Core::name(void) const {
	std::cout << "Core::grade()" << std::endl;
	return n;
}

std::istream& Core::read(std::istream& in) {
	read_common(in);
	read_homework(in, homework);
	return in;
}

double Core::grade(void) const {
	std::cout << "Core::grade()" << std::endl;
	if (valid())
		return ::grade(midterm, final, homework);
	
	return 0;
}

std::string Core::letter_grade(const double grade) {
	std::string result;

	static const double scores[] = {
		97, 90, 83, 75, 69, 61, 54, 48, 40, 30, 0
	};

	static const char* const letters[]{
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};

	static const size_t ngrades = sizeof(scores) / sizeof(*scores);
	/*std::cout << sizeof(scores) << " | "
		<< sizeof(*scores) << " | "
		<< ngrades << std::endl;*/

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

	//std::cout << "result: " << result << std::endl;

	return result;
}

void Core::show(void) {
	std::cout << "==== Core::show(void) for " << n << " ====" << std::endl;
	std::cout << "final   : " << final << std::endl;
	std::cout << "midterm : " << midterm << std::endl;
	std::cout << "homework: ";
	for (std::vector<double>::const_iterator iter = homework.begin();
		iter != homework.end(); ++iter)
	{
		if (iter != homework.begin())
			std::cout << " | ";
		std::cout << (*iter);
	}
	std::cout << std::endl;
	std::cout << "===============================" << std::endl;
}

// protected

std::istream& Core::read_common(std::istream& in) {
	in >> n >> midterm >> final;
	return in;
}

std::istream& Core::read_homework(std::istream& in, std::vector<double>& hw) {
	if (in) {
		// 초기화
		hw.clear();

		double x;
		while (in >> x) {
			hw.push_back(x);
		}
		// istream 객체의 초기화
		in.clear();
	}
	return in;
}