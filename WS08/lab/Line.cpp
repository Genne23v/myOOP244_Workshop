#include <iostream>
#include "Line.h"

namespace sdds
{
	Line::Line() : LblShape()
	{
		m_length = 0;
	}
	Line::Line(const char* label, int length) : LblShape(label)
	{
		m_length = length;
	}
	Line& Line::operator&(const Line& src)
	{
		return *this;
	}
	void Line::draw(std::ostream& os) const
	{
		if (m_length > 0 && LblShape::label() != nullptr)
		{
			os << LblShape::label() << std::endl;
			os.width(m_length);
			os.fill('=');
			os << "";
		}
	}
	void Line::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);

		is >> m_length;
		is.ignore(100, '\n');
	}
}
