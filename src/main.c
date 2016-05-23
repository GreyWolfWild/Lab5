#include <stdio.h>
#include <math.h>
#include <locale.h>
#include "discriminant.h"
#include "solve.h"

#define SECCESS 0
#define ERROR -1
#define NO_ROOTS 0
#define ONE_ROOT 1
#define TWO_ROOTS 2
#define ANY_ROOTS -2
#define NO_DECISIONS -1
#define CONTINUE 0

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c, flag;
	long double x1, x2;
	scanf("%d %d %d", &a, &b, &c);
	long double d = discriminant(a, b, c);
	flag = prov(a, b, c, &x1, &x2);
	if (flag == ONE_ROOT)
	{
		printf("Уравнение вырождается в линейное:\nx = %Lf\n", x1);
		return SECCESS;
	}
	if (flag == ANY_ROOTS)
	{	
		printf("Все коэффициенты равны нулю:\nx - любое число\n");
		return SECCESS;
	}
	if (flag == NO_DECISIONS)
	{	
		printf("Нет решения\n");		
		return SECCESS;
	}		 
	flag = solve(a, b, c, d, &x1, &x2);
	if (flag == ERROR)
		printf("Произошла непредвиденная ошибка\n");
	if (flag == TWO_ROOTS)
			printf("D > 0; 2 корня:\nx1 = %Lf\nx2 = %Lf\n", x1, x2);
	if (flag == ONE_ROOT)
			printf("D = 0; 1 корень:\nx = %Lf\n", x1);
	if (flag == NO_ROOTS)
			printf("D < 0; нет корней.\n");	
	return SECCESS;
}
