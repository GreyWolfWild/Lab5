#include <ctest.h>
#include "discriminant.h"
#include "solve.h"

CTEST(test_suite, MINUS_DISCRIMINANT)
{
	const int a = 8;
	const int b = 1;
	const int c = 2;

	double test = discriminant(a, b, c);

	const double expected_discriminant = -63;

	ASSERT_DBL_NEAR(expected_discriminant, test);
}

CTEST(test_suite, ZERO_DISCRIMINANT)
{
	const int a = 12;
	const int b = 12;
	const int c = 3;

	double test = discriminant(a, b, c);

	const double expected_discriminant = 0;

	ASSERT_DBL_NEAR(expected_discriminant, test);
}

CTEST(test_suite, PLUS_DISCRIMINANT)
{
	const double a = 1;
	const double b = 5;
	const double c = 1;

	double test = discriminant(a, b, c);

	const double expected_discriminant = 21;

	ASSERT_DBL_NEAR(expected_discriminant, test);
}

CTEST(test_suite, NO_ROOTS)
{
	const int a = 9;
	const int b = 1;
	const int c = 4;
	const long double d = -143;
	const long double x1, x2;

	double test = solve(a, b, c, d, &x1, &x2);

	const double expected_root_quantity = 0;

	ASSERT_DBL_NEAR(expected_root_quantity, test);
}

CTEST(test_suite, ONE_ROOTS)
{
	const int a = 4;
	const int b = 4;
	const int c = 1;
	const long double d = 0;	
	const long double x1, x2;

	double test = solve(a, b, c, d, &x1, &x2);
	const double expected_x1 = -0.500000;
	const double expected_x2 = -0.500000;
	const double expected_root_quantity = 1;

	ASSERT_DBL_NEAR(expected_root_quantity, test);
	ASSERT_DBL_NEAR(expected_x1, x1);
	ASSERT_DBL_NEAR(expected_x2, x2);
}

CTEST(test_suite, TWO_ROOTS)
{
	const int a = 2;
	const int b = 6;
	const int c = 4;
	const long double d = 4;
	const long double x1, x2;

	double test = solve(a, b, c, d, &x1, &x2);
	const double expected_x1 = -1.000000;
	const double expected_x2 = -2.000000;

	const double expected_root_quantity = 2;

	ASSERT_DBL_NEAR(expected_root_quantity, test);
	ASSERT_DBL_NEAR(expected_x1, x1);
	ASSERT_DBL_NEAR(expected_x2, x2);
}

CTEST(test_suite, DEGENERATE_EQUATION)
{
	const int a = 0;
	const int b = 6;
	const int c = 4;
	const long double x1, x2;

	double test = prov(a, b, c, &x1, &x2);
	const double expected_value = 1;

	ASSERT_DBL_NEAR(expected_value, test);
}

CTEST(test_suite, ZERO_COEFFICIENTS)
{
	const int a = 0;
	const int b = 0;
	const int c = 0;
	const long double x1, x2;

	double test = prov(a, b, c, &x1, &x2);
	const double expected_value = -2;

	ASSERT_DBL_NEAR(expected_value, test);
}

CTEST(test_suite, NO_DECISIONS)
{
	const int a = 0;
	const int b = 0;
	const int c = 9;
	const long double x1, x2;

	double test = prov(a, b, c, &x1, &x2);
	const double expected_value = -1;

	ASSERT_DBL_NEAR(expected_value, test);
}
