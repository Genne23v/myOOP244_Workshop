#ifndef __LABEL_MAKER__
#define __LABEL_MAKER__

#include "Label.h"

namespace sdds
{
	class LabelMaker
	{
	private:
		Label *m_labels;
		int m_noOfLabels;
	public:
		LabelMaker(int noOfLabels);
		~LabelMaker();
		void readLabels();
		void printLabels();
		
	};
}

#endif 