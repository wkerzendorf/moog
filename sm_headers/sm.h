#include "copyright.h"
#if !defined(INC_SM_H)
#define INC_SM_H
#if !defined(PI)
#  define PI 3.1415926535897932384626434
#endif
#define PROGNAME "sm"			/* name of programme */

typedef struct {
   unsigned char red,
   		 green,
   		 blue;
} COLOR;
/*
 * defaults for plotting aesthetically pleasing text
 * CHEIGHT and CWIDTH may be adjusted for different aspect ratios when the
 * devices are opened.
 */
#define CDEF     22			/* Fonts are enlarged by CDEF */
#define CHEIGHT  32			/* unenlarged character height */
#define CWIDTH   20			/* unenlarged character width */
#define PDEF 128			/* SCREEN size of a point (before
					   corection for aspect ratio) */
/*
 * plot window size
 */
#define SCREEN_SIZE 32767
/*
 * maximum number of corners for PTYPE 3 points
 */
#define MAX_POLYGON 30
/*
 * Symbolic names for styles used in filling polygons
 */
#define FILL_SOLID 0			/* solid color */
#define FILL_DOTS 1			/* filled with dots */

extern float cheight,cwidth,	  /* canonical height and width of characters*/
  	     fx1,fx2,fy1,fy2,     /* User coords of graphics area    */
	     fsx,fsy,ffx,ffy;     /* Scale and offset to conversion  */
extern int   s_depth,s_height,	  /* pixel depth, height, */
	     s_width;		  /* 			  and width of str */
extern long  saved_seek_ptr;	  /* where we got to in a file */
extern int   gx1,gx2,gy1,gy2;     /* Device coords of graphics area  */
extern long xp,yp;		  /* current plot position (can be offscreen)*/
extern float llweight;            /* Line weight		     */
extern int   lltype;              /* Line type: dotted, etc.         */
extern float lltype_expand;	  /* expansion for ltypes */
extern float aspect,		  /* aspect ratio of screen y/x      */
	     eexpand;             /* Global expansion of chars, pts  */
extern float aangle,sm_sin,sm_cos;  /* Rotation of chars and points  */
extern REAL *angle_vec;		  /* vector of angles, used in point */
extern int   n_angle_vec;	  /* dimension of angle_vec          */
extern REAL *expand_vec;	  /* vector of expansions, used in point */
extern int   n_expand_vec;	  /* dimension of expand_vec         */
extern int   termout;             /* True for term, false for print  */
extern char *version_string;	  /* version string */
extern float xscreen_to_pix,	  /* scale SCREEN to window coords   */
  	     yscreen_to_pix;
extern int   ldef;		  /* scale spacing for lweight       */
extern float label_offset_scale;  /* How much to increase label offset */
#endif
