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
			int b[6][3] = { {100000, 2000000, 3000000}, // 0
							{30, 40, 50}, // 1
							{200, 500, 700}, // 2
							{170, 180, 160}, // 3
							{1000, 2000, 3000}, // 4
							{210, 220, 170} }; // 5
			int* pb[6] = { b[0], b[1], b[2], b[3], b[4], b[5] };
			int max = 0;
			OddRows(pb, 6, 3, 0, max); 
			Assert::AreEqual(max, 170);
		}
	};
}
