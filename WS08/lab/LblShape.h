
/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#ifndef __LBLSHAPE_H__
#define __LBLSHAPE_H__

#include <iostream>
#include "Shape.h"

namespace sdds
{
	class LblShape : public Shape
	{
		char* m_label = nullptr;
	protected:
		char* label() const;
	public:
		void set();
		explicit LblShape();
		LblShape(const char* label);
		LblShape(const LblShape& src) = delete;
		LblShape& operator=(const LblShape& src) = delete;
		~LblShape();
		virtual void draw(std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& is) override;
		//virtual LblShape& operator&(LblShape& src) = 0;

	};
	/*std::ostream& operator<<(std::ostream& os, LblShape& src);
	std::istream& operator>>(std::istream& is, LblShape& src);*/
}

#endif