#include "ConcessionStand.h"
#include <iostream>
#include <iomanip> // std::setw(), std::setprecision(), std::fixed, std::left
#include <fstream>
#include <string>
#include <vector>


// constructors

ConcessionStand::ConcessionStand(std::string StandName) {} // name of stand 

// change information

void ConcessionStand::addItemToMenu(std::string ProductName, double ProductPrice, unsigned int ProductQuantity) {
	products.push_back(ProductName);
	
	prices.push_back(ProductPrice);
	
	quantity.push_back(ProductQuantity);
}
void ConcessionStand::sellMenuItem(unsigned int ItemNumber) {
	if (quantity[ItemNumber-1] == 0)std::cout << "Item is sold out" << std::endl;
	else quantity[ItemNumber-1] -= 1;
}

// get information
void ConcessionStand::displayMenu() const { 
	std::cout << "Menu" << std::endl <<std::endl << "---------------------------------" << std::endl << standName << std::endl;
	for (int i = 0; i < products.size();i++){
		std::cout << i + 1 << std::setw(15) << products[i] <<std::setw(15);
		if (quantity[i] > 0)std::cout << prices[i] << std::endl;
		else std::cout <<std::setw(15) << "SOLD OUT" << std::endl;
	}
}
bool ConcessionStand::printInventoryToFile() const { 
	std::ofstream inv;
	inv.open("inventory.txt");
	if(!(inv))
		return false;
	else {
		inv << std::setw(20) << "INVENTORY" << std::endl << "==============================" << std::endl;
		for (int i = 0; i < products.size(); i++) {
			inv << std::setw(15) << products[i] << std::setw(15) << quantity[i] << std::endl;
		}
	}
	inv.close();
	return true;
}