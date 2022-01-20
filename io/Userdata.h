#pragma once
class Userdata
{
public:

	std::string username;
	std::string password;
	

	Userdata() {};
	Userdata(std::string u, std::string p)
	{
		username = u;
		password = p;
	}

	bool empty()
	{
		if (username.empty() && password.empty()) return true;
		return false;
	}

	std::string formatUserdata()
	{
		return username + ";" + password;
	}
};

