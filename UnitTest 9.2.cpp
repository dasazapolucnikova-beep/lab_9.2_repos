#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 9.2/macros.h" // Якщо видасть помилку шляху, вкажіть точний шлях до macros.h

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest92
{
	TEST_CLASS(UnitTest92)
	{
	public:

		// Тест 1: перевірка базових макросів SQR, MAX, MIN
		TEST_METHOD(TestMacros)
		{
			Assert::AreEqual(25.0, (double)SQR(2 + 3), 0.0001);
			Assert::AreEqual(10.0, (double)MAX(4, 10), 0.0001);
			Assert::AreEqual(4.0, (double)MIN(4, 10), 0.0001);
		}

		// Тест 2: перевірка формули для гілки z > 3
		TEST_METHOD(TestBranchZGreaterThan3)
		{
			double x = 2.0;
			double y = 3.0;
			double z = 5.0; // z > 3

			// (x + y)^2 = (2 + 3)^2 = 25
			// (x - z)^2 = (2 - 5)^2 = 9
			// max(25, 9) = 25
			double w = MAX(SQR(x + y), SQR(x - z));

			Assert::AreEqual(25.0, w, 0.0001);
		}

		// Тест 3: перевірка формули для гілки z <= 3
		TEST_METHOD(TestBranchZLessOrEqual3)
		{
			double x = 1.0;
			double y = 2.0;
			double z = 2.0; // z <= 3

			// x*y + y*z = 1*2 + 2*2 = 6
			// (z*x + y*z)^2 = (2*1 + 2*2)^2 = 36
			// min(6, 36) = 6
			double w = MIN(x * y + y * z, SQR(z * x + y * z));

			Assert::AreEqual(6.0, w, 0.0001);
		}
	};
}