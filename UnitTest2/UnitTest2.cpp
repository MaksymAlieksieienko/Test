#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Максим\Desktop\ОІПЗ Лаб\L2\L2\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calculate_Tests)
	{
	public:

		TEST_METHOD(calculate_get2and2_3halfreturned)
		{
			double x = 2;
			int n = 2;
			double expected = 3.5;

			double actual = calculateProduct(n, x);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(calculate_getminus2and2_1returned)
		{
			double x = -2;
			int n = 2;
			double expected = 1;

			double actual = calculateSum(n, x);

			Assert::AreEqual(expected, actual);
		};
	};
	TEST_CLASS(checkValidParams_Tests)
	{
	public:

		TEST_METHOD(checkValidParams_get10_exceptionNotThrown)
		{
			int n = 10;

			try
			{
				checkValidParams(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(checkValidParams_getminus1_exceptionThrown)
		{
			int n = -1;
			try {
				checkValidParams(n);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		};
	};
}