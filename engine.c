#include "parameters.h"
#include "input.h"

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* calculates gradient of function f at point x and stores it in g */
void gradient(double const * x, double (* f)(double const * x), double * g)
{
	double * xh;
	double h;
	double t;
	xh = malloc(n * sizeof(double));
	memcpy(xh, x, n * sizeof(double));
	for(size_t i = 0; i < n; ++i)
	{
		t = xh[i];
		h = sqrt(DBL_EPSILON) * fmax(1.0, fabs(t));
		xh[i] += h;
		g[i] = (f(xh) - f(x)) / h;
		xh[i] = t;
	}
	free(xh);
}

/* performs operation a * x + y and stores result in r */
void axpy(double a, double const * x, double const * y, double * r)
{
	for(size_t i = 0; i < n; ++i) r[i] = a * x[i] + y[i];
}

/* performs operation a * x - y and stores result in r */
void axmy(double a, double const * x, double const * y, double *r)
{
	for(size_t i = 0; i < n; ++i) r[i] = a * x[i] - y[i];
}

/* returns dot product of vector x and y */
double dot(double const * x, double const * y)
{
	double result = 0.0;
	for(size_t i = 0; i < n; ++i) result += x[i] * y[i];
	return result;
}

/* returns norm of vector x */
double norm(double * x)
{
	double result = 0.0;
	for(size_t i = 0; i < n; ++i) result += x[i] * x[i];
	return sqrt(result);
}

/* performs Polak-Ribiere algorithm on function f with a given set of parameters and prints results */
void optimize(double * (* x0)(), double (* f)(double const * x))
{
	int k;
	double alpha;
	double beta;
	double * x;
	double * d;
	double * g;
	double * gk;
	double * buffer;
	clock_t clocks;

	x = x0();
	d = (double *) malloc(n * sizeof(double));
	g = (double *) malloc(n * sizeof(double));
	gk = (double *) malloc(n * sizeof(double));
	buffer = (double *) malloc(n * sizeof(double));

	clocks = clock();
	/* step 0 */
	k = 0;
	gradient(x, f, gk);
	for(size_t i = 0; i < n; ++i) d[i] = -gk[i];

	while(1)
	{
		/* step 1 */
		memcpy(g, gk, n * sizeof(double));

		/* step 2 */
		alpha = 1.0;
		axpy(alpha, d, x, buffer);
		for(size_t i = 0; f(buffer) > f(x) + delta * alpha * dot(g, d); ++i)
		{
			alpha = pow(gamma, i + 1);
			axpy(alpha, d, x, buffer);
		}

		/* step 3 */
		axpy(alpha, d, x, x);

		/* step 4 */
		++k;

		/* step 5 */
		gradient(x, f, gk);

		/* step 6 */
		if(norm(gk) < epsilon) break;

		/* step 7 */
		axmy(1.0, gk, g, buffer);
		beta = dot(gk, buffer) / dot(g, g);

		/* step 8 */
		axmy(beta, d, gk, d);
	}
	clocks = clock() - clocks;
	printf("   Number of iterations: %d\n", k);
	printf("   Execution time (sec): %f\n", (double) clocks / CLOCKS_PER_SEC);
	printf("   F(x) = %f\n", f(x));
	printf("   x = [ %f", x[0]);
	for(size_t i = 1; i < n; ++i) printf(", %f", x[i]);
	printf(" ]\n");
	free(x);
	free(d);
	free(g);
	free(gk);
	free(buffer);
}
