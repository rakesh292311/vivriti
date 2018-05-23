#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
enum CType {
	REGULAR, SENIOR, EMPLOYEE
};
class Person {
public:
	//factory pattern;
	static Person *createPerson(int typeId);

};
class 
Customer :public Person {
public:
	void addToCart();
};

class Cashier :public Person {
public:
};

Person *Person::createPerson(int typeId)
{
	if (typeId == 1)
		return new Customer();
	else if (typeId == 2)
		return new Cashier();
}

class StoreItem {
	string m_name;
	double m_price;
public:
	StoreItem(string name, float price) :m_name("default"), m_price(0.01) {
		m_name = name;
		m_price = price;
	}
	double getPrice() { return m_price; }
	string getName() const { return this->m_name; }
};
// decorator pattern
class EmployeeDItem {
	StoreItem m_item;
public:
	EmployeeDItem(StoreItem item)  {
		m_item =  item;
	}
	double getPrice() { return m_item.getPrice()-m_item.getPrice()*10/100; }
	string getName() const { return m_item.getName(); }
};
class SeniorDItem {
	StoreItem m_item;
public:
	SeniorDItem(StoreItem item) {
		m_item = item;
	}
	double getPrice() { return m_item.getPrice() - m_item.getPrice() * 20 / 100; }
	string getName() const { return m_item.getName(); }
};
class GroceryStore {
	map<string, int> m_inventory;

public:
	void addInventory(string itemname, int count) { m_inventory[itemname] += count; }
	void printInventory()
	{
		map<string , int>::iterator it;
		for (it = m_inventory.begin();it != m_inventory.end();it++)
		{
			cout << it->first << " " << it->second << endl;
			
		}

	}
};

int main()
{
	return 0;
}