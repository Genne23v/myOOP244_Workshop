#ifndef __LABEL__
#define __LABEL__

#include <iostream>
#include "cstring.h"

using namespace std;
namespace sdds
{
	class Label
	{
	private:
		char m_frame[9];
		char *m_content;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();

		void setDefault();
		void readLabel();
		std::ostream& printLabel() const;
	};

}

#endif 