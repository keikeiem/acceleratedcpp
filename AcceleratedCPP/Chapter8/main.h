#ifndef METHOD_H
#define METHOD_H

#include <string>
#include <map>

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
using std::map;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
//typedef list<string> Rule;
//typedef list<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

template <class T>
T median(vector<T> v) {
	typedef typename vector<T>::size_type vec_sz;
	vec_sz size = v.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(v.begin(), v.end());

	vec_sz mid = size / 2;

	return (size % 2 == 0) ? (v[mid] + v[(mid - 1)]) / 2 : v[mid];
}

template <class T>
T max(const T& left, const T& right) {
	return (left > right) ? left : right;
}

int Chapter8Example1() {
	vector<double> vec;
	vec.push_back(1.2);
	vec.push_back(1.4);
	vec.push_back(1.5);
	vec.push_back(1.7);
	vec.push_back(2.1);

	// median
	double result = median(vec);
	cout << result << endl;

	// max
	int A = 1;
	double B = 1.5;

	max((double)A, B);

	return 0;
}

template <class In, class X>
//In find(In begin, In end, const X& x) {
//	while (begin != end && (*begin) != x) {
//		++begin;
//	}
//	return (begin);
//}
In find_iter(In begin, In end, const X& x) {
	if (begin == end || (*begin) == x)
		return (begin);
	begin++;
	return find_iter(begin, end, x);
}

template <class In, class Out>
Out copy_item(In begin, In end, Out dest) {
	// dest means destination
	while (begin != end) {
		(*dest++) = *begin++;
	}
	return dest;
}

template <class For, class X>
void replace_item(For beg, For end, const X& x, const X& y) {
	// 아마도
	// beg부터 end까지 x를 찾아서 y로 변환하는 것
	while (beg != end) {
		if ((*beg) == x)
			*beg = y;

		++beg;
	}
}

template <class Bi>
void reverse_item(Bi begin, Bi end) {
	while (begin != end) {
		// -- 가 되는 iterator를
		// bidirectional iterator 라고 함.
		// bi + directional 이겠지 뭐
		// 그래서 Bi 라고 쓴 모양
		--end;

		if (begin != end)
		{
			// end에서 begin 방향으로 가는데

			std::swap(*begin++, *end);
		}
	}
}

template <class Ran, class X>
// Range, Value
bool binary_search_item(Ran begin, Ran end, const X& x) {
	while (begin != end) {
		Ran mid = begin + (end - begin) / 2;
		if (x < *mid)
		{
			end = mid;
		}
		else if (*mid < x)
		{
			begin = mid + 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

int Chapter8Example2() {
	vector<double> vec;
	vec.push_back(1.2);
	vec.push_back(1.4);
	vec.push_back(1.5);
	vec.push_back(1.7);
	vec.push_back(2.1);

	// find
	vector<double>::iterator iter = find_iter(vec.begin(), vec.end(), 1.5);

	if (iter == vec.end())
	{
		domain_error("no matched double number");
		return 1;
	}
	cout << "find: " << (*iter) << endl;

	// copy
	// *************
	// back_inserter를 잊으면 안된다
	// *************
	vector<double> dest;
	copy_item(vec.begin() + 1, vec.end(), std::back_inserter(dest));
	cout << "copied dest is:" << endl;
	for (vector<double>::const_iterator iter = dest.begin();
		iter != dest.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

	// replace
	replace_item(vec.begin(), vec.end(), 1.5, 2.4);
	cout << "replaced vec is:" << endl;
	for (vector<double>::const_iterator iter = vec.begin();
		iter != vec.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

	reverse_item(vec.begin(), vec.end());
	cout << "reversed vec is:" << endl;
	for (vector<double>::const_iterator iter = vec.begin();
		iter != vec.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

	bool is_value = binary_search_item(vec.begin(), vec.end(), 1.3);
	cout << "is_value: " << is_value << endl;

	return 0;
}

int Chapter8Example2_list() {
	list<double> vec;
	vec.push_back(1.2);
	vec.push_back(1.4);
	vec.push_back(1.5);
	vec.push_back(1.7);
	vec.push_back(2.1);

	// find
	list<double>::iterator iter = find_iter(vec.begin(), vec.end(), 1.5);

	if (iter == vec.end())
	{
		domain_error("no matched double number");
		return 1;
	}
	cout << "find: " << (*iter) << endl;

	// copy
	// *************
	// back_inserter를 잊으면 안된다
	// *************
	list<double> dest;
	copy_item(++vec.begin(), vec.end(), std::back_inserter(dest));
	cout << "copied dest is:" << endl;
	for (list<double>::const_iterator iter = dest.begin();
		iter != dest.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

	// replace
	replace_item(vec.begin(), vec.end(), 1.5, 2.4);
	cout << "replaced vec is:" << endl;
	for (list<double>::const_iterator iter = vec.begin();
		iter != vec.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

	reverse_item(vec.begin(), vec.end());
	cout << "reversed vec is:" << endl;
	for (list<double>::const_iterator iter = vec.begin();
		iter != vec.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

	//bool is_value = binary_search_item(vec.begin(), vec.end(), 1.3);
	bool is_value = std::binary_search(vec.begin(), vec.end(), 1.3);
	cout << "is_value: " << is_value << endl;

	return 0;
}
#endif