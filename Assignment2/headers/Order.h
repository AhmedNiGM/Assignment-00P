#ifndef Order_h
#define Order_h
#include "Customer.h"
#include "DeliveryDriver.h"
#include "FoodItem.h"
#include <iostream>
using namespace std;
// ENUM FOR ORDER STATUS :
enum class orderstatus { PENDING, PREPARING, OUT_FOR_DELIVERY, DELIVERED, CANCELLED };
//ORDER CLASS :
class Order {
private:
	string orderID;
	Customer* customer;
	DeliveryDriver* driver;
	FoodItem* items;
	int itemcount, capacity;
	OrderStatus status;
	Static int totalorders;
public:
	Order();
	Order(string id, customer* c)
		Order(const Order& other); // copy constructor
	~Order(); // destructor

	void additem(const fooditem& item);
	void assigndriver(DeliveryDriver* drv);
	void updatestatus(OrderStatus newstatus);
	double calculatetotal()const;
	void displayorder()const;

	static int gettotalorders();

	Order& operator+=(const fooditem& item);//add item to order
	friend Order operator+(const Order& o1 , const Order& o2) const;// combine two orders
	friend ostream& operator<<(ostream& out, const order& o);// output order details
	friend bool operator>(const order& o1, const order& o2);// compare orders by total value
	fooditem& operator[](int index);// access item by index for editing
	const fooditem& operator[](int index) const;// access item by index (const version)
};
#endif
