#include "LabelMaker.h"

namespace sdds
{
	LabelMaker:: LabelMaker(int noOfLabels)
	{
		m_labels = new Label[noOfLabels];
		m_noOfLabels = noOfLabels;
	}
	LabelMaker::~LabelMaker()
	{
		delete[] m_labels;
		m_labels = nullptr;
	}
	void LabelMaker::readLabels()
	{
		cout << "Enter " << m_noOfLabels << " labels:" << endl;
		for (int i = 0; i < m_noOfLabels; i++) {
			cout << "Enter label number " << i + 1 << endl;
			cout << "> "; 
			m_labels[i].readLabel();
		}
	}
	void LabelMaker::printLabels()
	{
		for (int i = 0; i < m_noOfLabels; i++) {
			m_labels[i].printLabel();
		}
	}
}
