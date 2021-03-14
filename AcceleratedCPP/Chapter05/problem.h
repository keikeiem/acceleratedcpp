#ifndef PROBLEM_H
#define PROBLEM_H

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

void make_rotation(vector<string>& container, const string& v);

int Chapter5Problem1() {
	vector<string> vec;
	vec.push_back("The quick brown fox");
	vec.push_back("jumped over the fence");
	// 색인 만들기 (결과)
	//       The quick      brown fox
	// jumped over the      fence
	// The quick brown      fox
	//                      jumped over the fence
	//          jumped      over the fence
	//             The      quick brown fox
	//     jumped over      the fence
	//                      The quick brown fox
	vector<string> container;
	for (vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
		make_rotation(container, *iter);
	}
	show_vector_string(container);

	// 색인은 다 만들었는데
	// 문제에서 주어진 3단계 방식을 이해하지 못하겠음...

	return 0;
}

int Chapter5Problem4() {
	// typedef를 통해 vector<Student_info> 와 list<Student_info> 케이스를
	// 쉽게 전환할 수 있도록 소스 변경하기
	return 0;
}

int Chapter5Problem6() {
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
	grade(students);
	//Students failed_students = extract_fails(students);
	Students failed_students = resize_vector(students);
	//Students failed_students = classify_iter(students);

	cout << "passed:" << endl;
	PrintStudentsData(students);
	cout << "failed:" << endl;
	PrintStudentsData(failed_students);

	return 0;
}

int Chapter5Problem9() {
	// lower case letters to upper case
	string str;
	cin >> str;

	if (str.empty())
		return 0;

	// result라는 새로운 string을 만드는 방식
	string result;
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter) {
		result += toupper(*iter);
	}
	cout << "result: " << result << endl;

	// 원문을 변경하는 방식?
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter) {
		(*iter) = toupper(*iter);
	}
	cout << "str:    " << str << endl;
	return 0;
}

int Chapter5Problem10() {
	// 회문 체크하기
	vector<string> vec;
	vec.push_back("mom is mom");
	vec.push_back("anana");
	vec.push_back("tomato");
	// trim해서 비교하진 않았음..

	vector<string> result;

	bool statement = false;
	string::size_type total;
	for (vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
		total = (*iter).size();
		statement = true;
		string::size_type fin = (total / 2);
		for (string::size_type i = 0; i <= fin; i++) {
			if ((*iter)[i] != (*iter)[total - (i + 1)]) {
				statement = false;
				break;
			}
		}
		if (statement)
			result.push_back(*iter);
	}

	// 결과보기
	for (vector<string>::const_iterator it = result.begin(); it != result.end(); ++it) {
		cout << (*it) << endl;
	}

	return 0;
}

int Chapter5Problem11() {
	// ascender char: b, d, f, h, k, l, t
	// descender char: g, j, p, q, y

}

#endif