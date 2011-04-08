#include "copyright.h"
#define INC_VECTORS_H
/*
 * These are the definitions for VECTORs
 */
#define VEC_DESCRIP_SIZE 80		/* size of descrip string in VECTOR */
/*
 * VEC_STR_SIZE and NO_VALUE are defined in options.h
 */
#define VEC_NULL 0			/* vector is of unknown type */
#define VEC_FLOAT 1			/* vector's elements are REALs */
#define VEC_LONG 2			/* vector's elements are integers */
#define VEC_STRING 3			/* vector's elements are strings */

typedef struct {
   char descrip[VEC_DESCRIP_SIZE],	/* Description of vector for help() */
	*name;				/* name of vector (stored in tree) */
   union {
      struct {				/* VEC_STRING */
	 char **s,
	      *s_s;			/* space for **s */
      } s;
      LONG *l;				/* VEC_LONG */
      REAL *f;				/* VEC_FLOAT */
   } vec;      				/* pointer to vector values */
   int dimen,				/* dimension of vec */
       type;				/* type of vector */
} VECTOR;   
