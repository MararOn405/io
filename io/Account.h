#pragma once
#include"Userdata.h"
#include "FileRW.h"
class Account : private FileRW 
{

public:
	static bool isDataValid(Userdata userdata)
	{
		if (userdata.username.length() < 3)
		{
			throw  std::string("Nazwa uzytkownika jest za krotka.\n");
			return false;
		}
		if (userdata.password.length() < 6)
		{
			throw  std::string("Haslo jest za krotkie.\n");
			return false;
		}
		return true;
	}

	static bool isUsernameInUse(Userdata userdata)
	{
		std::string line = userdata.username;
		if (isLineInFile(line, "users.txt"))
		{
			throw std::string("Nazwa uzytkownika jest juz w uzyciu.\n");
			return true;
		}
		return false;
	}

	static bool createAccount(Userdata userdata)
	{
		if (isDataValid(userdata) && !isUsernameInUse(userdata))
		{
			insertLine(userdata.formatUserdata(), "users.txt");
			return true;
		}
		return false;
	}

	static bool logIn(Userdata userdata)
	{
		std::string line = userdata.formatUserdata();
		if (isLineInFile(line, "users.txt")) return true;
		return false;
	}

	static bool deleteAccount(std::string username)
	{
		if (isLineInFile(username+";", "users.txt"))
		{
			deleteLine(username + ";", "users.txt");
			return true;
		}
		throw std::string("Nie istnieje konto z taka nazwa uzytkownika\n");
		return false;
	}

};

