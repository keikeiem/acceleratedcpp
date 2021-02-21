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

int main() {
	//return Chapter6Example1();
	//return Chapter6Example1_1();
	//return Chapter6Example1_2();
	//return Chapter6Example1_3();
	return Chapter6Example2();
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

	// string ���� �ִ� url���� �ϳ��� ã�� ret�� push
	while (b != e) {
		b = url_beg(b, e);
		if (b != e) {
			// b���� e������ ���ڿ� �� �� ó�� ������ after������ ã�Ƽ�
			// [url_beg()]://[url_end(b, e) �� �����ϰ�
			// ���������� ã�´�
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

	// search �� algorithm ���̺귯���� �ִ� �޼����
	// i���� end������ sep�� ���۰� ������ �˻�
	// ���� ���� ������ ��ġ�� ã�� �ǰ�
	// ������ ������ iter(= end)�� �����ϴµ�?
	
	while ((i = search(i, end, sep.begin(), sep.end())) != end) {
		if (i != begin && i + sep.size() != end) {
			// beg�� protocol-name �κ�
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
	// å�� ���ִ� url_ch�� �߸��Ǿ� ������.
	static const string url_char = "~;/?:@=&$-_.+!*'(),";

	return !(isalnum(c)
		|| find(url_char.begin(), url_char.end(), c) != url_char.end());
}

// Chapter6 Example2
bool did_all_hw(const Student_info& s) {
	// find�� s.homework�� 0�� �ִ��� ã�´�
	// ������ find�� return ���� s.homework.end() �� �ǹǷ�
	// true�� �����ϰ� �ȴ�. ��, ��� homework�� ������ ������
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
}

double median_analysis(const vector<Student_info>& s) {
	vector<double> grades;
	//std::transform(s.begin(), s.end(), std::back_inserter(grades), grade_aux);
	return get_median_value(grades);
}



// �ѹ� �� ���ư���
// iterator�� ��Ƴ��� vector�� ������ �����ϴ� ����� ���?
// iterator�� pointer�� Ư���� ���� ��ü�̳� �� ���̿��� �������� �ִ� 
