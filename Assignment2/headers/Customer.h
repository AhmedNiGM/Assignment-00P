#ifndef Customer_h
#define Customer_h
#include "User.h"

// CUSTOMER CLASS :
class Customer : public User {
private:
	string deliveryaddress;
	int loyaltypoints;                
public:
	Customer(); // default constructor
	Customer(string id, string n, string phone, string addr);

	void displayinfo() const override;
	double calculateearnings() const override;

	Customer& operator+=(int points);// add loyalty points
	// Setters
	void setaddress(string addr);
	void setpoints(int ppts);
	// Getters,Setters
	string getaddress() const;
	int getpoints() const;
};
#endif
