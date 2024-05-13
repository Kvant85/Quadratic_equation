#include <math.h>

struct quadratic_equation
{
	bool haveRealResult;				//���� �� ������������ ��������� �������
	long double firstResult, secondResult;	//������ � ������ ����������
};

quadratic_equation solve_equation(double _a, double _b, double _c)
{
	//������������ ��������� � ����������� ����������
	quadratic_equation result;

	if (_a == 0 && _b != 0)	//�� ���������� ��������� ���� bX + c = 0, ��� a = 0
	{
		result.haveRealResult = true;
		result.firstResult = (0 - _c) / _b;
		result.secondResult = result.firstResult;
		return result;
	}
	else if (_a == 0 && _b == 0)	//��������� ���� 0*X^2 + 0*X + c = 0, �� ������� �������
	{
		result.haveRealResult = false;
		return result;
	}

	//������������ b^2 - 4*a*c:
	long double disc = _b * _b - 4 * _a * _c;

	//��� ������������ ����������� - ������������ ������ ����
	if (disc < 0) result.haveRealResult = false;
	//1 ��� 2 ���������� - ������������ ������ ��� ����� ����
	else
	{
		result.haveRealResult = true;
		result.firstResult = (sqrt(disc) - _b) / (2 * _a);
		result.secondResult = (0 - sqrt(disc) - _b) / (2 * _a);
	}
	return result;
}