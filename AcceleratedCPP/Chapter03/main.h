#pragma once
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

void Greeting(const string name);
string InsertName(void);
void ParseSentence(vector<string> * word_v, vector<int> * int_v, const string str, const char delimeter = ' ');
void InsertWord(vector<string> * word_v, vector<int> * int_v, const string& word);

void Chapter3Example3() {
	cout << "Enter first name: ";
	string name = InsertName();
	Greeting(name);

	cout << "Enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Enter your homework grades, "
		<< "followed by endoffile: ";

	vector<double> homework;
	double x;
	while (cin >> x) {
		homework.push_back(x);
	}

	// homework 데이터 입력여부 체크
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0) {
		cout << endl << "You must enter your grades. "
			<< "Please try again." << endl;
		return;
	}

	//정렬
	sort(homework.begin(), homework.end());

	// homework 중앙값 계산
	vec_sz mid = (size / 2);
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[(mid - 1)]) / 2 : homework[mid];

	// 최종 성적 계산
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;
}

void Chapter3Problem2() {
	cout << "Enter integer numbers at least 5: ";
	vector<int> integer_items;
	int x;
	while (cin >> x) {
		integer_items.push_back(x);
	}

	vector<int>::size_type size = integer_items.size();
	if (size < 5) {
		cout << endl;
		cout << "You should insert at least one integer number.";
		return;
	}

	// 기본 sort는 ascending으로 된다.
	// descending 하려면 
	//sort(integer_items.begin(), integer_items.end());
	sort(integer_items.begin(), integer_items.end(), std::greater<int>());

	int count = 0;
	int summation = 0;
	for (auto iter = integer_items.begin(); iter != integer_items.end(); iter++) {
		summation += (*iter);
		count++;
		if (count == 4) break;
	}

	cout << "Result: " << summation << endl;
}

void Chapter3Problem3() {
	vector<string> word_items;
	vector<int> integer_items;

	vector<string> string_items;
	string x;
	while (cin >> x) {
		string_items.push_back(x);
	}

	vector<string>::size_type size = string_items.size();
	if (size == 0) {
		return;
	}

	// begin/end를 iteration 처리
	for (auto iter_str = string_items.begin(); iter_str != string_items.end(); iter_str++) {
		ParseSentence(&word_items, &integer_items, (*iter_str));
	}

	// vector index로 접근하기
	/*for (vector<string>::size_type i = 0; i < size; i++) {
		ParseSentence(&word_items, &integer_items, string_items[i]);
	}*/

	int pos = 0;
	for (auto iter = word_items.begin(); iter != word_items.end(); iter++)
	{
		cout << (*iter) << " | " << integer_items[pos] << endl;
		pos++;
	}
}

#endif