#ifndef _NLIN_H_
#define _NLIN_H_

double bisec(double a, double b, double eps, double(*f1)(double, double), int *iter, double w);
double seca(double a, double b, double eps, double(*f1)(double, double), int *iter, double w);
double newt(double a, double b, double eps, double(*f1)(double, double), double(*der)(double, double), int *iter, double w);
#endif 