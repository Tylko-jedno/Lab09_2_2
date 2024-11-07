#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab09_2_2/Lab09_2_2.cpp" // замініть на шлях до вашого файлу з функціями
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Тест для функції countRepeats
        TEST_METHOD(TestCountRepeats)
        {
            std::stringstream buffer;
            std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());

            // Викликаємо функцію
            countRepeats(8, 1, 3, 4, 4, 3, 2, 1, 4);

            // Очікуваний результат
            std::string expected =
                "Number 1 repeats 2 times\n"
                "Number 2 repeats 1 times\n"
                "Number 3 repeats 2 times\n"
                "Number 4 repeats 3 times\n";

            // Перевірка результату
            Assert::AreEqual(expected, buffer.str());

            std::cout.rdbuf(oldCoutStreamBuf); // Повертаємо стандартний потік
        }

        // Тест для функції findSymbolPositions
        TEST_METHOD(TestFindSymbolPositions)
        {
            std::stringstream buffer;
            std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());

            // Викликаємо функцію
            findSymbolPositions(7, 65, 'A', 'B', 'C', 'A', 'D', 'A');

            // Очікуваний результат
            std::string expected =
                "Positions of character with ASCII code 65:\n"
                "Position 0, Character: 'A'\n"
                "Position 3, Character: 'A'\n"
                "Position 5, Character: 'A'\n";

            // Перевірка результату
            Assert::AreEqual(expected, buffer.str());

            std::cout.rdbuf(oldCoutStreamBuf); // Повертаємо стандартний потік
        }
    };
}
