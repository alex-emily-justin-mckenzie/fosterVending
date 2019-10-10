#include "snacks.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


void snack::setPrice(float priceSet)
{
	price = priceSet;
	return;
}

void snack::setName(string nameSet)
{
	name = nameSet;
	return;
}

void snack::setKey(string keySet)
{
	keypadNum = keySet;
	return;
}

void snack::setStock(int stockSet)
{
	stock = stockSet;
	return;
}

string snack::getName()
{
	return name;
}

string snack::getKey()
{
	return keypadNum;
}

int snack::getStock()
{
	return stock;
}

float snack::getPrice()
{
	return price;
}