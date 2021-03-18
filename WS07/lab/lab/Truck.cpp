/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include <string>
#include "Truck.h"

namespace sdds
{
	Truck::Truck(const char* licensePlate, int yearOfBuild, double capacity, const char* address, double currentLoad) : MotorVehicle(licensePlate, yearOfBuild, address)
	{
		m_capacity = capacity;
		m_currentLoad = currentLoad;
	}
	bool Truck::addCargo(double cargo)
	{
		bool ok = false;
		if ((m_capacity - m_currentLoad) >= cargo)
		{
			m_currentLoad += cargo;
			ok = true;
		}
		else if (m_capacity > m_currentLoad)
		{
			m_currentLoad = m_capacity;
			ok = true;
		}
		return ok;
	}
	bool Truck::unloadCargo()
	{
		bool ok = false;
		if (m_currentLoad > 0)
		{
			m_currentLoad = 0;
			ok = true;
		}

		return ok;
	}
	std::ostream& Truck::write(std::ostream& os)
	{
		os << "| ";
		os << readBuildYear();
		os << " | ";
		os << readLicensePlate();
		os << " | ";
		os << readAddress();
		os << " | " << m_currentLoad << "/" << m_capacity;

		return os;
	}
	std::ostream& operator<<(std::ostream& os, Truck& src)
	{
		return src.write(os);
	}
	std::istream& Truck::read(std::istream& is)
	{
		MotorVehicle::read(is);
		std::cout << "Capacity: ";
		is >> m_capacity;
		std::cout << "Cargo: ";
		is >> m_currentLoad;
		return is;
	}
	std::istream& operator>>(std::istream& is, Truck& src)
	{
		return src.read(is);
	}
}