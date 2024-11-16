#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Максим\Desktop\ОІПЗ Лаб\L2\L2\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestCalculateSum)
        {
            // Тест для функції calculateSum з x < 0
            double x = -1;
            int n = 3;
            double expected = pow(1 + x, 2) + pow(2 + x, 2) + pow(3 + x, 2);
            double result = calculateSum(n, x);
            Assert::AreEqual(expected, result, 1e-5, L"calculateSum test failed");
        }

        TEST_METHOD(TestCalculateProduct)
        {
            // Тест для функції calculateProduct з x >= 0
            double x = 1;
            int n = 3;
            double expected = 0;
            for (int i = 0; i < n; i++) {
                double product = 1;
                for (int j = 1; j <= n; j++) {
                    product *= (x + i) / (i + j);
                }
                expected += product;
            }
            double result = calculateProduct(n, x);
            Assert::AreEqual(expected, result, 1e-5, L"calculateProduct test failed");
        }

        TEST_METHOD(TestInvalidN)
        {
            // Тест на некоректне значення n
            double x = 1;
            int n = 0;  // Некоректне значення n
            try {
                double result = calculateProduct(n, x);  // Функція повинна обробити це без аварійного завершення
                Assert::Fail(L"Expected exception for invalid n");
            }
            catch (...) {
                // Якщо зловили виключення, тест пройдено
            }
        }
    };
}