#ifndef FoodItem_h
#define FoodItem_h
#include <iostream>
#include <string>
using namespace std;

// FOOD ITEM CLASS :
class FoodItem {
private:
	string itemname;
	double price;
	int quantity;
public:
	FoodItem(); // default constructor
	FoodItem(string name, double p, int q); // parameterized constructor
	// Setters
	void setitemname(string name);
	void setprice(double p);
	void setquantity(int q);
	// Getters
	string getitemname() const;
	double getprice() const;
	int getquantity() const;

	double calculateitemtotal() const;
	void displayitem() const;
};
#endif

