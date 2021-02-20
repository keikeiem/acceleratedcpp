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
Students extract_fails(Students& s); // only vector (problem 6)
Students resize_vector(Students& s); // only vector (problem 6)

int Chapter5Example1() {
	Students students;

	Student_info record;

	string::size_type max_length = 0;

	vector<double> hw1;
	hw1.push_back(10);
	hw1.push_back(20);
	hw1.push_back(30);
	hw1.push_back(40);
	read_test(record, "kimkm", 100, 100, hw1);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	vector<double> hw2;
	hw2.push_back(50);
	hw2.push_back(40);
	hw2.push_back(30);
	hw2.push_back(40);
	read_test(record, "kyungmin", 50, 50, hw2);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	students.push_back(random_grade("note"));
	students.push_back(random_grade("alpha"));
	students.push_back(random_grade("beta"));
	students.push_back(random_grade("gamma"));
	students.push_back(random_grade("delta"));
	students.push_back(random_grade("epsilon"));

	//sort(students.begin(), students.end(), compare);

	/*Students failed_students;
	typedef vector<Student_info>::size_type std_size;
	for (std_size i = 0; i != students.size(); ++i) {
		cout << students[i].name
			<< string(max_length + 1 - students[i].name.size(), ' ');

		try {
			students[i].grade = grade(students[i]);
			streamsize prec = cout.precision(3);
			cout << setprecision(3) << students[i].grade
				<< setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}*/

	// Chapter5 Example 1.1
	// 인덱스를 사용한 vector 접근 방식
	//classify_index(students, failed_students);
	// Chapter5 Example 1.2
	// iterator를 사용한 vector 접근 방식
	
	Students failed_students = classify_iter(students);

	cout << "passed:" << endl;
	PrintStudentsData(students);
	cout << "failed:" << endl;
	PrintStudentsData(failed_students);

	return 0;
}

// list 타입
int Chapter5Example5() {
	Students students;

	Student_info record;

	string::size_type max_length = 0;

	vector<double> hw1;
	hw1.push_back(10);
	hw1.push_back(20);
	hw1.push_back(30);
	hw1.push_back(40);
	read_test(record, "kimkm", 100, 100, hw1);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	vector<double> hw2;
	hw2.push_back(50);
	hw2.push_back(40);
	hw2.push_back(30);
	hw2.push_back(40);
	read_test(record, "kyungmin", 50, 50, hw2);
	max_length = std::max(max_length, record.name.size());
	students.push_back(record);

	students.push_back(random_grade("note"));
	students.push_back(random_grade("alpha"));
	students.push_back(random_grade("beta"));
	students.push_back(random_grade("gamma"));
	students.push_back(random_grade("delta"));
	students.push_back(random_grade("epsilon"));

	//students.sort(compare);
	grade(students);
	Students failed_students = classify_iter(students);
	// Chapter5 Example 1.1
	// 인덱스를 사용한 vector 접근 방식
	//classify_index(students, failed_students);
	// Chapter5 Example 1.2
	// iterator를 사용한 vector 접근 방식
	//classify_iter(students, failed_students);


	cout << "passed:" << endl;
	PrintStudentsData(students);
	cout << "failed:" << endl;
	PrintStudentsData(failed_students);

	return 0;
}

vector<string> split(const string&);

int Chapter5Example6() {
	string letters = "Look at the picture marked number one in your test book";

	/*for (auto iter = letters.begin(); iter != letters.end(); iter++) {
		cout << (*iter) << endl;
	}*/

	vector<string> space_split = split(letters);
	for (auto iter = space_split.begin(); iter != space_split.end(); iter++) {
		cout << (*iter) << endl;
	}

	return 0;
}

int Chapter5Example7() {
	string s;
	while (getline(cin, s)) {
		vector<string> v = split(s);
		for (vector<string>::size_type i = 0; i != v.size(); ++i) {
			cout << v[i] << endl;
		}
	}

	return 0;
}

int Chapter5Example7_2() {
	// Same as Chapter5Example7
	string s;
	while (cin >> s) {
		cout << s << endl;
	}
	return 0;
}
string::size_type width(const vector<string>& v);
vector<string> frame(const vector<string>& v);
vector<string> gen_vector(void) {
	vector<string> vec;
	vec.push_back("this is an");
	vec.push_back("example");
	vec.push_back("to");
	vec.push_back("illustrate");
	vec.push_back("framing");
	return vec;
};

vector<string> gen_vector2(void) {
	vector<string> vec;
	vec.push_back("Look at");
	vec.push_back("the picture");
	vec.push_back("marked");
	vec.push_back("number one");
	vec.push_back("in your testbook");
	return vec;
};

void show_vector_string(const vector<string>& vec) {
	for (vector<string>::size_type i = 0; i < vec.size(); ++i) {
		cout << vec[i] << endl;
	}
}
int Chapter5Example8() {
	// 그림의 외곽 그리기 (asterisk *)
	vector<string> vec = gen_vector();
	vector<string> result = frame(vec);
	show_vector_string(result);

	return 0;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom);
int Chapter5Example8_2() {
	vector<string> vec = gen_vector();
	vector<string> ret = vcat(vec, frame(vec));

	show_vector_string(ret);

	return 0;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right);
int Chapter5Example8_3() {
	vector<string> vec = gen_vector();
	vector<string> ret = hcat(vec, frame(vec));
	show_vector_string(ret);

	return 0;
}

#endif