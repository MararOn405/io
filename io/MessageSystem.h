#pragma once
#include"FileRW.h"
#include<algorithm>
#include"Message.h"
class MessageSystem : protected FileRW
{

public:

	static bool sendMessage(Message message)
	{
		if (isLineInFile(message.recipient + ";", "users.txt"))
		{
			insertLine(message.formatMessage(), "messages.txt");
			return true;
		}
		throw std::string("Nie istnieje taki uzytkownik.");
		return false;
	}

	static std::vector<std::string> getUserMessages(std::string username)
	{
		return getLines(";" + username + ";", "messages.txt");
	}
};

