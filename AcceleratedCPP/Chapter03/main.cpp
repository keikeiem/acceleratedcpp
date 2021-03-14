#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#include "main.h"

int main() {
	//Chapter3Example3();
	//Chapter3Problem2();
	Chapter3Problem3();

	return 0;
}

void Greeting(const string name) {
	cout << "Hello, " << name << "!" << endl;
}

string InsertName(void) {
	string name;
	cin >> name;

	return (name);
}

void ParseSentence(vector<string> * word_items, vector<int> * integer_items, const string str, const char delimeter) {
	size_t begin_pos = -1;
	size_t end_pos = str.find(delimeter);

	while (str.substr((begin_pos + 1)).find(delimeter) <= str.length()) {
		InsertWord(word_items, integer_items, str.substr((begin_pos + 1), (end_pos - begin_pos - 1)));

		begin_pos = end_pos;
		end_pos += str.substr((begin_pos + 1)).find(delimeter) + 1;
	}
	InsertWord(word_items, integer_items, str.substr((begin_pos + 1)));
}

void InsertWord(vector<string> * str_v, vector<int> * int_v, const string & word) {

	bool is_exist = false;
	int pos = 0;
	for (auto iter = (*str_v).begin(); iter != (*str_v).end(); iter++) {
		if ((*iter) == word) {
			is_exist = true;
			(*int_v)[pos] += 1;
			break;
		}
		pos++;
	}

	// 없으면 신규 추가
	if (!is_exist) {
		(*str_v).push_back(word);
		(*int_v).push_back(1);
	}
}