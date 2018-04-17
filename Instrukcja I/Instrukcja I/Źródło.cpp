#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"inter.h"
#include"winbgi2.h"

void exper(double *x, double *y, int n, double a, double b);

const double pi = 4.0*atan(1.0);

int main(void)
{
	FILE *wyn;		//zapis danych do pliku jest wymagany dalej
	wyn = fopen("lagrange.txt", "w");

	FILE *lag;
	lag = fopen("lag.txt", "w");

	double *x;		//wskazniki na tablice wspolrzednych 
	double *y;
	int n = 100;		//liczba punktow interpolacji	WAZNE	interpolacja nie dziala dla duzej liczby wezlow jesli uzywa sie wezlow Czebyszewa!!
	double a, b;	//zakres badania funkcji

	a = -2;			//deklaruje zakres
	b = 2;

	x = (double*)malloc(n * sizeof(double));		//zarezerwowanie pamieci na tablice wspolrzednych punktow interpolacji
	y = (double*)malloc(n * sizeof(double));

	exper(x, y, n, a, b);		//wyznaczenie punktow eksperymentalnych

	graphics(800, 800);scale(a,-1 , b, 3);		//okno grafiki w odpowiedniej skali, z przedzialka

	for (int i = 0; i <n; i++)
	{
		//printf("%lf\t%lf\n", x[i], y[i]);		//dla pewnosci wypisuje wspolrzedne wszystkich punktow
		fprintf(wyn, "%lf\t%lf\n", x[i], y[i]);		//dodatkowo do pliku
	
		point(x[i], y[i]);		//mozna tez uzyc circle() jesli chce sie wieksze punkty na wykresie
	}

	double h2 = (b - a) / (4 *n + 1) ;

	for (int i = 0; i < 4 *n+1; i++)
	{
		printf("Wartosc wielomianu Lagrange'a dla x=%lf to %lf \n", a + i*h2, lagrange(x, y, n, a + i*h2));
		point(a+i*h2, lagrange(x, y, n, a+i*h2));
		fprintf(lag, "%lf \t %lf \n", a + i*h2, lagrange(x, y, n, a + i*h2));
	}

	getchar();
	getchar();
}

void exper(double *x, double *y, int n, double a, double b)
{
	double h = (b - a) / (n+1);
	double nn = n;
	for (int i = 0; i < n; i++)
	{
		//x[i] = a + ((i+1)*h);
		double j = i;
		double k = (double)(j / (nn-1.0));
		x[i] = (cos(pi * k) * (-(b - a) / 2.0)) +((a + b) / 2.0);
		printf("%lf \n", x[i]);
		//y[i] = exp(-pow(x[i], 2));	//pierwsza funkcja podana w zadnaiu
		y[i] = fabs(x[i]);
	}
}