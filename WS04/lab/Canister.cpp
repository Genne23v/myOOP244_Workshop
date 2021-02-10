/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
#define PI 3.14159265  
using namespace std;
namespace sdds {

	void Canister::setToDefault()
	{
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	void Canister::setName(const char* Cstr)
	{
		if (Cstr != nullptr && m_usable)
		{
			m_contentName = new char[strLen(Cstr) + 1];
			strCpy(m_contentName, Cstr);
		}
	}

	bool Canister::isEmpty()const
	{
		if (m_contentVolume < 0.00001)
		{
			return true;
		}
		return false;
	}

	bool Canister::hasSameContent(const Canister& C)const
	{
		int result;
		if (C.m_contentName != nullptr && this->m_contentName != nullptr)
		{
			result = strCmp(this->m_contentName, C.m_contentName);
		}
		if (result == 0)
		{
			return true;
		}
		else {
			return false;
		}
	}

	Canister& Canister::setContent(const char* contentName)
	{
		if (contentName == nullptr) {
			this->m_usable = false;
		}
		else if (this->isEmpty()) {
			setName(contentName);
		}
		else if (!hasSameContent(contentName)) {
			this->m_usable = false;
		}
		return *this;
	}

	Canister::Canister()
	{
		setToDefault();
	}

	Canister::Canister(const char* contentName)
	{
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter,
		const char* contentName)
	{
		setToDefault();

		if ((height >= 10 && height <= 40) && (diameter >= 10 && diameter <= 30))
		{
			this->m_height = height;
			this->m_diameter = diameter;
			this->m_contentVolume = 0.0;
			this->m_usable = true;
			if (contentName != nullptr)
			{
				setName(contentName);
			}
		}
		else {
			this->m_usable = false;
		}
	}

	Canister::~Canister()
	{
		delete[] m_contentName;
	}


	Canister& Canister::pour(double quantity)
	{
		if (m_usable && quantity > 0 && (quantity + volume() < capacity()))
		{
			this->m_contentVolume += quantity;
		}
		else {
			this->m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C)
	{
		setContent(C.m_contentName);
		if (C.m_contentVolume > (this->capacity() - this->volume()))
		{
			C.m_contentVolume -= (this->capacity() - this->volume());
			this->m_contentVolume = this->capacity();
		}
		else {
			this->pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}
		//this->m_usable = false;
		return *this;
}

double Canister::volume()const
{
	return this->m_contentVolume;
}
std::ostream& Canister::display()const
{
	cout.setf(ios::fixed);
	cout.precision(1);
	cout.width(7);
	cout << capacity();
	cout << "cc (" << this->m_height << "x" << this->m_diameter << ") Canister";

	if (m_usable)
	{
		if (this->m_contentName != nullptr)
		{
			cout << " of ";
			cout.setf(ios::fixed);
			cout.width(7);
			cout << volume() << "cc   ";
			cout.setf(ios::fixed);
			cout << this->m_contentName;
		}
	}
	else {
		cout << " of Unusable content, discard!";
	}
	return cout;
}

double Canister::capacity()const
{
	double capacity = PI * (this->m_height - 0.267) * (this->m_diameter / 2) * (this->m_diameter / 2);
	return capacity;
}

void Canister::clear()
{
	delete[] m_contentName;
	m_contentName = nullptr;
	m_contentVolume = 0.0;
	m_usable = true;
}

}