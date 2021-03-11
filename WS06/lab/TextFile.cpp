/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	Line::operator const char* () const {
		return (const char*)m_value;
	}
	Line& Line::operator=(const char* lineValue) {
		delete[] m_value;
		m_value = new char[strLen(lineValue) + 1];
		strCpy(m_value, lineValue);
		return *this;
	}
	Line::~Line() {
		delete[] m_value;
	}

	void TextFile::setFilename(const char* fname, bool isCopy)
	{
		delete[] m_filename;
		if (isCopy == false)
		{
			m_filename = new char[strLen(fname) + 1];
			strCpy(m_filename, fname);
		}
		else
		{
			m_filename = new char[strLen(fname) + 3];
			strCpy(m_filename, "C_");
			strCat(m_filename, fname);
		}
	}
	void TextFile::setNoOfLines()
	{
		ifstream file(m_filename);
		while (file)
		{
			m_noOfLines += (file.get() == '\n');
		}
		if (m_noOfLines == 0)
		{
			delete[] m_filename;
			m_filename = nullptr;
		}
		else
		{
			m_noOfLines++;
		}
	}
	/*bool getline(ifstream& file, string line)
	{
		bool ok = false;
		if (file.is_open())
		{
			getline()
		}
		return ok;
	}*/
	void TextFile::loadText()
	{
		if (m_filename != nullptr)
		{
			/*for (int i = 0; i < m_noOfLines; i++)
			{
				delete[] m_textLines[i].m_value;
			}*/
			ifstream file(m_filename);
			m_textLines = new Line[m_noOfLines];
			int i = 0;
			string line;
			while (getline(file, line))
			{
				m_textLines[i++] = line.c_str();
			}
			m_noOfLines = i;
		}
	}
	void TextFile::saveAs(const char* fileName)const
	{
		ofstream fout(m_filename);
		//ifstream fin(fileName);
		if (fout.is_open())
		{
			for (unsigned i = 0; i < m_noOfLines; i++)
			{
				fout << m_textLines[i].m_value << endl;
			}
		}
	}

	void TextFile::setEmpty()
	{
		/*for (unsigned i = 0; i < m_noOfLines; i++)
		{
			delete[] m_textLines[i];
		}*/
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;
	}

	TextFile::TextFile(unsigned pageSize)
	{
		setEmpty();
		m_pageSize = pageSize;
	}
	TextFile::TextFile(const char* filename, unsigned pageSize)
	{
		setEmpty();
		m_pageSize = pageSize;
		if (filename != nullptr)
		{
			m_filename = new char[strLen(filename) + 1];
			strCpy(m_filename, filename);
			setNoOfLines();
			loadText();
		}
	}
	TextFile::TextFile(const TextFile& src)
	{
		m_pageSize = src.m_pageSize;
		m_noOfLines = 0;
		m_textLines = nullptr;
		m_filename = nullptr;

		if (src.m_filename != nullptr)
		{
			setFilename(src.m_filename, true);
			m_noOfLines = src.m_noOfLines;
			//m_textLines = src.m_textLines;
			m_textLines = new Line[m_noOfLines];
			
			for (unsigned i = 0; i < m_noOfLines; i++)
			{
				m_textLines[i].m_value = new char[strLen(src.m_textLines[i].m_value)+1];
				strCpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
			}
			saveAs(m_filename);
		}
	}
	TextFile& TextFile::operator=(const TextFile& src)
	{
		m_pageSize = src.m_pageSize;
		m_noOfLines = src.m_noOfLines;
		delete[] m_textLines;

		if (src.m_filename != nullptr)
		{
			//m_filename = new char[strLen(src.m_filename) + 1];
			m_textLines = new Line[m_noOfLines];
			for (unsigned i = 0; i < m_noOfLines; i++)
			{
				m_textLines[i].m_value = new char[strLen(src.m_textLines[i].m_value) + 1];
				strCpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
			}
			saveAs(m_filename);
			//loadText();
		}
		return *this;
	}
	TextFile::~TextFile()
	{
		/*for (int i = 0; i < m_noOfLines; i++)
		{
			delete m_textLines[i];
		}*/
		delete[] m_textLines;
		delete[] m_filename;
	}
	ostream& TextFile::view(ostream& ostr)const
	{
		if (m_filename != nullptr)
		{
			ostr << m_filename << endl;
			ostr.width(strLen(m_filename));
			ostr.fill('=');
			ostr << "" << endl;

			for (unsigned i = 0; i < m_noOfLines; i++)
			{
				ostr << m_textLines[i].m_value << endl;
				if ((i + 1) % m_pageSize == 0)
				{
					ostr << "Hit ENTER to continue...";
					cin.ignore(1000, '\n');
				}
			}
		}
		return ostr;
	}

	istream& TextFile::getFile(istream& istr)
	{
		char temp[50] = { '\0' };
		istr >> temp;
		m_filename = new char[strLen(temp) + 1];
		strCpy(m_filename, temp);
		setNoOfLines();
		loadText();
		return istr;
	}
	TextFile::operator bool()const
	{
		return m_filename != nullptr;
	}
	unsigned TextFile::lines()const
	{
		return m_noOfLines;
	}
	const char* TextFile::name()const
	{
		return m_filename;
	}
	const char* TextFile::operator[](unsigned index)const
	{
		const char* line = nullptr;
		if (*this)
		{
			line = m_textLines[index % m_noOfLines];
		}
		return line;
	}
	ostream& operator<<(ostream& ostr, const TextFile& text)
	{
		return text.view(ostr);
	}
	istream& operator>>(istream& istr, TextFile& text)
	{
		return text.getFile(istr);
	}
}