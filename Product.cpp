#include <iostream>
#include "Store.h"
#include <string>
#include <stdexcept>
#include <exception>
using namespace std;

Product::Product(int productNum, string productName) :
	productNum(productNum), productName(productName)
{
	inventory = 0;
	numSold = 0;
	totalCost = 0.0;
	description = "";
	defaultReturnDays = 0;
}

void Product::setProductNum(int productNum) {
	this->productNum = productNum;
}

int Product::getProductNum() const {
	return this->productNum;
}
void Product::setDescription(string description)
{
	this->description = description;
}

string Product::getDescription() const
{
	return description;
}

void Product::setDefaultReturnPeriod(int days)
{
	this->defaultReturnDays = days;
}

int Product::getReturnPeriod() const
{
	return defaultReturnDays;
}

int Product::getNumberSold() const
{
	return numSold;
}

double Product::getTotalCost() const
{
	return totalCost;
}

void Product::addShipment(int quantity, double cost)
{
	inventory += quantity;
	totalCost += cost;
	//Add quantity to inventory and increase totalCost by cost. Do not replace value in cost, just increase it.
}

double Product::getPrice()
{
	//This function will calculate the current price based on the average cost per item over time.
	return (totalCost / (inventory + numSold)) * 1.25;
}

void Product::processOrder(int quantity)
{
	if (inventory < quantity) {
		throw runtime_error("inventory too small");
	}
	else {
		inventory -= quantity;
		numSold += quantity;
	}
}

string Product::getInfo()
{
	return string();
}
int Product::getInventoryCount()
{
	return 0;
}

std::ostream& operator<<(std::ostream& os, const Product& obj) {
	os << "ProductNum: " << obj.getProductNum() << endl;
	os << "Description: " << obj.getDescription() << endl;

	return os;
}
//Not part of class: create an overloaded output operator for Product

