/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#include <fstream>
#include <string>
#include <cstring>
#include "Text.h"
#include "cstring.h"

using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }
   const char& Text::operator[](int index)const
   {
       return m_content[index];
   }

   Text::Text(const char* filename)
   {
       init();

       if (filename != nullptr)
       {
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
           read();
       }
       //int temp = strlen(m_content);
   }

   Text::Text(const Text& src)
   {
       init();

       if (src.m_filename != nullptr)
       {
           m_filename = new char[strLen(src.m_filename) + 1];
           strCpy(m_filename, src.m_filename);
       }

       if (src.m_content != nullptr)
       {
           m_content = new char[strLen(src.m_content) + 1];
           strCpy(m_content, src.m_content);
       }
   }

   Text::~Text()
   {
       delete[] m_filename;
       delete[] m_content;
       m_filename = nullptr;
       m_content = nullptr;
   }

   Text& Text::operator=(const Text& src)
   {
       if (m_filename != nullptr)
       {
           delete[] m_filename;
           m_filename = nullptr;
       }
       if (m_content != nullptr)
       {
           delete[] m_content;
           m_content = nullptr;
       }

       if (src.m_filename != nullptr)
       {
           m_filename = new char[strLen(src.m_filename) + 1];
           strCpy(m_filename, src.m_filename);
       }

       if (src.m_content != nullptr)
       {
           m_content = new char[strLen(src.m_content) + 1];
           strCpy(m_content, src.m_content);
       }

       return *this;
   }

   char* Text::getContent() const
   {
       return m_content;
   }

   void Text::copyContent(const char* str)
   {
       if (m_content != nullptr)
       {
           delete[] m_content;
       }
       m_content = new char[strLen(str) + 1];
       strCpy(m_content, str);
   }

   char* Text::getFilename() const
   {
       return m_filename;
   }

   void Text::copyFilename(const char* filename)
   {
       if (m_filename != nullptr)
       {
           delete[] m_filename;
       }
       m_filename = new char[strLen(filename) + 1];
       strCpy(m_filename, filename);
   }

   void Text::init()
   {
       m_filename = nullptr;
       m_content = nullptr;
   }

   void Text::read()
   {
       int length = getFileLength();
       m_content = new char[length + 1];

       ifstream fin(m_filename);
       string temp;
       char c;

       if (fin.is_open())
       {
           //int i = 0;
           fin >> noskipws;
           while (fin >> c)
           {
               //fin.get(temp[i]);
               //fin.get() >> temp[i];
               //i++;
               temp += c;
           }
           //temp[i] = '\0';
       }
       strCpy(m_content, temp.c_str());

       fin.close();
   }

   void Text::write(std::ostream& os)const
   {
       if (m_content != nullptr)
       {
           os << m_content;
       }
   }
   
   ostream& operator<<(ostream& os, const Text& src)
   {
       src.write(os);
       return os;
   }
}