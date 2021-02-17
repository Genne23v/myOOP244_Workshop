/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   Account& Account::operator=(int account)
   {
       if (!(bool)account)
       {
           setEmpty();
       }
       if (~account == true)
       {
           this->m_number = account;
       }
       return *this;
   }
   Account& Account::operator=(Account& account)
   {
       if (((bool)*this || ~*this) && ((bool)account || ~account))
       {
           this->m_number = account.m_number;
           this->m_balance = account.m_balance;
           account.m_number = 0;
           account.m_balance = 0.0;
       }
       return *this;
   }
   Account& Account::operator+=(double depositMoney)
   {
       if ((bool)*this && depositMoney >= 0.0)
       {
           this->m_balance += depositMoney;
       }
       return *this;
   }
   Account& Account::operator-=(double withdrawMoney)
   {
       if ((bool)*this && withdrawMoney >= 0.0 && this->m_balance > withdrawMoney)
       {
           this->m_balance -= withdrawMoney;
       }
       return *this;
   }
   Account& Account::operator<<(Account& account)
   {
       if ((bool)*this && (bool)account && this != &account)
       {
           this->m_balance += account.m_balance;
           account.m_balance = 0.0;
       }
       return *this;
   }
   Account& Account::operator>>(Account& account)
   {
       if ((bool)*this && (bool)account)
       {
           account.m_balance += this->m_balance;
           this->m_balance = 0.0;
       }
       return *this;
   }
   Account::operator bool() const
   {
       return (m_number >= 10000 && m_number <= 99999) && (m_balance >= 0);
   }
   Account::operator int() const 
   {
       return m_number;
   }
   Account::operator double() const
   {
       return m_balance;
   }
   bool operator~(const Account& account)
   {
       return ((int)account == 0);
   }
   double operator+(const Account& account, const Account& other)
   {
       double sum = 0.0;
       if ((bool)account && (bool)other)
       {
           sum = (double)account + (double)other;
       }
       else
       {
           sum = 0.0;
       }
       return sum;
   }
   double& operator+=(double& balance, const Account& account)
   {
       if ((bool)account)
       {
           balance += (double)account;
       }
       return balance;
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

}