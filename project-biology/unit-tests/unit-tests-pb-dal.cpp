#include "pch.h"
#include "CppUnitTest.h"
#include "../pb.dal/login-files.h"
#include "../pb.types/sha256.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
	TEST_CLASS(unittests)
	{
	public:

		TEST_METHOD(TestLoginFiles1)
		{
			// Arrange
			int result;
			std::string password = sha256("password1234$");
			//Act
			result = getId("VRKirov19", password);

			//Assert
			Assert::AreEqual(4, result);
		}
	};
}
