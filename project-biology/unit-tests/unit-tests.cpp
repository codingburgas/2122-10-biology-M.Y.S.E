#include "pch.h"
#include "CppUnitTest.h"
#include "../pb.bll/register.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
	TEST_CLASS(unittests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Arrange
			bool result;

			//Act
			result = passwordHasNumbers("password 123");

			//Assert
			Assert::AreEqual(true, result);
		}

	};
}
