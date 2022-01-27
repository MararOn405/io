#include "offer.h"
#include "seller.h"
#include "FileRW.h"
#include "auctions.txt"
#pragma once

class Buyer:private Seller
{
private:

public:

    void buyItem(std::string adr)
    {
        seller.removeOffer(id);

    }

    void ShowItem(std::Cattegory cattegory)
    {
        std::string line;
        std::fstream file;
        file.open("auctions.txt");

        do
        {
           getline(file, line);
           std::cout << line << endl;
        } while (line != "");

        file.close();
    }
        
};