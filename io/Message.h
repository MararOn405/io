#pragma once
#include<string>
#include<vector>
class Message
{
public:
	std::string sender;
	std::string recipient;
	std::string message;

	Message() {};
	Message(std::string s, std::string r, std::string m)
	{
		sender = s;
		recipient = r;
		message = m;
	}

	Message(std::string formatted)
	{
		int pos1 = formatted.find_first_of(";");
		int pos2 = formatted.find_last_of(";");
		sender = formatted.substr(0, pos1);
		recipient = formatted.substr(pos1 + 1, pos2);
		message = formatted.substr(pos2 + 1);
	}

	std::string formatMessage()
	{
		return sender + ";" + recipient + ";" + message + "\n";
	}

};

