#include <math.h>

struct quadratic_equation
{
	bool haveRealResult;				//Есть ли вещественный результат решения
	double firstResult, secondResult;	//Первый и второй результаты
};

quadratic_equation solve_equation(double _a, double _b, double _c)
{
	//Возвращаемая структура с результатом вычисления
	quadratic_equation res;

	if (_a == 0 && _b != 0)	//Не квадратное уравнение вида bX + c = 0, где a = 0
	{
		res.haveRealResult = true;
		res.firstResult = (0 - _c) / _b;
		res.secondResult = res.firstResult;
		return res;
	}
	else if (_a == 0 && _b == 0)	//Уравнение вида 0*X^2 + 0*X + c = 0, не имеющее решения
	{
		res.haveRealResult = false;
		return res;
	}

	//Дискриминант b^2 - 4*a*c:
	float disc = _b * _b - 4 * _a * _c;

	//Нет вещественных результатов - дискриминант меньше нуля
	if (disc < 0) res.haveRealResult = false;
	//1 или 2 результата - дискриминант больше или равен нулю
	else
	{
		res.haveRealResult = true;
		res.firstResult = (sqrt(disc) - _b) / (2 * _a);
		res.secondResult = (0 - sqrt(disc) - _b) / (2 * _a);
	}
	return res;
}