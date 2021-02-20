#ifndef METHOD_H
#define METHOD_H

#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::string;
using std::streamsize;
using std::vector;
using std::domain_error;

using std::list;

void Greeting(const string name);
string InsertName(void);

void read_test(Student_info& s, const string name, const double midterm, const double final, const vector<double> & homework);
Student_info random_grade(const string name);
Students classify_iter(Students& s); // list case

void show_strings(const vector<string>& v) {
	cout << "vec: " << endl;
	for (vector<string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
		cout << "\t" << (*iter) << endl;
	}
}

int Chapter6Example1() {
	vector<string> vec;
	vec.push_back("front1");
	vec.push_back("front2");
	vec.push_back("front3");
	vector<string> bottom;
	bottom.push_back("bottom1");
	bottom.push_back("bottom2");
	bottom.push_back("bottom3");
	// vector의 특정 위치에 넣는 역할
	// vec.insert(vec.end(), bottom.begin(), bottom.end());
	//vec.insert((vec.begin() + 1), bottom.begin(), bottom.end());

	vector<string>::iterator begin = bottom.begin();
	vector<string>::iterator end = bottom.end();
	std::back_insert_iterator<vector<string>> out = std::back_inserter(vec);

	while (begin != end) {
		*out++ = *begin++;
	}

	//std::copy(bottom.begin(), bottom.end(), std::back_inserter(vec));
	show_strings(vec);
	
	return 0;
}

bool space(char c);
bool not_space(char c);
vector<string> split(const string& s);

int Chapter6Example1_1() {
	string str = "Notorious Biggie Small";

	vector<string> result = split(str);
	show_strings(result);
	return 0;
}

bool is_palindrome(const string& s) {
	return std::equal(s.begin(), s.end(), s.rbegin());
}

int Chapter6Example1_2() {
	vector<string> vec;
	vec.push_back("civic");
	vec.push_back("banana");
	vec.push_back("level");
	vec.push_back("mother");
	vec.push_back("madam");

	vector<string> ret;
	for (vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
		if (is_palindrome(*iter))
			ret.push_back(*iter);
	}

	show_strings(ret);

	return 0;
}

vector<string> find_urls(const string& s);
typedef string::const_iterator siter;
string::const_iterator url_beg(string::const_iterator, string::const_iterator);
string::const_iterator url_end(string::const_iterator, string::const_iterator);
bool not_url_char(char c);
int Chapter6Example1_3() {
	vector<string> vec;
	vec.push_back("The address of naver is http://www.naver.com you can find a lot of things.");
	vec.push_back("File transform protocol example address: ftp://open.somewhere.com/files");
	vec.push_back("empty data");

	vector<string> result = find_urls(*(vec.begin() + 1));

	show_strings(result);

	return 0;
}

#endif