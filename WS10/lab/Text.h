/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#include <iostream>
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
namespace sdds {
   class Text {
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
      Text(const Text& src);
      ~Text();

      Text& operator=(const Text& src);

      void copyContent(const char* str);
      char* getContent() const;
      void copyFilename(const char* filename);
      char* getFilename() const;
      void init();
      void read();
      virtual void write(std::ostream& os)const;
   };
   std:: ostream& operator<<(std::ostream& os, const Text& src);
}
#endif // !SDDS_PERSON_H__

