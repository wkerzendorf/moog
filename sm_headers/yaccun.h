#include "copyright.h"
#define INC_YACCUN_H
/*
 * these are the typedefs for the yacc union 
 */
#if defined(macOSX)
#  define CHARMAX 160			/* maximum size of word */
#else
#  define CHARMAX 1000			/* maximum size of word */
#endif

typedef struct {			/* a pair of floats + 1 */
   float a,b;
} PAIR;

typedef struct {
   char *start,				/* start of string */
        *end;				/* end of string (just before '\0') */
} STR;

#define TYPE_WORD 1			/* values for TOK_LIST.type[] */
#define TYPE_VECTOR 2

typedef union {
   VECTOR vec;
   char str[CHARMAX];
} VECTOR_OR_STRING;

typedef struct {
   int nitem,				/* number of items on list */
       nmax;				/* max number with space allocated */
   VECTOR_OR_STRING **i_list;		/* array of pointers to items */
   char *i_space;			/* storage for items */
   int *i_type;				/* types of objects on i_list */
} TOK_LIST;

union yystype {				/* union for yacc variable stack */
   char charval[CHARMAX];
   REAL floatval;
   int intval;
   PAIR pairval;
   STR strval;
   TOK_LIST *t_list;
   VECTOR vector;
};
#define YYSTYPE union yystype
