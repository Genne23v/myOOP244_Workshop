/**********************************************************
* Name: Wonkeun No
* Student ID: 145095196
* Seneca email: wno@myseneca.ca
* Section: NGG
**********************************************************/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
	class Account {
		int m_number;
		double m_balance;
		void setEmpty();
	public:
		Account();
		Account(int number, double balance);
		std::ostream& display()const;
		operator bool() const; 
		operator int() const;
		operator double() const;
		
		Account& operator=(int account);
		Account& operator=(Account& account);
		Account& operator+=(double depositMoney);
		Account& operator-=(double withdrawMoney);
		Account& operator<<(Account& account);
		Account& operator>>(Account& account);
	};
	bool operator~(const Account& account);
	double operator+(const Account& account, const Account& other);
	double& operator+=(double& balance, const Account& account);
}
#endif // SDDS_ACCOUNT_H_