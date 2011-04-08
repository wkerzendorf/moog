#include "copyright.h"
/*
 *  SM devices struct
 */

typedef struct {		/* output device dependent functions */
   char d_name[40];			/* name of device */
   int (*dev_setup)();			/* initialization  */
   void (*dev_enable)();		/* enable graphics */
   void (*dev_line)();			/* draw a line from x1, y1 to x2, y2 */
   void (*dev_reloc)();			/* relocate current position */
   void (*dev_draw)();			/* draw a line from curr pos to x,y  */
   int (*dev_char)();			/* hardware characters  */
   int (*dev_ltype)();			/* hardware line type */
   int (*dev_lweight)();		/* hardware line weight */
   void (*dev_erase)();			/* erase graphics screen  */
   void (*dev_idle)();			/* switch from graph to alpha mode */
   int (*dev_cursor)();			/* cursor display */
   void (*dev_close)();			/* close device */
   int (*dev_dot)();			/* draw a single pixel dot */
   int (*dev_fill_pt)();		/* draw a filled point */
   int (*dev_fill_polygon)();		/* draw a filled polygon */
   void (*dev_ctype)();			/* set colour of line */
   int (*dev_set_ctype)();		/* set possible colours of lines */
   void (*dev_gflush)();		/* flush graphics */
   void (*dev_page)();			/* start a new page */
   void (*dev_redraw)();		/* redraw the screen, if need be */
} DEVICES;

extern DEVICES devices[];	/* all devices known to SM */
#define NODEVICE 0
#define STDGRAPH 1
#define RASTER 2
#define METAFILE 3

extern int devnum,			/* current device */
	   ndev;			/* number of devices */

/*
 * defines for graphics functions
 * If they are predefined, undef them (i.e. in control.y)
 */
#undef CTYPE
#undef CURSOR
#undef DOT
#undef DRAW
#undef ERASE
#undef LTYPE
#undef LWEIGHT
#undef PAGE

#define CHAR    (*devices[devnum].dev_char)
#define CTYPE   (*devices[devnum].dev_ctype)
#define CLOSE   (*devices[devnum].dev_close)
#define CURSOR  (*devices[devnum].dev_cursor)
#define DOT     (*devices[devnum].dev_dot)
#define DRAW    (*devices[devnum].dev_draw)
#define ENABLE	(*devices[devnum].dev_enable)
#define ERASE   (*devices[devnum].dev_erase)
#define FILL_PT	(*devices[devnum].dev_fill_pt)
#define FILL_POLYGON (*devices[devnum].dev_fill_polygon)
#define GFLUSH  (*devices[devnum].dev_gflush)
#define IDLE    (*devices[devnum].dev_idle)
#define LTYPE   (*devices[devnum].dev_ltype)
#define LWEIGHT (*devices[devnum].dev_lweight)
#define LINE    (*devices[devnum].dev_line)
#define PAGE    (*devices[devnum].dev_page)
#define REDRAW  (*devices[devnum].dev_redraw)
#define RELOC   (*devices[devnum].dev_reloc)
#define SET_CTYPE (*devices[devnum].dev_set_ctype)
#define SETUP   (*devices[devnum].dev_setup)
