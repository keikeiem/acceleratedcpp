#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>
#include <string>
#include <vector>

#include "PictureBase.h"
#include "Ptr.h"

class Picture {
public:
	Picture(const std::vector<std::string>& = std::vector<std::string>());

private:
	Ptr<PictureBase> p;
};

Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);


#endif // !PICTURE_H
