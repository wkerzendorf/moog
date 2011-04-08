#include "copyright.h"
#define INC_TTY_H			/* we've included this file */
/*
 * TTY package definitions.
 */
#define	DEF_BAUDRATE	9600		/* default baud rate */
#define	TABSIZE		8
#define	MAX_TC_NESTING	5	/* max nesting of tc=term references */
/*
 * Mapping function used to map capcodes ("cm", etc.) into unique integers.
 */
#define	ENCODE(X) ((X)[0]*128+(X)[1])
/*
 * TTY descriptor structure.  Full termcap entry is the 'caplist' string.
 * The caplist is indexed at open time to permit a binary search for
 * capabilities at run time.
 */
#define T_MEMINC 512			/* increment if overflow occurs */
#define MAX_CAPS 300			/* maximum capabilities */
#define MAX_COORD 7			/* maximum coords for ttysubi */
#define SZ_CTRLST 50			/* buffer size for control strings */

typedef struct {
int t_baud,			/* baud rate for delays */
    t_istc,			/* is sg_tcdevice tc or TC? */
    t_nlines,			/* nlines on terminal at open */
    t_ncols,			/* ncols on terminal at open */
    t_ncaps,			/* number of capabilities */
    t_caplen,			/* length of caplist, chars */
    t_len,			/* size of t_caplist */
    t_op,			/* index of end of caplist */
    t_capcode[MAX_CAPS],	/* cap code array */
    t_capindex[MAX_CAPS];	/* cap index array */
char t_padchar,				/* pad character for delays */
     t_tcdevice[40],			/* name of tc/TC device */
     *t_caplist;			/* termcap entry */
} TTY;
