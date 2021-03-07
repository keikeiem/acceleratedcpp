#include "student_info.h"

using std::istream;
using std::vector;
using std::cout;
using std::endl;

using std::list;

double Student_info::grade() const {
	return grade(midterm, final, homework);
}

double Student_info::grade(double midterm, double final, const vector<double>& hw) const  {
	if (hw.size() == 0)
		throw domain_error("student has done no homework");

	return grade(midterm, final, get_median_value(hw));
}

double Student_info::grade(double midterm, double final, double hw) const {
	return (0.2 * midterm) + (0.4 * final) + (0.4 * hw);
}

double Student_info::get_median_value(const vector<double>& vec) const {
	typedef std::vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw std::domain_error("an empty vector");

	//sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;
	return (size % 2) == 0 ? (vec[mid] + vec[(mid - 1)]) / 2 : vec[mid];
}


std::istream& Student_info::read(std::istream& in) {
	in >> name_ >> midterm >> final;
	read_homework(in);
	return in;
}

std::istream& Student_info::read_homework(std::istream& in) {
	if (in) {
		// 초기화
		homework.clear();
		double x;
		while (in >> x) {
			homework.push_back(x);
		}
		// istream 객체의 초기화
		in.clear();
	}
	return in;
}

void Student_info::show() {
	cout << name_
		<< " | " << midterm
		<< " | " << final
		<< " | ";

	int count = 0;
	for (vector<double>::const_iterator iter = homework.begin(); iter != homework.end(); ++iter)
	{
		if (count > 0) cout << ", ";

		cout << (*iter);
		count++;
	}
	cout << endl;
}

bool compare(const Student_info& x, const Student_info& y) {
	return x.name() > y.name();
};