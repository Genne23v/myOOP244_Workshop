/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
**********************************************************/
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
//#include <iostream>
#include <iostream>
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
      char* m_title;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      HtmlText(const HtmlText& src);
      HtmlText& operator=(const HtmlText& src);
      ~HtmlText();
      char* getFilename() const;
      //char* getContent() const;
      void write(std::ostream& os);

   };
   std::ostream& operator<<(std::ostream& os, HtmlText& src);
}
#endif // !SDDS_HTMLTEXT_H__
