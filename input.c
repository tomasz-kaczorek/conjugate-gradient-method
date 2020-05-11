#include "parameters.h"

#include <math.h>
#include <stdlib.h>

double f(double const * x)
{
	double result = 0.0;
	for(size_t i = 2; i < n; ++i)
	{
		result += 100 * (pow(x[i], 2) + pow(x[i-1], 2)) + pow(x[i-2], 2);
	}
	return result;
}

double * x()
{
	double * x = (double *) malloc(n * sizeof(double));
	for(size_t i = 0; i < n; ++i) x[i] = 3.0;
	return x;
}
