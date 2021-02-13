#include "Label.h"

namespace sdds {

	Label::Label()
	{
		setDefault();
	}
	Label::Label(const char* frameArg)
	{
		strCpy(m_frame, frameArg);
		m_content = nullptr;
	}
	Label::Label(const char* frameArg, const char* content)
	{
		if (frameArg)
		{
			strCpy(m_frame, frameArg);
		}
		if (content && strLen(content) <= 70) {
			m_content = new char[strLen(content) + 1];
			strCpy(m_content, content);
		}
	}
	Label::~Label()
	{
		delete[] m_content;
	}

	void Label::setDefault()
	{
		strCpy(m_frame, "+-+|+-+|");
		m_content = nullptr;
	}
	void Label::readLabel()
	{
		char buffer[71];
		cin.getline(buffer, 71);

		m_content = new char[strLen(buffer) + 1];
		strCpy(m_content, buffer);
	}

	std::ostream& Label::printLabel() const
	{
		if (m_content != nullptr)
		{
			int len = strLen(m_content);

			cout << m_frame[0];
			for (int i = 0; i < len + 2; i++) {
				cout << m_frame[1];
			}
			cout << m_frame[2] << endl;
			cout << m_frame[3];
			for (int i = 0; i < len + 2; i++) {
				cout << " ";
			}
			cout << m_frame[7] <<  endl;
			cout << m_frame[3] << " " << m_content << " " << m_frame[7] << endl;
			cout << m_frame[3];
			for (int i = 0; i < len + 2; i++) {
				cout << " ";
			}
			cout << m_frame[7] << endl;
			cout << m_frame[6];
			for (int i = 0; i < len + 2; i++) {
				cout << m_frame[5];
			}
			cout << m_frame[4] << endl;
		}
		return cout;
	}
}
