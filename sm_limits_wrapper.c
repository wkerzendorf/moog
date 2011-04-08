/* int sm_limits(double,double,double,double); */
#include <stdio.h>
#include "sm_declare.h"

void sm_limits_wrapper(double *a, double *b, double *c, double *d)
{
    sm_limits(*a, *b, *c, *d);
}
