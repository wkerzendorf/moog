#include "copyright.h"
#define INC_STDGRAPH_H 1
  
/*
 * STDGRAPH definitions.
 */
#define OK 1
#define NO 0
#define YES 1

#define N_ARGS 10			/* max. number of arguments */
#define	SZ_PROGRAM	1024		/* maximum size of an encoded cap */
#define SZ_SBUF		1024		/* initial string buffer size */
#define SZ_MEMORY	1024		/* encoder memory size */
#define LEN_STACK	20		/* encoder stack size */
#define NREGISTERS	12		/* number of encoder registers */
#define E_IOP		10		/* encoder i/o pointer register */
#define E_TOP		11		/* encoder top memory register */
#define PADCHAR		0		/* used to gen. delays */
/*
 * The STDGRAPH state/device descriptor
 */
typedef struct {
   char sg_sbuf[SZ_SBUF],			/* string buffer */
        *sg_av[N_ARGS+1],			/* pointers to args */
	*sg_nextch,				/* next char pos in str buf */
        *sg_encodexy,				/* format for encoding coords */
        *sg_delimcur,				/* string delim cursor value */
        *sg_decodecur,				/* scan value format */
        *sg_devname,				/* name of open device */
        *sg_startdraw,				/* pointer to DS string */
        *sg_enddraw,				/* pointer to DE string */
        *sg_startdraw_rel,			/* pointer to dS string */
        *sg_enddraw_rel,			/* pointer to dE string */
        *sg_startmove,				/* pointer to VS string */
        *sg_endmove,				/* pointer to VE string */
        *sg_startmove_rel,			/* pointer to vS string */
        *sg_endmove_rel,			/* pointer to vE string */
        *sg_startmark,				/* pointer to MS string */
        *sg_endmark,				/* pointer to ME string */
        *sg_starttext,				/* pointer to TB string */
        *sg_endtext,				/* pointer to TE string */
	*sg_record_term,			/* output record terminator */
	sg_outfile[60];				/* name of output file */
   int sg_ac,					/* number of args in sg_av */
       sg_szsbuf,				/* size, string buffer */
       sg_lencur,				/* number of chars in value */
       sg_ltype,				/* line type */
       sg_lwidth,				/* line width */
       sg_rt_size;				/* length of RT string */
} SG;

typedef union {
   int i;
   float f;
} REGISTER;				/* an encoder register */

/*
 * STDGRAPH external variables. The commonest (time critical) variables occur
 * directly, and the struct SG has everything else.
 */
extern SG *g_sg;			/* stdgraph graphics descriptor */
extern TTY *g_tty;			/* graphcap descriptor */
extern char *g_xy;			/* pointer to coord encoding string */
extern int g_in, g_out;			/* file descriptors to device */
extern int g_xc, g_yc;			/* current window position */
extern REGISTER g_reg[];		/* encoder registers */
extern char g_mem[];			/* encoder memory */
