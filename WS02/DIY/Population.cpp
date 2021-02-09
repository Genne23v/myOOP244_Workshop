/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/

#include "Population.h"
#include <iostream>

using namespace std;
namespace sdds {

	PopulationByArea* areaPopulation;
	int numOfAreas;
	
	bool load(const char *fileName)
	{
		bool ok = false;
		int i = 0;
		if (openFile(fileName)) {
			
			numOfAreas = noOfRecords();
			areaPopulation = new PopulationByArea[numOfAreas];

			while (i < numOfAreas) {
				if (read(areaPopulation[i].m_postalCode) && read(areaPopulation[i].m_population))
				{
					i++;
				}
				else
				{
					cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
				}
				ok = true;
			}
		}
		else {
			cout << "Could not open data file: "<<fileName << endl;
		}

		return ok;
	}
	void sort() 
	{
	PopulationByArea temp;
	int i, j;

		for (i = 0; i < numOfAreas-1; i++) {
			int maxIndex = 0;
			for (j = 1; j<= (numOfAreas-1-i);j++)  {
				if ((areaPopulation[j].m_population > areaPopulation[maxIndex].m_population) || ((areaPopulation[j].m_population == areaPopulation[maxIndex].m_population) && (strcmp((areaPopulation+j)->m_postalCode, (areaPopulation+maxIndex)->m_postalCode)) == 1))
				{
					maxIndex = j;
				}
			}
			temp = areaPopulation[numOfAreas - 1 - i];
			areaPopulation[numOfAreas - 1 - i] = areaPopulation[maxIndex];
			areaPopulation[maxIndex] = temp;
		}
	}
	int sum()
	{
		int sum = 0;
		for (int i = 0; i < numOfAreas; i++)
		{
			sum += areaPopulation[i].m_population;
		}
		return sum;
	}
	void display()
	{
		sort();
		int sumOfPopulation = sum();
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		for (int i = 0; i < numOfAreas; i++)
		{
			cout << i + 1 << "- " << (areaPopulation + i)->m_postalCode << ":  " << (areaPopulation + i)->m_population << endl;
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " <<sumOfPopulation<< endl;
	}
	void deallocateMemory()
	{
		delete[] areaPopulation;
	}
}