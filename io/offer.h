#pragma once
#include "FileRW.h"
#include<string>

enum Cattegory{electronics, clothes, moto, chemistry, garden, cosmetics};

int g_id; 

class Offer : private FileRW
{
private:
	std::string title;
	std::string description;
	double price;
	Cattegory cattegory;
	int id;

public:
	Offer(std::string t, std::string d, double p, Cattegory c) {
		title = t;
		description = d;
		price = p;
		cattegory = c;
		id = g_id;

		insertLine(t, "auctions.txt");
		insertLine(d, "auctions.txt");
		insertLine(std::to_string(p), "auctions.txt");
		insertLine(std::to_string(static_cast<int>(c)), "auctions.txt");
		insertLine("id: " + std::to_string(id), "auctions.txt");

		g_id++;
	}

	void remove() {
		deleteLine(title, "auctions.txt");
		deleteLine(description, "auctions.txt");
		deleteLine(std::to_string(price), "auctions.txt");
		deleteLine(std::to_string(static_cast<int>(cattegory)), "auctions.txt");
		deleteLine("id: " + std::to_string(id), "auctions.txt");
	}

	int getId() {
		return id;
	}
};
