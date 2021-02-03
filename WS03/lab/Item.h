/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
#define TAX 0.13
namespace sdds {
   class Item {
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
   };
}

#endif // !SDDS_SUBJECT_H
