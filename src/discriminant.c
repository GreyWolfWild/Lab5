#include <stdio.h>
#include <math.h>

double discriminant(int a, int b, int c)
{
	long double d;
	d = b * b - 4 * a * c;
	return d;
}
