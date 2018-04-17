#define _CRT_SECURE_NO_WARNINGS

#include"NLIN.h"
#include<math.h>
#include<stdlib.h>

double bisec(double a, double b, double eps, double(*f1)(double, double), int *iter, double w)
{
	double m = (a + b) / 2.0;
	int i = 0;
	while (f1(a, w)*f1(b, w) < 0 && fabs(f1(m, w)) > eps)
	{
		i++;
		m = (a + b) / 2.0;

		if (f1(m, w)*f1(a, w) < 0)
			b = m;
		else if (f1(m, w)*f1(b, w) < 0)
			a = m;
	}

	*iter = i;

	return m;
}

double seca(double a, double b, double eps, double(*f1)(double, double), int *iter, double w)
{
	int i = 1;

	double x1, x2, x3;
	x1 = a;
	x2 = b;
	x3 = x2 - f1(x2, w)*(x2 - x1) / (f1(x2, w) - f1(x1, w));

	while (i<10000 && fabs(f1(x3, w))>eps)
	{
		i++;
		x3 = x2 - f1(x2, w)*(x2 - x1) / (f1(x2, w) - f1(x1, w));
		x1 = x2;
		x2 = x3;
	}

	*iter = i;

	return x3;
}

double newt(double a, double b, double eps, double(*f1)(double, double), double(*der)(double, double), int *iter, double w)
{
	int i = 1;

	double x1;
	x1 = a;
	x1 = x1 - f1(x1, w) / der(x1, w);

	while (i<10000 && fabs(f1(x1, w))>eps)
	{
		i++;
		x1 = x1 - f1(x1, w) / der(x1, w);
	}

	*iter = i;

	return x1;
}