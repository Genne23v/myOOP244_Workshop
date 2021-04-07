/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
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

	/*char* getContent() const
	{
		return Text::getContent();
	}*/

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

		if (fin.is_open())
		{
			temp += "<html><head><title>";

			if (m_title != nullptr)
			{
				temp.append(m_title);
				temp += "</title></head>\n<body>\n<h1>";
				temp.append(m_title);
				temp += "</h1>";
			}
			else
			{
				temp += "No title</html></head>\n<body>\n";
			}

			while (!fin.eof())
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
				else if (c == '\n')
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
					ms = false;
				}
				else
				{
					temp += c;
					ms = false;
				}
			}
			temp += "</body>\n</html>\0";
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
