#include "copyright.h"
/*
 * Definitions for fonts
 */
#define FONT_FILE_TYPE 3		/* revision number for font file.
					   Increment this whenever the
					   font file format changes */

#define CURRENT -1			/* use the current font */
#define FONT_MOVE '\177'		/* move to, not draw to, here */
#define NCHAR 96			/* number of characters in a font */
/* #define NFONT 6			   number of fonts: defined below */
#define MAGSTEP 1.2			/* size change corresponding to \1 */
#define SUB_SUPER_EXPAND 0.6		/* factor to expand sub/superscripts */
#define SLANT 0.2			/* italic slant ratio */
#define TEX_NAME_SIZE 50		/* longest allowed definition name */
#define TEX_VAL_SIZE 500		/* longest allowed definition value
					   (but space is in fact malloc'd) */

static struct {
   char *ab1,*ab2;			/* names of fonts */
} fonts[] = {				/* names of fonts, TeX mode only */
#define ROMAN 0
   { "r", "rm"},
#define GREEK 1
   { "g", "gr"},
#define SCRIPT 2
   { "s", "sc"},
#define TINY 3
   { "t", "ti"},
#define OLD_ENGLISH 4
   { "o", "oe"},
#define PRIVATE 5
   { "p", "privateA"},
#define PRIVATE1 6
   { "", "privateB"},
#define PRIVATE2 7
   { "", "privateC"},
#define PRIVATE3 8
   { "", "privateD"},
#define PRIVATE4 9
   { "", "privateE"},
#define PRIVATE5 10
   { "", "privateF"},
#define PRIVATE6 11
   { "", "privateG"},
/*#define ITALIC ?
   { "i", "it"}	is special, and doesn't appear here */
/*#define BOLD ?
   { "b", "bf"}	is special, and doesn't appear here */
};
#define NFONT (sizeof(fonts)/sizeof(fonts[0])) /* number of fonts */
