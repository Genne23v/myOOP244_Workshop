
/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#ifndef __LINE_H__
#define __LINE_H__

#include <iostream>
#include "LblShape.h"

namespace sdds
{
	class Line : public LblShape
	{
		int m_length = 0;
	public:
		Line();
		Line(const char* label, int length);
		Line(const Line& src) {};
		Line& operator=(const Line& src);
		void draw(std::ostream& os) const override;
		void getSpecs(std::istream& is)override;
		Line& operator&(const Line& src) ;
	};
	/*void operator<<(std::ostream& os, Line& src);
	void operator>>(std::istream& is, Line& src);*/
}

#endif