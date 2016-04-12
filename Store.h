#pragma once
#include "Customer.h"
#include "Product.h"
#include <string>
#include <vector>



class Store
{

private:
	//data members
	std::vector<Product> products;
	std::vector<Customer> customers;
	std::string storename;



public:

	//constructors
	Store(std::string name);
	Store();

	//accessors and mutators
	std::string getStorename() const;
	void setStorename(std::string name);

	//Commented out for Milestone 1 only
	void addProduct(int productNum, std::string productName);
	void addCustomer(int customerID, std::string name);
	void takeShipment(int productNum, int quantity, double cost);
	void makePurchase(int customerID, int productNum, int quantity);
	void takePayment(int customerID, double amount);
	void listProducts();
	void listCustomers();

	//accessors
	Product& getProduct(int productNum);
	Customer& getCustomer(int customerID);

};
