/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************/
#ifndef __SEARCHNLIST_H_
#define __SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"
#include "ReadWrite.h"
#include "Car.h"
#include "Student.h"
#include "Employee.h"

namespace sdds
{
	template <typename T, typename N>
	bool search(Collection<T>& src, T *arr, int size, N key)
	{
		bool found = false;
		int matches = 0;

		src.resize(0);

		for (int i = 0; i < size; i++)
		{
			if (arr[i] == key)
			{
				src.add(arr[i]);
			}
		}

		if (src.size() > 0)
		{
			found = true;
		}

		return found;
	}

	template <typename T>
	void listArrayElements(const char* title, const T *arr, int size)
	{
		std::cout << title << std::endl;

		for (int i = 0; i < size; i++)
		{
			std::cout << i + 1 << ": " << arr[i] <<std::endl;
		}
	}
}
#endif // !__SEARCHNLIST_H_
