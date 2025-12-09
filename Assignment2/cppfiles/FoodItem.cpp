#include "../headers/FoodItem.h"
FoodItem::FoodItem() : itemname(""), price(0), quantity(0) {}
FoodItem::FoodItem(string name, double p, int q) : itemname(name), price(p), quantity(q) {}
string FoodItem::getitemname() const {
	return itemname;
}
double FoodItem::getprice() const {
	return price;
}
int FoodItem::getquantity() const {
	return quantity;
}
void FoodItem::setitemname(string name) {
	itemname = name;
}
void FoodItem::setprice(double p) {
	price = p;
}
void FoodItem::setquantity(int q) {
	quantity = q;
}
double FoodItem::calculateitemtotal() const {
	return price * quantity;
}
void FoodItem::displayitem() const {
	cout << "ItemName:" << itemname << "...Quantity" << quantity << "...Price:" << price << "EGP" <<"...Total:" << calculateitemtotal() << endl;
}