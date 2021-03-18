
/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#ifndef __TRUCK_H__
#define __TRUCK_H__

#include "MotorVehicle.h"

namespace sdds
{
	class Truck : public MotorVehicle
	{
	private:
		double m_capacity;
		double m_currentLoad;
	public:
		Truck(const char* licensePlate, int yearOfBuild, double capacity, const char* address = "Factory", double currentLoad = 0);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& is);
	};
	std::ostream& operator<<(std::ostream& os, Truck& src);
	std::istream& operator>>(std::istream& is, Truck& src);
}

#endif