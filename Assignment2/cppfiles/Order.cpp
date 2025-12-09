#include"../headers/Order.h"
int Order::totalorders = 0; // initialize static member out of class
Order::Order() : orderID("") , customer(nullptr) , driver (nullptr), items (nullptr), itemcount (0), capacity (0), status(orderstatus::PENDING) {
	totalorders++;
}
Order::Order(string id , Customer* c) :orderID(id) , customer(c), driver(nullptr), items(nullptr), itemcount(0), capacity(0), status(orderstatus::PENDING) {
	totalorders++;
}
// Copy Constructor
Order::Order(const Order& other) {
	orderID = other.orderID;
	customer = other.customer;
	driver = other.driver;
	itemcount = other.itemcount;
	capacity = other.capacity;
	status = other.status;
	totalorders++;
	if (capacity > 0) {
		items = new FoodItem[capacity];
		for (int i = 0; i < itemcount ; i++)
			items[i] = other.items[i];
	}
	else {
		items = nullptr;
	}
}
Order::~Order() {
	delete[] items;
}
void Order::additem(const FoodItem& item) {
	if (itemcount == capacity) {
		int newcapacity = (capacity == 0 ? 1 : capacity * 2);
		FoodItem* newitems = new FoodItem[newcapacity];
		for (int i = 0; i < itemcount; i++) {
			newitems[i] = items[i];
		}
		delete[] items;
		items = newitems;
		capacity = newcapacity;
	}
		items[itemcount++] = item;
}
void Order::assigndriver(DeliveryDriver* drv) {
	driver = drv;
}
void Order::updatestatus(orderstatus newstatus) {
	status = newstatus;
}
double Order::calculatetotal() const {
	double total = 0;
	for (int i = 0; i < itemcount; i++) {
		total += items[i].calculateitemtotal();
	}
	return total;
}




void Order::displayorder() const {
	cout << "OrderID : " << orderID << endl;
	if (customer) {
		cout << "Customer : " << customer->getname()
			<< "ID : " << customer->getid() << endl;
	}
	if (driver) {
		cout << "Driver : " << driver->getname()
			<< "ID : " << driver->getid() << endl;
	}
	cout << " STATUSSS :";
	switch (status) {
	case orderstatus::PENDING: cout << "Pendingg"; break;
	case orderstatus::PREPARING:cout << "Preparinggg"; break;
	case orderstatus::OUT_FOR_DELIVERY: cout << "OUT_FOR_DELIVERY"; break;
	case orderstatus::DELIVERED:cout << "Deliverddd"; break;
	case orderstatus::CANCELLED:cout << "Cancelledddddd"; break;
	}
	cout << endl;
	cout << " Total: " << calculatetotal() << " EGB" << endl;
	cout << " Items :" << endl;
	for (int i = 0; i < itemcount; i++) {
		cout << " -->> " << items[i].getitemname()
			<< " 0Oo" << items[i].getquantity()
			<< " ___--> @" << items[i].getprice() << "EGB"
			<< "+_+->> " << items[i].calculateitemtotal() << "EGB" << endl;
	}
}





	int Order::gettotalorders() {
		return totalorders;
	}
	Order& Order::operator+= (const FoodItem& item) {
		additem(item);
		return *this;
	}
	Order operator+(const Order& o1, const Order& o2) {
		Order combined(o1);
		for (int i = 0; i < o2.itemcount; i++) {
			combined.additem(o2.items[i]);
		}
		return combined;
	}
	ostream& operator<<(ostream& out, const Order& o) {
		out << "OrderID : " << o.orderID
		    << " ||Total : " << o.calculatetotal();
		return out;
	}
	bool operator>(const Order& o1, const Order& o2) {
		return o1.calculatetotal() > o2.calculatetotal();
	}
	FoodItem& Order::operator[](int index) {
		if (index < 0 || index >= itemcount) {
			throw out_of_range("Invalid Item Index");
		}
		return items[index];
	}
	const FoodItem& Order::operator[](int index) const {
		if (index < 0 || index >= itemcount) {
			throw out_of_range("Invalid Item Index");
		}
		return items[index];
	}

