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

int Chapter6Problem2() {
	vector<string> vec;
	vec.push_back("The address of naver is http://www.naver.com you can find a lot of things. You can get some files from http://ftp.kakao.co.kr");
	vec.push_back("The address of google is http://www.google.com you can find a lot of things. File transform protocol example address: ftp://open.somewhere.com/files");
	vec.push_back("empty data://.");

	vector<string> result = find_urls(*(vec.begin()));

	show_strings(result);

	return 0;
}

int Chapter6Problem3() {
	// 100이 열 번 들어가네요
	vector<int> u(10, 100);
	cout << "u: " << endl;
	for (auto iter = u.begin(); iter != u.end(); ++iter)
	{
		cout << (*iter) << endl;
	}
	
	// vector<int> v     :: 크기가 정해져 있지 않아서 오류 발생
	vector<int> v(u.size());
	std::copy(u.begin(), u.end(), v.begin());

	cout << "v: " << endl;
	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

	return 0;
}

int Chapter6Problem9() {
	string str = "ASDF";
	vector<string> vec(20, str);
	string sentence = std::accumulate(vec.begin(), vec.end(), string(""));

	cout << sentence << endl;
	return 0;
}

#endif