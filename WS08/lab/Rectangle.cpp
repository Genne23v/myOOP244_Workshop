#include <iostream>
#include <string>
#include "Rectangle.h"

namespace sdds
{
	Rectangle::Rectangle()
	{
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label)
	{
		int strLen = strlen(LblShape::label());
		if (height >= 3 && width >= strLen + 2)
		{
			m_width = width;
			m_height = height;
		}
		else
		{
			LblShape::set();
			m_width = 0;
			m_height = 0;
		}
	}
	Rectangle& Rectangle::operator&(const Rectangle& src)
	{
		return *this;
	}
	void Rectangle::draw(std::ostream& os) const
	{
		if (m_height > 0 && m_width > 0 && LblShape::label() != nullptr)
		{
			for (int i = 0; i < m_height; i++)
			{
				if (i == 0 || i == m_height - 1)
				{
					os << "+";
					os.width(m_width - 2);
					os.fill('-');
					os << "";
					os << "+" << std::endl;
				} 
				else if (i == 1)
				{
					os << "|";
					os.width(m_width - 2);
					os.fill(' ');
					os.setf(std::ios::left);
					os << LblShape::label();
					os << "|" << std::endl;
				}
				else
				{
					os << "|";
					os.width(m_width - 2);
					os.fill(' ');
					os << "";
					os << "|" << std::endl;
				}
			}
		}

	}
	void Rectangle::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);

		is >> m_width;
		is.ignore();
		
		is >> m_height;
		is.ignore(100, '\n');
	}

}
