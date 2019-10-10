#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class snack {

private:
	float price;
	string name;
	string keypadNum;
	int stock;

public:
	void setPrice(float priceSet);
	void setName(string nameSet);
	void setKey(string keySet);
	void setStock(int stockSet);
	string getName();
	float getPrice();
	string getKey();
	int getStock();
};

