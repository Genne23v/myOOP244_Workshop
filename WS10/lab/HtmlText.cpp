/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "HtmlText.h"
#include "cstring.h"

namespace sdds {

	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename)
	{
		m_title = nullptr;

		if (title != nullptr)
		{
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
		if (getFilename() != nullptr)
		{
			write(std::cout);
		}
	}

	HtmlText::HtmlText(const HtmlText& src) 
	{
		init();
		m_title = nullptr;
		if (src.m_title != nullptr)
		{
			m_title = new char[strLen(src.m_title) + 1];
			strCpy(m_title, src.m_title);
		}
		copyFilename(src.getFilename());
		copyContent(src.getContent());
	}

	HtmlText& HtmlText::operator=(const HtmlText& src)
	{
		if (m_title != nullptr)
		{
			delete[] m_title;
			m_title = nullptr;
		}
		if (src.m_title != nullptr)
		{
			m_title = new char[strLen(src.m_title) + 1];
			strCpy(m_title, src.m_title);
		}

		copyFilename(src.getFilename());
		copyContent(src.getContent());

		return *this;
	}

	HtmlText::~HtmlText()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	char* HtmlText::getFilename() const
	{
		return Text::getFilename();
	}

	void HtmlText::write(std::ostream& os) 
	{
		bool ms = false;

		std::ifstream fin(getFilename());
		std::string temp;
		char c;
		int i = 0;

		if (fin.is_open())
		{
			temp += "<html><head><title>";

			if (m_title != nullptr)
			{
				temp.append(m_title);
				temp += "</title></head>\n<body>\n<h1>";
				temp.append(m_title);
				temp += "</h1>\n";
			}
			else
			{
				temp += "No title</html></head>\n<body>\n";
			}
			
			while (i < 15769) //(!fin.eof())
			{
				fin.get(c);
				
				if (c == '<' )
				{
					temp += "&lt;";
					ms = false;
				}
				else if (c == '>')
				{
					temp += "&gt;";
					ms = false;
				}
				else if (c == '\n' && c != '\0')
				{
					temp += "<br />\n";
					ms = false;
				}
				else if (c == ' ' && ms == false)
				{
					temp += ' ';
					ms = true;
				}
				else if (c == ' ' && ms == true)
				{
					temp += "&nbsp;";
				}
				else
				{
					temp += c;
					ms = false;
				}
				i++;
			}
			temp += "</body>\n</html>";
		}
		fin.close();

		Text::copyContent(temp.c_str());
	}

	std::ostream& operator<<(std::ostream& os, HtmlText& src)
	{
		src.write(os);
		return os;
	}
}
