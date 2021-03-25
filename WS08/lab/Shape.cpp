#include <iostream>
#include "Shape.h"

namespace sdds
{
	std::ostream& operator<<(std::ostream& os,  Shape& src) 
	{
		src.draw(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Shape& src)
	{
		src.getSpecs(is);
		return is;
	}
}
