#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <vector>

#include "grade.h"

class Core
{
	friend class StudentInfo;
public:
	Core();
	Core(std::string s);
	Core(std::istream&);
	// 소멸자를 virtual로 추가
	virtual ~Core() { }

	std::string name() const;

	virtual std::istream& read(std::istream&);
	virtual double grade() const;
	virtual void regrade(double d1, double d2 = 0) {
		final = d1;
	}
	virtual bool valid() const {
		return (homework.size() > 0);
	}

protected:
	std::istream& read_common(std::istream&);
	std::istream& read_homework(std::istream&, std::vector<double>&);
	double midterm, final;
	std::vector<double> homework;

	virtual Core* clone() const { return new Core(*this); }

private:
	std::string n;
};

#endif