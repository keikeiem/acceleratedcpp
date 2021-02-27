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
	vec.push_back("The address of google is http://www.google.com you can find a lot of things. File transform protocol example address: ftp://open.somewhere.com/files");
	vec.push_back("empty data://.");

	vector<string> result = find_urls(*(vec.begin() + 1));

	show_strings(result);

	return 0;
}

bool did_all_hw(const Student_info& s);
void classify_did_hw(const vector<Student_info>&, vector<Student_info>&, vector<Student_info>&);
double median_analysis(const vector<Student_info>& s);

double average(const vector<double>& v);
double average_grade(const Student_info& s);
double average_analysis(const vector<Student_info>& s);
double optimistic_median(const Student_info& s);
double optimistic_median_analysis(const vector<Student_info>& s);

void write_analysis(std::ostream& out
	, const string& name
	, double analysis(const vector<Student_info>&)
	, const vector<Student_info>& did
	, const vector<Student_info>& didnt) {
	out << name << ": median(did) = " << analysis(did) <<
		", median(didnt) = " << analysis(didnt) << endl;
};

int Chapter6Example2() {
	Students students;

	Student_info record;

	string::size_type max_length = 0;

	vector<double> hw1;
	hw1.push_back(10);
	hw1.push_back(0);
	hw1.push_back(0);
	hw1.push_back(30);
	cout << "kyungmin: " << get_median_value(hw1) << endl;
	read_test(record, "kimkm", 50, 50, hw1);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	vector<double> hw2;
	hw2.push_back(50);
	hw2.push_back(0);
	hw2.push_back(0);
	hw2.push_back(30);
	cout << "kyungmin: " << get_median_value(hw2) << endl;
	read_test(record, "kyungmin", 50, 50, hw2);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	students.push_back(random_grade("note"));
	students.push_back(random_grade("alpha"));
	students.push_back(random_grade("beta"));
	students.push_back(random_grade("gamma"));
	students.push_back(random_grade("delta"));
	students.push_back(random_grade("epsilon"));

	vector<Student_info> did, didnt;
	classify_did_hw(students, did, didnt);

	cout << "did: " << endl;
	PrintStudentsData(did);
	cout << "didnt: " << endl;
	PrintStudentsData(didnt);
	//students.sort(compare);
	//grade(students);
	//Students failed_students = classify_iter(students);
	// Chapter5 Example 1.1
	// 인덱스를 사용한 vector 접근 방식
	//classify_index(students, failed_students);
	// Chapter5 Example 1.2
	// iterator를 사용한 vector 접근 방식
	//classify_iter(students, failed_students);

	//cout << "passed:" << endl;
	//PrintStudentsData(students);
	//cout << "failed:" << endl;
	//PrintStudentsData(failed_students);

	return 0;
}

vector<Student_info> extract_fails(vector<Student_info>&);
bool fgrade(const Student_info& s);
bool pgrade(const Student_info& s);
void compute_students_grade(Students&);

int Chapter6Example3() {

	Students students;

	Student_info record;

	string::size_type max_length = 0;

	vector<double> hw1;
	hw1.push_back(10);
	hw1.push_back(0);
	hw1.push_back(0);
	hw1.push_back(30);
	cout << "kyungmin: " << get_median_value(hw1) << endl;
	read_test(record, "kimkm", 50, 50, hw1);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	vector<double> hw2;
	hw2.push_back(50);
	hw2.push_back(0);
	hw2.push_back(0);
	hw2.push_back(30);
	cout << "kyungmin: " << get_median_value(hw2) << endl;
	read_test(record, "kyungmin", 50, 50, hw2);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	students.push_back(random_grade("note"));
	students.push_back(random_grade("alpha"));
	students.push_back(random_grade("beta"));
	students.push_back(random_grade("gamma"));
	students.push_back(random_grade("delta"));
	students.push_back(random_grade("epsilon"));

	// grade 계산부터 하자
	compute_students_grade(students);

	vector<Student_info> did, didnt;
	classify_did_hw(students, did, didnt);

	/*cout << "did: " << endl;
	PrintStudentsData(did);
	cout << "didnt: " << endl;
	PrintStudentsData(didnt);*/
	Students failed_students = extract_fails(students);

	cout << " " << endl;
	cout << "passed students: " << endl;
	PrintStudentsData(students);

	cout << " " << endl;
	cout << "failed students: " << endl;
	PrintStudentsData(failed_students);

	return 0;
}

vector<Student_info> extract_fails_ext(vector<Student_info>&);
int Chapter6Example3_2() {

	Students students;

	Student_info record;

	string::size_type max_length = 0;

	vector<double> hw1;
	hw1.push_back(10);
	hw1.push_back(0);
	hw1.push_back(0);
	hw1.push_back(30);
	cout << "kyungmin: " << get_median_value(hw1) << endl;
	read_test(record, "kimkm", 50, 50, hw1);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	vector<double> hw2;
	hw2.push_back(50);
	hw2.push_back(0);
	hw2.push_back(0);
	hw2.push_back(30);
	cout << "kyungmin: " << get_median_value(hw2) << endl;
	read_test(record, "kyungmin", 50, 50, hw2);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	students.push_back(random_grade("note"));
	students.push_back(random_grade("alpha"));
	students.push_back(random_grade("beta"));
	students.push_back(random_grade("gamma"));
	students.push_back(random_grade("delta"));
	students.push_back(random_grade("epsilon"));

	// grade 계산부터 하자
	compute_students_grade(students);

	vector<Student_info> did, didnt;
	classify_did_hw(students, did, didnt);

	/*cout << "did: " << endl;
	PrintStudentsData(did);
	cout << "didnt: " << endl;
	PrintStudentsData(didnt);*/
	Students failed_students = extract_fails_ext(students);

	cout << " " << endl;
	cout << "passed students: " << endl;
	PrintStudentsData(students);

	cout << " " << endl;
	cout << "failed students: " << endl;
	PrintStudentsData(failed_students);

	return 0;
}

#endif