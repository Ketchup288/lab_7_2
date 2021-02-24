#include "pch.h"
#include "CppUnitTest.h"
#include "../7_2_iter/7_2_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int b[5][3] = { {10, 11, 12}, {30, 40, 50}, {16, 17, 18}, {60, 70, 80}, {12, 11, 14} };
			int* pb[5] = { b[0], b[1], b[2], b[3], b[4] };
			int max = MaxMinOdd(pb, 5, 3); // В функції початок рахунку рядків матриці починається з 1 
			Assert::AreEqual(max, 16);
		}
	};
}
