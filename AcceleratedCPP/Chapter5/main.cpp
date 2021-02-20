#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <list>

#include "median.h"
#include "student_info.h"
#include "grade.h"
#include "main.h"
#include "problem.h"

int main() {
	//return Chapter5Example1();
	//return Chapter5Example5();
	//return Chapter5Example6();
	//return Chapter5Example7();
	//return Chapter5Example8();
	//return Chapter5Example8_2();
	//return Chapter5Example8_3();

	//return Chapter5Problem1();
	//return Chapter5Problem4();
	//return Chapter5Problem6();
	//return Chapter5Problem9();
	return Chapter5Problem10();
}

void Greeting(const string name) {
	cout << "Hello, " << name << "!" << endl;
}

string InsertName(void) {
	string name;
	cin >> name;

	return (name);
}

void read_test(Student_info& s, const string name, const double midterm, const double final, const vector<double> & homework) {
	s.name = name;
	s.midterm = midterm;
	s.final = final;
	s.homework = homework;
}

Student_info random_grade(const string name) {
	Student_info record;

	int random_value = (1 + std::rand() % 10);
	bool statement = (random_value % 2 == 0 ? true : false);

	double homework = random_value * 10;
	double mid = homework + (statement ? 5 : -5);
	double final = homework + (statement ? -5 : 5);

	vector<double> hw;
	hw.push_back(random_value * 10);

	read_test(record, name, mid, final, hw);
	return (record);
}

bool check_fail(const Student_info& s) {
	return (s.grade < 50);
}

Students classify_iter(Students& s) {
	Students failed;	
	Students::const_iterator iter = s.begin();
	while (iter != s.end()) {
		if (check_fail(*iter)) {
			failed.push_back(*iter);
			iter = s.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	return failed;
}

Students extract_fails(Students & s) {
	Students fail;
	Students::size_type i = 0;
	while (i != s.size()) {
		if (check_fail(s[i])) {
			fail.push_back(s[i]);
			s.erase(s.begin() + i);
		}
		else {
			++i;
		}
	}
	return fail;
}

Students resize_vector(Students & s) {
	Students fail;
	Students::size_type passed_count = 0;
	Students::size_type i = 0;

	while (i != s.size()) {
		if (check_fail(s[i])) {
			fail.push_back(s[i]);
			//s.erase(s.begin() + i);
			i++;
		}
		else {
			s.insert(s.begin(), s[i]);
			i += 2;
			passed_count++;
		}
	}
	s.resize(passed_count);

	return fail;
}

// Chapter5 Example 6
vector<string> split(const string& s) {
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		while (i != s.size() && isspace(s[i]))
		{
			++i;
		}

		string_size j = i;
		while (j != s.size() && !isspace(s[j]))
		{
			++j;
		}

		if (i != j) {
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}

// Chapter5 Example 8
string::size_type width(const vector<string>& v) {
	string::size_type max_length = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i) {
		max_length = std::max(max_length, v[i].size());
	}
	return (max_length);
}

vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type max_length = width(v);
	string border(max_length + 4, ' *');

	ret.push_back(border);
	// draw boundary using asterisk and empty space ...
	for (vector<string>::size_type i = 0; i != v.size(); ++i) {
		ret.push_back("* " + v[i] + 
			string(max_length - v[i].size(), ' ') + " *");
	}
	ret.push_back(border);

	return ret;
}
// Chapter 5 Example 8-2
vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
	// top 그림을 복사
	vector<string> ret = top;

	// 전체 bottom 그림을 복사
	for (vector<string>::const_iterator iter = bottom.begin(); iter != bottom.end(); ++iter) {
		ret.push_back(*iter);
	}
	return ret;
}
// Chapter 5 Example 8-3
vector<string> hcat(const vector<string>& left, const vector<string>& right) {
	vector<string> ret;

	// 그림 사이의 공백을 위해 +1
	string::size_type width1 = width(left) + 1;

	// left와 right를 가리키는 인덱스
	vector<string>::size_type i = 0;
	vector<string>::size_type j = 0;

	while (i != left.size() || j != right.size()) {
		string s;
		if (i != left.size())
			s = left[i++];

		s += string(width1 - s.size(), ' ');

		if (j != right.size())
			s += right[j++];

		ret.push_back(s);
	}

	return ret;
}

// Chapter5 Problem1
void make_rotation(vector<string>& container, const string& v) {
	vector<string> sp = split(v);
	//show_vector_string(sp);
	vector<string>::size_type i = 0;

	int count = 0;
	while (i < sp.size()) {
		string first_item;
		count = 0;
		for (vector<string>::size_type j = 0; j <= i; j++) {
			if (count > 0)
				first_item += " ";
			first_item += sp[j];
			count++;
		}

		if (!first_item.empty())
			container.push_back(first_item);

		string second_item;
		count = 0;
		for (vector<string>::size_type k = i + 1; k != sp.size(); k++) {
			if (count > 0) 
				second_item += " ";

			second_item += sp[k];
			count++;
		}

		if (!second_item.empty())
			container.push_back(second_item);

		i++;
	}
}

