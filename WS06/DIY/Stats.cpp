/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "Stats.h"
#include "cstring.h"
namespace sdds {

	Numbers::Numbers()
	{
		m_numbers = nullptr;
	}
	Numbers::~Numbers()
	{
		delete[] m_numbers;
	}
	void Stats::setFilename(const char* fname, bool isCopy)
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
	void Stats::setNoOfLines()
	{
		std::ifstream file(m_filename);

		if (file.is_open())
		{
			while (!file.eof())
			{
				m_numCount += (file.get() == ',');
			}
			m_numCount++;
			m_noOfLines = (m_numCount / m_noOfCols) + 1;

			if (m_noOfLines == 0)
			{
				delete[] m_filename;
				m_filename = nullptr;
			}
		}
	}
	void Stats::loadNumbers()
	{
		if (m_filename != nullptr)
		{
			std::ifstream file(m_filename);

			m_numberRows = new Numbers[m_noOfLines];

			for (unsigned i = 0; i < m_noOfLines; i++)
			{
				m_numberRows[i].m_numbers = new double[m_noOfCols];
			}

			std::string temp;
			for (unsigned i = 0; i < m_noOfLines; i++)
			{
				for (unsigned j = 0; j < m_noOfCols; j++)
				{
					if (!file.eof())
					{
						getline(file, temp, ',');
						m_numberRows[i].m_numbers[j] = std::stod(temp);
					}
					/*else
					{
						m_numberRows[i].m_numbers[j] = std::stod('');
					}*/
				}
			}
		}
	}
	void Stats::saveAs(const char* fileName)const
	{
		std::ofstream fout(m_filename);
		if (fout.is_open())
		{
			std::string temp;
			for (unsigned i = 0; i < m_noOfLines; i++)
			{
				for (unsigned j = 0; j < m_noOfCols; j++)
					temp = std::to_string(m_numberRows[i].m_numbers[j]);
					fout << temp+',';
			}
		}
	}
	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision)
	{
		m_filename = nullptr;
		m_numberRows = nullptr;
		m_colWidth = columnWidth;
		m_noOfCols = noOfColumns;
		m_precision = precision;
		m_noOfLines = 0;
		m_numCount = 0;
	}
	Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision)
	{
		if (filename != nullptr)
		{
			m_filename = new char[strLen(filename) + 1];
			strCpy(m_filename, filename);
		}
		else
		{
			m_filename = nullptr;
		}
		m_numberRows = nullptr;
		m_colWidth = columnWidth;
		m_noOfCols = noOfColumns;
		m_precision = precision;
		m_noOfLines = 0;
		m_numCount = 0;
		setNoOfLines();
		loadNumbers();
	}
	Stats::Stats(const Stats& src)
	{
		m_colWidth = src.m_colWidth;
		m_noOfCols = src.m_noOfCols;
		m_precision = src.m_precision;
		m_noOfLines = src.m_noOfLines;
		m_numCount = src.m_numCount;
		m_numberRows = nullptr;
		m_filename = nullptr;

		if (src.m_filename != nullptr)
		{
			setFilename(src.m_filename, true);
			m_noOfLines = src.m_noOfLines;

			m_numberRows = new Numbers[m_noOfLines];
			for (unsigned i = 0; i < m_noOfLines; i++)
			{
				m_numberRows[i].m_numbers = new double[m_noOfCols];
			}

			for (unsigned i = 0; i < m_noOfLines; i++)
			{
				for (unsigned j = 0; j < m_noOfCols; j++)
					m_numberRows[i].m_numbers[j] = src.m_numberRows[i].m_numbers[j];
			}
			saveAs(m_filename);
		}
	}
	Stats& Stats::operator=(const Stats& src)
	{
		m_colWidth = src.m_colWidth;
		m_noOfCols = src.m_noOfCols;
		m_precision = src.m_precision;
		m_noOfLines = src.m_noOfLines;
		m_numCount = src.m_numCount;
		delete[] m_numberRows;

		if (src.m_filename != nullptr)
		{
			m_numberRows = new Numbers[m_noOfLines];

			for (unsigned i = 0; i < m_noOfLines; i++)
			{
				m_numberRows[i].m_numbers = new double[m_noOfCols];
			}
			for (unsigned i = 0; i < m_noOfLines; i++)
			{
				for (unsigned j = 0; j < m_noOfCols; j++)
					m_numberRows[i].m_numbers[j] = src.m_numberRows[i].m_numbers[j];
			}
			saveAs(m_filename);
		}
		return *this;
	}
	Stats::~Stats()
	{
		delete[] m_filename;
		delete[] m_numberRows;
	}
	double& Stats::operator[](unsigned idx)
	{
		double* ret = nullptr;

		if (*this)
		{
			if (idx >= m_numCount)
			{
				idx = idx % m_numCount;
			}
			ret = &m_numberRows[idx / m_noOfCols].m_numbers[idx % m_noOfCols];
		}
		return *ret;
	}
	double Stats::operator[](unsigned idx)const
	{
		double ret = 0.0;

		if (*this)
		{
			if (idx >= m_numCount)
			{
				idx = idx % m_numCount;
			}
			ret = m_numberRows[idx / m_noOfCols].m_numbers[idx % m_noOfCols];
		}
		return ret;
	}
	Stats::operator bool()const
	{
		return m_filename != nullptr;
	}
	int compare(double a, double b, bool ascending)
	{
		if (ascending)
			return a < b;
		else
			return a > b;
	}
	void Stats::sort(bool ascending)
	{
		double temp = 0.0;
		int r = 0;

		for (unsigned y1 = 0; y1 < m_noOfLines; y1++)
		{
			for (unsigned x1 = 0; x1 < m_noOfCols; x1++)
			{
				r = x1 + 1;
				for (unsigned y2 = y1; y2 < m_noOfLines; y2++)
				{
					for (unsigned x2 = r; x2 < m_noOfCols; x2++)
					{
						if (compare(m_numberRows[y2].m_numbers[x2], m_numberRows[y1].m_numbers[x1], ascending))
						{
							temp = m_numberRows[y2].m_numbers[x2];
							m_numberRows[y2].m_numbers[x2] = m_numberRows[y1].m_numbers[x1];
							m_numberRows[y1].m_numbers[x1] = temp;
						}
					}
					r = 0;
				}
			}
		}
	}
unsigned Stats::size()const
{
	return m_numCount;
}
const char* Stats::name() const
{
	return m_filename;
}
unsigned Stats::occurrence(double min, double max, std::ostream& ostr)
{
	int count = 0;
	
	if (m_filename != nullptr)
	{
		for (unsigned i = 0; i < m_noOfLines; i++)
		{
			for (unsigned j = 0; j < m_noOfCols; j++)
			{
				if (m_numberRows[i].m_numbers[j] > min && m_numberRows[i].m_numbers[j] < max && m_numberRows[i].m_numbers[j] != 0)
				{
					ostr.width(m_colWidth);
					ostr.fill(' ');
					ostr.setf(std::ios::fixed);
					ostr.setf(std::ios::right);
					ostr.precision(m_precision);
					ostr << m_numberRows[i].m_numbers[j];
					count++;
					if (count % m_noOfCols == 0)
					{
						ostr << std::endl;
					}
				}
			}
		}
		ostr << std::endl;
		ostr << "Total of " << count << " numbers are between " << min << " and " << max << std::endl;
	}
	return count;
}
std::ostream& Stats::view(std::ostream& ostr)const
{
	if (m_filename != nullptr || m_numberRows != nullptr)
	{
		ostr << m_filename << std::endl;
		ostr.width(strLen(m_filename));
		ostr.fill('=');
		ostr << "" << std::endl;
		;
		for (unsigned i = 0; i < m_noOfLines; i++)
		{
			for (unsigned j = 0; j < m_noOfCols; j++)
			{
				if (m_numberRows[i].m_numbers[j] != 0)
				{
					ostr.width(m_colWidth);
					ostr.fill(' ');
					ostr.setf(std::ios::fixed);
					ostr.setf(std::ios::right);
					ostr.precision(m_precision);
					ostr << m_numberRows[i].m_numbers[j];
				}
			}
			ostr << std::endl;
		}
		ostr << "Total of " << m_numCount << " listed!" << std::endl;
	}
	return ostr;
}
std::ostream& operator<<(std::ostream& ostr, const Stats& dst)
{
	return dst.view(ostr);
}
std::istream& Stats::getFile(std::istream& istr)
{
	char temp[50] = { '\0' };
	istr >> temp;
	std::cin.ignore(100, '\n');
	setFilename(temp);
	setNoOfLines();
	loadNumbers();
	return istr;
}
std::istream& operator>>(std::istream& istr, Stats& src)
{
	return src.getFile(istr);
}
}