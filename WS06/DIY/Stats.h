/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#ifndef __STATS_H__
#define __STATS_H__
#include <iostream>

namespace sdds {
	
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
	static double zero = 0.0;
#pragma GCC diagnostic pop

	class Numbers {
		double* m_numbers;
		Numbers();
		~Numbers();
		//Numbers& opereator=(const int*);
		friend class Stats;
		Numbers(const Numbers& src) = delete;
		void operator=(const Numbers& src) = delete;
	};
	class Stats {
		Numbers *m_numberRows;
		char* m_filename;
		unsigned m_colWidth;
		unsigned m_noOfCols;
		unsigned m_precision;
		unsigned m_noOfLines;
		unsigned m_numCount;

		void setFilename(const char* fname, bool isCopy = false);
		void setNoOfLines();
		void loadNumbers();
		void saveAs(const char* filename) const;
	public:
		Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
		Stats(const char* filename, unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
		Stats(const Stats& src);
		Stats& operator=(const Stats& src);
		~Stats();
		double& operator[](unsigned idx);
		double operator[](unsigned idx)const;
		operator bool()const;
		void sort(bool ascending);
		unsigned size()const;
		const char* name() const;
		unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
		std::ostream& view(std::ostream& ostr)const;
		std::istream& getFile(std::istream& istr);

	};
	std::ostream& operator<<(std::ostream& ostr, const Stats& src);
	std::istream& operator>>(std::istream& istr, Stats& dest);
}

#endif // !__STATS_H__