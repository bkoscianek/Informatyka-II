#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

const double pi = 4.0*atan(1.0);

double trapez(double a, double b, int n, double(*f)(double));
double simpson(double a, double b, int n, double(*f)(double));
double analit(double a, double b, int n, double(*f)(double));

double fun(double x)
{
	return 1.0 / (1 + x*x);
}

int main(void)
{
	double a, b;
	int n;

	a = 0;
	b = 1;
	
	FILE *wyn;
	wyn = fopen("wyniki.txt", "w");

	//fprintf(wyn, "N \t trapez \t simpson\n");

	for (int i = 1; i <= 10; i++)
	{
		n = i * 10;
		double tra = trapez(a, b, n, fun);
		double sim = simpson(a, b, n, fun);
		double an = analit(a, b, n, fun);

		double err1 = fabs(tra - an);
		double err2 = fabs(sim - an);

		fprintf(wyn, "%d\t%lf\t%lf\t%e\t%e\n", n, tra, sim, err1, err2);

	}

	getchar();
	getchar();
}

double trapez(double a, double b, int n, double(*f)(double))
{
	double k = (b - a) / (n - 1);

	double sum = 0;
	double l = a;

	for (int i = 0; i < n-1; i++)
	{
		sum += k*(f(l) + f(l + k)) / 2.0;
		l += k;
	}

	return sum;
}

double simpson(double a, double b, int n, double(*f)(double))
{
	double k = (b - a) /n;

	double sum1 = 0;
	double sum2 = 0;

	double x1;
	double x2;

	for (int i = 1; i <= n; i++)
	{
		x1 = a + i*k;
		sum1 += f(x1 - k / 2.0);
	}

	for (int i = 1; i < n; i++)
	{
		x2 = a + i*k;
		sum2 += f(x2);
	}

	double sum = (k / 6.0)*(f(a) + f(b) + 4.0 * sum1 + 2.0 * sum2);

	return sum;
}

double analit(double a, double b, int n, double(*f)(double))
{
	return atan(b) - atan(a);
}