#include "../headers/Customer.h"
Customer::Customer() : User(), deliveryaddress(""), loyaltypoints(0) {}
Customer::Customer(string id, string n, string phone, string addr) :User(id, n, phone), deliveryaddress(addr), loyaltypoints(0) {}

void Customer::displayinfo() const {
	cout << "Customer : " << name << ", ID: " << userID << ", Phone: " << phonenumber <<
		", Address: " << deliveryaddress << ", Loyalty Points: " << loyaltypoints << endl;
}
double Customer::calculateearnings() const {
	return loyaltypoints * 0.5;
}
void Customer::setaddress(string addr) {
	deliveryaddress = addr;
}
void Customer::setpoints(int points) {
	loyaltypoints = points;
} 
Customer& Customer::operator+=(int points) {
	loyaltypoints += points;
	return *this;
}
