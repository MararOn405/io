#include "pch.h"
#include "CppUnitTest.h"
#include "../io/FileRW.h"
#include "../io/UserData.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UserdataTest)
	{
	public:
		
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
			std::string test = "abc;asd\n";

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
}
