#include "pch.h"
#include "CppUnitTest.h"
#include "../pb.bll/register.h"
#include "../pb.bll/logic-for-objects.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
	TEST_CLASS(unittests)
	{
	public:
		
		TEST_METHOD(TestRegister1)
		{
			// Arrange
			bool result;

			//Act
			result = passwordHasNumbers("password 123");

			//Assert
			Assert::AreEqual(true, result);
		}


		TEST_METHOD(TestRegister2)
		{
			// Arrange
			bool result;

			//Act
			result = passwordHasNumbers("password");

			//Assert
			Assert::AreEqual(false, result);
		}


		TEST_METHOD(TestRegister3)
		{
			// Arrange
			bool result;

			//Act
			result = passwordHasSymbols("password %");

			//Assert
			Assert::AreEqual(true, result);
		}


		TEST_METHOD(TestRegister4)
		{
			// Arrange
			bool result;

			//Act
			result = passwordHasSymbols("password");

			//Assert
			Assert::AreEqual(false, result);
		}


		TEST_METHOD(TestRegister5)
		{
			// Arrange
			int result;

			//Act
			result = passwordIsGood("pass", "pass");

			//Assert
			Assert::AreEqual(1, result);
		}


		TEST_METHOD(TestRegister6)
		{
			// Arrange
			int result;

			//Act
			result = passwordIsGood("password", "password");

			//Assert
			Assert::AreEqual(2, result);
		}


		TEST_METHOD(TestRegister7)
		{
			// Arrange
			int result;

			//Act
			result = passwordIsGood("password1", "password1");

			//Assert
			Assert::AreEqual(3, result);
		}


		TEST_METHOD(TestRegister8)
		{
			// Arrange
			int result;

			//Act
			result = passwordIsGood("password123$", "password123");

			//Assert
			Assert::AreEqual(4, result);
		}


		TEST_METHOD(TestRegister9)
		{
			// Arrange
			int result;

			//Act
			result = passwordIsGood("password123$", "password123$");

			//Assert
			Assert::AreEqual(0, result);
		}


		TEST_METHOD(TestRegister10)
		{
			// Arrange
			int result;

			//Act
			result = registerUser("VRKirov19", "password123$", "password123$");

			//Assert
			Assert::AreEqual(0, result);
		}


		TEST_METHOD(TestSimulationData1)
		{
			// Arrange
			std::string result;
			std::string expected = "Spring";
			unsigned short int day = 85;
			//Act
			result = getSeason(day, "March");

			//Assert
			Assert::AreEqual(expected, result);
		}
	};
}
