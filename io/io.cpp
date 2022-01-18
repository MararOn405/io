#include <iostream>
#include "Account.h"
#include "MessageSystem.h"
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
	std::cout << "Wybierz akcje\n1 - Wyslij wiadomosc\n2 - Odbierz wiadomosci\n9 - Wyloguj sie\n0 - Wyjdz z programu\n";
	std::cin >> action;
	Message msg;
	std::vector<std::string> messages;
	try
	{
		switch (action)
		{

		case 0:
			exit(0);

		case 1:
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
				std::cout << "Brak wiadomosci.";
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
				std::cout << "1 - Nastepna wiadomosc\nDowolny przycisk - Wyjdz z wiadomosci\n";
				std::cin >> action;
				switch (action)
				{
				case 1:
					continue;
					break;
				default:
					break;
				}
				break;
			}
			goto logged_in;
			break;

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