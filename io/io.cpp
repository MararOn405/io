#include <iostream>
#include "Account.h"
#include "MessageSystem.h"
#include "seller.h"
#include "buyer.h"

int main()
{
main:
	system("cls");
	std::cout << "Nie jestes zalogowany. Zaloguj sie lub utworz konto\n1 - Zaloguj sie\n2 - Utworz konto\n0.Wyjdz\n";
	int action;
	Userdata login_data;
	std::cin >> action;
	try {
		switch (action)
		{
			case 0: exit(0);

			case 1:
				std::cout << "Wpisz nazwe uzytkownika\n";
				std::cin >> login_data.username;
				std::cout << "Wpisz haslo\n";
				std::cin >> login_data.password;
				if (!Account::logIn(login_data))
				{
					throw std::string("Niepoprawna nazwa uzytkownika lub haslo.\n");
				}
				else std::cout<<"pomyslnie zalogowano.\n";
					break;

			case 2:
				std::cout << "Wpisz nazwe uzytkownika\n";
				std::cin >> login_data.username;
				std::cout << "Wpisz haslo\n";
				std::cin >> login_data.password;
				if (Account::createAccount(login_data))
				{
					std::cout << "Pomyslnie utworzono konto.\n";
					system("pause");
					goto main;
				}
				break;

			case 2137:
				std::cout << "Wpisz nazwe uzytkownika\n";
				std::cin >> login_data.username;
				if (Account::deleteAccount(login_data.username))
				{
					std::cout << "Pomyslnie usunieto konto.\n";
					system("pause");
					goto main;
				}
				//else std::cout << "Nie istnieje konto z taka nazwa uzytkownika\n";
				break;

			default:
				throw  std::string("Wybrano niepoprawna akcje.");
				system("pause");
				goto main;
				break;
		}
	}
	catch (std::string e)
	{
		std::cout << e << "\n";
		system("pause");
		goto main;
	}
logged_in:

	system("cls");
	std::cout << "Zalogowano jako " << login_data.username << std::endl;
	std::cout << "Wybierz akcje\n1 - Wyslij wiadomosc\n2 - Odbierz wiadomosci\n3 - Dodaj aukcje\n4 - Usun aukcje\n5 - Wyslij przedmiot ze swojej aukcji\n6 - Pokaz aukcje\n7 - Zakup przedmiot\n9 - Wyloguj sie\n0 - Wyjdz z programu\n";
	std::cin >> action;
	Message msg;
	Seller seller;
	std::vector<std::string> messages;
	try
	{
		switch (action)
		{

		case 0:
			exit(0);

		case 1:
			getchar();

			std::cout << "Wpisz nazwe uzytkownika odbiorcy:\n";
			std::cin >> msg.recipient;

			std::cout << "Wpisz wiadomosc:\n";
			std::cin >> msg.message;

			msg.sender = login_data.username;
			if (MessageSystem::sendMessage(msg))
			{
				std::cout << "Pomyslnie wyslano wiadomosc\n";
				system("pause");
				goto logged_in;
			}

			break;

		case 2:
			messages = MessageSystem::getUserMessages(login_data.username);
			if (messages.size() == 0)
			{
				std::cout << "Brak wiadomosci.\n";
				system("pause");
				goto logged_in;
			}
			for (int i = 0; i < messages.size(); i++)
			{
				system("cls");
				msg = messages[i];
				std::cout << "Wiadomosc " << i+1 << " z " << messages.size() << "\n";
				std::cout << "Nadawca: " << msg.sender << std::endl;
				std::cout << "Tresc: " << msg.message << std::endl;
				std::cout << "1 - Nastepna wiadomosc\n2 - Usun wiadomosc\nDowolny przycisk - Wyjdz z wiadomosci\n";
				std::cin >> action;
				switch (action)
				{
				case 1:
					continue;
					break;
				case 2:
					if(MessageSystem::deleteMessage(msg)) std::cout << "Pomyslnie usunieto wiadomosc.\n";
					system("pause");
					continue;
					break;
				default:
					break;
				}
				break;
			}
			goto logged_in;
			break;

		case 3: {
			std::string title, description; double price; int cattegory;
			getchar();

			std::cout << "Podaj tytul: ";
			std::getline(std::cin, title);

			std::cout << "Podaj opis: ";
			std::getline(std::cin, description);

			std::cout << "Podaj cene: ";
			std::cin >> price;

			do {
				std::cout << "Wybierz kategorie: 0 - elektronika 1 - ubrania 2 - motoryzacja 3 - artykuly chemiczne 4 - artykuly ogrodowe 5 - kosmetyki: ";
				std::cin >> cattegory; 
			} while(!(cattegory >= 0 && cattegory <= 5));

			Cattegory cat = static_cast<Cattegory>(cattegory);

			seller.addOffer(title, description, price, cat);

			std::cout << "Aukcja utworzona pomyslnie.\n";
			system("pause");

			goto logged_in;
			break;
		}

		case 4: {
			std::cout << "Podaj id aukcji ktora chcesz usunac: ";
			int id;
			std::cin >> id;

			if(seller.removeOffer(id)) {
				std::cout << "Aukcja usunieta pomyslnie";
			}

			else {
				std::cout << "Nie jestes wlascicielem aukcji o takim id";
			}

			system("pause");

			goto logged_in;
			break;
		}

		case 5: {
			std::cout << "Podaj adres wysylki: ";
			std::string adr;
			std::getline(std::cin, adr);
			getchar();

			std::cout << "Twoj kod wysylki pod adres " << adr << " to " << seller.getShippingCode();
			system("pause");
			getchar();

			goto logged_in;
			break;
		}

		case 6: {
			do {
				std::cout << "Wybierz kategorie: 0 - elektronika 1 - ubrania 2 - motoryzacja 3 - artykuly chemiczne 4 - artykuly ogrodowe 5 - kosmetyki: ";
				std::cin >> cattegory;
			}

			ShowItem(cattegory);

			system("pause");
			goto logged_in;
			break;

		}

		case 7: {
			std::cout << "Podaj numer id aukcji ktora chcesz zakupic: ";
			int id;
			std::cin >> id;

			buyer.BuyItem(id);

			std::cout << "Podaj adres wysylki: ";
			std::string adr;
			std::getline(std::cin, adr);
			getchar();

			std::cout << "Przedmiot zostal zakupiony, przejdz do platnosci kontaktujac sie ze sprzedawca" << endl; 
			system("pause");
			goto logged_in;
			break;
		}

		case 9:
			goto main;
			break;

		default:

			goto logged_in;
			break;
		}
	}
	catch (std::string e)
	{
		std::cout << e << "\n";
		system("pause");
		goto logged_in;
	}
}