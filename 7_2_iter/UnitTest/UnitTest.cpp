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
			int z[5][3] = { {10, 11, 12}, // 0 
							{30, 40, 50}, // 1
							{200, 500, 700}, // 2
							{60, 70, 80}, // 3
							{1000, 2000, 3000} }; // 4
			int* pz[5] = { z[0], z[1], z[2], z[3], z[4] };
			int max = MaxMinOdd(pz, 5, 3); 
			Assert::AreEqual(max, 60);
		}
	};
}
