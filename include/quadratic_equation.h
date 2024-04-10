#include <math.h>

struct quadratic_equation
{
	bool haveRealResult;				//���� �� ������������ ��������� �������
	double firstResult, secondResult;	//������ � ������ ����������
};

quadratic_equation solve_equation(double _a, double _b, double _c)
{
	//������������ ��������� � ����������� ����������
	quadratic_equation res;

	if (_a == 0 && _b != 0)	//�� ���������� ��������� ���� bX + c = 0, ��� a = 0
	{
		res.haveRealResult = true;
		res.firstResult = (0 - _c) / _b;
		res.secondResult = res.firstResult;
		return res;
	}
	else if (_a == 0 && _b == 0)	//��������� ���� 0*X^2 + 0*X + c = 0, �� ������� �������
	{
		res.haveRealResult = false;
		return res;
	}

	//������������ b^2 - 4*a*c:
	float disc = _b * _b - 4 * _a * _c;

	//��� ������������ ����������� - ������������ ������ ����
	if (disc < 0) res.haveRealResult = false;
	//1 ��� 2 ���������� - ������������ ������ ��� ����� ����
	else
	{
		res.haveRealResult = true;
		res.firstResult = (sqrt(disc) - _b) / (2 * _a);
		res.secondResult = (0 - sqrt(disc) - _b) / (2 * _a);
	}
	return res;
}