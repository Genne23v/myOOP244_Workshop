/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#include "cstring.h"

namespace sdds
{
	void strCpy(char* des, const char* src)
	{
		//des[0] = '\0';
		int i = 0;
		while (src[i] != '\0')
		{
			des[i] = src[i];
			i++;
		}
		des[i] = '\0';
	}
	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len)
	{
		int i = 0;
		while (i < len)
		{
			des[i] = src[i];
			i++;
		}
		des[i] = '\0';
	}
	// Compares two C-strings 
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2)
	{
		int i = 0;
		while (1)
		{
			if (s1[i] > s2[i])
			{
				return 1;
			}
			else if (s1[i] < s2[i])
			{
				return -1;
			}
			else if (s1[i] == '\0' && s2[i] == '\0')
			{
				return 0;
			}
			else
			{
				i++;
			}
		}
	}
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len)
	{
		int i = 0;
		while (i < len)
		{
			if (s1[i] > s2[i])
			{
				return 1;
			}
			else if (s1[i] < s2[i])
			{
				return -1;
			}
			i++;
		}
		return 0;
	}
	// returns the lenght of the C-string in characters
	int strLen(const char* s)
	{
		int i = 0;
		while (s[i] != '\0')
		{
			i++;
		}
		return i;
	}
	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2)
	{
		int i = 0;
		while (str1[i] != '\0')
		{
			int j = 0;
			if (str1[i] == str2[j])
			{
				while (str2[j] != '\0' && (str1[i] == str2[j]))
				{
					i++;
					j++;
				}
				if (str2[j] == '\0')
				{
					return str1 + (i - j);
				}
			}
			i++;
		}
		return nullptr;
	}
	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src)
	{
		int i = 0;
		while (des[i] != '\0')
		{
			i++;
		}
		int j = 0;
		while (src[j] != '\0')
		{
			des[i] = src[j];
			i++;
			j++;
		}
		des[i] = '\0';
	}
}