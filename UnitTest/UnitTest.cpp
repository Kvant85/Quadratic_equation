#include "pch.h"
#include "CppUnitTest.h"
#include "../quadratic_equation/quadratic_equation.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(NoRoots)
		{
			//���� �� ���������� ������
			//���� ���� ��������� ���������
			quadratic_equation result_expected, result_actual;
			int a = 1, b = 2, c = 3;	//��������� - ��� ����������� ������

			result_actual = solve_equation(a, b, c);
			result_expected.haveRealResult = false;

			Assert::AreEqual(result_actual.haveRealResult, result_expected.haveRealResult);


			//���� ��� ���������� ���������
			a = 0, b = 0, c = 3;	//��������� - ��� ����������� ������

			result_actual = solve_equation(a, b, c);

			Assert::AreEqual(result_actual.haveRealResult, result_expected.haveRealResult);
		}

		TEST_METHOD(OneRoot)
		{
			//���� �� ������� ������ �����
			quadratic_equation result_expected, result_actual;
			int a = 1, b = 6, c = 9;	//��������� - 1 ������, ������ "-3"

			result_actual = solve_equation(a, b, c);
			result_expected.haveRealResult = true;
			result_expected.firstResult = -3;
			result_expected.secondResult = -3;

			Assert::AreEqual(result_actual.haveRealResult, result_expected.haveRealResult);
			Assert::AreEqual(result_actual.firstResult, result_expected.firstResult);
			Assert::AreEqual(result_actual.secondResult, result_expected.secondResult);
		}

		TEST_METHOD(TwoRoots)
		{
			//���� �� ������� ���� ������
			quadratic_equation result_expected, result_actual;
			int a = 2, b = -5, c = 3;	//��������� - 2 �����: "1.5", "1"

			result_actual = solve_equation(a, b, c);
			result_expected.haveRealResult = true;
			result_expected.firstResult = 1.5;
			result_expected.secondResult = 1;

			Assert::AreEqual(result_actual.haveRealResult, result_expected.haveRealResult);
			Assert::AreEqual(result_actual.firstResult, result_expected.firstResult);
			Assert::AreEqual(result_actual.secondResult, result_expected.secondResult);
		}

		TEST_METHOD(NonQuadratic)
		{
			//���� �� ������������ ��������� (a = 0)
			quadratic_equation result_expected, result_actual;
			int a = 0, b = 2, c = 3;	//��������� - 1 ������: "-1.5"

			result_actual = solve_equation(a, b, c);
			result_expected.haveRealResult = true;
			result_expected.firstResult = -1.5;
			result_expected.secondResult = -1.5;

			Assert::AreEqual(result_actual.haveRealResult, result_expected.haveRealResult);
			Assert::AreEqual(result_actual.firstResult, result_expected.firstResult);
			Assert::AreEqual(result_actual.secondResult, result_expected.secondResult);
		}
	};
}
