#ifndef DeliveryDriver_H
#define DeliveryDriver_H
#include "User.h"

// DElIVERY DRIVER CLASS :
class DeliveryDriver : public User {
private:
	string vehicletype;
	int completeddeliveries;
	double totalearnings;
public:
	DeliveryDriver();// default constructor
	DeliveryDriver(string id, string n, string phone, string vehicle);

	void displayinfo() const override;
	double calculateearnings() const override;
	void completedelivery(double overvalue);

	DeliveryDriver& operator++(); // prefix ++
	DeliveryDriver operator++(int); // postfix ++
	// Getters
	string getvehicle() const;
	int    getcompleteddeliveries() const;
	double getearnings() const;
};
#endif