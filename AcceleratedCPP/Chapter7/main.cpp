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
	//return Chapter7Example2();
	//return Chapter7Example3();
	//return Chapter7Example4();

	//return Chapter7Problem1();
	//return Chapter7Problem5();
	//return Chapter7Problem9();
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

Rule split(const string& s) {
	Rule ret;
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
Rule find_urls(const string& s) {
	Rule ret;
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

// Chapter7 Example 3
map<string, vector<int> > xref(std::istream& in, Rule find_words(const string&))
{
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;

	while (std::getline(in, line))
	{
		++line_number;

		// 라인을 단어별로 쪼개기
		Rule words = find_words(line);

		// 각 단어가 현재 라인에 나타났는지 기록
		for (Rule::iterator iter = words.begin(); iter != words.end(); ++iter)
		{
			ret[(*iter)].push_back(line_number);
		}
	}	
	return ret;
}

void show_map_string_with_vint(const map<string, vector<int> >& m)
{
	int count = 0;
	for (map<string, vector<int> >::const_iterator iter = m.begin(); iter != m.end(); ++iter)
	{
		cout << iter->first << ":" << endl;
		count = 0;
		for (vector<int>::const_iterator iter_int = iter->second.begin();
			iter_int != iter->second.end(); ++iter_int)
		{
			if (count > 0)
				cout << " | ";

			cout << (*iter_int);
			count++;
		}
		cout << endl;
	}
}

// Chapter7 Example4
Grammar read_grammar(std::istream& cin) {
	Grammar ret;
	string line;
	while (std::getline(cin, line)) {
		Rule entry = split(line);

		if (!entry.empty())
		{
			Rule::iterator iter = entry.begin();
			ret[(*iter)].push_back(
				//Rule(entry.begin(), entry.end())
				entry
			);
		}
	}
	return ret;
}

void show_map_string_with_vstring(const Grammar& item) {
	int count = 0;
	for (Grammar::const_iterator iter = item.begin(); iter != item.end(); ++iter)
	{
		count = 0;
		cout << iter->first << ":" << endl;
		for (Rule_collection::const_iterator iter_rule = iter->second.begin();
			iter_rule != iter->second.end(); ++iter_rule)
		{
			if (count > 0)
				cout << ", ";
			for (Rule::const_iterator it = (*iter_rule).begin();
				it != (*iter_rule).end(); ++it)
			{
				cout << (*it);
			}
			count++;
		}
		cout << endl;
	}
}

Rule gen_sentence(const Grammar& g) {
	// 문장을 만드는 메서드	

	Rule ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}
bool bracketed(const string& s) {
	// <noun>, <verb> 와 같이 rule에 해당하는 값 여부를 판단하는 함수
	return (s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>');
}

void gen_aux(const Grammar& g, const string& word, Rule& ret) {
	// g에서 word에 해당하는 값을 뽑아내서 v에 넣는다
	if (!bracketed(word))
	{
		ret.push_back(word);
	}
	else
	{
		Grammar::const_iterator iter = g.find(word);
		if (iter == g.end())
			throw std::logic_error("empty rule");

		const Rule_collection& c = iter->second;

		//cout << iter->first << "nrand: " << c.size() << " | " << nrand(c.size()) << endl;
		Rule_collection::const_iterator iter_rc = c.begin();

		int count = 0;
		int random_number = nrand(c.size());
		while (count < random_number)
		{
			iter_rc++;
			count++;
		}

		
		const Rule& r = (*iter_rc);
		for (Rule::const_iterator iter_rule = r.begin();
			iter_rule != r.end(); ++iter_rule)
		{
			gen_aux(g, (*iter_rule), ret);
		}
	}
}

int nrand(const int n, bool print) {
	if (n <= 0)
		throw domain_error("Argument to nrand is out of range");

	const int bucket_size = (n > RAND_MAX ? 1 : RAND_MAX / n);

	int ret;
	do ret = rand() / bucket_size;
	while (ret >= n);

	if (print)
		cout << "random number: " << ret << endl;

	return ret;
}

void read_grammar_for_test(Grammar& g, const Rule& r) {

	for (Rule::const_iterator iter = r.begin(); iter != r.end(); ++iter)
	{
		Rule entry = split(*iter);

		if (!entry.empty())
		{
			Rule::const_iterator it = entry.begin();

			Rule word;
			while (it != entry.end()) {
				it++;
				if (it == entry.end())
					break;

				word.push_back(*it);
			}

			g[*(entry.begin())].push_back(word);
		}
	}
}

Grammar read_grammar_on_book(std::istream& in) {
	Grammar ret;
	string line;
	while (std::getline(in, line))
	{
		vector<string> entry = split(line);

		Rule test = Rule(entry.begin() + 1, entry.end());

		if (!entry.empty())
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
	}

	return ret;
}