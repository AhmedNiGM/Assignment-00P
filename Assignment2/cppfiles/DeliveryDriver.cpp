#include "../headers/DeliveryDriver.h"
DeliveryDriver::DeliveryDriver() : User(), vehicletype(""), completeddeliveries(0), totalearnings(0) {}
DeliveryDriver::DeliveryDriver(string id, string n, string phone, string vehicle) :User(id, n , phone), vehicletype(vehicle), completeddeliveries(0), totalearnings(0) {}

void DeliveryDriver::displayinfo() const {
cout<< "Delivery Driver : " << name << ", ID: " << userID << ", Phone: " << phonenumber <<
		", Vehicle Type: " << vehicletype << ", Completed Deliveries: " << completeddeliveries <<
	", Total Earnings: " << totalearnings << " EGP" << endl;
}
double DeliveryDriver::calculateearnings() const {
	return totalearnings;
}
void DeliveryDriver::completedelivery(double overvalue) {
	totalearnings += overvalue * 0.15;
}
DeliveryDriver& DeliveryDriver::operator++() {
	completeddeliveries++;
	return *this;
}
DeliveryDriver DeliveryDriver::operator++(int) {
	DeliveryDriver temp = *this;
	completeddeliveries++;
	return temp;
}
string DeliveryDriver::getvehicle() const {
	return vehicletype;
}
int DeliveryDriver::getcompleteddeliveries() const {
	return completeddeliveries;
}
double DeliveryDriver::getearnings() const {
	return totalearnings;
}