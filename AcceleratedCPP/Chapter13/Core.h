#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <vector>

class Core
{
public:
	Core();
	Core(std::istream&);
	std::string name() const;
	std::istream& read(std::istream&);
	double grade() const;
private:
	std::istream& read_common(std::istream&);
	std::string n;
	double midterm, final;
	std::vector<double> homework;
};

#endif