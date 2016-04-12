#include <iostream>
#include "Store.h"
#include <string>
#include <sstream>
#include <stdexcept>
#include <exception>

using namespace std;

Store::Store(string name) :storename(name)
{

}

Store::Store()
{

}

string Store::getStorename() const
{
	return this->storename;
}

void Store::setStorename(string name)
{
	this->storename = name;
}

void Store::addProduct(int productNum, string productName)
{
	//Create a new Product and add it to products.
	Product p1(productNum, productName);
	this->products.push_back(p1);
}

void Store::addCustomer(int customerID, string name)
{
	//Create a new Customer and add it to customers.
	bool credit = true;
	Customer c1(name, customerID, credit);
	this->customers.push_back(c1);
}

Product& Store::getProduct(int productNum)
{
	//Find the matching product and return it.Be sure that the product can be edited.If the customer does not exist throw an exception.
	// TODO: insert return statement

	int size = products.size();

	for (int i = 0; i < size; i++)
	{
		Product& product = products.at(i);

		if (product.getProductNum() == productNum) {
			return product;
		}
	}
	throw runtime_error("invalid productNum");
}

Customer& Store::getCustomer(int customerID)
{
	//Find the matching customer and return it. Be sure that the customer can be edited.
	//If the product does not exist throw an exception.
	//TODO: insert return statement

	bool credit = true;

	int size = customers.size();

	for (int i = 0; i < size; i++) {
		Customer& customer = customers.at(i);

		if (customer.getID() == customerID) {
			return customer;
		}
	}
	throw runtime_error("invalid CustomerId");
}

void Store::takeShipment(int productNum, int quantity, double cost)
{
	//Find matching Product. If product is not in list of products throw an exception.
	//Otherwise, update product with the shipment quantity and cost.

	Product prod = getProduct(productNum);

	prod.addShipment(quantity, cost);
}

void Store::makePurchase(int customerID, int productNum, int quantity)
{
	//Make the purchase if it is allowed, otherwise throw an exception or let an exception propagate.

	Customer customer = getCustomer(customerID);
	Product product = getProduct(productNum);
	product.processOrder(quantity);
	customer.processPurchase(quantity, product);
}

void Store::takePayment(int customerID, double amount)
{
	//Find matching customer and process the payment.

	Customer customer = getCustomer(customerID);

	customer.processPayment(amount);

}

void Store::listProducts()
{
	//Output information about each product.
	int size = products.size();

	for (int i = 0; i < size; i++) {
		ostringstream os;
		os << products.at(i) << endl;
	}
}

void Store::listCustomers()
{
	//Output information about each customer.

	int size = customers.size();

	for (int i = 0; i < size; i++) {
		ostringstream nos;
		nos << customers.at(i) << endl;
	}
}

