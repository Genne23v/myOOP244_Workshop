/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/

#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Food.h"
#include "cstring.h"
namespace sdds {
    class CalorieList {
        Food* m_items;
        int m_noOfFood;
        int m_itemsAdded;
        
        void Title()const;
        void footer()const;
        void setEmpty();
        int totalCalories()const;
    public:
        void init(int size);
        bool add(const char* item_name, int calories, int time);
        bool isValid()const;
        void display()const;
        void deallocate();
    };
}
#endif // !SDDS_TRANSCRIPT_H
