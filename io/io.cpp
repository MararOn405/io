#include <iostream>
#include "FileRW.h"

int main()
{
	try
	{
		Userdata userdata = FileRW::readUserdataFromFile("asd");
		if (!userdata.empty())
		{
			std::cout << "username: " << userdata.username << "\npassword: " << userdata.password;
		}

		Userdata new_user("dfgsdfg", "zxsdfgdsfgc");
		//FileRW::addUserdataToFile(new_user);

		//FileRW::deleteUserdata(new_user);

		if (FileRW::usernameInUse(new_user)) std::cout << "uzytkownik istnieje sdfsdf\n";
		else std::cout << "nie ma uzytkownika";
	}
	catch (const char* e)
	{
		std::cout << e;
	}
}
