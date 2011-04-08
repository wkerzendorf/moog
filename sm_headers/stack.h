#include "copyright.h"
/*
 * These are the flags for the I/O stack
 */
#define S_ILLEGAL 0			/* illegal value */
#define S_DO 1				/* the body of a do loop */
#define S_FOREACH 2			/* the body of a foreach loop */
#define S_MACRO 3			/* a macro */
#define S_NORMAL 4			/* nothing special */
#define S_TEMP 5			/* like S_NORMAL, delete after use */
#define S_RESET_PROMPT 6		/* like S_NORMAL, reset prompt on pop*/
#define S_WHILE 7			/* a WHILE loop */
