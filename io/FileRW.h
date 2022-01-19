#pragma once
#include<string>
#include<fstream>
#include<vector>
#include"Userdata.h"
class FileRW
{
public:
	static bool isStringInLine(std::string s1, std::string s2)
	{
		if (s2.find(s1) != std::string::npos) return true;
		return false;
	}

	static bool isLineInFile(std::string content, std::string path)
	{
		std::ifstream file(path);
		if (!file.is_open()) throw  std::string(__func__ + (std::string)": Plik nie zostal otwarty");
		else
		{
			std::string line;
			while (file >> line)
			{
				if (content.find(content) != std::string::npos)
				{
					file.close();
					return true;
				}
			}
		}
		return false;
	}

	static void insertLine(std::string content, std::string path)
	{
		std::ofstream file(path, std::ios_base::app);
		if (!file.is_open()) throw  std::string(__func__ + (std::string)": Plik nie zostal otwarty");
		else
		{
			file << content;
			file.close();
		}

	}

	static std::vector<std::string> getLines(std::string content, std::string path)
	{
		std::ifstream file;
		file.open(path);
		std::vector<std::string> ret;
		if (!file.is_open()) throw  std::string(__func__ + (std::string)": Plik nie zostal otwarty");
		else
		{
			std::string line;
			while (file >> line)
			{
				if (isStringInLine(content, line))
				{
					ret.push_back(line);
				}
			}
		}
		return ret;
	}

	static void deleteLine(std::string content, std::string path)
	{
		std::ifstream file;
		file.open(path);
		std::ofstream temp;
		temp.open("temp.txt");
		if (!file.is_open() || !temp.is_open()) throw  std::string(__func__ + (std::string)": Plik nie zostal otwarty");
		else
		{
			std::string line;
			while (file >> line)
			{
				if (!isStringInLine(line, content)) temp << line << std::endl;
			}
		}
		temp.close();
		file.close();

		const char* p = path.c_str();
		remove(p);
		rename("temp.txt", p);
	}
};

