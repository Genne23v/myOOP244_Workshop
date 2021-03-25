#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

namespace sdds
{
	void LblShape::set()
	{
		if (m_label != nullptr)
		{
			delete[] m_label;
			m_label = nullptr;
		}
		else
		{
			m_label = nullptr;
		}
	}
	LblShape::LblShape()
	{
		set();
	}
	LblShape::LblShape(const char* label)
	{
		set();
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}
	LblShape::~LblShape()
	{
		set();
	}
	char* LblShape::label() const
	{
		return m_label;
	}
	void LblShape::getSpecs(std::istream& is)
	{
		char temp[100];
		is.getline(temp, 100, ',');
		
		delete[] m_label;
		m_label = nullptr;
		m_label = new char[strlen(temp) + 1];
		strcpy(m_label, temp);
	}
}
