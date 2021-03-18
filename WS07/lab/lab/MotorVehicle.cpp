/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "MotorVehicle.h"

namespace sdds
{
	MotorVehicle::MotorVehicle(const char* licensePlate, int yearOfBuild, const char* address)
	{
		//m_licensePlate = { '\0', };
		if (licensePlate != nullptr)
		{
			strcpy(m_licensePlate, licensePlate);
		}
		if (address == "Factory")
		{
			moveTo(address);
		}
		m_yearOfBuild = yearOfBuild;
	}
	void MotorVehicle::moveTo(const char* address)
	{
		if (address != nullptr)
		{
			std::cout << "|";
			std::cout.width(8);
			std::cout.setf(std::ios::right);
			std::cout << m_licensePlate;
			std::cout << "| |";
			std::cout.width(20);
			std::cout << m_address;
			std::cout << " ---> ";
			std::cout.unsetf(std::ios::right);
			std::cout.width(20);
			std::cout.setf(std::ios::left);
			std::cout << address;
			std::cout << "|" << std::endl;
			strcpy(m_address, address);
		}
	}
	const char* MotorVehicle::readLicensePlate()
	{
		return m_licensePlate;
	}
	const char* MotorVehicle::readAddress()
	{
		return m_address;
	}
	int MotorVehicle::readBuildYear()
	{
		return m_yearOfBuild;
	}
	std::ostream& MotorVehicle::write(std::ostream& os)
	{
		os << "| " << m_yearOfBuild << " | " << m_licensePlate << " | " << m_address << "" << std::endl;
		return os;
	}
	std::ostream& operator<<(std::ostream& os, MotorVehicle& src)
	{
		return src.write(os);
	}
	
	std::istream& MotorVehicle::read(std::istream& is)
	{
		std::cout << "Built year: ";
		is >> m_yearOfBuild;
		std::cout << "License plate: ";
		is >> m_licensePlate;
		std::cout << "Current location: ";
		is >> m_address;
		return is;
	}
	std::istream& operator>>(std::istream& is, MotorVehicle& src)
	{
		return src.read(is);
	}
}