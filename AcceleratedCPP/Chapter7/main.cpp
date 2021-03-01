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
	// accumulate�� numeric ���̺귯���� �ִ� �޼���
	// Q. 0.0�� �����ΰ�?
	// A. double Ÿ������ �Ϸ���.. 0���� �ϸ� int�� �����Ѵٰ���
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
	// remove_copy�� �����ΰ�?
	// iterator�� ���鼭 0�� �׸��� ����� 
	// �������� ���� ������ nonzero�� ����Ǵ°� ����
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

// �ѹ� �� ���ư���
// iterator�� ��Ƴ��� vector�� ������ �����ϴ� ����� ���?
// iterator�� pointer�� Ư���� ���� ��ü�̳� �� ���̿��� �������� �ִ� 


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

		// ������ �ܾ�� �ɰ���
		Rule words = find_words(line);

		// �� �ܾ ���� ���ο� ��Ÿ������ ���
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
	// ������ ����� �޼���	

	Rule ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}
bool bracketed(const string& s) {
	// <noun>, <verb> �� ���� rule�� �ش��ϴ� �� ���θ� �Ǵ��ϴ� �Լ�
	return (s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>');
}

void gen_aux(const Grammar& g, const string& word, Rule& ret) {
	// g���� word�� �ش��ϴ� ���� �̾Ƴ��� v�� �ִ´�
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