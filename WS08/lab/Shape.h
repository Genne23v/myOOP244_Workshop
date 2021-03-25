
/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <iostream>

namespace sdds
{
	class Shape
	{
	public:
		virtual ~Shape() {};
		virtual void draw(std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& is) = 0;
	};
	std::ostream& operator<<(std::ostream& os, Shape& src);
	std::istream& operator>>(std::istream& is, Shape& src);
}

#endif