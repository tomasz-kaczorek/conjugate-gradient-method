#include "parameters.h"

#include <math.h>
#include <stdlib.h>

/* Quadratic function */
double f1(double const * x)
{
	double result = 0.0;
	for(size_t i = 3; i <= n; ++i)
	{
		result += 100.0 * (pow(x[i - 1], 2.0) + pow(x[i - 2], 2.0)) + pow(x[i - 3], 2.0);
	}
	return result;
}

double * x1()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i) x[i] = 3.0;
	return x;
}

/* Woods function */
double f2(double const * x)
{
	double result = 0.0;
	for(size_t i = 1; i <= n / 4; ++i)
	{
		result += 100.0 * pow(x[4 * i - 3] - pow(x[4 * i - 4], 2.0), 2.0) + pow(1 - x[4 * i - 4], 2.0) + 90.0 * pow(x[4 * i - 1] - pow(x[4 * i - 2], 2.0), 2.0) + pow(1 - x[4 * i - 2], 2.0) + 10.0 * pow(x[4 * i - 3] + x[4 * i -1] - 2.0, 2.0) + 0.1 * pow(x[4 * i - 3] - x[4 * i -1], 2.0);
	}
	return result;
}

double * x2()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; i += 2)
	{
		x[i] = -3.0;
		x[i + 1] = -1.0;
	}
	return x;
}

/* Powell singular function */
double f3(double const * x)
{
	double result = 0.0;
	for(size_t i = 1; i <= n / 4; ++i)
	{
		result += pow(x[4 * i - 4] + 10.0 * x[4 * i - 3], 2.0) + 5.0 * pow(x[4 * i - 2] - x[4 * i - 1], 2.0) + pow(x[4 * i - 3] - 2.0 * x[4 * i - 2], 4) + 10.0 * pow(x[4 * i - 4] - x[4 * i - 1], 4.0); 
	}
	return result;
}

double * x3()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; i += 4)
	{
		x[i] = 3.0;
		x[i + 1] = -1.0;
		x[i + 2] = 0.0;
		x[i + 3] = 1.0;
	}
	return x;
}

/* Extended Rosenbrock function */
double f4(double const * x)
{
	double result = 0.0;
	for(size_t i = 1; i <= n / 2; ++i)
	{
		result += 100.0 * pow(x[2 * i - 1] - pow(x[2 * i - 2], 2.0), 2.0) + pow(1.0 - x[2 * i - 2], 2.0);
	}
	return result;
}

double * x4()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; i += 2)
	{
		x[i] = -1.2;
		x[i + 1] = 1.0;
	}
	return x;
}

/* Generalized Rosenbrock function */
double f5(double const * x)
{
	double result = 1.0;
	for(size_t i = 2; i <= n; ++i)
	{
		result += 100.0 * pow(x[i - 1] - pow(x[i - 2], 2.0), 2.0) + pow(1.0 - x[i - 2], 2.0);
	}
	return result;
}

double * x5()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i)
	{
		x[i] = 1.0 / (n + 1.0);
	}
	return x;
}

/* Shanno's function */
double f6(double const * x)
{
	double result = pow(2.0 * x[0] - 1.0, 2.0);
	for(size_t i = 2; i <= n; ++i)
	{
		result += i * pow(2.0 * x[i - 2] - x[i - 1], 2.0);
	}
	return result;
}

double * x6()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i) x[i] = -1.0;
	return x;
}

/* Engval function */
double f7(double const * x)
{
	double result = 0.0;
	for(size_t i = 2; i <= n; ++i)
	{
		result += pow(pow(x[i - 2], 2.0) + pow(x[i - 1], 2.0), 2.0) - 4.0 * x[i - 2] + 3.0;
	}
	return result;
}

double * x7()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i) x[i] = 2.0;
	return x;
}

/* Cragg and Levy function */
double f8(double const * x)
{
	double result = 0.0;
	for(size_t i = 2; i <= n / 2; ++i)
	{
		result += pow(x[2 * i - 3] - exp(x[2 * i - 4]), 4.0) + 100.0 * pow(x[2 * i - 3] - x[2 * i - 2], 6.0) + pow(tan(x[2 * i - 2] - x[2 * i - 1]), 4.0) + pow(x[2 * i - 4], 8.0) + pow(x[2 * i - 1] - 1.0, 2.0);
	}
	return result;
}

double * x8()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i) x[i] = 2.0;
	return x;
}

/* Freudstein and Roth function */
double f9(double const * x)
{
	double result = 0.0;
	for(size_t i = 2; i <= n; ++i)
	{
		result += pow(-13.0 + x[i - 2] + ((5.0 - x[i - 1]) * x[i - 1] - 2.0) * x[i - 1], 2.0) + pow(-29.0 + x[i - 2] + ((1 + x[i - 1]) * x[i - 1] - 14.0) * x[i - 1], 2.0);
	}
	return result;
}

double * x9()
{
	double * x = (double *) malloc(n * sizeof(double));
	x[0] = 0.5;
	x[1] = -2.0;
	for(size_t i = 2; i < n; ++i) x[i] = 0.0;
	return x;
}

/* Discrete boundary value function */
double f10(double const * x)
{
	double result = pow(2 * x[0] + pow(x[0] + 1.0 / (n + 1.0) + 1.0, 3.0) / (2.0 * pow(n + 1.0, 2.0)), 2.0) + pow(2 * x[n - 1] + pow(x[n - 1] + n / (n + 1.0) + 1.0, 3.0) / (2.0 * pow(n + 1.0, 2.0)), 2.0);
	for(size_t i = 2; i < n; ++i)
	{
		result += pow(2 * x[i - 1] - x[i - 2] - x[i] + pow(x[i - 1] + i / (n + 1.0) + 1.0, 3.0) / (2.0 * pow(n + 1.0, 2.0)), 2.0);
	}
	return result;
}

double * x10()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i) x[i] = (i / (n + 1.0)) * (i / (n + 1.0) - 1.0) * (n + 1.0);
	return x;
}

/* Broyden tridiagonal function */
double f11(double const * x)
{
	double result = pow((3.0 - 2.0 * x[0]) * x[0] + 1.0, 2) + pow((3.0 - 2.0 * x[n - 1]) * x[n - 1] + 1.0, 2);
	for(size_t i = 2; i < n; ++i)
	{
		result += pow((3.0 - 2.0 * x[i - 1]) * x[i - 1] - x[i - 2] - 2.0 * x[i] + 1.0, 2);
	}
	return result;
}

double * x11()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i) x[i] = -1.0;
	return x;
}

/* Arrowhead function */
double f12(double const * x)
{
	double result = 0.0;
	for(size_t i = 1; i < n; ++i)
	{
		result += pow(pow(x[i - 1], 2.0) + pow(x[n - 1], 2.0), 2) - 4.0 * x[i - 1] + 3.0;
	}
	return result;
}

double * x12()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i) x[i] = 1.0;
	return x;
}

/* Nondiagonal quartic function */
double f13(double const * x)
{
	double result = pow(x[0] - x[1], 2.0);
	for(size_t i = 2; i < n; ++i)
	{
		result += pow(x[i - 2] + x[i - 1] + x[n - 1], 4.0) + pow(x[n - 2] - x[n - 1], 2.0);
	}
	return result;
}

double * x13()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i)
	{
		x[i] = 1.0;
		x[i + 1] = -1.0;
	}
	return x;
}

/* Banded quartic function */
double f14(double const * x)
{
	double result = 0.0;
	for(size_t i = 4; i < n; ++i)
	{
		result += pow(pow(x[i - 4], 2.0) + 2.0 * pow(x[i - 3], 2.0) + 3.0 * pow(x[i - 2], 2.0) + 4.0 * pow(x[i - 1], 2.0) + 5.0 * pow(x[n - 1], 2.0), 2.0) - 4.0 * x[i - 4] + 3.0; 
	}
	return result;
}

double * x14()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i) x[i] = 1.0;
	return x;
}

/* Penalty function */
double f15(double const * x)
{
	double result = 0.0;
	for(size_t i = 1; i <= n; ++i)
	{
		result += pow(x[i - 1], 2.0) - 0.25;
	}
	result = pow(result, 2.0);
	for(size_t i = 1; i <=n; ++i)
	{
		result += pow(x[i - 1] - 1.0, 2) / pow(10.0, 5.0);
	}
	return result;
}

double * x15()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i) x[i] = i + 1.0;
	return x;
}

/* Trigonometric function */
double f16(double const * x)
{
	double result = 0.0;
	double subresult = 0.0;
	for(size_t i = 1; i <= n; ++i)
	{
		subresult = 0.0;
		for(size_t j = 1; j <= n; ++j)
		{
			subresult += cos(x[j - 1]) + i * (1.0 - cos(x[i - 1])) - sin(x[i - 1]);
		}
		result += pow(n - subresult, 2.0);
	}
	return result;
}

double * x16()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i) x[i] = 1.0;
	return x;
}

/* Quartic function */
double f17(double const * x)
{
	double result = 0.0;
	for(size_t i = 1; i <= n; ++i)
	{
		result += i * pow(x[i - 1], 2.0);
	}
	return pow(result, 2.0);
}

double * x17()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i) x[i] = 1.0;
	return x;
}
