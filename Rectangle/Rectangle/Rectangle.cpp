#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Rectangle
{
    extern "C" int getPerimeter(int* length, int* width);
    extern "C" int getArea(int* length, int* width);
    extern "C" void setLength(int input, int* length);
    extern "C" void setWidth(int input, int* width);

    // Function implementations
    extern "C" int getPerimeter(int* length, int* width) {
        return 2 * (*length + *width);
    }

    extern "C" int getArea(int* length, int* width) {
        return (*length) * (*width);
    }

    extern "C" void setLength(int input, int* length) {
        *length = input;
    }

    extern "C" void setWidth(int input, int* width) {
        *width = input;
    }

    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    namespace RectangleAppTests
    {
        // Test class for Perimeter
        TEST_CLASS(TestPerimeter)
        {
        public:
            TEST_METHOD(TestGetPerimeter)
            {
                int length = 10;
                int width = 5;
                int expectedPerimeter = 2 * (length + width);

                Assert::AreEqual(expectedPerimeter, getPerimeter(&length, &width));
            }
        };

        // Test class for Area
        TEST_CLASS(TestArea)
        {
        public:
            TEST_METHOD(TestGetArea)
            {
                int length = 10;
                int width = 5;
                int expectedArea = length * width;

                Assert::AreEqual(expectedArea, getArea(&length, &width));
            }
        };

        // Test class for setLength
        TEST_CLASS(TestSetLength)
        {
        public:
            TEST_METHOD(TestSetLength_ValidInput)
            {
                int input = 15;
                int length = 0;
                setLength(input, &length);
                Assert::AreEqual(input, length);
            }

            TEST_METHOD(TestSetLength_MinValue)
            {
                int input = 1;
                int length = 0;
                setLength(input, &length);
                Assert::AreEqual(input, length);
            }

            TEST_METHOD(TestSetLength_MaxValue)
            {
                int input = 99;
                int length = 0;
                setLength(input, &length);
                Assert::AreEqual(input, length);
            }
        };

        // Test class for setWidth
        TEST_CLASS(TestSetWidth)
        {
        public:
            TEST_METHOD(TestSetWidth_ValidInput)
            {
                int input = 20;
                int width = 0;
                setWidth(input, &width);
                Assert::AreEqual(input, width);
            }

            TEST_METHOD(TestSetWidth_MinValue)
            {
                int input = 1;
                int width = 0;
                setWidth(input, &width);
                Assert::AreEqual(input, width);
            }

            TEST_METHOD(TestSetWidth_MaxValue)
            {
                int input = 99;
                int width = 0;
                setWidth(input, &width);
                Assert::AreEqual(input, width);
            }
        };
    }
}
