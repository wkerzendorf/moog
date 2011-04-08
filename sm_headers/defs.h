#include "copyright.h"
#define FALSE 0
#define TRUE 1

#define MIN(A,B) ((A)<(B)?(A):(B))
#define MAX(A,B) ((A)>(B)?(A):(B))
#define NINT(I) ((int)((I) + 0.5))		/* nearest int (I >= 0) */
#define IN_RANGE(X,L,U)   ((U) > (L) ? (X) >= (L) && (X) <= (U) :\
				       (X) >= (U) && (X) <= (L))
