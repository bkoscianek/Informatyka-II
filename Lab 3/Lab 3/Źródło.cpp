#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<math.h>
#include<stdlib.h>
#include"NLIN.h"

double fun(double x, double w)
{
	return cos(x) - w*x;
}

double der(double x, double w)
{
	return -w - sin(x);
}

int main(void)
{
	double a, b, eps;
	//scanf("%lf %lf %lf", &a, &b, &eps);
	scanf("%lf %lf", &a, &b);

	int *iter;
	iter = (int*)malloc(sizeof(int));

	FILE *wynik;
	wynik = fopen("wynik4.txt", "w");

	eps = pow(10, -6);

	fprintf(wynik, "w	 \t wynik \t l. iteracji\n");
	for (double w = 0.5; w <=15; w+=0.1)
	{
		double wyn = seca(a, b, eps, fun, iter, w);
		fprintf(wynik, "%lf\t%lf\t%d\n", w, wyn, *iter);
	}

	getchar();
	getchar();
}

