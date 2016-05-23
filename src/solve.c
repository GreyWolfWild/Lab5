#include <stdio.h>
#include <math.h>
#include <locale.h>

#define ERROR -1
#define NO_ROOTS 0
#define ONE_ROOT 1
#define TWO_ROOTS 2
#define ANY_ROOTS -2
#define NO_DECISIONS -1
#define CONTINUE 0

int prov(int a, int b, int c, long double *x1, long double *x2)
{
if (a == 0)
	{
		if (b != 0)
		{
			*x1 = *x2 = -1.*c/b;
			return ONE_ROOT;
		}
		else 
			if (c == 0)
				return ANY_ROOTS;
			else
				return NO_DECISIONS;
	}
	return CONTINUE;
}

int solve(int a, int b, int c, long double d, long double *x1, long double *x2)
{
	if (d > 0)
	{
		*x1 = (-b + sqrt(d))/(2*a);
		*x2 = (-b - sqrt(d))/(2*a);
		return TWO_ROOTS;
	}
	else if (d == 0)
	{
		*x1 = *x2 = -1.*b/(2*a);
		return ONE_ROOT;
	}
	else if (d < 0)
		return NO_ROOTS;
	return ERROR;
}
