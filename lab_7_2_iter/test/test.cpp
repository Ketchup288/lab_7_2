#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7_2_iter/lab_7_2_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int b[4][3] = { {10, 11, 12}, {30, 40, 50}, {16, 17, 18}, {60, 70, 80} };
			int* pb[4] = { b[0], b[1], b[2], b[3] };
			int x = MaxMinOdd(pb, 4, 3);
			Assert::AreEqual(x, 16);
		}
	};
}
