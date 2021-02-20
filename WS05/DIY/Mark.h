/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#pragma once

#include <iostream>

using namespace std;

namespace sdds
{
	class Mark
	{
	private:
		int m_score;
		//double m_gpa;
		bool isValid;

	public:
		Mark();
		Mark(int score);
		Mark& operator+=(int num);
		Mark& operator=(int num);
		operator int();
		operator double();
		operator char();
		
		void setDefault();
	};

	int& operator+=(int& value, Mark& ref);

}