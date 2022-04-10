#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Solomia_\source\repos\PR2-4\PR2-4\Matrix.cpp"
#include "C:\Users\Solomia_\source\repos\PR2-4\PR2-4\Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest24
{
	TEST_CLASS(UnitTest24)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix C(2);
			C[0][0] = 5; C[0][1] = 4;
			C[1][0] = 8; C[1][1] = 4;

			Assert::AreEqual(C.NormMatrix(), 11.0);
		}
	};
}
