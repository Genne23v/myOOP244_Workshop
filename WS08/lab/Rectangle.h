
/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "LblShape.h"

namespace sdds
{
	class Rectangle : public LblShape
	{
		int m_height;
		int m_width;
	public:
		Rectangle();
		Rectangle(const char* label, int height, int width);
		Rectangle(const Rectangle& src);
		Rectangle& operator=(const Rectangle& src);
		void draw(std::ostream& os) const;
		void getSpecs(std::istream& is);
		Rectangle& operator&(const Rectangle& src) ;
	};
	/*void operator<<(std::ostream& os, Rectangle& src);
	void operator>>(std::istream& is, Rectangle& src);*/
}

#endif