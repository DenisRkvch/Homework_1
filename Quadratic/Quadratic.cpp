#include "Quadratic.h"
#include <cmath>
#include <limits>
#include <locale>

// здесь a, b, c - коэффициенты квадратного уравнения, функция возвращает список корней квадратного уравнения.
double* solve(double a, double b, double c)
{
	double D, X1, X2;
	 
	// проверка на недопустимые значения NAN INF
	if (std::isnan(a) || std::isnan(b) || std::isnan(c))
	{
		throw std::runtime_error("Invalid params: NAN!");
		return nullptr;
	}
	if (std::isinf(a) || std::isinf(b) || std::isinf(c))
	{
		throw std::runtime_error("Invalid params: INF!");
		return nullptr;
	}
	
	// первый параметр не может быть равен 0
	if (std::abs(a) < std::numeric_limits<double>::epsilon())
	{
		throw std::runtime_error("Invalid first param!");
		return nullptr;
	}

	D = b * b - 4.0 * a * c;

	if (D < 0)
	{
		// корней нет
		return nullptr;
	}
	else if (std::abs(D) < std::numeric_limits<double>::epsilon())
	{
		// один корень
		X1 = X2 = (-b) / (2 * a);
	}
	else 
	{
		// два корня
		X1 = (-b + std::sqrt(D)) / (2 * a);
		X2 = (-b - std::sqrt(D)) / (2 * a);
	}
	return new double[2] {X1,X2};
}
