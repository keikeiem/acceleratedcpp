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

#endif