// vendingMachine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "snacks.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	cout << fixed << showpoint;
	cout << setprecision(2);

	snack snackList[10];//array of snacks
	ifstream snackVars;//read in file variable

	snackVars.open("snackList.txt");

	string name;
	float price;
	string alphaNum;
	int stock;
	int tempVar = 0;
	
	//User Defined Variables
	float costPrompt; //input for user to pay price of snack selected
	string snackSelect;
	char quit = 'y';

	//this for loop iterates throught the snackList array and assigns all the values to the different elements by reading in from "snackList.txt"
	//and using accessors and mutators
	for (int i = 0; i < 8; i++)
	{
		snackVars >> name >> price >> alphaNum >> stock;
		snackList[i].setName(name);
		snackList[i].setPrice(price);
		snackList[i].setKey(alphaNum);
		snackList[i].setStock(stock);
	}

	while (quit == 'y' || quit == 'Y')
	{
		cout << "Welcome to our vending machine! Here are a list of our snacks and their prices." << endl;

		for (int i = 0; i < 8; i++)
		{
			cout << "Key: " << snackList[i].getKey() << " " << snackList[i].getName() << " Price: " << snackList[i].getPrice() << endl;
		}

		cout << "Enter the key of the snack you want." << endl;
		cin >> snackSelect;

		for (int i = 0; i < 8; i++)
		{
			if (snackSelect == snackList[i].getKey())
			{
				tempVar = i;
				break;
			}
		}

		cout << "You have chosen " << snackList[tempVar].getName() << ", which cost: " << snackList[tempVar].getPrice() << endl;
		cout << "Please enter $" << snackList[tempVar].getPrice() << " to continue." << endl;
		cin >> costPrompt;

		while (costPrompt < snackList[tempVar].getPrice())
		{
			float oldPrompt = costPrompt;; // money user already entered into machine

			cout << "Insufficient funds, please insert at least $" << snackList[tempVar].getPrice() - costPrompt << " to continue." << endl;
			cin >> costPrompt;
			costPrompt = costPrompt + oldPrompt;
		}

		cout << "Thank you for your purchase, here is your " << snackList[tempVar].getName() << "." << endl;

		//Stock Decrement
		snackList[tempVar].setStock(snackList[tempVar].getStock() -1);
		cout << snackList[tempVar].getStock() << endl;

		cout << "Would you like to purchase another snack? Y/N?" << endl;
		cin >> quit;
	}
	cout << "Thank you for using our vending machine! Enjoy!" << endl;
}
