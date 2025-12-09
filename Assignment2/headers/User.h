#ifndef User_h
#define User_h
#include <iostream>
#include <string>
using namespace std;

// USER CLASS :
class User {
protected:
	string userID, name, phonenumber;
	static int totalusers;
public:
	User(); // default constructor
	User(string id, string n, string phone);//phone is string cause of +201... "parametarized constructor "

	virtual void displayinfo() const = 0;
	virtual double calculateearnings() const = 0;
	static int gettotalusers();

	// Getters
	string getid() const;
	string getname() const;
	string getphonenumber() const;

	virtual ~User(); // virtual destructor
};
#endif