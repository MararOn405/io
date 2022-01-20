#include "pch.h"
#include "CppUnitTest.h"
#include "../io/FileRW.h"
#include "../io/UserData.h"
#include "../io/Account.h"
#include "../io/Message.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UserdataTest)
	{
	public:
		TEST_METHOD(UserdataConstructorTest)
		{
			Userdata u("abc", "def");

			bool test1 = (u.username == "abc") ? true : false;
			bool test2 = (u.password == "def") ? true : false;

			Assert::IsTrue(test1 && test2);
		}
		TEST_METHOD(UserdataEmptyTest)
		{
			Userdata u;

			Assert::IsTrue(u.empty());
		}
		TEST_METHOD(UserdataNotEmptyTest)
		{
			Userdata u;
			u.username = "abc";

			Assert::IsFalse(u.empty());
		}

		TEST_METHOD(formatUserData)
		{
			Userdata u("abc", "asd");
			std::string test = "abc;asd";

			std::string output = u.formatUserdata();

			Assert::AreEqual(test,output);
		}
	};

	TEST_CLASS(FileRWTest)
	{
		TEST_METHOD(isStringInLineTest)
		{
			std::string test1 = "abc";
			std::string test2 = "abcdef";

			bool test = FileRW::isStringInLine(test1, test2);

			Assert::IsTrue(test);
		}

		TEST_METHOD(isStringNotInLineTest)
		{
			std::string test1 = "ghi";
			std::string test2 = "abcdef";

			bool test = FileRW::isStringInLine(test1, test2);

			Assert::IsFalse(test);
		}
	};

	TEST_CLASS(AccountTest)
	{
		TEST_METHOD(isDataValidTest)
		{
			Userdata u("abc", "defghi");

			bool test = Account::isDataValid(u);

			Assert::IsTrue(test);
		}
	};

	TEST_CLASS(MessageTest)
	{
		TEST_METHOD(MessageConstructorTest)
		{
			std::string s = "sender";
			std::string r = "recipient";
			std::string m = "message";

			Message msg(s, r, m);

			bool test1 = (msg.sender == s) ? true : false;
			bool test2 = (msg.recipient == r) ? true : false;
			bool test3 = (msg.message == m) ? true : false;

			Assert::IsTrue(test1 && test2 && test3);
		}
		TEST_METHOD(formatMessageTest)
		{
			Message msg("abc", "def", "jkl");
			std::string expected = "abc;def;jkl";

			std::string output = msg.formatMessage();

			Assert::AreEqual(expected, output);
		}
	};
}
