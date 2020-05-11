/* calculates gradient of function f at point x and stores it in g */
void gradient(double const * x, double (* f)(double const * x), double * g);

/* performs operation a * x + y and stores result in r */
void axpy(double a, double const * x, double const * y, double * r);

/* performs operation a * x - y and stores result in r */
void axmy(double a, double const * x, double const * y, double *r);

/* returns dot product of vector x and y */
double dot(double const * x, double const * y);

/* returns norm of vector x */
double norm(double * x);

/* performs Polak-Ribiere algorithm on function f with a given set of parameters */
void optimize(double * (* x0)(), double (* f)(double const * x));
