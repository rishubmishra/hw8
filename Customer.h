#pragma once
#include "Product.h"
#include <string>
#include <vector>
#include <iostream>



class Customer
{

private:
	//data members
	std::string memberName;
	int customerID;
	bool credit;
	double balance;

	std::vector<Product> productsPurchased;


public:
	//constructor
	Customer(std::string name, int customerID, bool credit);

	//accessors and mutators
	void setName(std::string name);
	std::string getName() const;
	int getID() const;
	void setCredit(bool hascredit);
	bool getCredit() const;
	double getBalance() const;

	void processPayment(double amount);
	void processPurchase(double amount, Product product);

	std::string name;

};

std::ostream& operator<<(std::ostream& nos, const Customer& obj);

