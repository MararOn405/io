#include <vector>
#include<random>
#include "FileRW.h"
#include "offer.h"
#pragma once

class Seller
{
private:
	std::vector<Offer> offers;

public:
	void addOffer(std::string title, std::string description, double price, Cattegory cattegory) {

		Offer offer(title, description, price, cattegory);

		offers.push_back(offer); 
	}

	bool removeOffer(int id) {
		for(int i = 0; i < offers.size(); i++) {
			if(offers[i].getId() == id) {
				offers[i].remove();
				offers.erase(offers.begin() + i);
				return true;
			}
		}

		return false;
	}

	int getShippingCode() {
		std::random_device dev;
    	std::mt19937 rng(dev());
    	std::uniform_int_distribution<std::mt19937::result_type> dist(10000,99999); 

		return dist(rng);
	}


};