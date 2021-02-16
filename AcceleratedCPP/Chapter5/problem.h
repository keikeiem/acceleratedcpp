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

#endif