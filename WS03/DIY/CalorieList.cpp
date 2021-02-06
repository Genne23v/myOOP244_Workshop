/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/

#include <iostream>
#include "CalorieList.h"

using namespace std;
namespace sdds {

	int CalorieList::totalCalories()const
	{
		int i = 0;
		int totalCalroies = 0;

		while (i < m_itemsAdded)
		{
			totalCalroies += m_items[i].calories();
			i++;
		}
		return totalCalroies;
	}
	void CalorieList::Title()const
	{
		cout << "+----------------------------------------------------+" << endl;
		if (isValid())
		{
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}
	void CalorieList::footer()const
	{
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid())
		{
			cout << "|    Total Calories for today:";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(9);
			cout << totalCalories();
			cout << " |            |" << endl;

		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}
	void CalorieList::setEmpty()
	{
		m_items = nullptr;
		m_noOfFood = 0;
		m_itemsAdded = 0;
	}
	bool CalorieList::isValid()const
	{
		bool ok = true;
		if (m_items != nullptr)
		{
			int i = 0;
			while (i < m_noOfFood)
			{
				if (!m_items[i].isValid())
				{
					ok = false;
				}
				i++;
			}
		}
		return ok;
	}
	void CalorieList::init(int size)
	{
		if (size <= 0)
		{
			setEmpty();
		}
		else
		{
			m_noOfFood = size;
			m_itemsAdded = 0;
			m_items = new Food[m_noOfFood];
		}
		int i = 0;
		while (i < m_noOfFood)
		{
			m_items[i].setEmpty();
			i++;
		}
	}
	bool CalorieList::add(const char* item_name, int calories, int time)
	{
		bool ok = false;
		if (m_itemsAdded < m_noOfFood)
		{
			if (item_name == nullptr || calories < 0 || (time > 4 || time < 0))
			{
				m_items[m_itemsAdded].setEmpty();
			}
			else
			{
				m_items[m_itemsAdded].set(item_name, calories, time);
				ok = true;
			}
			m_itemsAdded += 1;
		}
		return ok;
	}
	void CalorieList::display()const
	{
		int i = 0;
		Title();
		while (i < m_noOfFood)
		{
			m_items[i].display();
			i++;
		}
		footer();
	}
	void CalorieList::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;
	}
}