#include "pch.h"
#include "CppUnitTest.h"
#include "D:\лаба 4\ConsoleApplication1\ConsoleApplication1\ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Test1)
	{
	public:
		TEST_METHOD(TestMethod1_nValidation)
		{
			int n = 1;

			try
			{
				nValidation(0, n);
				Assert::Fail(); // Ошибка, если исключение не было выброшено
			}
			catch (const std::runtime_error&)
			{
				Assert::IsTrue(true); // Тест пройден, если исключение было выброшено
			}
			catch (...) {
				Assert::Fail(L"Unexpected exception type");
			}
		}

		TEST_METHOD(TestMethod2_dataValidation)
		{
			double a = 6.0;
			double b = 4.0;
			double h = 1.0;
			int n = 3;

			try
			{
				dataValidation(a, b, h, n);
				Assert::Fail(); // Ошибка, если исключение не было выброшено
			}
			catch (const std::runtime_error&)
			{
				Assert::IsTrue(true); // Тест пройден, если исключение было выброшено
			}
			catch (...) {
				Assert::Fail(L"Unexpected exception type");
			}
		}

		TEST_METHOD(TestMethod3_calculateY_n1a6b2h1)
		{
			double x = -3.0;
			int n = 3;

			// Рассчитаем значение expected_y вручную, используя логику функции calculateY
			double expected_y = 1.0;
			for (int j = 2; j <= n - 2; j++) {
				expected_y *= (j * j + x);
			}

			double y = calculateY(x, n);

			Assert::AreEqual(expected_y, y, 0.0001, L"Calculated y does not match expected value");
		}
	};
}

