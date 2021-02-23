#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7_2_recur/lab_7_2_recur.cpp"

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
			int row = 1;
			int max = 0;
			MaxMinOddRows(pb, 4, 3, 0, max, row);
			Assert::AreEqual(max, 16);
		}
	};
}
