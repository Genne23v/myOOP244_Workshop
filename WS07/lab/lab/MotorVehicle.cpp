/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "MotorVehicle.h"

namespace sdds
{
	MotorVehicle::MotorVehicle(const char* licensePlate, int yearOfBuild, const char* address)
	{
		//m_licensePlate = { '\0', };
		if (licensePlate != nullptr)
		{
			strCpy(m_licensePlate, licensePlate);
		}
		const char* defaultAddress = "Factory";
		strCpy(m_address, defaultAddress);
		if (strcmp(address, defaultAddress) != 0)
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
			strCpy(m_address, address);
		}
	}
	const char* MotorVehicle::readLicensePlate() const
	{
		return m_licensePlate;
	}
	const char* MotorVehicle::readAddress() const
	{
		return m_address;
	}
	int MotorVehicle::readBuildYear() const
	{
		return m_yearOfBuild;
	}
	std::ostream& MotorVehicle::write(std::ostream& os)const
	{
		os << "| " << m_yearOfBuild << " | " << m_licensePlate << " | " << m_address << "";
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& src)
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