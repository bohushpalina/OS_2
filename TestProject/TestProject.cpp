#include "pch.h"
#include "CppUnitTest.h"
#include "../Project2/threads.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{
	TEST_CLASS(TestProject)
	{

	public:

		TEST_METHOD(FindMinMax_NormalArray)
		{
			static int data[] = { 7, 2, 9, 4, 6 };
			arr = data;
			arr_size = 5;

			min_max(nullptr);

			Assert::AreEqual(2, min_val);
			Assert::AreEqual(9, max_val);
		}

		TEST_METHOD(FindMinMax_OneElement)
		{
			static int data[] = { 42 };
			arr = data;
			arr_size = 1;

			min_max(nullptr);

			Assert::AreEqual(42, min_val);
			Assert::AreEqual(42, max_val);
		}

		TEST_METHOD(FindMinMax_AllEqual)
		{
			static int data[] = { 5,5,5,5 };
			arr = data;
			arr_size = 4;

			min_max(nullptr);

			Assert::AreEqual(5, min_val);
			Assert::AreEqual(5, max_val);
		}

		TEST_METHOD(FindMinMax_NegativeNumbers)
		{
			static int data[] = { -10, -3, -25, -7 };
			arr = data;
			arr_size = 4;

			min_max(nullptr);

			Assert::AreEqual(-25, min_val);
			Assert::AreEqual(-3, max_val);
		}

		TEST_METHOD(FindAverage_NormalArray)
		{
			static int data[] = { 2,4,6,8 };
			arr = data;
			arr_size = 4;

			average(nullptr);

			Assert::AreEqual(5.0, avg_val, 0.0001);
		}

		TEST_METHOD(FindAverage_NegativeNumbers)
		{
			static int data[] = { -5,-2,-10,-3 };
			arr = data;
			arr_size = 4;

			average(nullptr);

			Assert::AreEqual(-5.0, avg_val, 0.0001);
		}

		TEST_METHOD(FindAverage_WithZeros)
		{
			static int data[] = { 0,0,0,0 };
			arr = data;
			arr_size = 4;

			average(nullptr);

			Assert::AreEqual(0.0, avg_val, 0.0001);
		}

		TEST_METHOD(ReplaceMinMax_WithAverage)
		{
			static int data[] = { 7,2,9,4,6 };
			arr = data;
			arr_size = 5;

			min_max(nullptr);
			average(nullptr);

			for (int i = 0; i < arr_size; i++)
			{
				if (arr[i] == min_val || arr[i] == max_val)
					arr[i] = (int)avg_val;
			}

			Assert::AreEqual(7, arr[0]);
			Assert::AreEqual(5, arr[1]); // min replaced
			Assert::AreEqual(5, arr[2]); // max replaced
			Assert::AreEqual(4, arr[3]);
			Assert::AreEqual(6, arr[4]);
		}

		TEST_METHOD(ReplaceMinMax_AllEqual)
		{
			static int data[] = { 3,3,3 };
			arr = data;
			arr_size = 3;

			min_max(nullptr);
			average(nullptr);

			for (int i = 0; i < arr_size; i++)
			{
				if (arr[i] == min_val || arr[i] == max_val)
					arr[i] = (int)avg_val;
			}

			Assert::AreEqual(3, arr[0]);
			Assert::AreEqual(3, arr[1]);
			Assert::AreEqual(3, arr[2]);
		}

	};
}