#include "copyright.h"
#define N_SCROLL 5			/* number of lines to 'scroll' */
#define TERM_SIZE 40
#define HSIZE 162			/* length of line for history/editor */

typedef struct {
   int baud,			/* baud rate of terminal */
       dlin,			/* `destination line' if "ch" unavailable */
       ncol,			/* number of columns */
       nlin,			/* and number of lines */
       pad;			/* character for padding */
   char name[TERM_SIZE],	/* name of term */
	del_char[TERM_SIZE],	/* delete previous character */
	del_line[TERM_SIZE],	/* delete to the end of the current line */
	forw_curs[TERM_SIZE],	/* move cursor forward */
   	set_keys[TERM_SIZE],	/* put terminal in "keyboard transmit" */
   	unset_keys[TERM_SIZE];	/* take terminal out of "keyboard transmit" */
} TERMINAL;

typedef struct edit {
   struct edit *next;		/* next command */
   struct edit *prev;		/* previous command */
   char line[HSIZE + 1];		/* command text */
   char mark;				/* a mark in the list */
   int num;				/* command number */
} EDIT;

#define MARK '\001'			/* the programme mark */
#define HISTORY_MARK '\002'		/* the history pointer  */
#define SEARCH_MARK '\004'		/* the search got here */

extern int last_char;			/* the last char that was typed */
