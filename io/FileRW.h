#pragma once
#include<exception>
#include<vector>
#include<string>
#include<fstream>
#include"Userdata.h"
class FileRW
{
public:

	static bool isStringInLine(std::string s1, std::string s2)
	{
		if (s2.find(s1) != std::string::npos) return true;
		return false;
	}

	static Userdata readUserdataFromFile(std::string username,  std::string path = "users.txt")
	{
		std::ifstream file(path);
		if (!file.is_open()) throw "readUserdataFromFile: Plik nie zostal otwarty";
		else
		{
			std::string content;
			Userdata userdata;
			while (file >> content)
			{
				int pos = content.find_first_of(";");
				if (content.substr(0, pos) == username)
				{
					userdata.username = content.substr(0, pos);
					userdata.password = content.substr(pos + 1);
				}
			}
			file.close();
			return userdata;
		}
	}

	static bool usernameInUse(Userdata userdata , std::string path = "users.txt")
	{
		std::ifstream file(path);
		if (!file.is_open()) throw "usernameInUse: Plik nie zostal otwarty";
		else
		{
			std::string content;
			while (file >> content)
			{
				if (isStringInLine(userdata.username, content))
				{
					file.close();
					return true;
				}
			}
			file.close();
			return false;
		}
	}

	static void addUserdataToFile(Userdata userdata, std::string path = "users.txt")
	{
		std::ofstream file(path, std::ios_base::app);
		if (!file.is_open()) throw "addUserdataToFile: Plik nie zostal otwarty";
		else
		{
			file << userdata.formatUserdata();
			file.close();
		}
	}

	static void deleteUserdata(Userdata userdata, std::string path = "users.txt")
	{
		std::string line;
		std::ifstream file;

		file.open(path);
		if (!file.is_open()) throw "eraseUserdata: Plik nie zostal otworzony";
		else
		{
			std::ofstream temp;
			temp.open("temp.txt");

			while (file >> line) 
			{
				if (line != userdata.formatUserdata())
					temp << line << std::endl;
			}

			temp.close();
			file.close();
		}

		const char* p = path.c_str();
		remove(p);
		rename("temp.txt", p);
	}
};

