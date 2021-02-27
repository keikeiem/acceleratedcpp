#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <list>
#include <numeric>

#include "median.h"
#include "student_info.h"
#include "grade.h"
#include "main.h"
#include "problem.h"

int main() {
	//return Chapter6Example1();
	//return Chapter6Example1_1();
	//return Chapter6Example1_2();
	//return Chapter6Example1_3();
	//return Chapter6Example2();
	//return Chapter6Example3();
	//return Chapter6Example3_2();

	//return Chapter6Problem2();
	//return Chapter6Problem3();
	return Chapter6Problem9();
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

	/*double homework = (random_value * 10);
	double mid = homework + (statement ? 5 : -5);
	double final = homework + (statement ? -5 : 5);*/
	double mid = 50;
	double final = 50;

	vector<double> hw;
	int count = 0;
	while (count <= 3) {
		int rand = (1 + std::rand() % 10);
		hw.push_back(rand * 10);
		count++;
	}
	cout << name << ": " << get_median_value(hw) << endl;
	//hw.push_back(random_value * 10);

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

// Chapter6 Example 1-1
bool space(char c) {
	return (isspace(c));
}

bool not_space(char c) {
	return !(isspace(c));
}

vector<string> split(const string& s) {
	vector<string> ret;
	typedef string::const_iterator iter;
	iter i = s.begin();

	while (i != s.end()) {
		i = std::find_if(i, s.end(), not_space);

		iter j = std::find_if(i, s.end(), space);

		if (i != s.end()) {
			ret.push_back(string(i, j));
		}
		i = j;
	}

	return ret;
}

// Chapter6 Example 1-3
vector<string> find_urls(const string& s) {
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	// string 내에 있는 url들을 하나씩 찾아 ret에 push
	while (b != e) {
		b = url_beg(b, e);
		if (b != e) {
			// b에서 e까지의 문자열 중 맨 처음 나오는 after까지를 찾아서
			// [url_beg()]://[url_end(b, e) 를 저장하고
			// 순차적으로 찾는다
			iter after = url_end(b, e);
			ret.push_back(string(b, after));
			b = after;
		}
	}
	return ret;
}

string::const_iterator url_beg(string::const_iterator begin, string::const_iterator end) {

	static const string sep = "://";
	typedef string::const_iterator iter;
	iter i = begin;

	// search 는 algorithm 라이브러리에 있는 메서드로
	// i부터 end까지를 sep의 시작과 끝으로 검색
	// 가장 먼저 나오는 위치를 찾게 되고
	// 없으면 마지막 iter(= end)를 리턴하는듯?
	
	while ((i = search(i, end, sep.begin(), sep.end())) != end) {
		if (i != begin && i + sep.size() != end) {
			// beg는 protocol-name 부분
			iter beg = i;
			while (beg != begin && isalpha(beg[-1])) {
				--beg;
			}

			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}

		i += sep.size();
	}
	return end;
}

string::const_iterator url_end(string::const_iterator begin, string::const_iterator end) {
	return std::find_if(begin, end, not_url_char);
}

bool not_url_char(char c) {
	// 책에 써있는 url_ch가 잘못되어 수정함.
	static const string url_char = "~;/?:@=&$-_.+!*'(),";

	return !(isalnum(c)
		|| find(url_char.begin(), url_char.end(), c) != url_char.end());
}

// Chapter6 Example2
bool did_all_hw(const Student_info& s) {
	// find로 s.homework에 0이 있는지 찾는다
	// 없으면 find의 return 값이 s.homework.end() 가 되므로
	// true를 리턴하게 된다. 즉, 모든 homework를 제출한 것으로
	return (find(s.homework.begin(), s.homework.end(), 0) == s.homework.end());
}

void classify_did_hw(const vector<Student_info>& s
	, vector<Student_info>& did
	, vector<Student_info>& didnt) {
	for (vector<Student_info>::const_iterator iter = s.begin();
		iter != s.end(); ++iter) {
		
		if (did_all_hw(*iter)) {
			did.push_back(*iter);
		}
		else {
			didnt.push_back(*iter);
		}
	}

	if (did.empty()) {
		cout << "No student did all the homework!" << endl;
	}
	if (didnt.empty()) {
		cout << "Every Student did all the homework!" << endl;
	}

	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);
}

double median_analysis(const vector<Student_info>& s) {
	vector<double> grades;
	std::transform(s.begin(), s.end(), std::back_inserter(grades), grade_aux);
	return get_median_value(grades);
}
double average(const vector<double>& v) {
	// accumulate는 numeric 라이브러리에 있는 메서드
	// Q. 0.0은 무엇인가?
	// A. double 타입으로 하려고.. 0으로 하면 int로 간주한다고함
	return (std::accumulate(v.begin(), v.end(), 0.0) / v.size());
}

double average_grade(const Student_info& s) {
	return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& s) {
	vector<double> grades;
	std::transform(s.begin(), s.end(), back_inserter(grades), average_grade);
	return get_median_value(grades);
}

double optimistic_median(const Student_info& s) {
	vector<double> nonzero;
	// remove_copy는 무엇인가?
	// iterator를 돌면서 0인 항목을 지우고 
	// 지워지지 않은 값들은 nonzero에 복사되는거 같네
	std::remove_copy(s.homework.begin(), s.homework.end(), std::back_inserter(nonzero), 0);
	if (nonzero.size()) {
		return grade(s.midterm, s.final, 0);
	}
	else {
		return grade(s.midterm, s.final, get_median_value(nonzero));
	}
}
double optimistic_median_analysis(const vector<Student_info>& s) {
	vector<double> grades;
	std::transform(s.begin(), s.end(), back_inserter(grades), optimistic_median);
	return get_median_value(grades);
}

// 한발 더 나아가기
// iterator를 모아놓은 vector로 성적을 산출하는 방법은 어떨까?
// iterator는 pointer의 특성을 가진 객체이나 둘 사이에는 차이점이 있다 


// Chapter6 Example 3
vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fails;
	std::remove_copy_if(students.begin(), students.end(), std::back_inserter(fails), pgrade);
	 
	students.erase(std::remove_if(students.begin(), students.end(), fgrade), students.end());

	return fails;
}

bool fgrade(const Student_info& s) {
	return (grade(s) < 50);
}

bool pgrade(const Student_info& s) {
	return (!fgrade(s));
}

void compute_students_grade(Students& s) {
	for (Students::iterator iter = s.begin(); iter != s.end(); ++iter)
	{
		grade(*iter);
	}
}

// Chapter6 Example 3 - 2
Students extract_fails_ext(Students& s) {
	Students::iterator iter = std::stable_partition(s.begin(), s.end(), pgrade);
	Students fails(iter, s.end());
	s.erase(iter, s.end());
	return fails;
}

