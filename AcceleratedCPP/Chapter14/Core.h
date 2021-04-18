#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <vector>

#include "grade.h"
#include "handle.h"
#include "ReferenceHandle.h"
#include "Ptr.h"

class Core
{
	friend class StudentInfo;
	friend class StudentInfoPtr;
	friend class Handle<Core>;
	friend class ReferenceHandle<Core>;
	friend class Ptr<Core>;
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
	virtual std::string letter_grade(const double grade);
	virtual void show(void);
	virtual void make_unique(void);

	virtual Core* clone() const { return new Core(*this); }
protected:
	std::istream& read_common(std::istream&);
	std::istream& read_homework(std::istream&, std::vector<double>&);
	double midterm, final;
	std::vector<double> homework;

	

private:
	std::string n;
};

#endif