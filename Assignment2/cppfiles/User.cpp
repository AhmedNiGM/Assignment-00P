#include"../headers/User.h"
int User::totalusers = 0; // initialize static member out of class
User::User() :userID(""), name(""), phonenumber("") {
	totalusers++; 
}
User::User(string id, string n, string phone) :userID(id), name(n), phonenumber(phone) {
	totalusers++; 
}

int User::gettotalusers() {
	return totalusers;
}
string User::getid() const { 
	return userID;
}
string User::getname() const {
	return name; 
}
string User::getphonenumber() const {
	return phonenumber;
}

User::~User() {}
