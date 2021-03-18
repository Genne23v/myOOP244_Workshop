
/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#ifndef __MOTORVEHICLE_H__
#define __MOTORVEHICLE_H__

#include <iostream>
#include "cstring.h"
//#include "Truck.h"

namespace sdds {
	class MotorVehicle
	{
	private:
		char m_licensePlate[9];
		char m_address[64];
		int m_yearOfBuild;
	public:
		MotorVehicle(const char* licensePlate, int yearOfBuild, const char* address = "Factory");
		void moveTo(const char* address);
		const char* readLicensePlate();
		const char* readAddress();
		int readBuildYear();
		virtual std::ostream& write(std::ostream& os);
		virtual std::istream& read(std::istream& is);
	};
	std::ostream& operator<<(std::ostream& os, MotorVehicle& src);
	std::istream& operator>>(std::istream& is, MotorVehicle& src);
}
#endif // !__MOTORVEHICLE_H__