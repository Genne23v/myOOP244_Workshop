/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_

namespace sdds {
    class Food {
        char f_name[31];
        int m_calories;
        int m_time;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calories, int time);
        bool isValid()const;
        int calories()const;
        void display()const;
    };
}

#endif // !SDDS_SUBJECT_H
