/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#include "Mark.h"

namespace sdds
{

	Mark::Mark()
	{
		m_score = 0;
		isValid = true;
	}

	Mark::Mark(int score)
	{
		if (score >= 0 && score <= 100)
		{
			m_score = score;
			isValid = true;
		}
		else
		{
			m_score = 0;
			isValid = false;
		}
	}

	Mark& Mark::operator+=(int num)
	{
		if (isValid && (m_score + num <= 100))
		{
			m_score += num;
		}
		else {
			m_score = 0;
			isValid = false;
		}
		return *this;
	}

	Mark& Mark::operator=(int num)
	{
		if (num >= 0 && num <= 100)
		{
			m_score = num;
			isValid = true;
		}
		else {
			isValid = false;
			m_score = 0;
		}
		return *this;
	}

	Mark::operator int() 
	{
		if (!isValid)
		{
			setDefault();
		}
		return m_score;
	}

	Mark::operator double() 
	{
		double gpa = 0.0;
		if (m_score <= 100 && m_score >= 80) {
			gpa = 4.0;
		}
		else if (m_score < 80 && m_score >= 70) {
			gpa = 3.0;
		}
		else if (m_score < 70 && m_score >= 60) {
			gpa = 2.0;
		}
		else if (m_score < 60 && m_score >= 50) {
			gpa = 1.0;
		}
		else {
			gpa = 0.0;
		}
		
		return gpa;
	}

	Mark::operator char() 
	{
		char grade;
		if (m_score <= 100 && m_score >= 80) {
			grade = 'A';
		}
		else if (m_score < 80 && m_score >= 70) {
			grade = 'B';
		}
		else if (m_score < 70 && m_score >= 60) {
			grade = 'C';
		}
		else if (m_score < 60 && m_score >= 50) {
			grade = 'D';
		}
		else if (m_score < 50)
		{
			grade = 'F';
		}
		else {
			grade = 'X';
		}

		return grade;
	}

	void Mark::setDefault()
	{
		m_score = 0;
		isValid = false;
	}

	int& operator+=(int& value, Mark& ref)
	{
		value += (int)ref;
		return value;
	}
}
