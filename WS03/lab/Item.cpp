/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/

#include <iostream>
#include "cstring.h"
#include "Item.h"

using namespace std;
namespace sdds {

	void Item::setName(const char* name)
	{
		if (name == nullptr)
		{
			m_itemName[0] = '\0';
		}
		else
		{
			strnCpy(m_itemName, name, 20);
		}
	}
	void Item::setEmpty()
	{
		m_itemName[0] = '\0';
		m_price = 0.0;
		m_taxed = false;
	}
	void Item::set(const char* name, double price, bool taxed)
	{
		setName(name);
		m_price = price;
		m_taxed = taxed;
	}
	void Item::display()const
	{
		if (isValid())
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.fill('.');
			cout.width(20);
			cout << m_itemName;
			cout << " | ";
			cout.unsetf(ios::left);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.fill(' ');
			cout.width(7);
			cout << m_price;
			cout << " | ";
			cout.setf(ios::left);
			cout.fill(' ');
			cout.width(3);
			if (m_taxed) {
				cout << "Yes";
			}
			else {
				cout << "No";
			}
			cout << " |" << endl;
			cout.unsetf(ios::left);
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}
	bool Item::isValid()const
	{
		if (m_itemName[0] != '\0' && m_price != 0.0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	double Item::price()const
	{
		return m_price;
	}
	double Item::tax()const
	{
		if (m_taxed)
		{
			return TAX;
		}
		else {
			return 0.0;
		}
	}
}