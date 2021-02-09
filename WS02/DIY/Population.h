/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#include "File.h"
#include <cstring>

namespace sdds {

	struct PopulationByArea
	{
		char m_postalCode[4];
		int m_population;
	};

	void sort();
	int sum();
	bool load(const char* fileName);
	void display();
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_