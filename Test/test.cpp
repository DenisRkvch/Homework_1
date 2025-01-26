#include <gtest/gtest.h>
#include "../Quadratic/Quadratic.h"
#include <limits>
#include <locale>

// �������� ����, ������� ���������, ��� ��� ��������� x^2+1 = 0 ������ ��� (������������ ������ ������)
TEST(Test1, no_roots)
{
	EXPECT_TRUE(solve(1.0, 0.0, 1.0) == nullptr);
}

// �������� ����, ������� ���������, ��� ��� ��������� x^2-1 = 0 ���� ��� ����� ��������� 1 (x1=1, x2=-1)
TEST(Test1, two_roots)
{
	constexpr double epsilon = std::numeric_limits<double>::epsilon();

	double* res_ptr = solve(1.0, 0.0, -1.0);
	
	EXPECT_TRUE((std::abs(res_ptr[0] - 1.0) < epsilon && std::abs(res_ptr[1] - (-1.0)) < epsilon) ||
			    (std::abs(res_ptr[1] - 1.0) < epsilon && std::abs(res_ptr[0] - (-1.0)) < epsilon));

}

// �������� ����, ������� ���������, ��� ��� ��������� x ^ 2 + 2x + 1 = 0 ���� ���� ������ ��������� 2 (x1 = x2 = -1).
TEST(Test1, one_root)
{
	const double epsilon = std::numeric_limits<double>::epsilon();

	double* res_ptr = solve(1.0, 2.0, 1.0);

	EXPECT_TRUE((std::abs(res_ptr[0] - (-1.0)) < epsilon) && 
				(std::abs(res_ptr[1] - (-1.0)) < epsilon));

}

/* �������� ����, ������� ���������, ��� ����������� a �� ����� ���� ����� 0. � ���� ������ solve ����������� ����������.
����������. ������, ��� a ����� ��� double � ���������� � 0 ����� == ������. */
TEST(Test1, valid_format)
{
	EXPECT_THROW(solve(0.0, 2.0, 1.0), std::runtime_error);
}

/* � ������ ����, ��� ������������ ���� ������ ���������� � 0 ����� ���� ���������,
��������� ����� ������������ ����������� ��������� ��� ������ ������ ����� ��������� ���, 
����� ������������ ��� �������� �� ����, �� ������ ��������� �������. */
TEST(Test1, zero_D)
{
	double* res_ptr = solve(-1.0/4.0, 0.0, 0.5 * std::numeric_limits<double>::epsilon()); // D = 0.5 epsilon

	EXPECT_NEAR(res_ptr[0], res_ptr[1], std::numeric_limits<double>::epsilon()); // ������� ����� val1 � val2 �� ��������� ����������� abs_error
}

/* ���������� ����� ��� �������� ����� ��������� ����� ���� double,
����� �������� � �������� ���� � �� �������������� �� ��� ������������. solve ������ ����������� ����������. */
TEST(Test1, NAN_INF)
{
	EXPECT_THROW(solve(5.0, std::numeric_limits<double>::quiet_NaN(), 1.0), std::runtime_error);
	EXPECT_THROW(solve(5.0, std::numeric_limits<double>::infinity(), 1.0), std::runtime_error);
}

// ����������� ������ 
TEST(Test1, my_addition_test)
{
	const double epsilon = std::numeric_limits<double>::epsilon();

	double* res_ptr = solve(3.0, 7.0, -6.0);

	EXPECT_TRUE((std::abs(res_ptr[0] - 2.0/3.0) < epsilon && std::abs(res_ptr[1] - (-3.0)) < epsilon) ||
		(std::abs(res_ptr[1] - (-3.0)) < epsilon && std::abs(res_ptr[0] - 2.0/3.0) < epsilon));

}