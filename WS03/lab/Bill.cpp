/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/

#include <iostream>
#include "Bill.h"

using namespace std;
namespace sdds {

	double Bill::totalTax()const
	{
		int i = 0;
		double taxTotal = 0.0;
		double temp = 0.0;
		while (i < m_itemsAdded)
		{
			if (m_items[i].tax())
			{
				temp = m_items[i].price();
				taxTotal += (temp * TAX);
			}
			i++;
		}
		return taxTotal;
	}
	double Bill::totalPrice()const
	{
		int i = 0;
		double totalPrice = 0.0;
		double temp = 0.0;
		while (i < m_itemsAdded)
		{
			temp = m_items[i].price();
			totalPrice += temp;
			i++;
		}
		return totalPrice;
	}
	void Bill::Title()const
	{
		cout << "+--------------------------------------+" << endl;
		if (isValid())
		{
			cout << "| ";
			cout.width(36);
			cout.fill();
			cout.setf(ios::left);
			cout << m_title;
			cout.unsetf(ios::left);
			cout << " |" << endl;
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}
	void Bill::footer()const
	{
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid())
		{
			cout << "|                Total Tax: ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(10);
			cout << totalTax();
			cout << " |" << endl;
			cout << "|              Total Price: ";
			cout.precision(2);
			cout.width(10);
			cout << totalPrice();
			cout << " |" << endl;
			cout << "|          Total After Tax: ";
			cout.precision(2);
			cout.width(10);
			cout << totalTax() + totalPrice();
			cout << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}
	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}
	bool Bill::isValid()const
	{
		if (m_title[0] != '\0' && m_items != nullptr)
		{
			int i = 0;
			bool ok = true;
			while (i < m_noOfItems)
			{
				if (!m_items[i].isValid())
				{
					ok = false;
				}
				i++;
			}

			return ok;
		}
	}
	void Bill::init(const char* title, int noOfItems)
	{
		if (title == nullptr || noOfItems <= 0)
		{
			setEmpty();
		}
		else
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];
		}
		int i = 0;
		while (i < m_noOfItems)
		{
			m_items[i].setEmpty();
			i++;
		}
	}
	bool Bill::add(const char* item_name, double price, bool taxed)
	{
		bool ok = false;
		if (item_name == nullptr || price < 0)
		{
			m_items[m_itemsAdded].setEmpty();
		}
		else if (m_itemsAdded < m_noOfItems)
		{
			m_items[m_itemsAdded].set(item_name, price, taxed);
			ok = true;
		}
		m_itemsAdded += 1;
		return ok;
	}
	void Bill::display()const
	{
		int i = 0;
		Title();
		while (i < m_noOfItems)
		{
			m_items[i].display();
			i++;
		}
		footer();
	}
	void Bill::deallocate()
	{
		delete[] m_items;

		//*m_title = nullptr;
	}
}