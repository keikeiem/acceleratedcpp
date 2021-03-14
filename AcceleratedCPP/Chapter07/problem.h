#ifndef PROBLEM_H
#define PROBLEM_H

#include <string>
#include <random>

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

int Chapter7Problem1() {
	// 단어별로 개수를 세려고 함
	string s;
	std::map<string, int> counters;

	Rule messages;
	messages.push_back("sometimes things happen that are just out of your control");
	messages.push_back("you are on your own");
	messages.push_back("you are so much more than awesome");

	for (Rule::const_iterator iter = messages.begin(); iter != messages.end(); ++iter)
	{
		Rule words = split(*iter);
		for (Rule::const_iterator iter_word = words.begin();
			iter_word != words.end(); ++iter_word) {

			++counters[(*iter_word)];
		}
	}

	/*for (std::map<string, int>::const_iterator iter = counters.begin();
		iter != counters.end(); ++iter)
	{
		cout << iter->first << "\t" << iter->second << endl;
	}
	return 0;*/

	map<int, Rule> result;
	for (map<string, int>::const_iterator iter = counters.begin(); iter != counters.end(); ++iter)
	{
		result[iter->second].push_back(iter->first);
	}

	int count = 0;
	for (std::map<int, Rule>::const_iterator iter = result.begin();
		iter != result.end(); ++iter)
	{
		cout << iter->first << ": ";
		count = 0;
		for (Rule::const_iterator it = iter->second.begin(); it != iter->second.end(); ++it)
		{
			if (count > 0)
				cout << ", ";

			cout << (*it);
			count++;
		}
		cout << endl;
	}
	return 0;
}

int adv_nrand(const int n, bool print = false) {
	if (n <= 0 || n > INT_MAX)
		throw domain_error("Argument to nrand is out of range");

	if (n < RAND_MAX)
	{
		return nrand(n, print);
	}
	else
	{
		// 80000
		// 80000 / RAND_MAX 이 올림값인 3만큼의 범위에서
		// nrand(RAND_MAX + 1)
		// 두개를 합산한 값이 80000보다 작을 때까지 do-while

		const int divisor = ceil(n / (RAND_MAX + 1));

		int ret; 
		do ret = (nrand(RAND_MAX + 1) * divisor) + nrand(divisor);
		while (ret >= n);

		if (print)
			cout << "random number: " << ret << endl;

		return ret;
	}
}

int Chapter7Problem5() {
	// 문장 무작위 생성 프로그램을 list 타입으로 만들기

	//Grammar grammar_ = read_grammar(cin);	
	// show_map_string_with_vstring(grammar_);

	Rule lines;
	lines.push_back("<noun> cat");
	lines.push_back("<noun> dog");
	lines.push_back("<noun> table");

	lines.push_back("<noun-phrase> <noun>");
	lines.push_back("<noun-phrase> <adjective> <noun-phrase>");

	lines.push_back("<adjective> large");
	lines.push_back("<adjective> brown");
	lines.push_back("<adjective> absurd");

	lines.push_back("<verb> jumps");
	lines.push_back("<verb> sits");

	lines.push_back("<location> on the stairs");
	lines.push_back("<location> under the sky");
	lines.push_back("<location> wherever it wants");

	lines.push_back("<sentence> the <noun-phrase> <verb> <location>");

	//Grammar grammar = read_grammar(cin);
	Grammar grammar;
	read_grammar_for_test(grammar, lines);

	//Grammar grammar = read_grammar_on_book(cin);

	show_map_string_with_vstring(grammar);

	// nrand() 에서 항상 같은 값을 리턴하기에
	// 아래와같이 srand를 선언해줘야함 <time.h>
	// 여러번 선언하면 오류나므로 한 번만!
	srand(time(NULL));

	Rule result = gen_sentence(grammar);

	Rule::const_iterator it = result.begin();
	if (!result.empty()) {
		cout << *it;
		++it;
	}

	while (it != result.end())
	{
		cout << " " << (*it);
		++it;
	}
	return 0;
}

int nrand_ext(int n, bool print) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, n);

	int ret = dis(gen);
	if (print)
		cout << ret << endl;

	return ret;
}

int Chapter7Problem9() {
	srand(time(NULL));
	int max_range = 80000;

	int i = 0;
	while (i < 100)
	{
		adv_nrand(max_range, true);
		++i;
	}

	// 테스트해서 비율을 확인하는것도 흥미로울듯
	// rand() 함수 특성상 Normal Distribution을 따르지 않을까?

	return 0;
}

#endif