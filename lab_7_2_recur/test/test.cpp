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
			int b[5][3] = { {10, 11, 12}, // 0
							{30, 40, 50}, // 1
							{200, 500, 700}, // 2
							{60, 70, 80}, // 3
							{1000, 2000, 3000} }; // 4
			int* pb[5] = { b[0], b[1], b[2], b[3], b[4] };
			int row = 1;
			int max = 0;
			OddRows(pb, 5, 3, 0, max); 
			Assert::AreEqual(max, 60);
		}
	};
}
