#include "engine.h"
#include "input.h"
#include "parameters.h"
#include "test.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[] )
{
	if(argc < 2)
	{
		printf("Lacking argument!\n-run - to run custom configuration\n-test - to run set of tests\n");
		return EINVAL;
	}
	if(!strcmp(argv[1], "-run"))
	{
		printf("Running custom configuration\n");
		optimize(x, f);
		return 0;
	}
	if(!strcmp(argv[1], "-test"))
	{
		if(n == 0 || n % 4 != 0)
		{
			printf("Tests can only be run when n is a nonzero multiple of 4!\n");
			return  EINVAL;
		}
		printf("1. Quadratic function\n");
		optimize(x1, f1);
		printf("\n2. Woods function\n");
		optimize(x2, f2);
		printf("\n3. Powell singular function\n");
		optimize(x3, f3);
		printf("\n4. Extended Rosenbrock function\n");
		optimize(x4, f4);
		printf("\n5. Generalized Rosenbrock function\n");
		optimize(x5, f5);
		printf("\n6. Shanno's function\n");
		optimize(x6, f6);
		printf("\n7. Engval function\n");
		optimize(x7, f7);
		printf("\n8. Cragg and Levy function\n");
		optimize(x8, f8);
		printf("\n9. Freudstein and Roth function\n");
		optimize(x9, f9);
		printf("\n10. Discrete boundary value function\n");
		optimize(x10, f10);
		printf("\n11. Broyden tridiagonal function\n");
		optimize(x11, f11);
		printf("\n12. Arrowhead function\n");
		optimize(x12, f12);
		printf("\n13. Nondiagonal quartic function\n");
		optimize(x13, f13);
		printf("\n14. Banded quartic function\n");
		optimize(x14, f14);
		printf("\n15. Penalty function\n");
		optimize(x15, f15);
		printf("\n16. Trigonometric function\n");
		optimize(x16, f16);
		printf("\n17. Quartic function\n");
		optimize(x17, f17);
		return 0;
	}
	printf("Wrong argument!\n-run - to run custom configuration\n-test - to run set of tests\n");
	return EINVAL;
}
