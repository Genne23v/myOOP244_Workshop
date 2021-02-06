/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/

#include <iostream>
#include "cstring.h"
#include "Food.h"

using namespace std;
namespace sdds {

	void Food::setName(const char* name)
	{
		if (name == nullptr)
		{
			f_name[0] = '\0';
		}
		else
		{
			strnCpy(f_name, name, 30);
		}
	}
	void Food::setEmpty()
	{
		f_name[0] = '\0';
		m_calories = 0;
		m_time = 0;
	}
	void Food::set(const char* name, int calories, int time)
	{
		setName(name);
		m_calories = calories;
		m_time = time;
	}
	void Food::display()const
	{
		if (isValid())
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.fill('.');
			cout.width(30);
			cout << f_name;
			cout << " | ";
			cout.unsetf(ios::left);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.fill(' ');
			cout.width(4);
			cout << m_calories;
			cout << " | ";
			cout.setf(ios::left);
			cout.fill(' ');
			cout.width(10);
			switch (m_time) {
			case 1:
				cout << "Breakfast";
				break;
			case 2:
				cout << "Lunch";
				break;
			case 3:
				cout << "Dinner";
				break;
			case 4:
				cout << "Snack";
				break;
			}
			cout << " |" << endl;
			cout.unsetf(ios::left);
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}
	bool Food::isValid()const
	{
		if ((f_name[0] != '\0' && f_name != nullptr) && (m_calories >= 0 && m_calories <= 3000) && (m_time <=4 && m_time > 0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int Food::calories()const
	{
		return m_calories;
	}
}