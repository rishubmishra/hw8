#pragma once
#include <string>
#include <list>
#include <iostream>

#pragma once
#include <string>
#include <list>
#include <iostream>

class Product
{

private:
	//data members
	int productNum;
	int inventory;
	int numSold;
	double totalCost;
	std::string description;
	int defaultReturnDays;

protected:
	//data members
	std::string productName;

public:
	//constructor
	Product(int productNum, std::string ProductName);


	//accessors and mutators
	void setDescription(std::string description);
	std::string getDescription() const;
	void setDefaultReturnPeriod(int days);
	int getReturnPeriod() const;
	int getNumberSold() const;
	double getTotalCost() const;
	void setProductNum(int productNum);
	int getProductNum() const;

	void addShipment(int quanity, double cost);
	double getPrice();
	void processOrder(int quantity);
	std::string getInfo();
	int getInventoryCount();

};

std::ostream& operator<<(std::ostream& os, const Product& obj);


