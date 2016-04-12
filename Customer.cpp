#include <iostream>
#include "Customer.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <exception>

using namespace std;

Customer::Customer(string name, int customerID, bool credit) :
	name(name), customerID(customerID), credit(credit)
{
	memberName = "";
	balance = 0.0;
}

void Customer::setName(string name)
{
	this->name = name;
}

string Customer::getName() const
{
	return this->name;
}

int Customer::getID() const
{
	return this->customerID;
}

void Customer::setCredit(bool hascredit)
{
	this->credit = hascredit;
}

bool Customer::getCredit() const
{
	return this->credit;
}

double Customer::getBalance() const
{
	return this->balance;
}


void Customer::processPayment(double amount)
{
	balance += amount;
}
void Customer::processPurchase(double amount, Product product)
{
	if (credit)
	{
		balance -= amount;
		productsPurchased.push_back(product);
	}
	else if (!credit)
	{
		if (balance >= amount)
		{
			balance -= amount;
			productsPurchased.push_back(product);
		}
		else {
			throw std::exception();
		}
	}
	//If the customer has credit: subtract amount from balance (balance can be negative).
	//If the customer does not have credit: if the balance is greater than or equal to the amount then subtract amount from balance.
	//Otherwise throw an exception. (balance not allowed to be negative if credit is false)
	//Regardless, if the purchase occurs, then add product to productsPurchased.
}
//create an overloaded output operator for Customer.

std::ostream& operator<<(std::ostream& nos, const Customer& obj) {
	string name = obj.name;

	nos << "Customer name: " << obj.getName() << endl;
	return nos;
}
